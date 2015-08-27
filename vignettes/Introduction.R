## ----eval=FALSE----------------------------------------------------------
#  library(humaniformat)
#  names <- c("Oliver Keyes", "Keyes, Oliver")
#  format_reverse(names)
#  
#  [1] "Oliver Keyes" "Oliver Keyes"

## ----eval=FALSE----------------------------------------------------------
#  names <- c("G.K. Chesterton", "G.K.Chesterton")
#  format_period(names)
#  
#  [1] "G. K. Chesterton" "G. K. Chesterton"

## ----eval=FALSE----------------------------------------------------------
#  names <- c("G.K. Chesterton", "G.K.Chesterton")
#  narmes <- format_period(names)
#  parsed_chestertons <- parse_names(names)
#  str(parsed_chestertons)
#  
#  'data.frame':	2 obs. of  6 variables:
#   $ salutation : chr  "" ""
#   $ first_name : chr  "G.K." "G.K.Chesterton"
#   $ middle_name: chr  "" ""
#   $ last_name  : chr  "Chesterton" ""
#   $ suffix     : chr  "" ""
#   $ full_name  : chr  "G.K. Chesterton" "G.K.Chesterton"

## ----eval=FALSE----------------------------------------------------------
#  names <- c("Mr Jim Jeffries PhD", "Ms Tabitha Hawthorn PhD")
#  salutation(names)
#  [1] "Mr" "Ms"
#  
#  salutation(names) <- "Professor"
#  names
#  [1] "Professor Jim Jeffries"     "Professor Tabitha Hawthorn"

