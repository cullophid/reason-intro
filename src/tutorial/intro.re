/* Comments */
/* text inside these marks get ignored by the program */
/* They are only intended for programmers reading the code */

/* Use Js.log to print values to the console */


Js.log "Hello World";

/* VALUES */
/* There are several types of values available in reason */
/* Here a value of type string is save in a variable name*/
let name:string = "Andreas";


/* Here a value of type int is saved in a variable age */
/* and a value of type boolean is saved in the variable isImportant*/
let age:int = 33;
let isImportant:bool = true;

/* ReasonML can infer the types of a value so the following would also work */
let myName = "Andreas";
let myAge = 33;

let amIImportant = true;

/* Notice that I cannot use the same variable names, since they have already been defined */


/* FUNCTIONS */

/* functions are defined with the fun keyword followed by a single input parameter on the left
 * side of the arrow, and an "expression" on the right.
 * an expression is a single instruction for the computer to evaluate. It can be a simple value or a complex mathematical formula.
 * "Andreas"

 * 33
 * 5 + 5
 * age > 33
 * if (age > 33) true else false

 * are all valid expressions 
 * expressions evaluate to a value that can be assigned to a variable, or returned from a function
 * 
 * A function always take one input parameter and returns one value.
 */

let isOld = fun n =>
  if (n > 33) true else false;



/* 
 * In this case the function `isOld` returns true if age is large than 33 otherwise false.
 * Notice that I am using the name age even though I just told you that i cannot reused the same names.
 * Thats because a function defines a *scope*. Variables are only awailable inside the scope they are defined in.
 * Outside variables like "name" are still awailable.
 */

/* Variables inside a scope `shadows` the variables outside the scope. 
 * In the folowing example the input parameter `name` shadows the name variable in the outer scope
 */

let isAndreas = fun name =>
  if (name == "Andreas") true else false;

  Js.log (isAndreas name); /* true */
/* 
 * That means that inside the function isAndreas `name` refers to the parameter of the function.
 * Outside the function name is still defined as "Andreas".
 */

 /* 
  * You can `call` or `apply` a function by provding it with an argument
  */ 

  let youAreOld = isOld 36; /* true */
  let youAreNotAndreas = isAndreas "Sean"; /* false */
 
 /*
  * The terms argument and parameters are used somewhat interchangable
  */

/* 
 * Applying a function is an expression and can be used inside other functions
 */

let printableName = fun name =>
  if (isAndreas name) name else "Who Cares!!!?";

/* 
 * This allows us to build increasingly complicated functions by combining simple ones
 */

/* PATTERN MATCHING (Switch expressions) */
/* Pattern matching is a bit like the if expression we looked at before.
It allows us to chose what expression to evalueate base on some condition. */

let isPowerful = fun name => 
  if (name == "Andreas") true else false;

/* The same function can be written using pattern matching */

let isTotallyPowerful = fun name => 
  switch name {
  | "Andreas" => true
  | "The Hulk" => true
  | _ => false
  };

/* In this case the values "Andreas" matches the first pattern and "The Hulk" matches the second (both equally powerful).
 * The underscore means `any other value` 
 * We will be using pattern matchin alot more once we have learned about data structures.
*/


/* A function can call it self if we define it as recursive. we do that with the rec keyword */


let rec factorial = fun n => 
  if (n == 1) 
    n 
  else 
    n + factorial (n-1);

/* 
 * the factorial functions returns the sum of adding all the numbers below a given number 
 * factorial 1 == 1
 * factorial 2 == 3
 * factorial 3 == 6
 * ..etc
 * 
 * it works by something called the divide and conquer principle
 * first we solve the problem for the simplest case n = 1;
 * then we expand our solution to work for the remaining values
 * factorial 2 == 2 + (factorial 1) 
 * factorial 3 == 3 + (factorial 2)
 * ... ect
 * 
 * this principle is very important and we will be using it alot more in the future
 * */

/* Try out the excercises in intro_exercises or continue to lists.re */