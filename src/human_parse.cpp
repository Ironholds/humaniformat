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
  
  // Compounds
  compounds.push_back("vere");
  compounds.push_back("von");
  compounds.push_back("van");
  compounds.push_back("del");
  compounds.push_back("de");
  compounds.push_back("della");
  compounds.push_back("der");
  compounds.push_back("di");
  compounds.push_back("da");
  compounds.push_back("pietro");
  compounds.push_back("vanden");
  compounds.push_back("du");
  compounds.push_back("st.");
  compounds.push_back("st");
  compounds.push_back("la");
  compounds.push_back("lo");
  compounds.push_back("ter");
  compounds.push_back("bin");
  compounds.push_back("ben");
  compounds.push_back("ibn");
  
  
  
}
