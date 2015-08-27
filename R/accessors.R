#'@title Get or set a name's saltation
#'@description as in the lubridate package, individual components of a name
#'can be both extracted or set using the relevant function call - see the
#'examples.
#'@aliases salutation
#'@rdname salutation
#'
#'@param x a name, or vector of names
#'
#'@param value a replacement value for x's salutation
#'
#'@seealso \code{\link{first_name}}, \code{\link{middle_name}}, \code{\link{last_name}} 
#'and \code{\link{suffix}} for other accessors.
#'
#'@examples
#'#Get a salutation
#'example_name <- "Mr Jim Jeffries"
#'salutation(example_name)
#'
#'#Set a salutation
#'salutation(example_name) <- "Prof"
#'@import methods
#'@export
salutation <- function(x){
  return(get_(x,0))
}

"salutation<-" <- function(x, value) standardGeneric("salutation<-")
#'@rdname salutation
#'@export
setGeneric("salutation<-", useAsDefault = function(x, value){
  return(set_(x, 0, value))
})

#'@title Get or set a name's first name
#'@description as in the lubridate package, individual components of a name
#'can be both extracted or set using the relevant function call - see the
#'examples.
#'@aliases first_name
#'@rdname first_name
#'
#'@param x a name, or vector of names
#'
#'@param value a replacement value for x's first name.
#'
#'@seealso \code{\link{salutation}}, \code{\link{middle_name}}, \code{\link{last_name}} 
#'and \code{\link{suffix}} for other accessors.
#'
#'@examples
#'#Get a first name
#'example_name <- "Mr Jim Jeffries"
#'first_name(example_name)
#'
#'#Set a first name
#'first_name(example_name) <- "Prof"
#'@import methods
#'@export
first_name <- function(x){
  return(get_(x,1))
}

"first_name<-" <- function(x, value) standardGeneric("first_name<-")
#'@rdname first_name
#'@export
setGeneric("first_name<-", useAsDefault = function(x, value){
  return(set_(x, 1, value))
})

#'@title Get or set a name's middle name
#'@description as in the lubridate package, individual components of a name
#'can be both extracted or set using the relevant function call - see the
#'examples.
#'@aliases middle_name
#'@rdname middle_name
#'
#'@param x a name, or vector of names
#'
#'@param value a replacement value for x's middle name.
#'
#'@seealso \code{\link{salutation}}, \code{\link{first_name}}, \code{\link{last_name}} 
#'and \code{\link{suffix}} for other accessors.
#'
#'@examples
#'#Get a middle name
#'example_name <- "Mr Jim Toby Jeffries"
#'middle_name(example_name)
#'
#'#Set a middle name
#'middle_name(example_name) <- "Richard"
#'@import methods
#'@export
middle_name <- function(x){
  return(get_(x, 2))
}

"middle_name<-" <- function(x, value) standardGeneric("middle_name<-")
#'@rdname middle_name
#'@export
setGeneric("middle_name<-", useAsDefault = function(x, value){
  return(set_(x, 2, value))
})

#'@title Get or set a name's last name
#'@description as in the lubridate package, individual components of a name
#'can be both extracted or set using the relevant function call - see the
#'examples.
#'@aliases last_name
#'@rdname last_name
#'
#'@param x a name, or vector of names
#'
#'@param value a replacement value for x's last name.
#'
#'@seealso \code{\link{salutation}}, \code{\link{first_name}}, \code{\link{middle_name}}
#'and \code{\link{suffix}} for other accessors.
#'
#'@examples
#'#Get a last name
#'example_name <- "Mr Jim Toby Jeffries"
#'last_name(example_name)
#'
#'#Set a last name
#'last_name(example_name) <- "Smith"
#'@import methods
#'@export
last_name <- function(x){
  return(get_(x, 3))
}

"last_name<-" <- function(x, value) standardGeneric("last_name<-")
#'@rdname last_name
#'@export
setGeneric("last_name<-", useAsDefault = function(x, value){
  return(set_(x, 3, value))
})

#'@title Get or set a name's suffix
#'@description as in the lubridate package, individual components of a name
#'can be both extracted or set using the relevant function call - see the
#'examples.
#'@aliases suffix
#'@rdname suffix
#'
#'@param x a name, or vector of names
#'
#'@param value a replacement value for x's suffix.
#'
#'@seealso \code{\link{salutation}}, \code{\link{first_name}}, \code{\link{middle_name}}
#'and \code{\link{last_name}} for other accessors.
#'
#'@examples
#'#Get a suffix]
#'example_name <- "Mr Jim Toby Jeffries Esq"
#'suffix(example_name)
#'
#'#Set a suffix
#'suffix(example_name) <- "PhD"
#'@import methods
#'@export
suffix <- function(x){
  return(get_(x, 4))
}

"suffix<-" <- function(x, value) standardGeneric("suffix<-")
#'@rdname suffix
#'@export
setGeneric("suffix<-", useAsDefault = function(x, value){
  return(set_(x, 4, value))
})
