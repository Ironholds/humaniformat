#include "human_parse.h"


#ifndef __HUMAN_FORMAT__
#define __HUMAN_FORMAT__

class human_format: public human_parse {
  
private:
  
  std::string reverse_format(std::string name);
  
  std::string period_format(std::string name);
  
public:
  
  std::vector < std::string > reverse_format_vector(std::vector < std::string > names);
  
  std::vector < std::string > period_format_vector(std::vector < std::string > names);
  
};

#endif 
