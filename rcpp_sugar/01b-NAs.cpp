#include <Rcpp.h>
using namespace Rcpp;

// About booleans:

// [[Rcpp::export]]
bool testEqual(NumericVector x, NumericVector y) {
  // bool ret = all(x == y);
  bool ret = is_true(all(x == y));
  return ret;
}

/*** R
testEqual(1:5, 1L:5L)
testEqual(1:5, 1L:6L)
testEqual(1:5, 2L:6L)
*/
