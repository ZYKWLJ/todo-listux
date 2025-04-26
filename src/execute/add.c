#include "../../include/include.h"

int add(Day_Year_Task *year_task, int year, int month, int day, int index, int argc, char **argv,Setting *setting)
{
    if (argc != 3)
    {
        printf("Usage: tl add <task_content>\n");
        return 0;
    }
    add_task(year_task, year, month, day, index, argv[2]);
    display_current_date_tasks(year_task, year, month, day,setting);
    return 1;
}