#include <Rcpp.h>
using namespace Rcpp;

/*** R
head(mtcars)
*/


// TASK ===================

// PART 1.
// We'll use "mtcars" dataset again.
// Create CharacterVector categorizing cars into "powerful" and "weak".
// If a car has hp (horsepower) of > 150, then categorize it as "powerful",
// else as "weak". Your function should take a NumericVector obtained by:
/*** R
mtcars$hp
*/

// HOWEVER:
// Strings behave differently there. You have to create CharacterVectors
// of equal lengths to the conditional one, where each element is the same.
// To get such vector, you should use something like:
rep(CharacterVector("powerful"), hp.length())
// where hp is the power vector.
