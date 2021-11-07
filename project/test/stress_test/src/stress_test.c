#include "../include/utils.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    puts("Wrong number of arguments!");
    return WRONG_NUM_OF_ARG;
  }

  const char *test_file = "test_file.txt";

  matrix_t *task = NULL;

  for (size_t i = 1; i < 5; i++) {
    if (generate_matrix(test_file, 100 * i, 50 * i) != NO_ERROR) {
      return FILE_ERROR;
    }

    task = read_matrix(test_file);
    if (task == NULL) {
      return CANNOT_GET_MATRIX;
    }

    find_sum(task);
    write_answer_to_file(argv[1], task);
  }

  return NO_ERROR;
}