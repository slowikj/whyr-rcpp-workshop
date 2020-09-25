#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
int sumRcpp(IntegerVector x) {
  return sum(x);
}

// [[Rcpp::export]]
int sumRcpp2(IntegerVector x) {
  return sum(noNA(x));
}


// TASK ===================

// PART 1.
// Run benchmark, comparing these functions. Which one runs better?

// PART 2.
// Create your pair of functions, one using noNA(), the other not.
// There are many options available, for example "mean", "sd" and "diff".
// Now run benchmark on your functions. Is the result still the same?