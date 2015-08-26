#include <Rcpp.h>
using namespace Rcpp;

#ifndef __HUMAN_PARSE__
#define __HUMAN_PARSE__

class human_parse {

protected:
  
  std::set < std::string > salutations;
  
  std::set < std::string > compounds;
  
  std::set < std::string > suffixes;
  
  std::deque < std::string > split_parts(std::string name, std::string split_on);
  
  std::string erase_char(std::string part, std::string char_to_erase);
  
  bool match_component(std::string part, std::set < std::string > set_ref);
  
  std::vector < std::string > parse_single(std::string name);
  
public:
  
  DataFrame parse_vector(std::vector < std::string > names);
  
  human_parse();
  
};
#endif
