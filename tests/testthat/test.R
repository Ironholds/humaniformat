context("Name parsing")

test_that("Simple {first, last} names can be parsed", {
  result <- unlist(humaniformat("Jim Jeffries"))
  expect_true(all(names(result) == c("salutation","first_name","middle_name","last_name","suffix","full_name")))
  expect_true(result["first_name"] == "Jim")
  expect_true(result["last_name"] == "Jeffries")
})

test_that("Names with salutations can be parsed", {
  result <- unlist(humaniformat("Dr. Jim Jeffries"))
  expect_true(all(names(result) == c("salutation","first_name","middle_name","last_name","suffix","full_name")))
  expect_true(result["first_name"] == "Jim")
  expect_true(result["last_name"] == "Jeffries")
  expect_true(result["salutation"] == "Dr.")
})

test_that("Names with suffixes can be parsed", {
  result <- unlist(humaniformat("Jim Jeffries PhD"))
  expect_true(all(names(result) == c("salutation","first_name","middle_name","last_name","suffix","full_name")))
  expect_true(result["first_name"] == "Jim")
  expect_true(result["last_name"] == "Jeffries")
  expect_true(result["suffix"] == "PhD")
})

test_that("Names with middle names can be parsed", {
  result <- unlist(humaniformat("Jim Schmidt Jeffries"))
  expect_true(all(names(result) == c("salutation","first_name","middle_name","last_name","suffix","full_name")))
  expect_true(result["first_name"] == "Jim")
  expect_true(result["middle_name"] == "Schmidt")
  expect_true(result["last_name"] == "Jeffries")
})

test_that("Names with compound surnames can be parsed", {
  result <- unlist(humaniformat("Jim de la ben Jeffries"))
  expect_true(all(names(result) == c("salutation","first_name","middle_name","last_name","suffix","full_name")))
  expect_true(result["first_name"] == "Jim")
  expect_true(result["last_name"] == "de la ben Jeffries")
})

test_that("Names with all elements can be parsed", {
  result <- unlist(humaniformat("Rev Jim Schmidt de la ben Jeffries PhD"))
  expect_true(all(names(result) == c("salutation","first_name","middle_name","last_name","suffix","full_name")))
  expect_true(result["salutation"] == "Rev")
  expect_true(result["first_name"] == "Jim")
  expect_true(result["middle_name"] == "Schmidt")
  expect_true(result["last_name"] == "de la ben Jeffries")
  expect_true(result["suffix"] == "PhD")
  
})
