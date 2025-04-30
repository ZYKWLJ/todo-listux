#include "../../include/include.h"
// 添加数据
void add_task(Day_Year_Task *year_tasks, int year, int month, int day, int index, char *content)
{
    // 参数检查...
    LOG_PRINT("add_task....\n");

    TaskDay *day_tasks = &year_tasks->months[month - 1].days[day - 1];

    // 确保有足够容量
    if (day_tasks->size >= day_tasks->capacity)
    {
        expand_capacity(day_tasks);
    }
    if (strlen(content) > strlen(day_tasks->task[index].content))
    {
        LOG_PRINT("add_task....content is too long! ready to realloc......\n");
        day_tasks->task[index].content = (char *)realloc(day_tasks->task[index].content, strlen(content) + 1 > MAX_TASK_SIZE ? MAX_TASK_SIZE : strlen(content) + 1); // 扩容到刚好容下就好，并且防止最大的溢出，我们起到了保险措施，最多存在1百万的字，事实上，也存不到这么多，只是为了健壮罢了
    }
    // 如果是添加到末尾
    if (index == day_tasks->size)
    {
        // printf("添加到末尾\n");
        strcpy(day_tasks->task[index].content, content);
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
            strcpy(day_tasks->task[i].content, day_tasks->task[i - 1].content);
            day_tasks->task[i].is_done = day_tasks->task[i - 1].is_done;
        }
        // 插入新任务
        strcpy(day_tasks->task[index].content, content);
        day_tasks->task[index].is_done = 0;
        day_tasks->size++; // 必须增加size
    }
    LOG_PRINT("add_task....succussed!\n");

    // save_data(year_tasks, year);
}