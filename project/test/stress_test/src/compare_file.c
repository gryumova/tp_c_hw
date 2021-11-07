#include "../include/utils.h"

int main(int argc, char *argv[]) {
  if (argc < 3) {
    puts("Wrong number of arguments!");
    return WRONG_NUM_OF_ARG;
  }

  if (comparison(argv[1], argv[2]) == NO_ERROR) {
      printf("OK\n");
  }
  else {
      printf("LOOS\n");
  }

  return NO_ERROR;
}