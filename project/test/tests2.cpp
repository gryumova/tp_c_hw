#include <fstream>
#include <assert.h>
#include "gtest/gtest.h"

extern "C" {
    #include "../include/make.h"
    #include "../include/sum.h"
}

TEST(TEST_LIN, NULL_MATRIX) {
    matrix_t *m = NULL;
    EXPECT_EQ(find_sum(m), MEM_ERROR);
}

TEST(TEST_LIN, SUM_BY_COLLUMN) {
    FILE *f = fopen("../../test2.txt", "r");
    matrix_t *m = read_matrix(f);
    ASSERT_NE(m, nullptr);
    EXPECT_EQ(find_sum(m), NO_ERROR);
    fclose(f);
}
