#ifndef TASK_H
#define TASK_H
// #define MAX_TASK_CHAR_LENGTH 2000
// #define INIT_TASK_CAPACITY 20
// 单条任务的结构体
typedef struct Task
{
    char *content;
    int is_done;
} Task;
void set_task(Task *task, char *content, int is_done);
void free_task(Task *task);
#endif