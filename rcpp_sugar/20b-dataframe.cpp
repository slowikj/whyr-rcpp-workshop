#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
DataFrame metricConsumption(DataFrame df) {
  df["lp100km"] = 235.214583 / as<NumericVector>(df["mpg"]);
  return df;
}
