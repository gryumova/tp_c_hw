#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum error_list {
    NO_ERROR = 0,
    FAILED_FILE_OPENNING = 1,
    FAILED_FILE_CLOSING = 2,
    FAILED_MEMORY_ALLOCATION = 3,
    FAILED_MEMORY_CLEAR = 4,
    WRONG_NUM_OF_ARG = 5,
    SCANF_ERROR = 6,
    FREAD_ERROR = 7,
    PRINT_ERROR = 8,
};


typedef struct Date {
    int year;
    int mn;
    int day;
} Date;

typedef struct Task {
    int id_task;
    int priority;
    char description[30];
    Date date;
} Task;


typedef struct TaskList TaskList_t;
typedef struct TaskList {
    Task data;
    TaskList_t* next;
} TaskList_t;



int write_file(const size_t k, const char filename[], const char action[]);
TaskList_t* read_file(const char filename[]); 
