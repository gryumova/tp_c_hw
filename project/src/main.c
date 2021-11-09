#include "make.h"
#include "sum.h"
#include "sum_par.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return WRONG_NUM_OF_ARG;
  }

  matrix_t *task = NULL;
  task = read_matrix(argv[1]);
  if (task == NULL) {
    return CANNOT_GET_MATRIX;
  }

  find_sum(task);
  print_answer(task);

  clear_matrix(task);
  return NO_ERROR;
}