
#include "../../../include/include.h"

void set_week_month_tasks(Week_Month_Task *month_tasks, int month, int num_week, Week_Task *week_tasks)
{
    if (month_tasks == NULL)
    {
        LOG_PRINT("%s", "week_month_task is NULL");
        exit(EXIT_FAILURE);
    }
    month_tasks->month;
    month_tasks->num_week = num_week;
    month_tasks->week_tasks = week_tasks;
}
// 释放一个月份的任务结构体
void free_week_month_tasks(Week_Month_Task *month_tasks)
{
    free(month_tasks->week_tasks);
    free(month_tasks);
}
