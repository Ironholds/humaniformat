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
  
  /**
   * A function for taking a single name and parsing it
   * 
   * @param name a string (ideally a human name)
   * 
   * @return a vector containing the salutation, first name, middle name(s),
   * last name, and suffix(es). An element is an empty string if its component
   * could not be identified.
   */
  CharacterVector parse_single(std::string name);
  
public:
  
  /**
   * A function for taking a vector of names and parsing them
   * 
   * @param names a string vector containing human names
   * 
   * @return a data.frame containing the salutations, first names, middle name(s),
   * last names, suffix(es) and full names of each element of names, as columns.
   * An element is an empty string if its component could not be identified.
   */
  DataFrame parse_vector(CharacterVector names);
  
  /**
   * The constructor
   */
  human_parse();
  
};
#endif
