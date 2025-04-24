#include "../../include/include.h"
// 显示当前日期的所有数据
void display_current_date_tasks(int year, int month, int day, Task*** task_year) {
    int doy = day_of_year(year, month, day);
    month--;
    day--;
    printf("Date: %d-%d-%d\n", year, month + 1, day + 1);
    for (int i = 0; i < 10; i++) {
        if (strlen(task_year[month][day][i].task) > 0) {
            printf("[%s] %s\n", task_year[month][day][i].is_done ? "X" : " ", task_year[month][day][i].task);
        }
    }
}