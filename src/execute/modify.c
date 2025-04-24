#include "../../include/include.h"

int modify(TaskYear *year_task, int year, int month, int day, int index, int argc, char **argv)
{
    if (argc != 4)// 目前只能等于4，多少都不行！tl modify <task_index> <new_content>
    {
        printf("Usage: tl modify <task_index>\n");
        save_data(year_task, year);
        return 1;
    }
    int modify_index = atoi(argv[2]);
    modify_task(year_task, year, month, day, modify_index, argv[3]);
    display_current_date_tasks(year_task, year, month, day);
}