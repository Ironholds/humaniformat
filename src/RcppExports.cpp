// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// humaniformat
DataFrame humaniformat(std::vector < std::string > names);
RcppExport SEXP humaniformat_humaniformat(SEXP namesSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< std::vector < std::string > >::type names(namesSEXP);
    __result = Rcpp::wrap(humaniformat(names));
    return __result;
END_RCPP
}