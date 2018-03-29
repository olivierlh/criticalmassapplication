var toppings = ['pepperoni', 'mushrooms', 'mozzarella', 'ham', 'sausage', 'mozzarella', 'bacon', 'black olives', 'chicken', 'green peppers', 'red pepper', 'hotdog', 'bacon', 'spinach', 'garlic', 'ham', 'pineapple', 'feta', 'tomatoes', 'red onion'];

function removeTopping(array, element) {
  return array.filter(function (a) {
    return a !== element;
  });
}

var newToppings = removeTopping(toppings, 'pineapple');

function removeDuplicateSlow(array) {
  return array.filter(function (element, position, arr) {
    return arr.indexOf(element) == position;
  });
} //in O(n^2)
function removeDuplicateQuick(array) {
  return array.slice(0).sort().filter(function (x, i, arr) {
    return x.localeCompare(arr[i + 1]);
  });
} //in O(nlogn)
var deDupToppingsSlow = removeDuplicateSlow(toppings);
var deDupToppingsQuick = removeDuplicateQuick(toppings);

function displayList(array, id) {
  var aLen, text, i;
  aLen = array.length;
  text = "";
  for (i = 0; i < aLen; i++) {
    text += "<li>" + array[i] + "</li>";
  }
  document.getElementById(id).innerHTML = text;
}

displayList(toppings, "topping-list");
displayList(newToppings, "newtopping-list");
displayList(deDupToppingsSlow, "deDupTopping-list");
displayList(deDupToppingsQuick, "deDupTopping-list2");