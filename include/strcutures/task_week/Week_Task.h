#include "../../include.h"
typedef struct Week_Task
{
    // int week;//是哪一个周
    int size;
    int capacity; // 新增：当前分配的容量
    Task *task;   // 当月的任务列表
}  Week_Task;
void Week_Task_expand_capacity(Week_Task *week_task);