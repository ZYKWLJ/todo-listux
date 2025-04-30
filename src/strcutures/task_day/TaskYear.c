#include "../../../include/include.h"
// #include "Day_Year_Task.h"
void set_day_year_tasks(Day_Year_Task *year_tasks, int year, TaskMonth *months)
{
    if(year_tasks == NULL){
        LOG_PRINT("year_tasks is NULL\n");
        exit(EXIT_FAILURE);
    }
    if(months == NULL){
        LOG_PRINT("months is NULL\n");
        exit(EXIT_FAILURE);
    }
    year_tasks->year = year;
    year_tasks->months = months;
}
// 释放当年任务内存
void free_day_year_tasks(Day_Year_Task *year_tasks)
{
    free_day_month_tasks(year_tasks->months);
    free(year_tasks);
}