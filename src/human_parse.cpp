#include "human_parse.h"

human_parse::human_parse(){
  
  // Construct salutations vector
  salutations.push_back("mr");
  salutations.push_back("master");
  salutations.push_back("mister");
  salutations.push_back("mrs");
  salutations.push_back("miss");
  salutations.push_back("ms");
  salutations.push_back("dr");
  salutations.push_back("prof");
  salutations.push_back("rev");
  salutations.push_back("fr");
  salutations.push_back("judge");
  salutations.push_back("hon");
  salutations.push_back("honorable");
  
  // Suffixes
  suffixes.push_back("i");
  suffixes.push_back("ii");
  suffixes.push_back("iii");
  suffixes.push_back("iv");
  suffixes.push_back("senior");
  suffixes.push_back("sr");
  suffixes.push_back("junior");
  suffixes.push_back("jr");
  suffixes.push_back("phd");
  suffixes.push_back("apr");
  suffixes.push_back("rph");
  suffixes.push_back("pe");
  suffixes.push_back("md");
  suffixes.push_back("ma");
  suffixes.push_back("dmd");
  suffixes.push_back("cme");
  
}
