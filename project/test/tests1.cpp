#include "gtest/gtest.h"
#include <fstream>

extern "C" {
#include "make.h"
}

TEST(TEST_CREATE_MATRIX, WRONG_FILE_NAME) {
  const char filename[] = "wrong_name.txt";
  EXPECT_EQ(read_matrix(filename), nullptr);
}

TEST(TEST_CREATE_MATRIX, EMPTY_FILE) {
  const char filename[] = "emptyfile.txt";
  FILE *f = fopen(filename, "w");
  fclose(f);
  EXPECT_EQ(read_matrix(filename), nullptr);
}

TEST(TEST_PRINT, PRINT_NULL_ANSWER) {
  matrix_t *m = NULL;
  EXPECT_EQ(print_answer(m), PRINT_ERROR);
}

TEST(TEST_CREATE_MATRIX, EMPTY_MATRIX) {
  const char filename[] = "empty_matrix.txt";
  FILE *f = fopen(filename, "w");
  const char m[] = "2 3\n";
  fwrite(m, sizeof(m), 1, f);
  fclose(f);
  EXPECT_EQ(read_matrix(filename), nullptr);
}

TEST(TEST_CREATE_MATRIX, READ_FILE) {
  const char filename[] = "test1.txt";
  FILE *f = fopen(filename, "w");
  const char m[] = "2 3\n2 2 2\n1 1 1\n";
  fwrite(m, sizeof(m), 1, f);
  fclose(f);
  EXPECT_NE(read_matrix(filename), nullptr);
}

TEST(TEST_CLEAR, CLEAR_MATRIX) {
  matrix_t *m = new matrix_t;
  m->col = 2;
  m->row = 2;
  m->data = new float *[2];
  for (size_t i = 0; i < 2; i++) {
    m->data[i] = new float[2];
    for (size_t j = 0; j < 2; j++) {
      m->data[i][j] = i;
    }
  }

  m->sum_by_column = new float[2];
  for (size_t i = 0; i < 2; i++) {
    m->sum_by_column[i] = i * 2;
  }

  EXPECT_EQ(print_answer(m), NO_ERROR);
  EXPECT_EQ(clear_matrix(m), NO_ERROR);
}