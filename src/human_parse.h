#include <Rcpp.h>
using namespace Rcpp;

#ifndef __HUMAN_PARSE__
#define __HUMAN_PARSE__

class human_parse {
  
private:
  
  std::set < std::string > salutations;
  
  std::set < std::string > compounds;
  
  std::set < std::string > suffixes;
  
  std::deque < std::string > split_parts(std::string name);
  
  std::string erase_periods(std::string part);
  
  bool match_component(std::string part, std::set < std::string > & set_ref);
  
  std::vector < std::string > parse_single(std::string name);
  
public:
  
  DataFrame parse_vector(std::vector < std::string >& names);
  
  human_parse();
  
};
#endif
