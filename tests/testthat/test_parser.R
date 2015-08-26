context("Name parsing")

test_that("Simple {first, last} names can be parsed", {
  result <- unlist(parse_names("Jim Jeffries"))
  expect_true(all(names(result) == c("salutation","first_name","middle_name","last_name","suffix","full_name")))
  expect_true(result["first_name"] == "Jim")
  expect_true(result["last_name"] == "Jeffries")
})

test_that("Names with salutations can be parsed", {
  result <- unlist(parse_names("Dr. Jim Jeffries"))
  expect_true(all(names(result) == c("salutation","first_name","middle_name","last_name","suffix","full_name")))
  expect_true(result["first_name"] == "Jim")
  expect_true(result["last_name"] == "Jeffries")
  expect_true(result["salutation"] == "Dr.")
})

test_that("Names with suffixes can be parsed", {
  result <- unlist(parse_names("Jim Jeffries PhD"))
  expect_true(all(names(result) == c("salutation","first_name","middle_name","last_name","suffix","full_name")))
  expect_true(result["first_name"] == "Jim")
  expect_true(result["last_name"] == "Jeffries")
  expect_true(result["suffix"] == "PhD")
})

test_that("Names with middle names can be parsed", {
  result <- unlist(parse_names("Jim Schmidt Jeffries"))
  expect_true(all(names(result) == c("salutation","first_name","middle_name","last_name","suffix","full_name")))
  expect_true(result["first_name"] == "Jim")
  expect_true(result["middle_name"] == "Schmidt")
  expect_true(result["last_name"] == "Jeffries")
})

test_that("Names with compound surnames can be parsed", {
  result <- unlist(parse_names("Jim de la ben Jeffries"))
  expect_true(all(names(result) == c("salutation","first_name","middle_name","last_name","suffix","full_name")))
  expect_true(result["first_name"] == "Jim")
  expect_true(result["last_name"] == "de la ben Jeffries")
})

test_that("Names with all elements can be parsed", {
  result <- unlist(parse_names("Rev Jim Schmidt de la ben Jeffries PhD"))
  expect_true(all(names(result) == c("salutation","first_name","middle_name","last_name","suffix","full_name")))
  expect_true(result["salutation"] == "Rev")
  expect_true(result["first_name"] == "Jim")
  expect_true(result["middle_name"] == "Schmidt")
  expect_true(result["last_name"] == "de la ben Jeffries")
  expect_true(result["suffix"] == "PhD")
  
})

test_that("Names with no spaces do not break everything", {
  result <- unlist(parse_names("G.R.Dobbs"))
  expect_true(result["first_name"] == "G.R.Dobbs")
})

test_that("Names with multiple suffixes can be parsed", {
  result <- unlist(parse_names("Jim Jeffries Jr PhD"))
  expect_true(result["first_name"] == "Jim")
  expect_true(result["last_name"] == "Jeffries")
  expect_true(result["suffix"] == "Jr PhD")
})
