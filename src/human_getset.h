#include "human_parse.h"

#ifndef __HUMAN_GETSET__
#define __HUMAN_GETSET__

class human_getset: public human_parse {

private:
  
  std::string get_single(std::string name, int element);
  
  std::string set_single(std::string name, int element, std::string replacement);
  
public:
  
  std::vector < std::string > get_vector(std::vector < std::string > names, int element);
  
  std::vector < std::string > set_vector(std::vector < std::string > names, int element,
                                         std::string replacement);
  
};

#endif
