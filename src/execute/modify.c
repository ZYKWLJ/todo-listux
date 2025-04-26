#include "../../include/include.h"

int modify(Day_Year_Task *year_task, int year, int month, int day, int index, int argc, char **argv,Setting *setting)
{
    if (argc != 4)// 目前只能等于4，多少都不行！tl modify <task_index> <new_content>
    {
        printf("Usage: tl modify <task_index>\n");
        save_data(year_task, year);
        return 1;
    }
    int modify_index = atoi(argv[2]);
    modify_task_content(year_task, year, month, day, modify_index-1, argv[3]);
    display_current_date_tasks(year_task, year, month, day,setting);
}