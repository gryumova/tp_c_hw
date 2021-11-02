#include "sum.h"

int find_sum(matrix_t *task) {
  if (task == NULL) {
    return MEM_ERROR;
  }
  FILE *file = fopen("sum_debug.txt", "w");

  task->sum_by_column = malloc(sizeof(float) * task->col);
  
  for (size_t i = 0; i < task->col; i++) {
    task->sum_by_column[i] = 0;
    for (size_t j = 0; j < task->row; j++) {
      task->sum_by_column[i] += task->data[j][i];
      fprintf(file, "%10.2f", task->sum_by_column[i]);
    }
    fprintf(file, "\n");
  }
  fclose(file);
  return NO_ERROR;
}

