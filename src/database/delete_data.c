#include "../../include/include.h"
// 删除数据
void delete_task(int year, int month, int day, Task*** task_year, int index) {
    month--;
    day--;
    if (index >= 0 && index < 10 && strlen(task_year[month][day][index].task) > 0) {
        free(task_year[month][day][index].task);
        task_year[month][day][index].task = (char*)malloc(sizeof(char) * 100);
        task_year[month][day][index].task[0] = '\0';
        task_year[month][day][index].is_done = 0;
        save_data(year, task_year);
        printf("Task deleted.\n");
    } else {
        printf("Invalid task index.\n");
    }
}