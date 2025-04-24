#include "../../include/include.h"

int done(TaskYear *year_task, int year, int month, int day, int index, int argc, char **argv)
{
    if (argc != 3) // 目前只能等于3，多少都不行！
    {
        printf("Usage: tl delete <task_index/all>\n");
        save_data(year_task, year);
        return 1;
    }
    // printf("argv[2]: %s\n", argv[2]);
    if (strcmp(argv[2], "all") == 0)
    {
        modify_task_state(year_task, year, month, day, -1, 1);
    }
    else
    {
        int task_index = atoi(argv[2]);
        modify_task_state(year_task, year, month, day, task_index - 1, 1);
    }
    display_current_date_tasks(year_task, year, month, day);
    return 0;
}