#include "make.h"
#include "sum.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    puts("Wrong number of arguments!");
    return WRONG_NUM_OF_ARG;
  }

  // FILE *f = fopen(argv[1], "r");
  // if (f == NULL) {
  //   puts("File not found");
  //   return FILE_ERROR;
  // }

  matrix_t *task = NULL;
  task = read_matrix(argv[1]);
  if (task == NULL) {
    return CANNOT_GET_MATRIX;
  }

  // if (fclose(f)) {
  //   return FILE_ERROR;
  // }
  
  find_sum(task);
  print_answer(task);

  clear(task);
  return NO_ERROR;
}