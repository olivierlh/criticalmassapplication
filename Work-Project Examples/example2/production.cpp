#include "production.hpp"
#include <iostream>
#include <utility>

// This function takes an instance of the production scheduling problem and returns
// in the "solution" vector the quantity that must be produced each day in order to minimize the costs
// of production and storage.
void ProductionProgrammationDynamique(const InstanceProduction& instance,
		std::vector<unsigned int>& solution) {

	std::vector<std::vector<unsigned int>> tableau;
	std::vector<std::vector<unsigned int>> tableauProduit;
	std::vector<std::vector<std::pair<unsigned int, unsigned int>>>tableauPair;
	tableau.reserve(instance.entreposage_maximal() + 1);
	tableau.reserve(instance.entreposage_maximal() + 1);
	tableau.reserve(instance.entreposage_maximal() + 1);

	std::vector<unsigned int> vecteur;
	std::vector<std::pair<unsigned int, unsigned int>> vecteur2;
	for (unsigned int i = 0; i < instance.nb_jours(); i++) {
		vecteur.push_back(std::numeric_limits<unsigned int>::max());
		vecteur2.push_back(
				std::make_pair(std::numeric_limits<unsigned int>::max(),
						std::numeric_limits<unsigned int>::max()));
	}

	for (unsigned int e = 0; e <= instance.entreposage_maximal(); e++) {
		tableau.push_back(vecteur);
		tableauProduit.push_back(vecteur);
		tableauPair.push_back(vecteur2);
	}

	for (unsigned int i = 0; i < instance.nb_jours(); i++) {
		for (unsigned int ek = 0; ek <= instance.entreposage_maximal(); ek++) {
			unsigned int coutDeEj = 0;
			unsigned int coutMin = std::numeric_limits<unsigned int>::max();
			unsigned int productionMin = 0;
			std::pair<unsigned int, unsigned int> paire;
			unsigned int cout = 0;
			unsigned int enlever = 0;
			unsigned int a, b;
			a = instance.entreposage_maximal() + 1;
			b = instance.nb_jours();
			paire = std::make_pair(a, b);
			for (unsigned int ej = 0; ej <= instance.entreposage_maximal();
					ej++) {
				if (i == 0) {
					coutDeEj = 0;
					enlever = 0;
				} else {
					a = ej;
					b = i - 1;
					coutDeEj = tableau[a][b];
					enlever = ej;
				}
				int production = instance.demande(i) - enlever + ek;

				if (production <= (int) instance.production_maximale()
						&& production >= 0 && coutDeEj < 9999999) {
					int coutProduction = instance.cout_production(production);
					int coutEntreposage = instance.cout_entreposage(ek);
					cout = coutProduction + coutEntreposage + coutDeEj;
					if (cout < coutMin) {
						coutMin = cout;
						productionMin = production;
						paire = std::make_pair(a, b);
					}
				}

			}
			tableau[ek][i] = coutMin;
			tableauProduit[ek][i] = productionMin;
			tableauPair[ek][i] = paire;
		}
	}

	unsigned int coutFinalMinimal = std::numeric_limits<unsigned int>::max();
	unsigned int cout, eiFinal = 0;
	for (unsigned int ei = 0; ei <= instance.entreposage_maximal(); ei++) {
		cout = tableau[ei][instance.nb_jours() - 1];
		if (cout < coutFinalMinimal) {
			coutFinalMinimal = cout;
			eiFinal = ei;
		}
	}

	solution.reserve(instance.nb_jours());
	std::vector<unsigned int> solutionInverse;
	std::pair<unsigned int, unsigned int> pair =
			tableauPair[eiFinal][instance.nb_jours()];
	unsigned int a = eiFinal;
	unsigned int b = instance.nb_jours() - 1;

	for (unsigned int i = 0; i < instance.nb_jours(); i++) {
		unsigned int produits = tableauProduit[a][b];
		solutionInverse.push_back(produits);
		pair = tableauPair[a][b];
		a = pair.first;
		b = pair.second;
	}

	for (int i = instance.nb_jours() - 1; i >= 0; i--) {
		solution.push_back(solutionInverse[i]);
	}
}
