#include "../../include/include.h"
// #include "task.h"

T_task T_task_init(T_task t)
{
    T_task task = (T_task)checked_malloc(sizeof(*t));
    return task;
}