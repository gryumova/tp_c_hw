#include <fstream>
#include "gtest/gtest.h"

extern "C" {
    #include "../include/make.h"
}

// TEST(TEST_CREATE_MATRIX, WRONG_FILE_NAME) {
//     FILE *f = fopen("wrong_name.txt", "r");
//     EXPECT_EQ(read_matrix(f), nullptr);
//     fclose(f);
// }

// TEST(TEST_CREATE_MATRIX, EMPTY_FILE) {
//     FILE *f1 = fopen("../../empty_file.txt", "r");
//     EXPECT_EQ(read_matrix(f1), nullptr);
//     fclose(f1);
//     FILE *f2 = fopen("../../test1.txt", "r");
//     EXPECT_EQ(read_matrix(f2), nullptr);
//     fclose(f2);
// }

TEST(TEST_PRINT, PRINT_NULL_MATRIX) {
    matrix_t *m = nullptr;
    EXPECT_EQ(print_matrix(m), NULL);
}

// TEST(TEST_PRINT, PRINT_NO_COL_MATRIX) {
//     matrix_t *m = new matrix_t;
//     m->row = 3;
//     m->data = new float*[m->row];
//     for (size_t i = 0; i < m->row; i ++) {
//         m->data[i] = new float;
//     }

//     EXPECT_EQ(print_matrix(m), NULL);
// }

// TEST(TEST_PRINT, PRINT_NULL_ANSWER) {
//     matrix_t *m = NULL;
//     EXPECT_EQ(print_answer(m), NULL);
// }

// TEST(TEST_CLEAR, CLEAR_MATRIX) {
//     matrix_t *m = new matrix_t;
//     m->col = 2;
//     m->row = 2;
//     m->data = new float*[2];
//     for (size_t i = 0; i < 2; i++) {
//         m->data[i] = new float[2];
//         for (size_t j = 0; j < 2; j++) {
//             m->data[i][j] = i;
//         }
//     }

//     EXPECT_EQ(print_answer(m), NO_ERROR);
//     EXPECT_EQ(clear(m), NO_ERROR);
// }