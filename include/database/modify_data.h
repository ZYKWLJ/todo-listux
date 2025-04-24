#ifndef MODIFY_DATA_H
#define MODIFY_DATA_H
#include "../include.h"
void modify_task_content(TaskYear *year_tasks, int year, int month, int day, int index, char *new_content);
void modify_task_state(TaskYear *year_tasks, int year, int month, int day, int index, int new_state);
#endif