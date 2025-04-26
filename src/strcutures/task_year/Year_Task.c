#include "../../../include/include.h"
Year_Task *init_Year_Task(int year)
{
    LOG_PRINT("init_Year_Task\n");
    Year_Task *year_task = (Year_Task *)malloc(sizeof(Year_Task));
    if (year_task == NULL)
    {
        LOG_PRINT("init_Year_Task malloc failed\n");
        return NULL;
    }
    year_task->year = year;
    year_task->size = 0;
    year_task->capacity = DEFALUT_YEAR_TASK_SIZE;                              // 初始容量为1000
    year_task->task = (Task *)malloc(sizeof(Task) * DEFALUT_TASK_CHAR_LENGTH); // 每条任务初识容量为2000
    if (year_task->task == NULL)
    {
        LOG_PRINT("init_Year_Task Task malloc failed\n");
    }
    return year_task;
}

void free_Year_Task(Year_Task *year_tasks)
{
    LOG_PRINT("free_Year_Task\n");
    if (year_tasks == NULL)
    {
        // LOG_PRINT("free_Year_Task year_tasks is NULL\n");
        return;
    }
    if (year_tasks->task != NULL)
    {
        free(year_tasks->task);
    }
    free(year_tasks);
}

void Year_Task_expand_capacity(Year_Task *year_task)
{
    int new_capacity = year_task->capacity * 2; // 增加容量为当前容量的两倍
    year_task->task = (Task *)realloc(year_task->task, new_capacity * sizeof(Task));
    if (year_task->task == NULL){
        LOG_PRINT("realloc failed!\n");
        exit(EXIT_FAILURE);
    }
    year_task->capacity = new_capacity;
}