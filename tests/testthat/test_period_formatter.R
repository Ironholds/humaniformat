context("Formatting for period-separated names")

test_that("Simple period-formatted names can be handled", {
  expect_true(format_period("O.S.B.Keyes") == "O. S. B. Keyes")
})

test_that("Non-period-delimited names are not modified", {
  expect_true(format_period("Oliver Keyes") == "Oliver Keyes")
})

test_that("Multipart period-delimited names can be handled", {
  expect_true(format_period("O.S.B. Keyes") == "O. S. B. Keyes")
})

test_that("post-space periods do not cause issues", {
  expect_true(format_period("O.S.B. Keyes, M.D.") == "O. S. B. Keyes, M.D.")
})

test_that("NA support works", {
  data <- format_period(c("O.S.B. Keyes, M.D.", NA))
  expect_true(data[1] == "O. S. B. Keyes, M.D.")
  expect_true(is.na(data[2]))
})
