#ifndef TASKYEAR_H
#define TASKYEAR_H
#include "../../include.h"
// 当年任务结构体
typedef struct Day_Year_Task
{
    int year;
    TaskMonth *months; // 指向12个月的任务结构体
} Day_Year_Task;

// 初始化某年的任务
Day_Year_Task *init_year_tasks(int year);
// 释放某一年的任务
void free_year_tasks(Day_Year_Task *year_tasks);
#endif