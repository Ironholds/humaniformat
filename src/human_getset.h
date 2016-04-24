#include "human_parse.h"

#ifndef __HUMAN_GETSET__
#define __HUMAN_GETSET__

class human_getset: public human_parse {

private:
  
  /**
   * A function for taking a single name and retrieving a specified element of it
   * 
   * @param name a string (ideally a human name)
   * 
   * @param element an integer identifying which element of the parsed name to return
   * 
   * @return a string containing the requested element.
   */
  String get_single(std::string name, int element);
  
  /**
   * A function for taking a single name and setting a specified element of it
   * 
   * @param name a string (ideally a human name)
   * 
   * @param element an integer identifying which element of the parsed name to return
   * 
   * @param replacement a string identifying what to replace the specified element with.
   * 
   * @return a string containing the re-specified name.
   */
  std::string set_single(std::string name, int element, std::string replacement);
  
public:
  
  /**
   * A function for taking a vector of names and retrieving a specified element of each
   * one.
   * 
   * @param names a string vector (ideally of human names)
   * 
   * @param element an integer identifying which element of the parsed names to return
   * 
   * @return a string vector containing each instance of the requested element.
   */
  CharacterVector get_vector(CharacterVector names, int element);
  
  /**
   * A function for taking a vector of names and setting a specified element of each
   * one.
   * 
   * @param names a string vector (ideally of human names)
   * 
   * @param element an integer identifying which element of the parsed names to return
   * 
   * @param replacement a string identifying what to replace each specified element with.
   * 
   * @return a string vector containing the re-specified names.
   */
  CharacterVector set_vector(CharacterVector, int element, String replacement);
  
};

#endif
