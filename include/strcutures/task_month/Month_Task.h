#include "../../include.h"
typedef struct Month_Task
{
    int month;//是哪一月
    int size;
    int capacity; // 新增：当前分配的容量
    Task *task;   // 当月的任务列表
} Month_Task;
// 扩容函数，(初始化函数在下面结构体中调用)
void Month_Task_expand_capacity(Month_Task *month_task);
