#include "../../../include/include.h"
// #include "Week_Year_Task.h"
void set_week_Year_task(Week_Year_Task *week_year_task, int year, Week_Month_Task *week_month_task)
{
    if (week_year_task == NULL)
    {
        LOG_PRINT("week_year_task is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (week_month_task == NULL)
    {
        LOG_PRINT("week_month_task is NULL\n");
        exit(EXIT_FAILURE);
    }
    week_year_task->year = year;
    week_year_task->months = week_month_task;
}
void free_week_year_task(Week_Year_Task *week_year_task)
{

    if (week_year_task == NULL)
    {
        LOG_PRINT("week_year_task is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (week_year_task->months == NULL)
    {
        LOG_PRINT("week_year_task->weeks is NULL\n");
        exit(EXIT_FAILURE);
    }
    free(week_year_task->months);
    free(week_year_task);
}
