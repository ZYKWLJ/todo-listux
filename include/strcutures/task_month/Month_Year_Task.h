#include "../../include.h"
// 当年任务结构体
typedef struct Month_Year_Task
{
    int year;
    Month_Task *months; // 指向12个月的任务结构体
} Month_Year_Task;

// 初始化某月的任务
Month_Year_Task *init_Month_Year_Task(int year);
// 释放某一月的任务
void free_Month_Year_Task(Month_Year_Task *month_year_task);

