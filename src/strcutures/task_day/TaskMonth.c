#include "../../../include/include.h"
// 初始化某个月的任务// 初始化当月任务
TaskMonth *init_month_tasks(int month, int year)
{
    TaskMonth *month_tasks = (TaskMonth *)malloc(sizeof(TaskMonth));
    if (month_tasks == NULL)
    {
        return NULL;
    }
    month_tasks->month = month;
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year))
    {
        month_days[1] = 29;
    }
    month_tasks->num_days = month_days[month - 1];
    month_tasks->days = (TaskDay *)malloc(month_tasks->num_days * sizeof(TaskDay));
    if (month_tasks->days == NULL)
    {
        free(month_tasks);
        return NULL;
    }
    for (int i = 0; i < month_tasks->num_days; i++)
    {
        month_tasks->days[i] = *init_day_tasks();
        if (&month_tasks->days[i] == NULL)
        {
            // 释放已分配内存
            for (int j = 0; j < i; j++)
            {
                free(&month_tasks->days[j]);
            }
            free(month_tasks->days);
            free(month_tasks);
            return NULL;
        }
    }
    return month_tasks;
}

// 释放当月任务内存
void free_month_tasks(TaskMonth *month_tasks)
{
    for (int i = 0; i < month_tasks->num_days; i++)
    {
        free_day_tasks(&month_tasks->days[i]);
    }
    free(month_tasks->days);
    free(month_tasks);
}