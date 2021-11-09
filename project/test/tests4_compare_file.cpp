#include "gtest/gtest.h"
#include <fstream>

extern "C" {
#include "./stress_test/include/utils.h"
#include "make.h"
#include "sum_par.h"
}

TEST(STRESS_TEST, compare) {
  EXPECT_EQ(comparison("test_lin.txt", "test_par.txt"), NO_ERROR);
}