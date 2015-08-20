#include <Rcpp.h>
using namespace Rcpp;

#ifndef __HUMAN_PARSE__
#define __HUMAN_PARSE__

class human_parse {
  
private:
  
  std::vector < std::string > salutations;
  
  std::vector < std::string > compounds;
  
  std::vector < std::string > suffixes;
  
  std::vector < std::string > parse_single(std::string name);
  
public:
  
  DataFrame parse_vector(std::vector < std::string >& names);
  
  human_parse();
  
};
#endif
