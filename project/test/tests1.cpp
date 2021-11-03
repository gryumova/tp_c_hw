#include <fstream>
#include "gtest/gtest.h"

extern "C" {
    #include "make.h"
}

TEST(TEST_CREATE_MATRIX, WRONG_FILE_NAME) {
    char filename[] = "wrong_name.txt";
    EXPECT_EQ(read_matrix(filename), nullptr);
}

TEST(TEST_CREATE_MATRIX, EMPTY_FILE) {
    char filename[] = "../../../emptyfile.txt";
    EXPECT_EQ(read_matrix(filename), nullptr);
}

TEST(TEST_PRINT, PRINT_NULL_ANSWER) {
    matrix_t *m = NULL;
    EXPECT_EQ(print_answer(m), PRINT_ERROR);
}

TEST(TEST_CLEAR, CLEAR_MATRIX) {
    matrix_t *m = new matrix_t;
    m->col = 2;
    m->row = 2;
    m->data = new float*[2];
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
    EXPECT_EQ(clear(m), NO_ERROR);
}