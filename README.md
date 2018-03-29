# Critical Mass Application

## Work / Project Examples


All my examples of work are in the folder \Work-Project Examples. Every of my project was in French, but I can code in English.
For my first example. The problem was that I had an enterprise that create products and they have a storage cost and a production cost, also I need to fulfil the demand every day and I can’t exceed my storage space. For a given period and prices, I need to optimize the cost of storage and production.

## Example 1

I worked alone on this project in c++. So what I did is create a table of dimensions of the maximum amount of storage from 0 to 𝐸 per n number of days from 0 to 𝑛 -1.
I put an image of my basic case in my folder. My variable 𝑑𝑖 is the demand for the day i, 𝑒𝑗 and 𝑒𝑘  are the amount of storage space available after the day. V is my matrix (E x n).

I need to verify:
 0 ≤ 𝑑𝑖−𝑒𝑗+𝑒𝑘  ≤ 𝑃 and 𝑒𝑘  <= E

So the solution is to create the matrix and for every single day, you calculate the price for e products plus the cost of storage. Then when I’m done with the matrix, I choose the minimum cost on the final day and I check what I needed to do (store and product) the day before until I find my solution for every day.

## Example 2




### Inspiration

blablabla

```
code example
```

### Focus

blablbla

## Code Challenge

For the function that removes all instances of a specified topping. I have no choice to go through the array. I can't let one element of the array because it can be the one I want to remove. Since the function "filter" in O(n), then, in all cases my function will be in big Theta(n).

At first, for the second function I tried, to do the same thing that the first function. I tried to remove the element that I have in double in the array. But I used the function indexOf in the function filter, so my function was in O(n^2). Then I thought if I sort every element of my array, use slice(0) and a function filter that compare my first element and my second element. I have a function that is in theta(nlogn) . So my second function is quicker than my first.

Bonus: I decided to use a small function that display my array in html list and add a little of CSS to make it better.
