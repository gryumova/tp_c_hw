#include "../include/sum_par.h"

// float *sum_matrix_par(matrix_t *task, size_t a, size_t b) {
//   float *sum = malloc(sizeof(float) * (b - a));

//   for (size_t i = a; i < b; i++) {
//     sum[i] = 0;
//     for (size_t j = 0; j < task->row; j++) {
//       sum[i] += task->data[j][i];
//     }
//     printf("1.1 - %5.2f\n", sum[0]);
//   }
//   return sum;
// }

float *sum_in_row(matrix_t *task, float *sum_, size_t a, size_t b) {
  if (task == NULL || sum_ == NULL) {
    return NULL;
  }

  if (a < 0 || b < 0 || a > ROWS || b > ROWS) {
    return NULL;
  }

  for (size_t j = a; j < b; j++) {
    for (size_t i = 0; i < COLS; i++) {
      sum_[i] += task->data[j][i];
    }
  }

  return sum_;
}

float *find_sum_process(matrix_t *task) {
  if (task == NULL) {
    return NULL;
  }

  float *shared_memory =
      mmap(NULL, COLS * sizeof(float), PROT_READ | PROT_WRITE,
           MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  if (shared_memory == MAP_FAILED) {
    printf("Mapping Failed\n");
    return NULL;
  }

  int status;
  size_t process_count = 3;
  size_t part_size = task->row / process_count;

  pid_t *pids = (pid_t *)malloc(sizeof(pid_t) * process_count);
  if (pids == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < process_count; ++i) {
    pids[i] = fork();
    if (pids[i] > 0) {
      continue;
    }

    if (i == process_count - 1) {
      shared_memory = sum_in_row(task, shared_memory, i * part_size, ROWS);
    } else {
      shared_memory =
          sum_in_row(task, shared_memory, i * part_size, (i + 1) * part_size);
    }

    if (shared_memory == NULL) {
      exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
  }

  for (size_t i = 0; i < process_count; ++i) {
    if (waitpid(pids[i], &status, 0) != pids[i]) {
      printf("can't wait for pids\n");
      free(pids);
      return NULL;
    }
  }

  return shared_memory;
}

int print_answer(float *answer) {
  if (answer == NULL) {
    return PRINT_ERROR;
  }
  printf("-------------------\n");
  for (size_t i = 0; i < COLS; i++) {
    printf("%5.2f ", answer[i]);
  }
  printf("\n\n");

  return NO_ERROR;
}

// float *find_sum_process(matrix_t *task) {
//   if (task == NULL) {
//     return NULL;
//   }

//   int status;
//   size_t process_count = 8;
//   size_t part_size = task->col / process_count;

//   key_t key = IPC_PRIVATE;
//   int qid = msgget(key, 0666 | IPC_CREAT);
//   if (qid == -1) {
//     return NULL;
//   }

//   pid_t *pids = (pid_t *)malloc(sizeof(pid_t) * process_count);
//   if (pids == NULL) {
//     return NULL;
//   }

//   for (size_t i = 0; i < process_count; ++i) {
//     pids[i] = fork();
//     if (pids[i] > 0) {
//       continue;
//     }

//     float *sum_;

//     if (i == process_count) {
//       sum_ = sum_matrix_par(task, i * part_size, task->col);
//     } else {
//       sum_ = sum_matrix_par(task, i * part_size, (i + 1) * part_size);
//       printf("2 - %5.2f\n", sum_[0]);
//     }

//     if (sum_ == NULL) {
//       exit(EXIT_FAILURE);
//     }

//     msg_struct message = {task->col, sum_};
//     if (msgsnd(qid, &message, sizeof(msg_struct), 0) == -1) {
//       printf("can't send msg\n");
//       exit(EXIT_FAILURE);
//     }

//     free(sum_);
//     exit(EXIT_SUCCESS);
//   }

//   for (size_t i = 0; i < process_count; ++i) {
//     if (waitpid(pids[i], &status, 0) != pids[i]) {
//       printf("can't wait for pids\n");
//       free(pids);
//       return NULL;
//     }
//   }

//   float *sum_;
//   for (size_t i = 0; i < process_count; ++i) {
//     msg_struct message;
//     if (msgrcv(qid, &message, sizeof(msg_struct), 0, 0) == -1) {
//       printf("can't receive msg\n");
//       free(pids);
//       return NULL;
//     }
//     for (size_t j = 0; j < 1; j++) {
//       printf("3 - %5.2f\n", message.msg_data[0]);
//     }
//   }
//   printf("\n");

//   free(pids);

//   return sum_;
// }
