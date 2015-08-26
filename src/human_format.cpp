#include "human_format.h"

std::string human_format::reverse_format(std::string name){
  
  std::deque < std::string > split_name = split_parts(name, ",");
  
  // If there's only one element, it's not comma-separated. Return
  if(split_name.size() == 1){
    return name;
  }
  
  // If there are more, reverse it
  std::string output;
  while(split_name.size() > 0){
    output = split_name[0] + " " + output;
    split_name.pop_front();
  }
  
  // Remove double spacing
  size_t double_position = 0;
  while((double_position = output.find("  ", double_position)) != std::string::npos) {
    output.replace(double_position, 2, " ");
    double_position += 1;
  }
  
  // If we end up with starting or terminating spaces, remove those
  if(output.size() > 0){
    if(output[0] == ' '){
      output.erase(0,1);
    }
    if(output[output.size() - 1] == ' '){
      output.erase((output.size() - 1), 1);
    }
  }
  return output;
}

std::string human_format::period_format(std::string name){
  
  //We'll assume that the first space marks the end of any period-delimited names.
  std::string remainder;
  size_t space_loc = name.find(" ");
  if(space_loc != std::string::npos && space_loc != name.size()){
    remainder = name.substr(space_loc+1);
    name = name.substr(0, space_loc);
  }
  std::deque < std::string > split_name = split_parts(name, ".");
  
  if(split_name.size() == 1){
    if(remainder.size() != 0){
      return name + " " + remainder;
    }
    return name;
  }
  
  std::string output = split_name[0];
  split_name.pop_front();
  while(split_name.size() > 0){
    output += ". " + split_name[0];
    split_name.pop_front();
  }
  output += remainder;
  
  return output;
}

std::vector < std::string > human_format::reverse_format_vector(std::vector < std::string > names){
  
  for(unsigned int i = 0; i < names.size(); i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    names[i] = reverse_format(names[i]);
  }
  
  return names;
}

std::vector < std::string > human_format::period_format_vector(std::vector < std::string > names){
  
  for(unsigned int i = 0; i < names.size(); i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    names[i] = period_format(names[i]);
  }
  
  return names;
}
