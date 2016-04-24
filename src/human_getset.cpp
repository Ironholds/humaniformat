#include "human_getset.h"

String human_getset::get_single(std::string name, int element){
  CharacterVector split_name = parse_single(name);
  if(split_name[element] == ""){
    return NA_STRING;
  }
  return split_name[element];
}

std::string human_getset::set_single(std::string name, int element, std::string replacement){
  CharacterVector split_name = parse_single(name);
  split_name[element] = replacement;
  std::string output;
  
  for(unsigned int i = 0; i < split_name.size(); i++){
    if(split_name[i] != NA_STRING){
      output.append(split_name[i]);
      if(i < (split_name.size() - 1) && split_name[i] != ""){
        output.append(" ");
      }
    }
  }
  
  // Final check for trailing spaces
  if(output[output.size()-1] == ' '){
    output.erase(output.size()-1,1);
  }

  return output;
}

CharacterVector human_getset::get_vector(CharacterVector names, int element){
  
  CharacterVector output(names.size());
  for(unsigned int i = 0; i < names.size(); i++){
    if(names[i] == NA_STRING){
      output[i] = NA_STRING;
    } else {
      output[i] = get_single(Rcpp::as<std::string>(names[i]), element);
    }
  }
  
  return output;
}

CharacterVector human_getset::set_vector(CharacterVector names, int element, String replacement){
  
  CharacterVector output(names.size());
  
  if(replacement == NA_STRING){
    return names;
  }
  
  for(unsigned int i = 0; i < names.size(); i++){
    if(names[i] == NA_STRING){
      output[i] = NA_STRING;
    } else {
      output[i] = set_single(Rcpp::as<std::string>(names[i]), element, replacement);
    }
  }
  
  return output;
}
