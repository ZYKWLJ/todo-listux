#include "../../include/include.h"
// 添加数据
void add_task(int year, int month, int day, Task*** task_year) {
    month--;
    day--;
    for (int i = 0; i < 10; i++) {
        if (strlen(task_year[month][day][i].task) == 0) {
            printf("Enter task: ");
            char input[100];
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;
            strcpy(task_year[month][day][i].task, input);
            task_year[month][day][i].is_done = 0;
            save_data(year, task_year);
            printf("Task added.\n");
            return;
        }
    }
    printf("No available slot for new task.\n");
}