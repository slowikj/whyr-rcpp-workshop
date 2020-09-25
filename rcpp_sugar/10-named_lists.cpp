#include <Rcpp.h>
using namespace Rcpp;

/*** R
x <- list(1:3, "a word")
y <- list(numbers = 1:3, word = "a word")
*/

// [[Rcpp::export]]
List getList() {
  List list = List::create(
    NumericVector::create(1, 2, 3),
    CharacterVector::create("a word")
  );
  return list;
}

// [[Rcpp::export]]
List getNamedList() {
  List list = List::create(
    Named("numbers") = seq(1, 3),
    _["word"] = CharacterVector::create("a word")
  );
  return list;
}
