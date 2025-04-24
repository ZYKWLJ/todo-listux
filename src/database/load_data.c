#include "../../include/include.h"
// 加载数据

// 加载数据
TaskYear *load_data(int year) {
    char filename[100];
    #ifdef _WIN32
        snprintf(filename, sizeof(filename), "C:\\%d.dat", year);
    #else
        snprintf(filename, sizeof(filename), "/tmp/tl/%d.dat", year);
    #endif

    struct stat buffer;
    int exists = (stat(filename, &buffer) == 0);
    if (!exists) {
        FILE *file = fopen(filename, "w");
        if (file) {
            fclose(file);
        }
    }

    TaskYear *year_tasks = init_year_tasks(year);
    if (!year_tasks) {
        return NULL;
    }

    FILE *file = fopen(filename, "r");
    if (file) {
        // 这里可以根据文件格式实现具体的读取逻辑
        // 目前只是简单打开并关闭，实际需要从文件中读取并填充 year_tasks 结构体
        fclose(file);
    }

    return year_tasks;
}