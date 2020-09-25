#include <Rcpp.h>

// Reminder how R uses NAs

/*** R
NA

NA_character_
NA_real_
*/

// [[Rcpp::export]]
Rcpp::NumericVector getRealNA() {
  Rcpp::NumericVector v = {NA_REAL};
  return v;
}

// [[Rcpp::export]]
Rcpp::IntegerVector getIntNA() {
  Rcpp::IntegerVector v = {NA_INTEGER};
  return v;
}

// [[Rcpp::export]]
Rcpp::CharacterVector getCharNA() {
  Rcpp::CharacterVector v = {NA_STRING};
  return v;
}

// [[Rcpp::export]]
Rcpp::LogicalVector getBoolNA() {
  Rcpp::LogicalVector v = {NA_LOGICAL};
  return v;
}
