#include "human_format.h"

//' @title Parse Human Names
//' @description human names are complex things; sometimes people have honorifics, or not. Or a single middle name, or many. Or
//' a compound surname, or not a compound surname but 'PhD' at the end of their name, and augh.
//' 
//' \code{parse_names} provides a simple
//' function for taking consistently formatted human names and splitting them into \code{salutation}, \code{first_name},
//' \code{middle_name}, \code{last_name} and \code{suffix}. It is capable of dealing with compound surnames, multiple middle names,
//' and similar variations, and is fully vectorised.
//' 
//' @param names a character vector of names to parse.
//' 
//' @return a data.frame with the columns \code{salutation}, \code{first_name},
//' \code{middle_name}, \code{last_name}, \code{suffix} and \code{full_name} (which contains the original name). In the
//' event that a name doesn't \emph{have} a salutation, middle name, suffix, or so on, an empty string will be in that
//' field instead.
//' 
//' @examples
//' # Parse a simple name
//' parse_names("Oliver Keyes")
//' 
//' # Parse a more complex name
//' parse_names("Hon. Oliver Timothy Keyes Esq.")
//' 
//' @export
// [[Rcpp::export]]
DataFrame parse_names(std::vector < std::string > names){
  human_parse parse_inst;
  return parse_inst.parse_vector(names);
}

// [[Rcpp::export]]
std::vector < std::string > format_names(std::vector < std::string > names){
  human_format format_inst;
  return format_inst.format_vector(names);
}
