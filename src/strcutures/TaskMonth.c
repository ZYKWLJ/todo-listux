#include "../../include/include.h"
// 初始化某个月的任务
TaskMonth *init_month_tasks(int month, int year)
{
    if (month < 1 || month > 12)
    {
        return NULL;
    }
    // 将某个月初始化
    TaskMonth *month_tasks = (TaskMonth *)malloc(sizeof(TaskMonth));
    if (month_tasks == NULL)
    {
        return NULL;
    }

    // 月份天数赋值
    if (is_leap_year(year))
    {
        month_tasks->num_days = 29;
    }else{
        month_tasks->num_days = MONTHS[month - 1];
    }

    // 分配 TaskDay 指针数组
    month_tasks->days = (TaskDay *)malloc(month_tasks->num_days * sizeof(TaskDay));
    if (month_tasks->days == NULL)
    {
        free(month_tasks);
        return NULL;
    }

    // 初始化每一天的任务
    for (int i = 0; i < month_tasks->num_days; i++)
    {
        month_tasks->days[i] = *init_day_tasks();
        if (month_tasks->days[i].task == NULL)
        {
            // 初始化失败，释放已分配的内存
            for (int j = 0; j < i; j++)
            {
                free_day_tasks(&month_tasks->days[j]);
            }
            free(month_tasks->days);
            free(month_tasks);
            return NULL;
        }
    }

    return month_tasks;
}

// 释放某个月的任务内存
void free_month_tasks(TaskMonth *month_tasks)
{
    if (month_tasks == NULL)
    {
        return;
    }

    // 先释放每一天的任务
    for (int i = 0; i < month_tasks->num_days; i++)
    {
        free_day_tasks(&month_tasks->days[i]);
    }

    // 再释放 TaskDay 指针数组
    free(month_tasks->days);

    // 最后释放 TaskMonth 本身
    free(month_tasks);
}