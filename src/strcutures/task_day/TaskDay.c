#include "../../../include/include.h"
// 初始化当天任务
TaskDay *init_day_tasks()
{
    TaskDay *day_tasks = (TaskDay *)malloc(sizeof(TaskDay));
    if (day_tasks == NULL)
    {
        return NULL;
    }
    day_tasks->size = 0;
    day_tasks->capacity = INIT_TASK_CAPACITY;
    day_tasks->task = (Task *)malloc(day_tasks->capacity * sizeof(Task));
    if (day_tasks->task == NULL)
    {
        free(day_tasks);
        return NULL;
    }
    for (int i = 0; i < day_tasks->capacity; i++)
    {
        day_tasks->task[i].task = (char *)malloc(DEFALUT_TASK_CHAR_LENGTH * sizeof(char));
        if (day_tasks->task[i].task == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(day_tasks->task[j].task);
            }
            free(day_tasks->task);
            free(day_tasks);
            return NULL;
        }
        day_tasks->task[i].task[0] = '\0';
        day_tasks->task[i].is_done = 0;
    }
    return day_tasks;
}

// 扩容函数
void expand_capacity(TaskDay *day_tasks)
{
    // 新容量为原容量的两倍
    int new_capacity = day_tasks->capacity * 2;

    // 重新分配内存
    Task *new_task = (Task *)realloc(day_tasks->task, new_capacity * sizeof(Task));
    if (new_task == NULL)
    {
        // 扩容失败，释放原有内存
        free_day_tasks(day_tasks);
        return;
    }

    // 更新任务数组指针和容量
    day_tasks->task = new_task;
    day_tasks->capacity = new_capacity;

    // 初始化新分配的任务空间
    for (int i = day_tasks->size; i < new_capacity; i++)
    {
        day_tasks->task[i].task = (char *)malloc(DEFALUT_TASK_CHAR_LENGTH * sizeof(char));
        if (day_tasks->task[i].task == NULL)
        {
            // 内存分配失败，释放已分配的内存
            for (int j = 0; j < i; j++)
            {
                free(day_tasks->task[j].task);
            }
            free(day_tasks->task);
            free(day_tasks);
            return;
        }
        day_tasks->task[i].task[0] = '\0';
        day_tasks->task[i].is_done = 0;
    }
}

// 释放当天任务内存
void free_day_tasks(TaskDay *day_tasks)
{
    for (int i = 0; i < day_tasks->size; i++)
    {
        free(day_tasks->task[i].task);
    }
    free(day_tasks->task);
    free(day_tasks);
}