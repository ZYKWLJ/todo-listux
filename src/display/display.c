#include "../../include/include.h"
// #include "display.h"
// 显示当前日期的所有数据
#define LOG
// void print_dates(int size,)
void display_DAY_tasks(All_Files *all_files, DISPLAY_NODE *display_node)
{

    if (display_node->date->date_type == CURRENT_DAY) // 当天的显示只能是tl s [-day xxxx.xx.xx],可能是tl s xxxx,如果不是这两种情况，那就报错，因为不允许，这是严谨性
    {

        LOG_PRINT("%s", "show current day task......\n");
    }
    else // 当天的显示只能是tl s [-day xxxx.xx.xx],可能是tl s xxxx,如果不是这两种情况，那就报错，因为不允许，这是严谨性
    {
        LOG_PRINT("%s", "show specific day task......\n");
    }
#ifdef LOG
    LOG_PRINT("display_DAY_tasks\n");

#endif
#ifdef DO
    // 到这一步一定是tl s/tl show了
    // 之前数据已经加载在total_file_year_date里面了！
    TaskDay *current_day_tasks = total_file_year_date->day_year_task->months->days;
    printf("Tasks for %d-%d-%d (Total: %d):\n", date->year, date->month, date->day, current_day_tasks->size);

    for (int i = 0; i < current_day_tasks->size; i++)
    {
        const char *color_prefix = "";
        const char *color_suffix = "";
        const char *status = current_day_tasks->task[i].is_done ? "[-]" : "[+]";

        if (strcmp(setting->color, "on") == 0)
        {
            color_prefix = current_day_tasks->task[i].is_done ? GREEN : RED;
            color_suffix = RESET;
        }

        printf("%s%2d. %s %s%s\n",
               color_prefix,
               i + 1,
               status,
               current_day_tasks->task[i].task,
               color_suffix);
    }
#endif
}

void display_WEEK_tasks(All_Files *all_files, DISPLAY_NODE *display_node)
{

    LOG_PRINT("display_WEEK_tasks\n");
    // if(display_node->)
// 到这一步一定是tl s/tl show了
// 之前数据已经加载在total_file_year_date里面了！
#ifdef DO
    Week_Task *week_tasks = total_file_year_date->week_year_task->weeks;
    printf("Tasks for %d-%d-%d (Total: %d):\n", date->year, date->month, date->week, week_tasks->size);

    for (int i = 0; i < week_tasks->size; i++)
    {
        const char *color_prefix = "";
        const char *color_suffix = "";
        const char *status = week_tasks->task[i].is_done ? "[-]" : "[+]";

        if (strcmp(setting->color, "on") == 0)
        {
            color_prefix = week_tasks->task[i].is_done ? GREEN : RED;
            color_suffix = RESET;
        }

        printf("%s%2d. %s %s%s\n",
               color_prefix,
               i + 1,
               status,
               week_tasks->task[i].task,
               color_suffix);
    }
#endif
}
void display_MONTH_tasks(All_Files *all_files, DISPLAY_NODE *display_node)
{

    LOG_PRINT("display_MONTH_tasks\n");
#ifdef DO
    // 到这一步一定是tl s/tl show了
    // 之前数据已经加载在total_file_year_date里面了！
    Month_Task *month_tasks = total_file_year_date->month_year_task->months;
    printf("Tasks for %d-%d (Total: %d):\n", date->year, date->month, month_tasks->size);

    for (int i = 0; i < month_tasks->size; i++)
    {
        const char *color_prefix = "";
        const char *color_suffix = "";
        const char *status = month_tasks->task[i].is_done ? "[-]" : "[+]";

        if (strcmp(setting->color, "on") == 0)
        {
            color_prefix = month_tasks->task[i].is_done ? GREEN : RED;
            color_suffix = RESET;
        }

        printf("%s%2d. %s %s%s\n",
               color_prefix,
               i + 1,
               status,
               month_tasks->task[i].task,
               color_suffix);
    }
#endif
}
void display_YEAR_tasks(All_Files *all_files, DISPLAY_NODE *display_node)
{

    LOG_PRINT("display_YEAR_tasks\n");

#ifdef DO

    // 到这一步一定是tl s/tl show了
    // 之前数据已经加载在total_file_year_date里面了！
    Year_Task *year_tasks = total_file_year_date->year_task;
    printf("Tasks for %d (Total: %d):\n", date->year, year_tasks->size);

    for (int i = 0; i < year_tasks->size; i++)
    {
        const char *color_prefix = "";
        const char *color_suffix = "";
        const char *status = year_tasks->task[i].is_done ? "[-]" : "[+]";

        if (strcmp(setting->color, "on") == 0)
        {
            color_prefix = year_tasks->task[i].is_done ? GREEN : RED;
            color_suffix = RESET;
        }

        printf("%s%2d. %s %s%s\n",
               color_prefix,
               i + 1,
               status,
               year_tasks->task[i].task,
               color_suffix);
    }
#endif
}

void display(All_Files *all_files, NODE *node)
{
    // 计算指定的日期，到这里才计算？
    // 指定显示
    switch (node->display_node->date->date_type)
    {
    case CURRENT_DAY:
    case DAY:
        display_DAY_tasks(all_files, node->display_node);
        break;
    case WEEK:
        display_WEEK_tasks(all_files, node->display_node);
        break;
    case MONTH:
        display_MONTH_tasks(all_files, node->display_node);
        break;
    case YEAR:
        display_YEAR_tasks(all_files, node->display_node);
        break;
    default:
        break;
    }
}