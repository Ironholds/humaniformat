context("Test that individual components of human names can be retrieved and/or set")

test_that("Individual components can be retrieved", {
  name <- "Mr Jim Samuel Jeffries PhD"
  expect_true(salutation(name) == "Mr")
  expect_true(first_name(name) == "Jim")
  expect_true(middle_name(name) == "Samuel")
  expect_true(last_name(name) == "Jeffries")
  expect_true(suffix(name) == "PhD")
})

test_that("Individual components can be retrieved from a name with missing components", {
  name <- "Mr Jim Jeffries PhD"
  expect_true(salutation(name) == "Mr")
  expect_true(first_name(name) == "Jim")
  expect_true(is.na(middle_name(name)))
  expect_true(last_name(name) == "Jeffries")
  expect_true(suffix(name) == "PhD")
})

test_that("Individual components can be set", {
  name <- "Mr Jim Samuel Jeffries PhD"
  salutation(name) <- "Hon"
  expect_true(name == "Hon Jim Samuel Jeffries PhD")
  first_name(name) <- "Toby"
  expect_true(name == "Hon Toby Samuel Jeffries PhD")
  middle_name(name) <- "Andrew"
  expect_true(name == "Hon Toby Andrew Jeffries PhD")
  last_name(name) <- "Smith"
  expect_true(name == "Hon Toby Andrew Smith PhD")
  suffix(name) <- "Jr"
  expect_true(name == "Hon Toby Andrew Smith Jr")
})

test_that("Setting handles NAs correctly", {
  
  name <- "Mr Jim Samuel Jeffries PhD"
  salutation(name) <- NA_character_
  expect_equal(salutation(name), "Mr")
})
