#include "make.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

float *find_sum_process(matrix_t *task);
int print_answer(float *answer);