#include "../../include.h"
typedef struct Year_Task
{
    int year;
    int size;
    int capacity; // 新增：当前分配的容量
    Task *task;   // 当年的任务列表
} Year_Task;

// 初始化某年的任务
void set_year_task(Year_Task *year_task, int year,int size,int capacity, Task *task);
// 释放某一年的任务
void free_year_task(Year_Task *year_tasks);
void year_task_expand_capacity(Year_Task *year_task);
