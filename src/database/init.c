#include "../../include/include.h"
// 初始化当天任务
Task* init_day_tasks() {
    Task* task_day = (Task*)malloc(sizeof(Task) * 10);
    for (int i = 0; i < 10; i++) {
        task_day[i].task = (char*)malloc(sizeof(char) * 100);
        task_day[i].is_done = 0;
    }
    return task_day;
}

// 初始化当年任务
Task*** init_year_tasks(int year) {
    Task*** task_year = (Task***)malloc(sizeof(Task**) * 12);
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year)) {
        month_days[1] = 29;
    }
    for (int i = 0; i < 12; i++) {
        task_year[i] = (Task**)malloc(sizeof(Task*) * month_days[i]);
        for (int j = 0; j < month_days[i]; j++) {
            task_year[i][j] = init_day_tasks();
        }
    }
    return task_year;
}
