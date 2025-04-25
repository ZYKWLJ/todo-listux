#ifndef TASKYEAR_H
#define TASKYEAR_H
#include "../include.h"
// 当年任务结构体
typedef struct TaskYear
{
    int year;
    TaskMonth *months; // 指向12个月的任务结构体
} TaskYear;

// 初始化某年的任务
TaskYear *init_year_tasks(int year);
// 释放某一年的任务
void free_year_tasks(TaskYear *year_tasks);
#endif