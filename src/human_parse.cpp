#include "human_parse.h"

std::deque < std::string > human_parse::split_parts(std::string name){
  
  std::deque < std::string > output;
  size_t last    = 0;
  size_t current = name.find(" ");
  
  while(current != std::string::npos){
    output.push_back(name.substr(last, (current - last)));
    last = ++current;
    current = name.find(" ", current);
    if(current == std::string::npos){
      output.push_back(name.substr(last, name.size()));
    }
  }
  
  return output;
}

// Erase periods
std::string human_parse::erase_periods(std::string part){
  
  for(size_t i = part.find("."); i != std::string::npos; i = part.find(".")){
    part.erase(i, 1);
  }
  
  return part;
}

// See if a chunk matches a component
bool human_parse::match_component(std::string part, std::set < std::string >& set_ref){
  
  // Clean up - erase periods and lowercase
  part = erase_periods(part);
  unsigned int input_size = part.size();
  for(unsigned int i = 0; i < input_size; i++){
    part[i] = tolower(part[i]);
  }
  
  // If the resulting string is in the set, it's a match!
  if(set_ref.find(part) != set_ref.end()){
    return true;
  }
  
  // Otherwise, it's not.
  return false;
}

std::vector < std::string > human_parse::parse_single(std::string name){
  
  // If it's literally just an empty string, throw things.
  if(name.size() == 0){
    throw std::range_error("You have provided an empty string");
  }
  
  // Split and create output object.
  std::deque < std::string > split_name = split_parts(name);
  std::vector < std::string > output(6);
  output[5] = name;
  
  // If there's only one element we assume it is a first name and return it.
  if(split_name.size() == 1){
    output[1] = split_name[0];
    return output;
  }
  
  // If there are > 1 element and we find a salutation in the first, pop those two elements.
  if(split_name.size() > 1 && match_component(split_name[0], salutations)){
    output[0] = split_name[0];
    split_name.pop_front();
    output[1] = split_name[1];
    split_name.pop_front();
  } else {
    output[1] = split_name[0];
    split_name.pop_front();
  }
  
  // If there is still > 1 element and we find a suffix, pop those two elements. Otherwise just one.
  if(split_name.size() > 1 && match_component(split_name[split_name.size() - 1], suffixes)){
    output[5] = split_name[split_name.size() - 1];
    split_name.pop_back();
    output[4] = split_name[split_name.size() - 1];
  } else if(split_name.size() > 0){
    output[5] = split_name[split_name.size() - 1];
    split_name.pop_back();
  }
  
}


// Constructor
human_parse::human_parse(){
  
  // Construct salutations vector
  salutations.insert("mr");
  salutations.insert("master");
  salutations.insert("mister");
  salutations.insert("mrs");
  salutations.insert("miss");
  salutations.insert("ms");
  salutations.insert("dr");
  salutations.insert("prof");
  salutations.insert("rev");
  salutations.insert("fr");
  salutations.insert("judge");
  salutations.insert("hon");
  salutations.insert("honorable");
  
  // Suffixes
  suffixes.insert("i");
  suffixes.insert("ii");
  suffixes.insert("iii");
  suffixes.insert("iv");
  suffixes.insert("senior");
  suffixes.insert("sr");
  suffixes.insert("junior");
  suffixes.insert("jr");
  suffixes.insert("phd");
  suffixes.insert("apr");
  suffixes.insert("rph");
  suffixes.insert("pe");
  suffixes.insert("md");
  suffixes.insert("ma");
  suffixes.insert("dmd");
  suffixes.insert("cme");
  
  // Compounds
  compounds.insert("vere");
  compounds.insert("von");
  compounds.insert("van");
  compounds.insert("del");
  compounds.insert("de");
  compounds.insert("della");
  compounds.insert("der");
  compounds.insert("di");
  compounds.insert("da");
  compounds.insert("pietro");
  compounds.insert("vanden");
  compounds.insert("du");
  compounds.insert("st.");
  compounds.insert("st");
  compounds.insert("la");
  compounds.insert("lo");
  compounds.insert("ter");
  compounds.insert("bin");
  compounds.insert("ben");
  compounds.insert("ibn");
  
}
