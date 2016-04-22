## A human name parser for R

__Author:__ Oliver Keyes <br/>
__License:__ [MIT](http://opensource.org/licenses/MIT)<br/>
__Status:__ Stable

[![Travis-CI Build Status](https://travis-ci.org/Ironholds/humaniformat.svg?branch=master)](https://travis-ci.org/Ironholds/humaniformat) ![downloads](http://cranlogs.r-pkg.org/badges/grand-total/humaniformat)

### Description
`humaniformat` (`humaniform` + `format`) is a human names parser for R. With it, you can parse names, distinguishing salutations, suffixes, and first, middle and last names. `humaniformat` recognises compound last names (and preserves them) from a wide range of cultures, although the name format itself is somewhat Western-centric (it assumes, for example, that first name comes before last name, which is not always the standard).

Please note that this project is released with a [Contributor Code of Conduct](https://github.com/Ironholds/humaniformat/blob/master/CONDUCT.md). By participating in this project you agree to abide by its terms.

### Installation

To get the current version:

    install.packages("humaniformat")

To get the development version:

    devtools::install_github("ironholds/humaniformat")

### Dependencies
* R. Doy.
* [Rcpp](https://cran.r-project.org/package=Rcpp)
