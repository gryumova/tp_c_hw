#include "gtest/gtest.h"
#include <assert.h>
#include <fstream>

extern "C" {
#include "./stress_test/include/utils.h"
#include "make.h"
#include "sum.h"
}

TEST(STRESS_TEST, par_algorithm) {
  const char *test_file = "test_file.txt";
  matrix_t *task = NULL;

  for (size_t i = 1; i < 5; i++) {
    EXPECT_EQ(generate_matrix(test_file, 100 * i, 50 * i), NO_ERROR);

    task = read_matrix(test_file);

    ASSERT_EQ(find_sum(task), NO_ERROR);
    write_answer_to_file("test_lin.txt", task);
  }
}