#include "../../../include/include.h"
// #include "Month_Year_Task.h"

void set_month_month_year_tasks(Month_Year_Task *month_year_task, int year, Month_Task *months)
{
    if(month_year_task == NULL){
        LOG_PRINT("set_month_month_year_tasks: month_year_task is NULL\n");
        exit(EXIT_FAILURE);
    }
    if(months == NULL){
        LOG_PRINT("set_month_month_year_tasks: months is NULL\n");
        exit(EXIT_FAILURE); 
    }
    month_year_task->year = year;
    month_year_task->months = months;
}

void free_month_month_year_tasks(Month_Year_Task *month_year_task)
{
    if(month_year_task == NULL){
        LOG_PRINT("free_month_month_year_tasks: month_year_task is NULL\n");
        exit(EXIT_FAILURE); 
    }
    if(month_year_task->months == NULL){
        LOG_PRINT("free_month_month_year_tasks: months is NULL\n");
        exit(EXIT_FAILURE);
    }
    free(month_year_task->months);
    free(month_year_task);
}