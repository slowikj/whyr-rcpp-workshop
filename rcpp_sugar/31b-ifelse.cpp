#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
CharacterVector categorizeByPower(NumericVector power) {
  int n = power.length();
  CharacterVector powerful = rep(CharacterVector("powerful"), n);
  CharacterVector weak = rep(CharacterVector("weak"), n);
  return ifelse(power > 150, powerful, weak);
}
