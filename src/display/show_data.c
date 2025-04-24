#include "../../include/include.h"
// 显示当前日期的所有数据
void display_current_date_tasks(TaskYear *task_year, int year, int month, int day)
{
    // 检查 task_year 是否为空
    if (task_year == NULL)
    {
        printf("task_year is NULL\n");
        return;
    }
    // 检查 months 数组是否为空
    if (task_year->months == NULL)
    {
        printf("task_year->months is NULL\n");
        return;
    }

    // printf("==display_current_date_tasks==\n");
    // 月份和日期减1是因为数组索引从0开始
    month--;
    day--;

    // 检查月份是否合法
    if (month < 0 || month >= 12)
    {
        printf("Invalid month\n");
        return;
    }

    // 检查 days 指针是否为空
    if (task_year->months[month]->days == NULL)
    {
        printf("task_year->months[%d].days is NULL\n", month);
        return;
    }

    // printf("Date: %d-%d-%d\n", year, month + 1, day + 1);

    // 获取当前日期的任务列表
    TaskDay *current_day_tasks = task_year->months[month]->days[day];

    // 检查当天是否有任务
    if (current_day_tasks->size == 0)
    {
        printf("No tasks for this day\n");
        return;
    }

    printf("Tasks for %d-%d-%d (Total: %d):\n", year, month + 1, day + 1, current_day_tasks->size);

    for (int i = 0; i < current_day_tasks->size; i++)
    {
        if (current_day_tasks->task[i].is_done)
        {
            printf(GREEN"%2d. [√] %s\n"RESET, i + 1, current_day_tasks->task[i].task);
        }
        else
        {
            printf(RED"%2d. [×] %s\n"RESET, i + 1, current_day_tasks->task[i].task);
        }
        // printf("%2d. [%s] %s\n", i + 1,
        //        current_day_tasks->task[i].is_done ? "√" : "×",
        //        current_day_tasks->task[i].task);
    }
}