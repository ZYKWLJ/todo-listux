#include "../../include/include.h"
#include "undo.h"

int undo(Day_Year_Task *year_task, int year, int month, int day, int index, int argc, char **argv,Setting *setting)
{
    if (argc != 3) // 目前只能等于3，多少都不行！
    {
        printf("Usage: tl delete <task_index/all>\n");
        save_data(year_task, year);
        return 1;
    }
    if (strcmp(argv[2], "all") == 0)
    {
        modify_task_state(year_task, year, month, day, -1, 0); // 全部撤销完成标记
    }
    else
    {
        int task_index = atoi(argv[2]);
        modify_task_state(year_task, year, month, day, task_index - 1, 0); // 撤销完成标记某个任务
    }

    display_current_date_tasks(year_task, year, month, day,setting);
    return 0;
}
void undo(Date *date, Date_Type *date_type, Total_File_Year_Date *total_file_year_date, Setting *setting, int argc, char **argv)
{
    if (argc != 3)
            {
                printf("too many arguments!将展示正确的delete命令的使用\n");
            }
}