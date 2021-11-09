#include "../../../include/make.h"
#include "../../../include/sum.h"
#include "../../../include/sum_par.h"
#include <stdio.h>
#include <stdlib.h>

int generate_matrix(const char *filename, size_t rows, size_t cols);
int write_answer_to_file(const char *filename, matrix_t *task);
int comparison(const char *filename1, const char *filename2);