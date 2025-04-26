#include "../../../include/include.h"
// extern const int MONTH_DAYS_IS_LEAP[12];
// extern const int MONTH_DAYS_IS_NOT_LEAP[12];
Month_Year_Task *init_Month_Year_Task(int year)
{
    LOG_PRINT("init_Month_Task\n");
    Month_Year_Task *month_year_task = (Month_Year_Task *)malloc(sizeof(Month_Year_Task)); // 肯定是12个月，毋庸置疑的！
    if (!month_year_task)
    {
        LOG_PRINT("malloc month_year_task failed\n");
        return NULL;
    }
    month_year_task->year = year;
    month_year_task->months = (Month_Task *)malloc(sizeof(Month_Task) * 12);
    if (!month_year_task->months)
    {
        LOG_PRINT("malloc month_year_task failed\n");
        return NULL;
    }
    for (int i = 0; i < 12; i++)
    {
        // 不管是不是闰年，都可以直接用，因为我们不是看天数
        month_year_task->months[i].task=(Task*)malloc(sizeof(Task)*DEFALUT_MONTH_TASK_SIZE);
        if (!month_year_task->months[i].task){
            LOG_PRINT("malloc month_year_task failed\n");
            return NULL;
        }
        month_year_task->months[i].size=0;
        month_year_task->months[i].capacity=DEFALUT_TASK_CHAR_LENGTH;//月任务的单条也是定长的2000不够再扩容！
    }
    return month_year_task;
}
