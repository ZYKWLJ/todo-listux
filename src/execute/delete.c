#include "../../include/include.h"

int delete_(TaskYear *year_task, int year, int month, int day, int index, int argc, char **argv,Setting *setting)
{
    if (argc != 3) // 目前只能等于3，多少都不行！
    {
        printf("Usage: tl delete <task_index>\n");
        save_data(year_task, year);
        return 1;
    }
    int task_index = atoi(argv[2]);
    // printf("task_index: %d\n", task_index-1);
    delete_task(year_task, year, month, day, task_index-1);
    display_current_date_tasks(year_task, year, month, day,setting);
    return 0;
}