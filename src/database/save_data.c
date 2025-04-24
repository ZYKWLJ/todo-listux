#include "../../include/include.h"
// 保存数据
void save_data(TaskYear *year_tasks, int year)
{
    char filename[20];
    sprintf(filename, "/tmp/tl/%d.dat", year);
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Failed to open file for writing.\n");
        return;
    }
    fprintf(file, "%d\n", year_tasks->year);
    for (int m = 0; m < 12; m++)
    {
        TaskMonth *month_tasks =year_tasks->months[m];
        for (int d = 0; d < month_tasks->num_days; d++)
        {
            TaskDay *day_tasks = month_tasks->days[d];
            fprintf(file, "%d %d %d %d\n", m + 1, d + 1, day_tasks->size, day_tasks->capacity);
            for (int t = 0; t < day_tasks->size; t++)
            {
                fprintf(file, "%s %d\n", day_tasks->task[t].task, day_tasks->task[t].is_done);
            }
        }
    }
    fclose(file);
}

