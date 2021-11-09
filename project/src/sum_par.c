#include "sum_par.h"

int find_sum(matrix_t *task) {
  if (task == NULL) {
    return MEM_ERROR;
  }

  float *shared_memory =
      mmap(NULL, task->col * sizeof(float), PROT_READ | PROT_WRITE,
           MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  if (shared_memory == MAP_FAILED) {
    return MEM_ERROR;
  }

  int status;

  size_t process_count = sysconf(_SC_NPROCESSORS_ONLN) % task->col;
  size_t part_size = task->col / process_count;

  pid_t *pids = (pid_t *)malloc(sizeof(pid_t) * process_count);
  if (pids == NULL) {
    return MEM_ERROR;
  }

  for (size_t i = 0; i < process_count; ++i) {
    pids[i] = fork();
    if (pids[i] > 0) {
      continue;
    }

    if (i == process_count - 1) {
      for (size_t j = i * part_size; j < task->col; j++) {
        for (size_t k = 0; k < task->row; k++) {
          shared_memory[j] += task->data[k][j];
        }
      }
    } else {
      for (size_t j = i * part_size; j < (i + 1) * part_size; j++) {
        for (size_t k = 0; k < task->row; k++) {
          shared_memory[j] += task->data[k][j];
        }
      }
    }

    if (shared_memory == NULL) {
      exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
  }

  for (size_t i = 0; i < process_count; ++i) {
    if (waitpid(pids[i], &status, 0) != pids[i]) {
      free(pids);
      return MEM_ERROR;
    }
  }

  task->sum_by_column = shared_memory;
  return NO_ERROR;
}
