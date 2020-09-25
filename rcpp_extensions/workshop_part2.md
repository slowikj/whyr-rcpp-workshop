Rcpp-extensions
========================================================
author: Dominik Rafacz
date: 25.09.2020
autosize: true

What we have learned so far
========================================================

From the first two parts of the workshop:
- C++ is faster than R, but requires more care about e.g. types.
- Rcpp provides convenient interface for operating on R internals 
(which themselves are not very user-friendly).
- Rcpp makes it possible to do everything that can be done in R in a similar way

What we are about to learn
========================================================

- There is still a lot of place for improvement - solely Rcpp is not always enough.
- Rcpp is easily extendible and there are already created useful extensions

Most relevant Rcpp extensions
========================================================

- Rcpp Modules (in fact, not an extension, but built-in feature)
- RcppParallel
- RcppArmadillo

RcppParallel
========================================================

From official page (https://rcppcore.github.io/RcppParallel/) :

> RcppParallel provides a complete toolkit for creating portable, high-performance parallel algorithms without requiring direct manipulation of operating system threads.

but first... classes and structures
========================================================

```cpp
struct MyStructure {
  
  // ### members
  int memberOne_;           
  IntegerVector memberTwo_; 
  
  // ### constructor
  MyStructure(IntegerVector memberOneVec, IntegerVector memberTwo) :
      memberOne_(memberOneVec[0]),
      memberTwo_(memberTwo) {} 
  
  // ### member functions
  int getMemberOneMultipliedBy5() { 
    return memberOne_ * 5;
  }
  void add5ToMemberOne() {
    memberOne_ += 5;
  }
}
```

instantination and calling methods
========================================================


```cpp
MyStructure x(IntegerVector{1,2,3}, IntegerVector(5));

int y = x.getMemberOneMultipliedBy5();  // 1 * 5 = 5
x.add5ToMemberOne();
int z = x.getMemberOneMultipliedBy5();  // 6 * 5 = 30
```

inheritance
========================================================

```cpp
struct AnotherStructure : public MyStructure {}
```

- `AnotherStructure` is `MyStructure`, but `MyStructure` is not `AnotherStructure`
- `AnotherStructure` has all fields that `MyStructure` has and possibly even more.

RVector
========================================================

R does not support parallelization natively and it is impossible to call R API simultaneously. In order to make parallelization possible, you cannot use Rcpp shortcuts.

Creating or destroying Rcpp object during performing a parallel operation may (and probably will do) result in crashing of the R session.

Simplest solution: RVector


```cpp
RVector<int> input(IntegerVector(100))
RVector<double> output(NumericVector(100))
```


parallelFor
========================================================

![](paralelFor.png)


parallelReduce
========================================================

![](parallelReduce.png)

RcppArmadillo
========================================================

From official page (https://github.com/RcppCore/RcppArmadillo) :

> RcppArmadillo provides an interface from R to and from Armadillo by utilising the Rcpp R/C++ interface library.



> Armadillo is a high-quality linear algebra library for the C++ language, aiming towards a good balance between speed and ease of use. It provides high-level syntax and functionality deliberately similar to Matlab (TM). 
