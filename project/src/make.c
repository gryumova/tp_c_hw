#include "make.h"

matrix_t *read_matrix(const char *filename) {
  FILE *read_file = fopen(filename, "r");
  if (read_file == NULL) {
    return NULL;
  }

  if (read_file == NULL) {
    return NULL;
  }

  matrix_t *matrix = malloc(sizeof(matrix_t));
  if (matrix == NULL) {
    fclose(read_file);
    return NULL;
  }

  if (fscanf(read_file, "%zu%zu", &matrix->row, &matrix->col) != 2) {
    free(matrix);
    fclose(read_file);
    return NULL;
  }

  matrix->data = malloc(sizeof(float *) * matrix->row);
  if (matrix->data == NULL) {
    free(matrix);
    fclose(read_file);
    return NULL;
  }

  for (size_t i = 0; i < matrix->row; i++) {
    matrix->data[i] = malloc(sizeof(float) * matrix->col);
    for (size_t j = 0; j < matrix->col; j++) {
      if (fscanf(read_file, "%f", &matrix->data[i][j]) < 1) {
        free(matrix->data);
        free(matrix);
        fclose(read_file);
        return NULL;
      }
    }
  }

  fclose(read_file);
  return matrix;
}

int print_answer(matrix_t *task) {
  if (task == NULL) {
    return PRINT_ERROR;
  }

  for (size_t i = 0; i < task->col; i++) {
    printf("%5.2f ", task->sum_by_column[i]);
  }
  printf("\n\n");

  return NO_ERROR;
}

int clear_matrix(matrix_t *matrix) {
  for (size_t i = 0; i < matrix->row; i++) {
    free(matrix->data[i]);
  }

  return NO_ERROR;
}
