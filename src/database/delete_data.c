#include "../../include/include.h"
// 删除任务
void delete_task(TaskYear *year_tasks, int year, int month, int day, int index)
{
    // printf("delete_task---%d\n", index);
    if (year_tasks == NULL || year != year_tasks->year || month < 1 || month > 12)
    {
        return;
    }
    TaskMonth *month_tasks = &year_tasks->months[month - 1];
    TaskDay *day_tasks = &month_tasks->days[day - 1];
    if (index < 0 || index >= day_tasks->size)
    {
        printf("Invalid task index.\n");
        return;
    }

    // 释放任务内存
    free(day_tasks->task[index].task);

    for (int i = index; i < day_tasks->size - 1; i++)
    {
        // 复制任务字符串
        strcpy(day_tasks->task[i].task, day_tasks->task[i + 1].task);
        // 复制任务完成状态
        day_tasks->task[i].is_done = day_tasks->task[i + 1].is_done;
    }
    day_tasks->size--;

    // 将最后一个任务的 task 指针设置为 NULL
    if (day_tasks->size > 0)
    {
        day_tasks->task[day_tasks->size].task = NULL;
    }
}