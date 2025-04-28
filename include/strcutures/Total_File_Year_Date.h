#ifndef TOTAL_FILE_YEAR_DATE_H_
#define TOTAL_FILE_YEAR_DATE_H_
#include "../include.h"
typedef struct Total_File_Year_Date
{
    Day_Year_Task *day_year_task;
    Month_Year_Task *month_year_task;
    Week_Year_Task *week_year_task;
    Year_Task *year_task;

} Total_File_Year_Date;

void set_total_file_year_date(Total_File_Year_Date *total_file_year_date, Day_Year_Task *day_year_task, Month_Year_Task *month_year_task, Week_Year_Task *week_year_task, Year_Task *year_task);
void free_total_file_year_date(Total_File_Year_Date *total_file_year_date);
#endif