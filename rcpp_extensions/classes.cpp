#include <Rcpp.h>
using namespace Rcpp;

struct Employee {
  CharacterVector name_;
  int experience_;
  double salary_;
  
  Employee(CharacterVector name, IntegerVector experience, NumericVector salary) :
      name_(name),
      experience_(experience[0]),
      salary_(salary[0]) {};
  
  void raiseSalary() {
    salary_ = salary_ + 1000; 
  }
};

//[[Rcpp::export]]
NumericVector createEmployee(CharacterVector name, 
                    IntegerVector experience, 
                    NumericVector salary) {
  Employee x(name, experience, salary);
  x.raiseSalary();
  return NumericVector{x.salary_};
}

struct Manager : public Employee {
  
};