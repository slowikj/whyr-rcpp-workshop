// [[Rcpp::plugins("cpp11")]]
#include <Rcpp.h>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace Rcpp;

// [[Rcpp::export]]
IntegerVector getUnique(IntegerVector v) {
  std::unordered_set<int> hs;
  for(const auto& elem: v) {
    hs.insert(elem);
  }
  
  return Rcpp::wrap(hs);
}

// [[Rcpp::export]]
StringVector getUniqueS(StringVector v) {
  std::unordered_map<std::string, int> hs;
  for(const auto& elem: v) {
    std::string convertedElem = Rcpp::as<std::string>(elem);
    if(hs.find(convertedElem) == hs.end()) {
      hs[convertedElem] = 1;
    } else {
      ++hs[convertedElem];
    }
  }
  return Rcpp::wrap(hs);
}

/*** R
getUnique(c(1,1,12,2,23,23,33))
v <- rep(12, 1000)
df <- as.data.frame(microbenchmark::microbenchmark(r=unique(v), rcpp=getUnique(v), times=10))
df
*/