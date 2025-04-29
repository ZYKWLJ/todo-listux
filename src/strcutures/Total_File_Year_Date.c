// #include "Total_File_Year_Date.h"
#include "../../include/include.h"


void set_total_file_year_date(Total_File_Year_Date *total_file_year_date, Day_Year_Task *day_year_task, Month_Year_Task *month_year_task, Week_Year_Task *week_year_task, Year_Task *year_task)
{
    if (total_file_year_date == NULL)
    {
        LOG_PRINT("set_total_file_year_date: total_file_year_date is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (day_year_task == NULL)
    {
        LOG_PRINT("set_total_file_year_date: day_year_task is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (month_year_task == NULL)
    {
        LOG_PRINT("set_total_file_year_date: month_year_task is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (week_year_task == NULL)
    {
        LOG_PRINT("set_total_file_year_date: week_year_task is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (year_task == NULL)
    {
        LOG_PRINT("set_total_file_year_date: year_task is NULL\n");
        exit(EXIT_FAILURE);
    }
    total_file_year_date->day_year_task = day_year_task;
    total_file_year_date->month_year_task = month_year_task;
    total_file_year_date->week_year_task = week_year_task;
    total_file_year_date->year_task = year_task;
}

void free_total_file_year_date(Total_File_Year_Date *total_file_year_date)
{
    if (total_file_year_date == NULL)
    {
        LOG_PRINT("free_total_file_year_date: total_file_year_date is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (total_file_year_date->day_year_task == NULL)
    {
        LOG_PRINT("free_total_file_year_date: total_file_year_date->day_year_task is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (total_file_year_date->month_year_task == NULL)
    {
        LOG_PRINT("free_total_file_year_date: total_file_year_date->month_year_task is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (total_file_year_date->week_year_task == NULL)
    {
        LOG_PRINT("free_total_file_year_date: total_file_year_date->week_year_task is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (total_file_year_date->year_task == NULL)
    {
        LOG_PRINT("free_total_file_year_date: total_file_year_date->year_task is NULL\n");
    }
    free_day_year_tasks(total_file_year_date->day_year_task);
    free(total_file_year_date->month_year_task);
    free(total_file_year_date->week_year_task);
    free(total_file_year_date->year_task);
    free(total_file_year_date);
}
