#pragma once
#include <stdio.h>
#include <stdlib.h>

enum error_list {
    NO_ERROR = 0,
    WRONG_NUM_OF_ARG = 1,
    FAILED_FILE_OPENNING = 2,
    MEM_ERROR = 3,
    PRINT_ERROR = 4,
    CANNOT_GET_MATRIX = 5,
    FILE_ERROR = 6,
};

typedef struct matrix {
    float **data;
    float *sum_by_column;
    size_t row;
    size_t col;
} matrix_t;


matrix_t *read_matrix(FILE *read_file);
int print_matrix(matrix_t* matrix);
int print_answer(matrix_t *task);
int clear(matrix_t *matrix);