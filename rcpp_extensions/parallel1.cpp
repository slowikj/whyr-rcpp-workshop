//[[Rcpp::depends(RcppParallel)]]

#include <Rcpp.h>
#include <RcppParallel.h>

struct MyWorker : RcppParallel::Worker {
  RVector<int> input_;
  RVector<int> output_;
  
  Worker(IntegerVector input, IntegerVector output) 
    
  operator()(std::size_t begin, sitd::size_t end) {
    
  } 
};

//[[Rcpp::export]]
IntegerVector add5(IntegerVector x) {
  
  MyWorker worker();
  
  RcppParallel::parallelFor(0, x.size(), worker);
}