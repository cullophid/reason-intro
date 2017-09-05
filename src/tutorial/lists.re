/* List is a data structure that lets you represent an ordered collection of items.
 * Its called a data structure because it structures other types of data. 
 * The following example is a list of strings:
 */

let heroes = ["Andreas", "Sean", "The Hulk"];

/* A list can have 0 or more items */
let emptyList = [];

/* List has a special sytax `...` called spread */

let moreHeroes = ["Pink Powerranger", ...heroes];

/* 
 * Here it added all the names from the list heroes to the list moreHeroes *
 * Hint: this only works with one list, `["Superman", ...dc_heroes, ...marvel_heroes]` wont work.
 * 
 * 
 * The same syntax can be used for pattern matching
 */

let isEmpty lst => switch lst {
| [] => true /* [] is the empty list */
| _ => false
};

/* 
 * When pattern matching you can temprarily assign varaibles from the pattern 
 * take a look at the following function that returns all elements except the first one
 * when applied to a list
*/

let tail lst => switch lst {
| [] => [] 
| [_, ...tail] => tail
};


/* In this example we used a combination of different tricks: 
 *  - we used [] to match the empty list
 *  - we used _ to ignore the first element of the list
 *  - we used ... catch all the remaining values in the variable tail
 * 
 * Notice that when the ... operator is used for pattern matching is does the opposite of whet it normally does
 * Usually it takes a list of items and spreads then in to a list
 * here it collectes all the remaining items in the list and captures them in the list named tail. 
 */

/* we can use a recursive function to get the number of elements in a list (its length) */

let rec length = fun lst => 
  switch lst {
  | [] => 0
  | [_] => 1
  | [_, ...tail] => 1 + (length tail)
  };
  
/* Here we use the divide an conquer principle again 
 * Its easy to solve the problem for an empty list (0)
 * its just as trivial to solve for a list containing only one element (1)
 * Finally we can solve for all other cases by reaslising that the length of a list is 
 * simply 1 + the length of its tail
 * */


/* Try out the excercises in lists_exercises or continue to functions.re */