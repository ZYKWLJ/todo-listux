#ifndef TASKDAY_H
#define TASKDAY_H
#include "../include.h"
// 单个日期的任务结构体(size为该日期的任务数量，动态分配使用)
typedef struct TaskDay
{
    int size;
    int capacity; // 新增：当前分配的容量
    Task *task;   // 当天的任务列表
} TaskDay;
// 初始化当天任务
TaskDay* init_day_tasks();
// 扩展任务容量
void expand_capacity(TaskDay *day_tasks) ;
// 释放当天任务内存
void free_day_tasks(TaskDay *day_tasks);
#endif
