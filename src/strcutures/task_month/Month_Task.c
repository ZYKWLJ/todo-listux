#include "../../../include/include.h"
// #include "Month_Task.h"

void Month_Task_expand_capacity(Month_Task *month_task)
{
    // 肯扩充，肯定不是NULL
    if (month_task == NULL)
    {
        LOG_PRINT("month_task is NULL!\n");
        exit(EXIT_FAILURE);
    }
    month_task->capacity *= 2;
    // 扩容了为原来的两倍！
    month_task->task = (Task *)realloc(month_task->task, month_task->capacity * sizeof(Task));
    if (month_task->task == NULL)
    {
        LOG_PRINT("month_task->task is NULL!\n");
        exit(EXIT_FAILURE);
    }
}

void set_month_month_task(Month_Task *month_task, int month, int size, int capacity, Task *task)
{
    if (month_task == NULL)
    {
        LOG_PRINT("month_task is NULL!\n");
        exit(EXIT_FAILURE);
    }
    if (task == NULL)
    {
        LOG_PRINT("month_task->task is NULL!\n");
        exit(EXIT_FAILURE);
    }
    month_task->month = month;
    month_task->size = size;
    month_task->capacity = capacity;
    month_task->task = task;
}
void free_month_month_task(Month_Task *month_task)
{
    if (month_task == NULL)
    {
        LOG_PRINT("month_task is NULL!\n");
        exit(EXIT_FAILURE);
    }
    if (month_task->task == NULL)
    {
        LOG_PRINT("month_task->task is NULL!\n");
        exit(EXIT_FAILURE);
    }
    free(month_task->task);
    free(month_task);
}