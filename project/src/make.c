#include "make.h"

matrix_t *read_matrix(FILE *read_file) {
  if (read_file == NULL) {
    return NULL;
  }
  matrix_t *matrix = malloc(sizeof(matrix_t));
  if (matrix == NULL) {
    return NULL;
  }

  if (fscanf(read_file, "%zu%zu", &matrix->row, &matrix->col) != 2) {
    free(matrix);
    return NULL;
  }

  matrix->data = malloc(sizeof(float *) * matrix->row);
  if (matrix->data == NULL) {
    free(matrix);
    return NULL;
  }

  for (size_t i = 0; i < matrix->row; i++) {
    matrix->data[i] = malloc(sizeof(float) * matrix->col);
    for (size_t j = 0; j < matrix->col; j++) {
      if (fscanf(read_file, "%f", &matrix->data[i][j]) < 1) {
        puts("Error getting matrix");
        free(matrix->data);
        free(matrix);
        return NULL;
      }
    }
  }

  return matrix;
}

int print_matrix(matrix_t *matrix) {
  if (matrix == NULL) {
    return MEM_ERROR;
  }

  if (printf("Matrix %ld * %ld:\n", matrix->row, matrix->col) < 2) {
    return PRINT_ERROR;
  }

  for (size_t i = 0; i < matrix->row; i++) {
    for (size_t j = 0; j < matrix->col; j++) {
      if (printf("%10.2f", matrix->data[i][j]) < 1) {
        return PRINT_ERROR;
      }
    }
    printf("\n");
  }

  return NO_ERROR;
}


int print_answer(matrix_t *task) {
  if (task->sum_by_column == NULL) {
    return PRINT_ERROR;
  }
  printf("-------------------\n");
  for (size_t i = 0; i < task->col; i++) {
    printf("%5.2f ", task->sum_by_column[i]);
  }
  printf("\n\n");

  return NO_ERROR;
}


int clear(matrix_t *matrix) {

  for (size_t i = 0; i < matrix->row; i++) {
    free(matrix->data[i]);
  }

  free(matrix->data);

  return NO_ERROR;
}
