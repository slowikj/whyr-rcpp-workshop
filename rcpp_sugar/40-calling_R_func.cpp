#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
CharacterVector rcppClasses(DataFrame df) {
  return df.attr("class");
}

// [[Rcpp::export]]
CharacterVector rcppRownames(DataFrame df) {
  return df.attr("row.names");
}

// [[Rcpp::export]]
CharacterVector rcppRownames2(DataFrame df) {
  return rownames(df);
}

// [[Rcpp::export]]
List splitNames(DataFrame df) {
  Environment base_env("package:base");
  Function strsplit = base_env["strsplit"];
  return strsplit(rcppRownames(df), " ");
}


// TASK ===================

// Simply mess around a bit. What other attributes can you access?
// Which attributes have defined sugar functions (like rownames())?
// And why on Earth would you import R function into C++ when calling it from within R??
