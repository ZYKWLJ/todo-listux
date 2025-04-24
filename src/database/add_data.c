#include "../../include/include.h"
// 添加数据
void add_task(TaskYear *year_tasks, int year, int month, int day, int index, char *content)
{
    // 参数检查...
    // printf("add_task....\n");
    TaskDay *day_tasks = year_tasks->months[month - 1]->days[day - 1];

    // 确保有足够容量
    if (day_tasks->size >= day_tasks->capacity)
    {
        expand_capacity(day_tasks);
    }
    if (strlen(content) > strlen(day_tasks->task[index].task))
    {
        day_tasks->task[index].task = (char *)realloc(day_tasks->task[index].task, strlen(content) + 1); // 扩容到刚好容下就好
    }
    // 如果是添加到末尾
    if (index == day_tasks->size)
    {
        // printf("添加到末尾\n");
        strcpy(day_tasks->task[index].task, content);
        day_tasks->task[index].is_done = 0;
        day_tasks->size++; // 必须增加size
    }
    // 如果是插入到中间
    else
    {
        // printf("插入到中间\n");
        // 移动后续任务
        for (int i = day_tasks->size; i > index; i--)
        {
            strcpy(day_tasks->task[i].task, day_tasks->task[i - 1].task);
            day_tasks->task[i].is_done = day_tasks->task[i - 1].is_done;
        }
        // 插入新任务
        strcpy(day_tasks->task[index].task, content);
        day_tasks->task[index].is_done = 0;
        day_tasks->size++; // 必须增加size
    }
    // printf("add_task....succussed!\n");
    save_data(year_tasks, year);
}