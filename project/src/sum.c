#include "sum.h"

int find_sum(matrix_t *task) {
  if (task == NULL) {
    return MEM_ERROR;
  }
  
  task->sum_by_column = malloc(sizeof(float) * task->col);
  
  for (size_t i = 0; i < task->col; i++) {
    task->sum_by_column[i] = 0;
    for (size_t j = 0; j < task->row; j++) {
      task->sum_by_column[i] += task->data[j][i];
    }
  }

  return NO_ERROR;
}

