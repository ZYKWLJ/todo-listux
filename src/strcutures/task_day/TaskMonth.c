#include "../../../include/include.h"
// #include "TaskMonth.h"
// 初始化某个月的任务// 初始化当月任务
void set_day_month_tasks(TaskMonth *month_tasks, int month, int num_days, TaskDay *days)
{
    if(month_tasks==NULL){
        LOG_PRINT("set_month_tasks: month_tasks is NULL\n");
        exit(EXIT_FAILURE);
    }
    if(days==NULL){
        LOG_PRINT("set_month_tasks: days is NULL\n");
        exit(EXIT_FAILURE);
    }
    month_tasks->month = month;
    month_tasks->num_days = num_days;
    month_tasks->days = days;
}
// 释放当月任务内存
void free_day_month_tasks(TaskMonth *month_tasks)
{
    free(month_tasks->days);
    free(month_tasks);
}