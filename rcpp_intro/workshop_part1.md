How to make your code fast - R and C++ integration using Rcpp
========================================================
author: Jadwiga Słowik, Dominik Rafacz, Mateusz Bąkała
date: 25.09.2020
autosize: true

People
========================================================

- **Jadwiga Słowik**
  - Data Science Msc student
  - strong algorithmic and software engineering background
- **Dominik Rafacz**
 - Data Science Bsc student
 - works in a research group for 1.5 years
- **Mateusz Bąkała**
  - Data Science Bsc student
  - R packages developer (tidysq, deepdep)
  

Workshop plan
========================================================

- Introduction to C++ and Rcpp 
- Rcpp syntactic sugar
- Rcpp extensions

A 15 minutes break after each hour 

General information
========================================================

- If you want to ask for help:
  - feel free to use ***#workshop-rcpp*** slack channel
- Make sure that you have installed:
  - Rcpp
  - RcppParallel
  - RcppArmadillo*
- Github repo link: https://github.com/slowikj/whyr-rcpp-workshop
- Have a good time! :)

Let's start our Rcpp journey!
========================================================

What is the Rcpp package?
========================================================
- an R package that facilitates the integration between R and C++
- a more convenient alternative for cumbersome R API
 - actually, it is a wrapper: it abstracts low-level details of R API
- it provides the C++ wrappers for R structures like vectors, lists, matrices
- it can make a C++ function accessible via R code
- **important**: it does not copy R objects during the invocation of the C++ function

When should the Rcpp package be used?
========================================================
It should be used when a part of your code:
- performs slow
- can be optimized by rewriting it in C++

**Important**: profile your code and find bottlenecks before rewriting your code to C++!

Common characteristics of R code bottlenecks
========================================================
- **for-loops that cannot be vectorised**
  - for example: the computation of Fibonacci sequence
- **the need for advanced data structures**
  - trees, sets, queues...
  - you can take advantage of STL and Boost library in C++
- **functions called many times**
  - for example: recursive functions
- **an algorithm requires low-level, imperative approach to be robust**
  
Simple function example
========================================================
The following code in R:

```r
one <- function() {
  1
}
```

can be rewritten in C++ in the following way:

```cpp
int one() {
  return 1;
}
```

Basic C++ types
========================================================
- **int**
- **double**
- **float**
- **bool**
- **char**


C++ for loop
========================================================
**For loop** syntax template

```cpp
for(init_statement; true_condition; instruction_after_each_iteration) {
  // code
}
```

An example:

```cpp
int sum = 0;
for(int i = 1; i < n; ++i) {
  sum += i;
}
```

If statement
========================================================
Syntax template:

```cpp
if(true_condition) {
  // code
}
```

An example:

```cpp
int a = 5;
int b = 9;
if (a + b == 14) {
  // code
}
```


Basic types of R objects in C++ (Rcpp)
========================================================
- Vectors
  - **IntegerVector**, **NumericVector**, **StringVector** / **CharacterVector**, **LogicalVector**
- Matrices 
  - **IntegerMatrix**, **NumericMatrix**, **StringMatrix** / **CharacterMatrix**, **LogicalMatrix**
- **List**, **DataFrame**, **Environment**

Variables
========================================================

```cpp
int x = 123;
```


```cpp
IntegerVector v {1, 2, 3}; // c(1, 2, 3)
```


```cpp
IntegerVector v(5); // c(0, 0, 0, 0, 0)
```


```cpp
StringVector v(3); // c("", "", "")
```

Let's go to RStudio!
========================================================

C++ STL
========================================================
STL (Standard Template Library) provides many useful data structures such as:
- set
- map
- queue
- stack
- hash map

In github resources there are examples!


Exporting Rcpp code to R
========================================================
You can
- write C++ and R code in one file and use *source* RStudio button
- separate C++ and R code
  - use `Rcpp::sourceCpp("source.cpp")` in R code
- create a package
  - use `Rcpp::Rcpp.package.skeleton("package_name")`

Important notes
========================================================
- vectors and matrices are indexed starting from 0
- C++ is compiled, strongly typed language
- Pure C++ code is imperative and standard operations are not vectorized
 - however, a part of Rcpp functions are vectorized
- Profile your code first
- Rewrite in C++ only critical parts (bottlenecks)


