# Critical Mass Application

## Work / Project Examples

All my examples of my work are in the folder \\Work-Project Examples. Everyone of my projects are in French, but I can code in English.

I do not have the complete code for my examples 2 and 3. I only have the cpp files.

### Example 1

For this first code in Matlab, I furnished all, so you can try it too with your personal photos if you want. I put my examples, pictures and the process images in the folder mix and I put the results in a folder too. I did this project all by myself.

The goal was to mix two pictures with a mask, but the problem is if you mix the pictures with a small mask (small gradient) you get a bad cut in the colour and if you mix the picture with a big mask (big gradient), we lose details.

The solution is to mix the pictures with frequency. As you can see in the mix folder, I mixed the high frequency (details) with small mask and the low with a big mask. I think it's very cool, because you can mix every picture you want and the result is impressive.

My project is not really done. I would like to create a window to import manually my photos and my masks that I want.

### Example 2

For my second example, the problem was that I had an enterprise that created products and they had a storage cost and a production cost, also I needed to fulfil the demand every day and I could not exceed my storage space. For a given period and prices, I needed to optimize the cost of storage and production.

I worked alone on this project in c++. So what I did is create a table of dimensions of the maximum amount of storage from 0 to 𝐸 per n number of days from 0 to 𝑛 -1.
I put an image of my basic case in my folder. My variable 𝑑𝑖 is the demand for the day i, 𝑒𝑗 and   are the amount of storage space available after the day. V is my matrix (E x n).

I need to verify:
 0 ≤ 𝑑𝑖−𝑒𝑗+  ≤ 𝑃 and 𝑒𝑘  &lt;= E

So the solution is to create the matrix and for every single day, you calculate the price for e products plus the cost of storage. Then when I’m done with the matrix, I choose the minimum cost on the final day and I check what I needed to do (store and product) the day before until I find my solution for every day.

### Example 3

I work alone too for that project in c++. I had to do something like a search engine. When someone requests a certain page, I need to give the 10 best results for that page within a million results not sorted. Every result in the search as a weight, so for example, if I want the page 10, I need to give the 100th to 109th best results.

Solution: The algorithm will take a vector of unsorted results and will do a SelectionRecRand to find the kth smallest element. Where k is the last of the current page. We therefore know that all the elements before k are now smaller than this one. Then we repeat SelectionRecRand sorts our elements between the first result and the kth smallest element. When the 2nd SelectionRecRand is done, all elements of the current page are between the smallest of the page and the largest of the page. So to finish just do QuickSort on the elements of the page.

This is my complexity for my algorithm:
(𝑛)∈ (𝑛+𝑛+𝑛+𝑘log𝑘), 𝐶(𝑛)∈ 𝜃(3𝑛+klog𝑘), 𝐶(𝑛)∈ 𝜃(𝑛+𝑘logk)

### Inspiration

### 1

One of my inspirations, I use this work "<https://hypjudy.github.io/2017/04/25/image-morphing/">. I found that impressive, what they can do. I tried myself, I use a little bit of their code, but I recreate all the code using the information they provide. I place every point (x,y) on two photos in the same order. I use delaunay to create triangles, with those triangles I morph every pixel in the triangle to another triangle. I use a function to calculate where every pixel is going to be with certain number of frames in the videos. I also calculate the percentage of colour I have between two images.

I put some results I had in a folder in /Inspiration.

### 2

A project I will do in the next month or so. I want to create a code in Matlab so that I do what "<https://www.ostagram.me/>" is doing. The goal is to analyze the style of one image and apply it to the other, if I get the chance to work with you, I will show you what I got!

### 3

I didn't do a lot of inspiration work. I like to inspire myself with a lot of code snippets.

I don't know if it can be considered, but I think it's a part of me that maybe you can like. I do a lot of creation with Photo Shop, I can almost do everything I want. I put some inspirations in my folders.

#### Breaking bad

I created  a picture of myself as a character of Breaking bad.

#### George Harrison

I put myself in a very old photo of George Harrison.

### Focus

I would like to focus on developing, either web or software, for the moment I think that’s what I'm best at and that's what I love the best. I would like to upgrade my abilities to create great codes that will age well.

## Code Challenge

The Code Challenge is in the folder /Code Challenge.

For the function that removes all instances of a specified topping. I have no choice to go through the array. I can't let one element of the array because it can be the one I want to remove. Since the function "filter" in O(n), then, in all cases my function will be in big Theta(n).

At first, for the second function I tried, to do the same thing that the first function. I tried to remove the element that I have in double in the array. But I used the function index Of in the function filter, so my function was in O(n^2). Then I thought if I sort every element of my array, use slice(0) and a function filter that compares  my first element and my second element. I have a function that is in the (nlogn) . So my second function is quicker than my first.

Bonus: I decided to use a small function that displays my array in html list and add a little of CSS to make it better.
