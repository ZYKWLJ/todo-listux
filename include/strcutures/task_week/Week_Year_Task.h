#include "../../include.h"
// 当年任务结构体
typedef struct Week_Year_Task
{
    int year;
    Week_Task *weeks; // 指向每个周的任务结构体
} Week_Year_Task;

// 初始化某年的任务
Week_Year_Task * init_Week_Year_Task(int year);
// 释放某一年的任务
void free_Week_Year_Task(Week_Year_Task *week_year_task);