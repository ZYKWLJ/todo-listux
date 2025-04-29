#ifndef Week_Month_Task_H
#define Week_Month_Task_H
#include "../../include.h"
// 单个月份的任务结构体
typedef struct Week_Month_Task
{
    int month;     // 是几月份
    int num_week;  // 是这个月的第几周
    Week_Task *week_tasks; // 这个月的每一天的任务
} Week_Month_Task;
// 初始化一个月份的任务结构体
void set_week_month_tasks(Week_Month_Task *week_month_tasks, int month, int week,  Week_Task *week_tasks);
// 释放一个月份的任务结构体
void free_week_month_tasks(Week_Month_Task *week_month_tasks);
#endif
