#include "../../include/include.h"

int delete_(TaskYear *year_task, int year, int month, int day, int index, int argc, char **argv)
{
    if (argc != 3) // 目前只能等于3，多少都不行！
    {
        printf("Usage: tl delete <task_index>\n");
        save_data(year_task, year);
        return 1;
    }
    int task_index = atoi(argv[2]);
    delete_task(year_task, year, month, day, index);
    display_current_date_tasks(year_task, year, month, day);
    return 0;
}