#include "../../include/include.h"
// 修改任务
void modify_task_content(Day_Year_Task *year_tasks, int year, int month, int day, int index, char *new_content)
{
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
    if (strlen(new_content) >= DEFALUT_TASK_CHAR_LENGTH)
    {
        LOG_PRINT("add_task....content is too long! ready to realloc......\n");
        day_tasks->task[index].content = (char *)realloc(day_tasks->task[index].content, strlen(new_content) + 1 > MAX_TASK_SIZE ? MAX_TASK_SIZE : strlen(new_content) + 1); // 扩容到刚好容下就好，并且防止最大的溢出，我们起到了保险措施，最多存在1百万的字，事实上，也存不到这么多，只是为了健壮罢了
        if (day_tasks->task[index].content == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }
    }
    strcpy(day_tasks->task[index].content, new_content);
    // save_data(year_tasks, year);
}

void modify_task_state(Day_Year_Task *year_tasks, int year, int month, int day, int index, int new_state)
{
    if (year_tasks == NULL || year != year_tasks->year || month < 1 || month > 12)
    {
        return;
    }
    TaskMonth *month_tasks = &year_tasks->months[month - 1];
    TaskDay *day_tasks = &month_tasks->days[day - 1];

    if (index == -1) // 全部完成或者不完成
    {
        for (int i = 0; i < day_tasks->size; i++)
        {
            day_tasks->task[i].is_done = new_state;
        }
    }
    else if (index < 0 || index >= day_tasks->size)
    {
        printf("Invalid task index.\n");
        return;
    }
    else
    {
        day_tasks->task[index].is_done = new_state;
    }
}
