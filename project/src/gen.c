#include <stdio.h>
#include <stdlib.h>


int main() {
  FILE *fd = fopen("big_matrix.txt", "w");
  fprintf(fd, "10000 5000\n");
  for (size_t i = 0; i < 10000; ++i) {
    for (size_t j = 0; j < 5000; ++j) {
      float haoticnum = rand() % 100 - 50 + 0.03 * (i % 10) - 0.01; 
      fprintf(fd, "%5.2f", haoticnum);
      if (j < 5000 - 1)
        fprintf(fd, " ");
    }
    fprintf(fd, "\n");
  }
  fprintf(fd, "\n");
  fclose(fd);
}