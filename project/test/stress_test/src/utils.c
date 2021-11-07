#include "../include/utils.h"

int generate_matrix(const char *filename, size_t rows, size_t cols) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    return FILE_ERROR;
  }

  fprintf(file, "%ld %ld\n", rows, cols);

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      float t = rand() % 100 - 50 + 0.03 * (i % 10) - 0.01;
      fprintf(file, "%5.2f ", t);
    }
    fprintf(file, "\n");
  }
  fprintf(file, "\n");

  fclose(file);
  return NO_ERROR;
}

int write_answer_to_file(const char *filename, matrix_t *task) {
  if (task == NULL) {
    return MEM_ERROR;
  }

  FILE *file = fopen(filename, "a+");
  if (file == NULL) {
    return FILE_ERROR;
  }

  for (size_t i = 0; i < task->col; i++) {
    fprintf(file, "%10.2f ", task->sum_by_column[i]);
  }
  fprintf(file, "\n\n");

  fclose(file);
  return NO_ERROR;
}

int comparison(const char *filename1, const char *filename2) {
  FILE *file1 = fopen(filename1, "r");
  if (file1 == NULL) {
    return FILE_ERROR;
  }

  FILE *file2 = fopen(filename2, "r");
  if (file2 == NULL) {
    return FILE_ERROR;
  }
  int ch1 = 0, ch2 = 0;
  while (!feof(file1) && !feof(file2) && (ch1 == ch2)) {
    ch1 = fgetc(file1);
    ch2 = fgetc(file2);
  }

  if (ch1 != ch2) {
    fclose(file1);
    fclose(file2);
    return ANSWER_ERROR;
  }

  fclose(file1);
  fclose(file2);
  return NO_ERROR;
}