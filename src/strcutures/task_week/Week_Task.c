#include "../../../include/include.h"
// #include "Week_Task.h"
void week_task_expand_capacity(Week_Task *week_task)
{
    int new_capacity = week_task->capacity * 2; // 增加容量为当前容量的两倍
    week_task->task = (Task *)realloc(week_task->task, new_capacity * sizeof(Task));
    if (week_task->task == NULL)
    {
        LOG_PRINT("realloc failed!\n");
        exit(EXIT_FAILURE);
    }
    week_task->capacity = new_capacity;
}
void set_week_tasks(Week_Task *week_task, int size, int capacity, Task *task)
{
    if (week_task == NULL)
    {
        LOG_PRINT("week_task is NULL!\n");
        exit(EXIT_FAILURE);
    }
    if (task == NULL)
    {
        LOG_PRINT("task is NULL!\n");
        exit(EXIT_FAILURE);
    }
    week_task->size = size;
    week_task->capacity = capacity;
    week_task->task = task;
}

void free_week_tasks(Week_Task *week_task)
{
    if (week_task == NULL)
    {
        LOG_PRINT("week_task is NULL!\n");
        exit(EXIT_FAILURE);
    }
    if (week_task->task == NULL)
    {
        LOG_PRINT("week_task->task is NULL!\n");
        exit(EXIT_FAILURE);
    }
    free(week_task->task);
    free(week_task);
}
