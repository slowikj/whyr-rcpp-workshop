//[[Rcpp::depends(RcppParallel)]]

#include <Rcpp.h>
#include <RcppParallel.h>

struct MyWorker : public RcppParallel::Worker {
  RcppParallel::RVector<int> input_;
  RcppParallel::RVector<int> output_;
  
  MyWorker(Rcpp::IntegerVector input, Rcpp::IntegerVector output) :
    input_(RcppParallel::RVector<int>(input)),
    output_(RcppParallel::RVector<int>(output)) {};
    
  void operator()(std::size_t begin, std::size_t end) {
    for(int i = begin; i < end; i++) {
      output_[i] = input_[i] + 5;
    }
  } 
};

//[[Rcpp::export]]
Rcpp::IntegerVector add5(Rcpp::IntegerVector x) {
  Rcpp::IntegerVector output(x.size());
  
  MyWorker worker(x, output);
  
  RcppParallel::parallelFor(0, x.size(), worker);
  
  return output;
}
