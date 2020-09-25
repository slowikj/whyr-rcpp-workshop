#include <Rcpp.h>
using namespace Rcpp;

// Rcpp attribute
// [[Rcpp::export]]
NumericVector timesTwo(NumericVector x) {
  return x * 2; /// vectorization
}

// [[Rcpp::export]]
int timesTwoInteger(int x) {
  return x * 2;
}

// create a vector of values 1, 10, 19
// compute the sum of it
// [[Rcpp::export]]
int computeTheSum() {
  IntegerVector res { 1, 10, 19 };
  return sum(res);
}

// TASK: create a vector of length n (n is a function parameter)
// fill it with the provided value (value is a function parameter)
// return this vector
// [[Rcpp::export]]
IntegerVector createVector(int n, int value) {
  IntegerVector res(n, value);
  return res;
}

// [[Rcpp::export]]
int getValue(IntegerVector v, int index) {
  // indexing from 0
  return v[index - 1];
}

// task: compute the vector of n Fibonacci numbers
// F[1] = 0, F[2] = 1, F[n] = F[n - 1] + F[n - 2]
// INPUT: n (integer)
// OUTPUT: an integer vector of n Fibonacci numbers
// example: input (4); output (c(0, 1, 1, 2))
// [[Rcpp::export]]
IntegerVector getFibonacciRcpp(int n) {
  IntegerVector res(n);
  res[0] = 0; 
  res[1] = 1;
  for(int i = 2; i < n; ++i) {
    res[i] = res[i - 1] + res[i - 2];
  }
  return res;
}

/*** R
timesTwo(42)
timesTwo(c(1,2,3))
timesTwoInteger(42)
#timesTwoInteger(c(1,2,3))
computeTheSum()
createVector(5, 10)
getValue(c(9, 10, 123), 2)
getFibonacciRcpp(10)
*/
