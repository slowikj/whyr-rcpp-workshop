#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
DataFrame appendDisplacementPerCylinder(DataFrame df) {
  df["disp_per_cyl"] = as<NumericVector>(df["disp"]) / as<NumericVector>(df["cyl"]);
  return df;
}


// TASK ===================

// We'll use "mtcars" dataset, available in base R.
// Create a column with consumption in liters per 100 km.
// The formula is as follows (mpg = miles per galon):
//  lp100km = 235.214583 / mpg
