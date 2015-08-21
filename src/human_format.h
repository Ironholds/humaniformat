#include "human_parse.h"


#ifndef __HUMAN_FORMAT__
#define __HUMAN_FORMAT__

class human_format: public human_parse {
  
private:
  
  std::string comma_format(std::string name);
  
public:
  
  std::vector < std::string > format_vector(std::vector < std::string > names);
  
};

#endif 
