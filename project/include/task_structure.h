#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/read_write.h"


TaskList_t* add_elem(Task* a, TaskList_t* head);
TaskList_t* initialise(Task* elem);
TaskList_t* insert_task(TaskList_t* head, Task* elem);

int print_task(TaskList_t* head);
int clear(TaskList_t *head);