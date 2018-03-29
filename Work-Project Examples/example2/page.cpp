#include "page.hpp"
#include <algorithm>
#include <assert.h>
#include <stdlib.h>
#include <random>
#include <iostream>

void swap(std::vector<Resultat>& vectorA, unsigned int position1,
		unsigned int position2) {
	Resultat rs1 = vectorA.at(position1);
	vectorA.at(position1) = vectorA.at(position2);
	vectorA.at(position2) = rs1;
}

unsigned int random(unsigned int l, unsigned int r) {
	unsigned int s;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(l, r);
	s = dis(gen);
	return s;
}

unsigned int PartitionRand(std::vector<Resultat>& vectorA, unsigned int premier,
		unsigned int dernier) {
	unsigned int j, s;
	unsigned int r = dernier;
	unsigned int l = premier;

	s = random(l, r);
	swap(vectorA, l, s);
	Resultat p = vectorA.at(l);
	j = l;

	for (unsigned int i = l + 1; i <= r; i++) {
		if (vectorA[i] < (p)) {
			j++;
			swap(vectorA, i, j);
		}
	}
	swap(vectorA, j, l);
	return j;
}

std::vector<Resultat> sousVector(std::vector<Resultat>& vectorA,
		unsigned int p1, unsigned p2) {
	std::vector<Resultat> vectorB;
	vectorB.reserve(p2 - p1 + 1);

	for (unsigned int i = p1; i <= p2; i++) {
		vectorB.push_back(vectorA.at(i));
	}
	return vectorB;
}

unsigned int SelectionRecRand(std::vector<Resultat>& vectorA, unsigned int k,
		unsigned int premier, unsigned int dernier) {
	unsigned int s, l, r;
	l = premier;
	r = dernier;

	s = PartitionRand(vectorA, l, r);

	if ((s - l + 1) == k) {
		return s;
	}
	if ((s - l + 1) > k) {

		return SelectionRecRand(vectorA, k, l, s - 1);
	}
	if ((s - l + 1) < k) {

		return SelectionRecRand(vectorA, k - s + l - 1, s + 1, r);
	}

	return 0;

}


// return the results of a page
// Inputs:
// results_non_tries: all search results not sorted
// number_results_by_page: the number of results per page (except possibly on the last page)
// number_page: the number of the page. The first page is page number 0.
// Outputs:
// page: search results on the requested page
void retournePage(const std::vector<Resultat>& resultats_non_tries,
		unsigned int nombre_resultats_par_page, unsigned int numero_page,
		std::vector<Resultat>& page) {
	assert(!resultats_non_tries.empty());
	assert(page.empty());
	assert(nombre_resultats_par_page > 0);
	assert(
			numero_page
					< (resultats_non_tries.size() + nombre_resultats_par_page
							- 1) / nombre_resultats_par_page);

	unsigned int premierElement, dernierElement;

	std::vector<Resultat> vectorA = resultats_non_tries;

	premierElement = nombre_resultats_par_page * numero_page;
	dernierElement = premierElement + nombre_resultats_par_page;

	if (dernierElement > resultats_non_tries.size()) {
		dernierElement = resultats_non_tries.size();
	}

	unsigned int position = SelectionRecRand(vectorA, dernierElement, 0,
			resultats_non_tries.size() - 1);

	if (premierElement >= 1) {
		SelectionRecRand(vectorA, premierElement, 0, position);
	}

	page = sousVector(vectorA, premierElement, dernierElement - 1);

	std::sort(page.begin(), page.end());
}
