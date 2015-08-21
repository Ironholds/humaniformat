#include "human_format.h"

std::string human_format::comma_format(std::string name){
  
  // Split on commas. If there are no commas, return.
  std::deque < std::string > split_string = split_parts(name, ",");
  if(split_string.size() < 2){
    return name;
  }
  
  std::string output;
  std::string holding;
  
  // Comma formatting
  while(split_string.size() > 0){
    unsigned int split_size = (split_string.size() - 1);
    if(match_component(split_string[split_size], suffixes)){
      if(output.size() == 0){
        output.append(split_string[split_size]);
      } else {
        output.append(" " + split_string[split_size]);
      }
    } else {
      if(output.size() == 0){
      
      }
      holding.append(split_string[split_size]);
    }
    split_string.pop_back();
  }
  
  if(holding.size() > 0){
    output = holding + output;
  }
  
  return output;
}

std::vector < std::string > human_format::format_vector(std::vector < std::string > names){
  
  unsigned int input_size = names.size();

  // For each element, go nuts
  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    
    names[i] = comma_format(names[i]);
    
  }
  
  return names;
}
