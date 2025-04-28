#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 单个任务结构体
typedef struct Task {
    char* content;
    int is_done;
} Task;

// 判断是否为闰年
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


// 计算当年第几天
int day_of_year(int year, int month, int day) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year)) {
        days[1] = 29;
    }
    int doy = 0;
    for (int i = 0; i < month - 1; i++) {
        doy += days[i];
    }
    doy += day;
    return doy;
}

// 初始化当天任务
Task* init_day_tasks() {
    Task* task_day = (Task*)malloc(sizeof(Task) * 10);
    for (int i = 0; i < 10; i++) {
        task_day[i].content = (char*)malloc(sizeof(char) * 100);
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

// 加载数据
void load_data(int year, Task*** task_year) {
    char filename[20];
    sprintf(filename, "%d.dat", year);
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return;
    }
    int k;
    while (fread(&k, sizeof(int), 1, file) == 1) {
        int month = 1;
        int day = k;
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (is_leap_year(year)) {
            days[1] = 29;
        }
        while (day > days[month - 1]) {
            day -= days[month - 1];
            month++;
        }
        month--;
        day--;
        for (int i = 0; i < 10; i++) {
            int len;
            fread(&len, sizeof(int), 1, file);
            if (len > 0) {
                free(task_year[month][day][i].content);
                task_year[month][day][i].content = (char*)malloc(sizeof(char) * (len + 1));
                fread(task_year[month][day][i].content, sizeof(char), len, file);
                task_year[month][day][i].content[len] = '\0';
            }
            fread(&task_year[month][day][i].is_done, sizeof(int), 1, file);
        }
    }
    fclose(file);
}

// 保存数据
void save_data(int year, Task*** task_year) {
    char filename[20];
    sprintf(filename, "%d.dat", year);
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year)) {
        month_days[1] = 29;
    }
    for (int month = 0; month < 12; month++) {
        for (int day = 0; day < month_days[month]; day++) {
            int k = day_of_year(year, month + 1, day + 1);
            fwrite(&k, sizeof(int), 1, file);
            for (int i = 0; i < 10; i++) {
                int len = strlen(task_year[month][day][i].content);
                fwrite(&len, sizeof(int), 1, file);
                if (len > 0) {
                    fwrite(task_year[month][day][i].content, sizeof(char), len, file);
                }
                fwrite(&task_year[month][day][i].is_done, sizeof(int), 1, file);
            }
        }
    }
    fclose(file);
}

// 显示当前日期的所有数据
void display_current_date_tasks(int year, int month, int day, Task*** task_year) {
    int doy = day_of_year(year, month, day);
    month--;
    day--;
    printf("Date: %d-%d-%d\n", year, month + 1, day + 1);
    for (int i = 0; i < 10; i++) {
        if (strlen(task_year[month][day][i].content) > 0) {
            printf("[%s] %s\n", task_year[month][day][i].is_done ? "X" : " ", task_year[month][day][i].content);
        }
    }
}

// 添加数据
void add_task(int year, int month, int day, Task*** task_year) {
    month--;
    day--;
    for (int i = 0; i < 10; i++) {
        if (strlen(task_year[month][day][i].content) == 0) {
            printf("Enter task: ");
            char input[100];
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;
            strcpy(task_year[month][day][i].content, input);
            task_year[month][day][i].is_done = 0;
            save_data(year, task_year);
            printf("Task added.\n");
            return;
        }
    }
    printf("No available slot for new task.\n");
}

// 删除数据
void delete_task(int year, int month, int day, Task*** task_year, int index) {
    month--;
    day--;
    if (index >= 0 && index < 10 && strlen(task_year[month][day][index].content) > 0) {
        free(task_year[month][day][index].content);
        task_year[month][day][index].content = (char*)malloc(sizeof(char) * 100);
        task_year[month][day][index].content[0] = '\0';
        task_year[month][day][index].is_done = 0;
        save_data(year, task_year);
        printf("Task deleted.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

// 修改数据
void modify_task(int year, int month, int day, Task*** task_year, int index) {
    month--;
    day--;
    if (index >= 0 && index < 10 && strlen(task_year[month][day][index].content) > 0) {
        printf("Enter new task: ");
        char input[100];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        free(task_year[month][day][index].content);
        task_year[month][day][index].content = (char*)malloc(sizeof(char) * (strlen(input) + 1));
        strcpy(task_year[month][day][index].content, input);
        save_data(year, task_year);
        printf("Task modified.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

// int main() {
//     int year, month, day;
//     get_current_date(&year, &month, &day);

//     Task*** task_year = init_year_tasks(year);
//     load_data(year, task_year);

//     while (1) {
//         printf("\n1. Display current date tasks\n");
//         printf("2. Add task\n");
//         printf("3. Delete task\n");
//         printf("4. Modify task\n");
//         printf("5. Exit\n");
//         printf("Enter your choice: ");
//         int choice;
//         scanf("%d", &choice);
//         getchar(); // 消耗掉换行符

//         switch (choice) {
//             case 1:
//                 display_current_date_tasks(year, month, day, task_year);
//                 break;
//             case 2:
//                 add_task(year, month, day, task_year);
//                 break;
//             case 3:
//                 printf("Enter task index to delete: ");
//                 int delete_index;
//                 scanf("%d", &delete_index);
//                 getchar(); // 消耗掉换行符
//                 delete_task(year, month, day, task_year, delete_index);
//                 break;
//             case 4:
//                 printf("Enter task index to modify: ");
//                 int modify_index;
//                 scanf("%d", &modify_index);
//                 getchar(); // 消耗掉换行符
//                 modify_task(year, month, day, task_year, modify_index);
//                 break;
//             case 5:
//                 save_data(year, task_year);
//                 for (int i = 0; i < 12; i++) {
//                     for (int j = 0; j < 31; j++) {
//                         for (int k = 0; k < 10; k++) {
//                             free(task_year[i][j][k].content);
//                         }
//                         free(task_year[i][j]);
//                     }
//                     free(task_year[i]);
//                 }
//                 free(task_year);
//                 return 0;
//             default:
//                 printf("Invalid choice.\n");
//         }
//     }

//     return 0;
// }    