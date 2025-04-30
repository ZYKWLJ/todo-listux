#include "../../../include/include.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#include <direct.h>
#else
#include <unistd.h>
#include <sys/stat.h>
#endif
// #define LOG1
# ifdef LOG1

// 跨平台保存数据
void save_data(Day_Year_Task *year_tasks, int year) {

    if (year_tasks == NULL) {
        fprintf(stderr, "Error: Null year_tasks pointer\n");
        return;
    }

    // 获取平台特定的数据目录
    const char* base_path = get_appdata_path1();
    char filename[MAX_PATH];
    
    // 构建完整文件路径
#ifdef _WIN32
    snprintf(filename, sizeof(filename), "%s\\%d.dat", base_path, year);
#else
    snprintf(filename, sizeof(filename), "%s/%d.dat", base_path, year);
#endif

    // 打开文件
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file for writing: %s\n", filename);
        return;
    }

    // 写入年份
    fprintf(file, "%d\n", year_tasks->year);

    // 写入每月数据
    for (int m = 0; m < 12; m++) {
        TaskMonth *month_tasks = &year_tasks->months[m];
        if (month_tasks == NULL) continue;

        for (int d = 0; d < month_tasks->num_days; d++) {
            TaskDay *day_tasks = &month_tasks->days[d];
            if (day_tasks == NULL) continue;

            // 写入日期信息和任务数量
            fprintf(file, "%d %d %d %d\n", 
                   m + 1, d + 1, 
                   day_tasks->size, 
                   day_tasks->capacity);

            // 写入任务详情
            for (int t = 0; t < day_tasks->size; t++) {
                if (day_tasks->task[t].content == NULL) continue;
                fprintf(file, "%s %d\n", 
                       day_tasks->task[t].content, 
                       day_tasks->task[t].is_done);
            }
        }
    }

    fclose(file);
}

#endif