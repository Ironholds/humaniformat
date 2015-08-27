#include <Rcpp.h>
using namespace Rcpp;

#ifndef __HUMAN_PARSE__
#define __HUMAN_PARSE__

/**
 * The base class for parsing human names.
 */
class human_parse {

protected:
  
  /**
   * A set of unique salutations. Populated by the constructor.
   */
  std::set < std::string > salutations;
  
  /**
   * A set of unique last name compounds. Populated by the constructor.
   */
  std::set < std::string > compounds;
  
  /**
   * A set of unique suffixes. Populated by the constructor.
   */
  std::set < std::string > suffixes;
  
  /**
   * A function for taking a string and splitting it by a
   * given substring into a deque
   * 
   * @param name a string (ideally a human name)
   * 
   * @param split_on a string to split `name` on.
   * 
   * @return a deque containing each token in name delimited
   * by split_on
   */
  std::deque < std::string > split_parts(std::string name, std::string split_on);
  
  /**
   * A function for taking a string and erasing all instances
   * of a specified character from it
   * 
   * @param part a string to erase the character from
   * 
   * @param char_to_erase a string containing the character
   * to erase.
   * 
   * @return a string excluding to_erase
   */
  std::string erase_char(std::string part, std::string char_to_erase);
  
  /**
   * A function for identifying in a boolean fashion whether
   * an input string is found within a set
   * 
   * @param part a string to match
   * 
   * @param set_ref a string set to match against.
   * 
   * @return a true (the string matched a member of set_ref) or false
   * (it did not).
   */
  bool match_component(std::string part, std::set < std::string > set_ref);
  
  std::vector < std::string > parse_single(std::string name);
  
public:
  
  DataFrame parse_vector(std::vector < std::string > names);
  
  human_parse();
  
};
#endif
