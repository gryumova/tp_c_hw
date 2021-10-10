#include "../include/read_write.h"
#include "../include/task_structure.h"

int main(int argc, char *argv[]) {
  if (argc < 3) {
    puts("Wrong number of arguments!");
    return WRONG_NUM_OF_ARG;
  }
  int error_code = NO_ERROR;
  if (strcmp(argv[1], "-a") == 0 || strcmp(argv[1], "-c") == 0) {
    if (argc < 4) {
      puts("Wrong number of arguments to write to a file");
      return WRONG_NUM_OF_ARG;
    }
    int num = atoi(argv[3]);
    error_code = write_file(num, argv[2], argv[1]);
    if (error_code) {
      return error_code;
    }
  }

  if (strcmp(argv[1], "-r") == 0) {
    TaskList_t *structure = NULL;
    structure = read_file(argv[2]);
    error_code = print_task(structure);
    if (error_code) {
      return error_code;
    }
    error_code = clear(structure);
    if (error_code) {
      return error_code;
    }
  }

  return error_code;
}