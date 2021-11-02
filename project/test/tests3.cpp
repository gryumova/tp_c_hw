#include <fstream>
#include <assert.h>
#include "gtest/gtest.h"

extern "C" {
    #include "../include/make.h"
    #include "../include/sum_par.h"
}

TEST(TEST_PAR, NULL_MATRIX) {
    matrix_t *m = NULL;
    EXPECT_EQ(find_sum(m), MEM_ERROR);
}


TEST(TEST_PAR, SUM_BY_COLLUMN_PAR) {
    FILE *f = fopen("../../test2.txt", "r");
    matrix_t *m = read_matrix(f);
    ASSERT_NE(m, nullptr);
    EXPECT_EQ(find_sum(m), MEM_ERROR);
    fclose(f);
}