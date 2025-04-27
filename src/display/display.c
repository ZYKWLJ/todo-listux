#include "../../include/include.h"
#include "display.h"
// 显示当前日期的所有数据
void display_DAY_tasks(Date *date, Total_File_Year_Date *total_file_year_date, Setting *setting, int argc, char **argv)
{
    if (argc != 2) // 当天的显示只能是tl s,可能是tl s xxxx,那就报错，因为不允许，这是严谨性
    {
        printf("too many arguments!将展示正确的show命令的使用\n");
    }
    // 到这一步一定是tl s/tl show了

}
void display(Date *date, Date_Type *date_type, Total_File_Year_Date *total_file_year_date, Setting *setting, int argc, char **argv)
{
    // 当天显示
    if (date_type == CURRENT_DAY)
    {
    }
    // 计算指定的日期，到这里才计算？

    // 指定显示
    switch (*date_type)
    {
    case CURRENT_DAY:
        display_DAY_tasks(date, total_file_year_date, setting, argc, argv);
        break;
    case DAY:
        display_DAY_tasks(date, total_file_year_date, setting, argc, argv);
        break;
    case WEEK:
        display_WEEK_tasks(date, total_file_year_date, setting, argc, argv);
        break;
    case MONTH:
        display_MONTH_tasks(date, total_file_year_date, setting, argc, argv);
        break;
    case YEAR:
        display_YEAR_tasks(date, total_file_year_date, setting, argc, argv);
        break;
    default:
        printf("Invalid date type\n");
        break;
    }

#ifdef LOG
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
    if (task_year->months[month].days == NULL)
    {
        printf("task_year->months[%d].days is NULL\n", month);
        return;
    }

    // printf("Date: %d-%d-%d\n", year, month + 1, day + 1);

    // 获取当前日期的任务列表
    TaskDay *current_day_tasks = &task_year->months[month].days[day];

    // 检查当天是否有任务
    if (current_day_tasks->size == 0)
    {
        printf("No tasks for this day\n");
        return;
    }

    printf("Tasks for %d-%d-%d (Total: %d):\n", year, month + 1, day + 1, current_day_tasks->size);

    for (int i = 0; i < current_day_tasks->size; i++)
    {
        if (strcmp(setting->color, "on") == 0)
        {
            if (current_day_tasks->task[i].is_done) // 默认是0
            {
                // 完成了绿色
                printf(GREEN "%2d. [-] %s\n" RESET, i + 1, current_day_tasks->task[i].task);
            }
            else
            {
                // 未完成红色
                printf(RED "%2d. [+] %s\n" RESET, i + 1, current_day_tasks->task[i].task);
            }
        }
        else
        {
            if (current_day_tasks->task[i].is_done) // 默认是0
            {
                // 完成了绿色
                printf("%2d. [-] %s\n", i + 1, current_day_tasks->task[i].task);
            }
            else
            {
                // 未完成红色
                printf("%2d. [+] %s\n", i + 1, current_day_tasks->task[i].task);
            }
        }
    }
}
#endif