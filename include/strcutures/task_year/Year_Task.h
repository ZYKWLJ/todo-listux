#include "../../include.h"
typedef struct Year_Task
{
    int year;
    int size;
    int capacity; // 新增：当前分配的容量
    Task *task;   // 当年的任务列表
} Year_Task;

// 初始化某年的任务
Year_Task *init_Year_Task(int year);
// 释放某一年的任务
void free_Year_Task(Year_Task *year_tasks);
void Year_Task_expand_capacity(Year_Task *year_task);
