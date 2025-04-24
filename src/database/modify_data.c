#include "../../include/include.h"
// 修改数据
void modify_task(int year, int month, int day, Task*** task_year, int index) {
    month--;
    day--;
    if (index >= 0 && index < 10 && strlen(task_year[month][day][index].task) > 0) {
        printf("Enter new task: ");
        char input[100];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        free(task_year[month][day][index].task);
        task_year[month][day][index].task = (char*)malloc(sizeof(char) * (strlen(input) + 1));
        strcpy(task_year[month][day][index].task, input);
        save_data(year, task_year);
        printf("Task modified.\n");
    } else {
        printf("Invalid task index.\n");
    }
}