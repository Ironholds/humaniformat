#include "human_getset.h"

std::string human_getset::get_single(std::string name, int element){
  std::vector < std::string > split_name = parse_single(name);
  return split_name[element];
}

std::string human_getset::set_single(std::string name, int element, std::string replacement){
  std::vector < std::string > split_name = parse_single(name);
  split_name[element] = replacement;
  std::string output;
  
  for(unsigned int i = 0; i < split_name.size(); i++){
    output.append(split_name[i]);
    if(i < (split_name.size() - 1) && split_name[i] != ""){
      output.append(" ");
    }
  }
  
  // Final check for trailing spaces
  if(output[output.size()-1] == ' '){
    output.erase(output.size()-1,1);
  }

  return output;
}

std::vector < std::string > human_getset::get_vector(std::vector < std::string > names, int element){
  
  for(unsigned int i = 0; i < names.size(); i++){
    names[i] = get_single(names[i], element);
  }
  
  return names;
}

std::vector < std::string > human_getset::set_vector(std::vector < std::string > names, int element,
                                                     std::string replacement){
  
  for(unsigned int i = 0; i < names.size(); i++){
    names[i] = set_single(names[i], element, replacement);
  }
  
  return names;
}
