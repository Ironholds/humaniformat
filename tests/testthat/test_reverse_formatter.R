context("Formatting for reversed names")

test_that("Simple reverse-formatted names can be handled", {
  expect_true(format_reverse("Keyes, Oliver") == "Oliver Keyes")
})

test_that("Non-comma-delimited names are not modified", {
  expect_true(format_reverse("Oliver Keyes") == "Oliver Keyes")
})

test_that("Multipart comma-delimited names can be handled", {
  expect_true(format_reverse("Keyes, Oliver, Mr") == "Mr Oliver Keyes")
})

test_that("Terminating commas do not cause issues", {
  expect_true(format_reverse("Keyes, Oliver,") == "Oliver Keyes")
})

test_that("Initial commas do not cause issues", {
  expect_true(format_reverse(", Keyes, Oliver") == "Oliver Keyes")
})

test_that("NA support works", {
  data <- format_reverse(c(", Keyes, Oliver", NA))
  expect_true(data[1] == "Oliver Keyes")
  expect_true(is.na(data[2]))
})
