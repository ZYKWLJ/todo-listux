#include "../../../include/include.h"
void set_year_task(Year_Task *year_task, int year, int size, int capacity, Task *task)
{
    if (year_task == NULL)
    {
        LOG_PRINT("year_task is NULL!\n");
        exit(EXIT_FAILURE);
    }
    if (task == NULL)
    {
        LOG_PRINT("task is NULL!\n");
        exit(EXIT_FAILURE);
    }
    year_task->year = year;
    year_task->size = size;
    year_task->capacity = capacity;
    year_task->task = task;
}
void free_year_task(Year_Task *year_tasks)
{
    if (year_tasks == NULL)
    {
        LOG_PRINT("year_tasks is NULL!\n");
        exit(EXIT_FAILURE);
    }
    if (year_tasks->task != NULL)
    {
        free(year_tasks->task);
        exit(EXIT_FAILURE);
    }
    free(year_tasks->task);
    free(year_tasks);
}
void year_task_expand_capacity(Year_Task *year_task)
{
    if (year_task == NULL)
    {
        LOG_PRINT("year_task is NULL!\n");
        exit(EXIT_FAILURE);
    }
    year_task->capacity *= 2;
    Task *new_task = (Task *)realloc(year_task->task, sizeof(Task) * year_task->capacity);
    if (new_task == NULL)
    {
        LOG_PRINT("realloc failed!\n");
        exit(EXIT_FAILURE);
    }
}