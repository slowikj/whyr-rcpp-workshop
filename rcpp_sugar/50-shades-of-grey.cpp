#include <Rcpp.h>
using namespace Rcpp;

/*** R
mat <- matrix(1:12, nrow = 4)
*/

// This is how we extract by value

// [[Rcpp::export]]
IntegerVector extractValue(IntegerMatrix matrix) {
  IntegerVector col = matrix(_, 2);
  col = col + 10;
  return col;
}

// And this - by reference

// [[Rcpp::export]]
IntegerVector extractReference(IntegerMatrix matrix) {
  IntegerMatrix::Column col = matrix(_, 2);
  col = col + 10;
  return col;
}


// TASK ===================

// PART 1.
// Experiment a bit. What name would you expect for a row?
// And how would you substitute whole column with 0's?

// PART 2.
// You can also access a sub matrix (e.g. matrix(Range(1, 2), Range(0, 2))).
// Knowing that it is named Sub, how would you triple submatrix values?

// PART 3. (optional, I have no idea how to do it easily)
// What do you need to fill submatrix with NA's (or any value really)?
