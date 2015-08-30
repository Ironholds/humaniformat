## humaniformat
A human name parser for R

__Author:__ Oliver Keyes <br/>
__License:__ [MIT](http://opensource.org/licenses/MIT)<br/>
__Status:__ Stable

### Description
`humaniformat` (`humaniform` + `format`) is a human names parser for R. With it, you can parse names, distinguishing salutations, suffixes, and first, middle and last names. `humaniformat` recognises compound last names (and preserves them) from a wide range of cultures, although the name format itself is somewhat Western-centric (it assumes, for example, that first name comes before last name, which is not always the standard).

Please note that this project is released with a [Contributor Code of Conduct](CONDUCT.md). By participating in this project you agree to abide by its terms.

### Installation

To get the current version:

    install.packages("humaniformat")

To get the development version:

    devtools::install_github("ironholds/humaniformat")

### Dependencies
* R. Doy.
* [Rcpp](http://cran.rstudio.com/web/packages/Rcpp/)
