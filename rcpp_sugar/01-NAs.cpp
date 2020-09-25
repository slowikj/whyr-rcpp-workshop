#include <Rcpp.h>

// NAs in pure C++

// [[Rcpp::export]]
double getRealNA() { return NA_REAL; }


// TASK ===================

// PART 1.
// Experiment a bit. What about other types? Test "int" and "bool".
// What are the results? Why will it not work for "char"?
// Can you replace "char" with "std::string"?

// PART 2.
// What happens when you add 1 to NA_XXX before returning?
// Test for different types.
