#include "../../../include/include.h"
// 初始化这一年的任务
// 初始化当年任务
Day_Year_Task* init_year_tasks(int year) {
    Day_Year_Task *year_tasks = (Day_Year_Task*)malloc(sizeof(Day_Year_Task));
    if (year_tasks == NULL) {
        return NULL;
    }
    year_tasks->year = year;
    year_tasks->months = (TaskMonth *)malloc(12 * sizeof(TaskMonth ));
    if (year_tasks->months == NULL) {
        free(year_tasks);
        return NULL;
    }
    for (int i = 1; i <= 12; i++) {
        year_tasks->months[i - 1] = *init_month_tasks(i, year);
        if (&year_tasks->months[i - 1] == NULL) {
            // 释放已分配内存
            for (int j = 0; j < i; j++) {
                free_month_tasks(&year_tasks->months[j]);
            }
            free(year_tasks->months);
            free(year_tasks);
            return NULL;
        }
    }
    return year_tasks;
}

// 释放当年任务内存
void free_year_tasks(Day_Year_Task *year_tasks) {
    for (int i = 0; i < 12; i++) {
        free_month_tasks(&year_tasks->months[i]);
    }
    free(year_tasks->months);
    free(year_tasks);
}