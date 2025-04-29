#include "../../include.h"
// 当年任务结构体
typedef struct Week_Year_Task
{
    int year;
    Week_Month_Task *months; // 指向每个周的任务结构体
} Week_Year_Task;

void set_week_Year_task(Week_Year_Task *week_year_task, int year, Week_Month_Task *week_month_task);
// 释放某一年的任务
void free_week_year_task(Week_Year_Task *week_year_task);
