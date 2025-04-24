#include "../../include/include.h"
// 添加数据
void add_task(TaskYear *year_tasks, int year, int month, int day, int index, char *content)
{
    if (year_tasks == NULL || year != year_tasks->year || month < 1 || month > 12)
    {
        return;
    }
    // 事实上，这一定是正确的，因为这是系统生成的！
    TaskMonth *month_tasks = &year_tasks->months[month - 1];
    TaskDay *day_tasks = &month_tasks->days[day - 1];
    if (day_tasks->size >= day_tasks->capacity)
    {
        expand_capacity(day_tasks); // 扩充任务容量
    }

    // 移动任务位置
    // 从后往前移动，方式覆盖
    for (int i = day_tasks->size; i > index; i--)
    {
        strcpy(day_tasks->task[i].task, day_tasks->task[i - 1].task);
        day_tasks->task[i].is_done = day_tasks->task[i - 1].is_done;
    }

    // 添加新任务(防止char超长，所以这里reallc扩容)
    if (strlen(content) >= MAX_TASK_CHAR_LENGTH)
    {
        day_tasks->task[index].task = (char *)realloc(day_tasks->task[index].task, strlen(content) + 1);
        if (day_tasks->task[index].task == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }
    }
    strcpy(day_tasks->task[index].task, content);
    day_tasks->task[index].is_done = 0;
    day_tasks->size++;
}