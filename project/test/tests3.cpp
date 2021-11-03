#include <fstream>
#include <assert.h>
#include "gtest/gtest.h"

extern "C" {
    #include "make.h"
    #include "sum_par.h"
}

TEST(TEST_PAR, NULL_MATRIX) {
    matrix_t *m = NULL;
    EXPECT_EQ(find_sum(m), MEM_ERROR);
}


TEST(TEST_PAR, SUM_BY_COLLUMN_PAR) {
    char filename[] = "../../../test2.txt";
    matrix_t *m = read_matrix(filename);
    ASSERT_NE(m, nullptr);
    EXPECT_EQ(find_sum(m), NO_ERROR);
}