#include "../../../include/include.h"
Week_Year_Task *init_Week_Year_Task(int year)
{
    LOG_PRINT("init_Week_Task\n");
    Week_Year_Task *week_year_task = (Week_Year_Task *)malloc(sizeof(Week_Year_Task)); // 肯定是12个月，毋庸置疑的！
    if (!week_year_task)
    {
        LOG_PRINT("malloc week_year_task failed\n");
        return NULL;
    }
    week_year_task->year = year;
    week_year_task->weeks = (Week_Task *)malloc(sizeof(Week_Task) * 48); // 因为每个月4周，所以12个月48周，当然每月的最后一周会多几天！
    if (!week_year_task->weeks)
    {
        LOG_PRINT("malloc week_year_task failed\n");
        return NULL;
    }
    for (int i = 0; i < 48; i++)
    {
        // 不管是不是闰年，都可以直接用，因为我们不是看天数
        week_year_task->weeks[i].task = (Task *)malloc(sizeof(Task) * DEFALUT_MONTH_TASK_SIZE);
        if (!week_year_task->weeks[i].task)
        {
            LOG_PRINT("malloc week_year_task failed\n");
            return NULL;
        }
        week_year_task->weeks[i].size = 0;
        week_year_task->weeks[i].capacity = DEFALUT_TASK_CHAR_LENGTH; // 月任务的单条也是定长的2000不够再扩容！
    }
    return week_year_task;
}

void free_Week_Year_Task(Week_Year_Task *week_year_task)
{
    if (!week_year_task)
    {
        // LOG_PRINT("week_year_task is NULL\n");
        return;
    }
    for (int i = 0; i < 48; i++)
    {
        if (!week_year_task->weeks[i].task){
            // LOG_PRINT("week_year_task->weeks[i].task is NULL\n");
            continue;
        }
        free(week_year_task->weeks[i].task);
    }
    free(week_year_task->weeks);
    free(week_year_task);
}

// 扩容函数
void Week_Year_Task_expand_capacity(TaskDay *day_tasks)
{
    // 新容量为原容量的两倍
    int new_capacity = day_tasks->capacity * 2;

    // 重新分配内存
    Task *new_task = (Task *)realloc(day_tasks->task, new_capacity * sizeof(Task));
    if (new_task == NULL)
    {
        // 扩容失败，释放原有内存
        free_day_tasks(day_tasks);
        return;
    }

    // 更新任务数组指针和容量
    day_tasks->task = new_task;
    day_tasks->capacity = new_capacity;

    // 初始化新分配的任务空间
    for (int i = day_tasks->size; i < new_capacity; i++)
    {
        day_tasks->task[i].task = (char *)malloc(DEFALUT_TASK_CHAR_LENGTH * sizeof(char));
        if (day_tasks->task[i].task == NULL)
        {
            // 内存分配失败，释放已分配的内存
            for (int j = 0; j < i; j++)
            {
                free(day_tasks->task[j].task);
            }
            free(day_tasks->task);
            free(day_tasks);
            return;
        }
        day_tasks->task[i].task[0] = '\0';
        day_tasks->task[i].is_done = 0;
    }
}