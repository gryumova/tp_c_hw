#include "../include/read_write.h"
#include "../include/task_structure.h"
#include <stdbool.h>

int write_file(const size_t k, const char filename[], const char action[]) {
  FILE *database = NULL;
  if (strcmp(action, "-c") == 0) {
    database = fopen(filename, "wb");
  }

  if (strcmp(action, "-a") == 0) {
    database = fopen(filename, "ab");
  }

  if (database == NULL) {
    puts("File not found");
    return (FAILED_FILE_OPENNING);
  }

  Task *info = (Task *)calloc(1, sizeof(Task));
  if (info == NULL) {
    puts("Memory error");
    if (fclose(database)) {
      return FAILED_FILE_CLOSING;
    }
    return (FAILED_MEMORY_ALLOCATION);
  }

  size_t i = 0;
  while (i < k) {
    if (fscanf(stdin, "%10d%2d%30s%2d.%2d.%4d", &info->id_task,
               &info->priority, info->description, &info->date.day,
               &info->date.mn, &info->date.year) < 0) {
      puts("Error getting full data");
      free(info);
      if (fclose(database)) {
        return FAILED_FILE_CLOSING;
      }
      return (SCANF_ERROR);
    }
    if (strlen(info->description) && info->date.day && info->date.mn &&
        info->date.year) {
      fwrite(info, sizeof(Task), 1, database);
    } else {
      puts("Some data was incomplete and didn't write to a file");
    }
    i++;
  }

  free(info);
  if (fclose(database)) {
    return FAILED_FILE_CLOSING;
  }
  return NO_ERROR;
}

TaskList_t *read_file(const char filename[]) {
  FILE *database = NULL;
  database = fopen(filename, "rb");

  if (database == NULL) {
    puts("File not found");
    return NULL;
  }

  Task *get_data = (Task *)malloc(sizeof(Task));
  if (get_data == NULL) {
    puts("Memory error");
    fclose(database);
    free(get_data);
    return NULL;
  }

  if (fread(get_data, sizeof(Task), 1, database) == 0) {
    puts("FILE IS EMPTY");
    fclose(database);
    free(get_data);
    return NULL;
  }

  TaskList_t *head = NULL;
  head = initialise(get_data);

  while (fread(get_data, sizeof(Task), 1, database) != 0) {
    head = add_elem(get_data, head);
  }

  free(get_data);
  if (fclose(database)) {
    return NULL;
  }
  return head;
}
