#include <stdio.h>
#include <stdlib.h>


int main() {
  FILE *file = fopen("big_matrix.txt", "w");
  fprintf(file, "10000 5000\n");
  for (size_t i = 0; i < 10000; ++i) {
    for (size_t j = 0; j < 5000; ++j) {
      float t = rand() % 100 - 50 + 0.03 * (i % 10) - 0.01; 
      fprintf(file, "%5.2f", t);
    }
    fprintf(file, "\n");
  }
  fprintf(file, "\n");
  fclose(file);
}