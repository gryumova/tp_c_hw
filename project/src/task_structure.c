#include "../include/task_structure.h"


TaskList_t* sort_by_date(TaskList_t* head, Task* elem) {
    if (head == NULL || elem == NULL) {
        return NULL;
    }
    TaskList_t* current = head;
    TaskList_t* next_current = next_current->next;
    while (next_current && next_current->data.priority == elem->priority) {
        if (date_comparison(next_current->data.date, elem->date)) {
            return current;
        }
        current = next_current;
        next_current = next_current->next;
    }
    return current;
}


TaskList_t* add_elem(Task* new_task, TaskList_t* head) {
    if (new_task == NULL || head == NULL) {
        return NULL;
    }
    TaskList_t* current = head;
    TaskList_t* pre_current = head;
    
    if (current->data.priority >= new_task->priority) {
        if (current->data.priority == new_task->priority && !date_comparison(current->data.date, new_task->date)) {
            current = current->next;
        }
        else {
            pre_current = initialise(new_task);
            pre_current->next = current;
            return pre_current;
        }
    }

    while (current != NULL) { 
        if (current->data.priority <= new_task->priority) {
            if (current->data.priority == new_task->priority) {
                pre_current = sort_by_date(pre_current, new_task);
            }
            current = insert_task(pre_current, new_task);
            return head;
        }
        pre_current = current;
        current = current->next;
    }


    current =  initialise(new_task); 
    pre_current->next = current;
    return head;
}

TaskList_t* initialise(Task* elem) {
    if (elem == NULL) {
        return NULL;
    }

    TaskList_t* current = (TaskList_t*) malloc(sizeof(TaskList_t));
    if (current == NULL) {
        return NULL;
    }
    current->next = NULL;

    current->data.id_task = elem->id_task;
    current->data.priority = elem->priority;
    snprintf(current->data.description,  sizeof(elem->description), "%s", elem->description);
    current->data.date.year = elem->date.year;
    current->data.date.mn = elem->date.mn;
    current->data.date.day = elem->date.day;

    return current;
}


TaskList_t* insert_task(TaskList_t* task, Task* elem) {
    if (elem == NULL || task == NULL) {
        return NULL;
    }
    TaskList_t* current = task;
    TaskList_t* current_next = current->next;
    
    TaskList_t* new_elem = (TaskList_t*) malloc(sizeof(TaskList_t));

    current->next = new_elem;

    new_elem->next = current_next;

    new_elem->data.id_task = elem->id_task;
    new_elem->data.priority = elem->priority;

    if (snprintf(new_elem->data.description, sizeof(elem->description), "%s", elem->description) < 0) {
        return NULL;
    }

    new_elem->data.date.year = elem->date.year;
    new_elem->data.date.mn = elem->date.mn;
    new_elem->data.date.day = elem->date.day;

    return task;
}


int print_task(TaskList_t* head) {
    if (head == NULL) {
        return PRINT_ERROR;
    }
    TaskList_t* q = head;
    printf("----------------------\n");
    while (q != NULL) {
        printf("Id task: %lu\nPriority: %d\n%s\n", q->data.id_task, q->data.priority, q->data.description);
        printf("Date: %d.%d.%d\n\n", q->data.date.day, q->data.date.mn, q->data.date.year);
        q = q->next;
        printf("----------------------\n\n");
    }
    return NO_ERROR;
}


int clear(TaskList_t *head)
{
    TaskList_t* temp = head;
    while (temp->next != NULL) 
    { 
        TaskList_t* current = temp->next;
        temp->next = temp->next->next;
        free(current);
    }
    free(temp);
    return NO_ERROR;
}

