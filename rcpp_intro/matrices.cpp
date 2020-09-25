#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
IntegerMatrix createAMatrix(int n, int m) {
  IntegerMatrix res(n, m);
  int value = res(1, 1); // note: the rows numbers and cols numbers are indexed starting from 0
  return res;
}

// task:
// create a matrix of dimensions n x m
// fill the r-th row with the provided value
// [[Rcpp::export]]
IntegerMatrix getFilledMatrix(int n, int m, int r, int value) {
  IntegerMatrix res(n, m);
  for(int col = 0; col < res.ncol(); ++col) {
    res(r - 1, col) = value;
  }
  return res;
}

/*** R
createAMatrix(3, 5)
getFilledMatrix(3, 4, 1, 100)
*/
