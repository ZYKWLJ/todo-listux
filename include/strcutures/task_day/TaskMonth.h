#ifndef TASKMONTH_H
#define TASKMONTH_H
#include "../../include.h"
// 单个月份的任务结构体
typedef struct TaskMonth
{
    int month;     // 是几月份
    int num_days;  // 这个月有几天
    TaskDay *days; // 这个月的每一天的任务
} TaskMonth;
// 初始化一个月份的任务结构体
// TaskMonth *init_month_tasks(int month, int year);
void set_day_month_tasks(TaskMonth *month_tasks, int month, int num_days, TaskDay *days);
// 释放一个月份的任务结构体
void free_day_month_tasks(TaskMonth *month_tasks);
#endif
