/* we have already touched on functions but there are lost more to them than meets the eye
 * ReasonML is called a functional programming language because functions are at the very core of how you program it.
 * 
 * 
 * Function in reason always take one input and returns one output. Sometimes however you want a function that operates on more that one input.
 * in reasonml this is called currying:
 *
 */

let add = fun a => fun b => a + b;
let three = add 1 2;


/* What happens here is that the function `add` takes one input `a` and returns one output `fun b => a + b`
 * when we call the function we are actually calilng add first, and the calling the function returned from add (fun b => a + b)
 * the return function remembers the value a that was given to add and uses it to add to b.
 * The type signature of add is 
 * int => int => int
 * 
 * its simpler to understand if you see it as `int => (int => int)`.
 * add takes an integer and returns a function
 * the new function takes on other int and returns the result which is an int
 *
 */


/* This is so common to do in ReasonML that the people who made the language wanted to make it simpler to write  */

let otherAdd a b => a + b;


/* This is exactly the same as the first add function its just simpler to write 
 * Its important to understant that the expression on the right side of the arrow (=>)
 * is only evaluate once a function has been called with ALL its arguments.
 * 
 * Because this way of writing functions is so common we often say that a function "takes two arguments"
 * As we have seen that is technically not true. it takes one argument and returns a function that takes the other argument
 * but it can make it easier to talk about functions in this way. When ever you hear talk about a 
 * function that take multiple arguments this is what is meant.
*/


/* 
 * We have seen how functions can return other function but functions can also accept functions as input 
 *  Lets look at a very common function for working with lists
 * */


let rec map f lst =>
  switch lst {
  | [] => []
  | [x] => [f x]
  | [x, ...xs]=> [f x, ...(map f xs)] 
  };

/* the map function can look a little strange when you see it first but its actually quite simple
 * its takes two arguments* the first one is a function and the second one is a list
 * it then calls the function with element in the list and returns a new list with
 * all the returned values.
 */






