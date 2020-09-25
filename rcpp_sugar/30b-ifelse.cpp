#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector Vmax(NumericVector power) {
  return ifelse(power > 150, 250, power + 100);
}

// [[Rcpp::export]]
NumericVector Vmax2(NumericVector power, double split) {
  return ifelse(power > split, split + 100, power + 100);
}
