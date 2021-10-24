#include "../include/make.h"
#include "../include/sum.h"
#include "../include/sum_par.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    puts("Wrong number of arguments!");
    return WRONG_NUM_OF_ARG;
  }

  matrix_t *task = NULL;
  task = read_matrix(argv[1]);
  if (task == NULL) {
    return CANNOT_GET_MATRIX;
  }

  printf("Sum of items by column\n");
  float *rez = find_sum(task);
  if (rez == NULL) {
    return CANNOT_GET_MATRIX;
  }
  print_answer(rez);

  // printf("Parallel algorithm\n");
  // float *rez = find_sum_process(task);
  // if (rez == NULL) {
  //   return CANNOT_GET_MATRIX;
  // }
  // print_answer(rez);

  clear(task);
  return NO_ERROR;
}