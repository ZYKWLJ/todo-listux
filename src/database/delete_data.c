#include "../../include/include.h"
// 删除任务
void delete_task(TaskYear *year_tasks, int year, int month, int day, int index)
{
    if (year_tasks == NULL || year != year_tasks->year || month < 1 || month > 12)
    {
        return;
    }
    TaskMonth *month_tasks = year_tasks->months[month - 1];
    TaskDay *day_tasks = month_tasks->days[day - 1];
    if (index < 0 || index >= day_tasks->size)
    {
        return;
    }
    free(day_tasks->task[index].task);
    // 移动任务位置
    for (int i = index; i < day_tasks->size - 1; i++)
    {
        strcpy(day_tasks->task[i].task, day_tasks->task[i + 1].task);
        day_tasks->task[i].is_done = day_tasks->task[i + 1].is_done;
    }
    day_tasks->size--;
    save_data(year_tasks, year);
}