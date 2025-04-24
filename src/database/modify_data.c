#include "../../include/include.h"
// 修改任务
void modify_task_content(TaskYear *year_tasks, int year, int month, int day, int index, char *new_content)
{
    if (year_tasks == NULL || year != year_tasks->year || month < 1 || month > 12)
    {
        return;
    }
    TaskMonth *month_tasks = year_tasks->months[month - 1];
    TaskDay *day_tasks = month_tasks->days[day - 1];
    if (index < 0 || index >= day_tasks->size)
    {
        printf("Invalid task index.\n");
        return;
    }
    if (strlen(new_content) >= MAX_TASK_CHAR_LENGTH)
    {
        day_tasks->task[index].task = (char *)realloc(day_tasks->task[index].task, strlen(new_content) + 1);
        if (day_tasks->task[index].task == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }
    }
    strcpy(day_tasks->task[index].task, new_content);
    save_data(year_tasks, year);
}

void modify_task_state(TaskYear *year_tasks, int year, int month, int day, int index, int new_state)
{
    if (year_tasks == NULL || year != year_tasks->year || month < 1 || month > 12)
    {
        return;
    }
    TaskMonth *month_tasks = year_tasks->months[month - 1];
    TaskDay *day_tasks = month_tasks->days[day - 1];

    if ((index<0&&index != -1) || (index < 0 || index >= day_tasks->size))
    {
        printf("Invalid task index.\n");
        return;
    }
    else if (index == -1) // 全部完成或者不完成
    {
        for (int i = 0; i < day_tasks->size; i++)
        {
            day_tasks->task[i].is_done = new_state;
        }
    }
    else
    {
        day_tasks->task[index].is_done = new_state;
    }
}
