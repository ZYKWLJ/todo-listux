#include "../../include/include.h"
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
                free(task_year[month][day][i].task);
                task_year[month][day][i].task = (char*)malloc(sizeof(char) * (len + 1));
                fread(task_year[month][day][i].task, sizeof(char), len, file);
                task_year[month][day][i].task[len] = '\0';
            }
            fread(&task_year[month][day][i].is_done, sizeof(int), 1, file);
        }
    }
    fclose(file);
}