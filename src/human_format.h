#include "human_parse.h"

#ifndef __HUMAN_FORMAT__
#define __HUMAN_FORMAT__

/**
 * A class for reformatting names before parsing them.
 */
class human_format: public human_parse {
  
private:
  
  /**
   * A function for taking a single name in the form (lastname, firstname)
   * and reformatting it
   * 
   * @param name a string (ideally a human name)
   * 
   * @return a string containing the reformatted name.
   */
  std::string reverse_format(std::string name);
  
  /**
   * A function for taking a single name in the form (initial.initial. lastname)
   * and reformatting it
   * 
   * @param name a string (ideally a human name)
   * 
   * @return a string containing the reformatted name, where each period-separated
   * element before the first space is now space-separated.
   */
  std::string period_format(std::string name);
  
public:
  
  /**
   * A function for taking a vector of names in the form (lastname, firstname)
   * and reformatting them
   * 
   * @param names a string vector (ideally of human names)
   * 
   * @return a string vector containing the reformatted names.
   */
  CharacterVector reverse_format_vector(CharacterVector names);
  
  /**
   * A function for taking a vector of names in the form (initial.initial. lastname)
   * and reformatting them.
   * 
   * @param name a string vector (ideally of human names)
   * 
   * @return a string vector containing the reformatted names, where each period-separated
   * element before the first space is now space-separated.
   */
  CharacterVector period_format_vector(CharacterVector names);
  
};

#endif 
