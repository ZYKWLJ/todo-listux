#include "../../../include/include.h"
void Week_Task_expand_capacity(Week_Task *week_task)
{
    int new_capacity = week_task->capacity * 2; // 增加容量为当前容量的两倍
    week_task->task = (Task *)realloc(week_task->task, new_capacity * sizeof(Task));
    if (week_task->task == NULL){
        LOG_PRINT("realloc failed!\n");
        exit(EXIT_FAILURE);
    }
    week_task->capacity = new_capacity;
}