#ifndef MODIFY_DATA_H
#define MODIFY_DATA_H
#include "../include.h"
void modify_task_content(Day_Year_Task *year_tasks, int year, int month, int day, int index, char *new_content);
void modify_task_state(Day_Year_Task *year_tasks, int year, int month, int day, int index, int new_state);
#endif