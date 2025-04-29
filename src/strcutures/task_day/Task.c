#include "../../../include/include.h"

void set_task(Task *task, char *content, int is_done)
{
    if (task == NULL)
    {
        LOG_PRINT("set_task: task is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (content == NULL)
    {
        LOG_PRINT("set_task: task_str is NULL\n");
        exit(EXIT_FAILURE);
    }
    task->content = content;
    task->is_done = is_done;
}
void free_task(Task *task)
{
    if (task == NULL)
    {
        LOG_PRINT("free_task: task is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (task->content == NULL)
    {
        LOG_PRINT("free_task: task->content is NULL\n");
        exit(EXIT_FAILURE);
    }
    free(task);
}