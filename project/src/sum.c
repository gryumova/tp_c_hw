#include "../include/sum.h"

float *find_sum(matrix_t *task) {
  if (task == NULL) {
    return NULL;
  }

  float *sum_ = malloc(sizeof(float) * task->col);
  if (sum_ = NULL) {
    return NULL;
  }

  for (size_t i = 0; i < task->col; i++) {
    sum_[i] = 0;
    for (size_t j = 0; j < task->row; j++) {
      sum_[i] += task->data[j][i];
    }
  }

  return sum_;
}