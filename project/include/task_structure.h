#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/read_write.h"


TaskList_t* add_elem(Task_t* new_task, TaskList_t* head);
TaskList_t* initialise(Task_t* elem);
TaskList_t* insert_task(TaskList_t* task, Task_t* elem);
TaskList_t *sort_by_date(TaskList_t *head, Task_t *elem);

bool date_comparison(Date_t date1, Date_t date2);
int print_task(TaskList_t* head);
int clear(TaskList_t *head);