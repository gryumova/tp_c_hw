#include "gtest/gtest.h"
#include <assert.h>
#include <fstream>

extern "C" {
#include "make.h"
#include "sum.h"
}

TEST(TEST_LIN, NULL_MATRIX) {
  matrix_t *m = NULL;
  EXPECT_EQ(find_sum(m), MEM_ERROR);
}

TEST(TEST_LIN, SUM_BY_COLLUMN) {
  const char filename[] = "test2.txt";
  FILE *f = fopen(filename, "w");
  const char m[] = "3 4\n2 2 2 4\n1 1 1 2\n2 1 2 1\n";
  fwrite(m, sizeof(m), 1, f);
  fclose(f);
  matrix_t *matrix = read_matrix(filename);
  ASSERT_NE(matrix, nullptr);
  EXPECT_EQ(find_sum(matrix), NO_ERROR);
  EXPECT_EQ(matrix->sum_by_column[0], 5);
  EXPECT_EQ(matrix->sum_by_column[1], 4);
  EXPECT_EQ(matrix->sum_by_column[2], 5);
  EXPECT_EQ(matrix->sum_by_column[3], 7);
}
