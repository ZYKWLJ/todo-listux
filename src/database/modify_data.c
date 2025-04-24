#include "../../include/include.h"
// 修改任务
void modify_task(TaskYear *year_tasks, int year, int month, int day, int index, char *new_content)
{
    if (year_tasks == NULL || year != year_tasks->year || month < 1 || month > 12)
    {
        return;
    }
    TaskMonth *month_tasks = &year_tasks->months[month - 1];
    TaskDay *day_tasks = &month_tasks->days[day - 1];
    if (index < 0 || index >= day_tasks->size)
    {
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
}
