#include "../include/make.h"

matrix_t *read_matrix(const char *filename) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    puts("File not found");
    return NULL;
  }

  matrix_t *matrix = malloc(sizeof(matrix_t));
  if (matrix == NULL) {
    if (fclose(f)) {
      return NULL;
    }
    return NULL;
  }

  matrix->row = ROWS;
  matrix->col = COLS;

  matrix->data = malloc(sizeof(float *) * ROWS);
  if (matrix->data == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < matrix->row; i++) {
    matrix->data[i] = malloc(sizeof(float) * COLS);
    for (size_t j = 0; j < matrix->col; j++) {
      if (fscanf(f, "%f", &matrix->data[i][j]) < 1) {
        puts("Error getting matrix");
        free(matrix);
        if (fclose(f)) {
          return NULL;
        }
        return NULL;
      }
    }
  }

  if (fclose(f)) {
    return NULL;
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

int clear(matrix_t *matrix) {

  for (size_t i = 0; i < matrix->row; i++) {
    free(matrix->data[i]);
  }

  free(matrix->data);

  return NO_ERROR;
}
