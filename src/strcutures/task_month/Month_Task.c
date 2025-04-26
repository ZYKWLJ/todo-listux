#include "../../../include/include.h"
void Month_Task_expand_capacity(Month_Task *month_task)
{
    int new_capacity = month_task->capacity * 2; // 增加容量为当前容量的两倍
    month_task->task = (Task *)realloc(month_task->task, new_capacity * sizeof(Task));
    if (month_task->task == NULL){
        LOG_PRINT("realloc failed!\n");
        exit(EXIT_FAILURE);
    }
    month_task->capacity = new_capacity;
}