#include "../../include/include.h"

int add(TaskYear *year_task, int year, int month, int day, int index, int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: tl add <task_content>\n");
        return 0;
    }
    add_task(year_task, year, month, day, index, argv[2]);
    display_current_date_tasks(year_task, year, month, day);
    return 1;
}