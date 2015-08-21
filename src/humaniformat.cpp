#include "human_parse.h"

//' @export
// [[Rcpp::export]]
DataFrame humaniformat(std::vector < std::string > names){
  human_parse parse_inst;
  return parse_inst.parse_vector(names);
}
