#include <Rcpp.h>
using namespace Rcpp;

/*** R
head(mtcars)
*/


// TASK ===================

// PART 1.
// We'll use "mtcars" dataset again.
// Create NumericVector describing max speed (Vmax) of a car.
// Suppose the formula is as follows:
// Vmax = 100 + hp or 250 if hp > 150
//   (it emulates speed limit present in many cars)
// Your function should take a NumericVector obtained by:
/*** R
mtcars$hp
*/

// PART 2.
// Now generalize the function to set speed limit at arbitrary point.
// User should be able to e.g. set a speed limit of 300.
