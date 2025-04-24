#include "../../include/include.h"
// 初始化这一年的任务
TaskYear *init_year_tasks(int year)
{
    TaskYear *year_tasks = (TaskYear *)malloc(sizeof(TaskYear));
    if (year_tasks == NULL)
    {
        return NULL;
    }
    year_tasks->year = year;
    year_tasks->months = (TaskMonth *)malloc(sizeof(TaskMonth) * 12);
    if (year_tasks->months == NULL)
    {
        free(year_tasks);
        return NULL;
    }
    for (int i = 0; i < 12; i++)
    {
        year_tasks->months[i] = *init_month_tasks(i + 1, year); // 修正这里
    }
    return year_tasks;
}
// 释放某一年的任务
void free_year_tasks(TaskYear *year_tasks)
{
    for (int i = 0; i < 12; i++)
    {
        free_month_tasks(year_tasks->months); // 释放每个月的任务
    }
    free(year_tasks); // 最后释放本身
}