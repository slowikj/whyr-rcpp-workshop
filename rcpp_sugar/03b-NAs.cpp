#include <Rcpp.h>
using namespace Rcpp;

/*** R
numbers <- as.integer(rnorm(1e6))
microbenchmark::microbenchmark(
  standard = sumRcpp(numbers),
  noNA = sumRcpp2(numbers)
)
*/
