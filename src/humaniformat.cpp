#include "human_format.h"
#include "human_getset.h"

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
//' event that a name doesn't \emph{have} a salutation, middle name, suffix, or so on, an NA will appear.
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
DataFrame parse_names(CharacterVector names){
  human_parse parse_inst;
  return parse_inst.parse_vector(names);
}

//' @title Reformat Reversed Names
//' @description a common pattern for names is 'Lastname Suffix, Salutation Firstname' -
//' or to put that more practically, 'Jeffries PhD, Mr Bernard'. \code{format_reverse}
//' takes these reversed names and reformats them to a form that \code{\link{parse_names}}
//' can handle.
//' 
//' @param names a vector of names following this convention. Names that lack commas will
//' be returned entirely intact, so assuming you don't have (legitimate) commas in names
//' not following this format, there's no need to worry if your vector has mixed formatting.
//' 
//' @return a vector containing the reformatted names
//' 
//' @seealso \code{\link{parse_names}}, which works more reliably if reversed names have
//' been reformatted, and \code{\link{format_period}} for period-separated names.
//' 
//' @examples
//' 
//' # Take a reversed name and un-reverse it
//' format_reverse("Keyes, Oliver")
//' 
//' @export
// [[Rcpp::export]]
CharacterVector format_reverse(CharacterVector names){
  human_format format_inst;
  return format_inst.reverse_format_vector(names);
}

//' @title Reformat Period-Separated Names
//' @description a common pattern for names is for first and middle names to be represented
//' by initials. Unfortunately depending on how this is done, that can make things problematic;
//' "G. K. Chesterton" is easy to parse, but "G.K. Chesterton" or "G.K.Chesterton" is not.
//' \code{format_period} takes names that are period-separated in this fashion and reformats
//' them to ensure there are spaces between each initial. Periods after any space in the name
//' are preserved, so "G.K. Chesterton, M.D." does not become "G. K. Chesterton, M. D. ".
//' 
//' @param names a vector of names following this convention. Names that lack periods will
//' be returned entirely intact, so assuming you don't have (legitimate) periods in names
//' not following this format, there's no need to worry if your vector has mixed formatting.
//' 
//' @seealso \code{\link{format_reverse}} for names stored as "Lastname, Firstname", and
//' \code{\link{parse_names}} to parse the output of this function.
//' 
//' @examples
//' format_period("G.K.Chesterton")
//' 
//' @export
// [[Rcpp::export]]
CharacterVector format_period(CharacterVector names){
  human_format format_inst;
  return format_inst.period_format_vector(names);
}

// [[Rcpp::export]]
CharacterVector get_(CharacterVector names, int element){
  human_getset getset_inst;
  return getset_inst.get_vector(names, element);
}

// [[Rcpp::export]]
CharacterVector set_(CharacterVector names, int element, String replacement){
  human_getset getset_inst;
  return getset_inst.set_vector(names, element, replacement);
}
