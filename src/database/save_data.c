#include "../../include/include.h"
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
                int len = strlen(task_year[month][day][i].task);
                fwrite(&len, sizeof(int), 1, file);
                if (len > 0) {
                    fwrite(task_year[month][day][i].task, sizeof(char), len, file);
                }
                fwrite(&task_year[month][day][i].is_done, sizeof(int), 1, file);
            }
        }
    }
    fclose(file);
}
