#include "../../include/include.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 检查并创建目录
int create_directory(const char *path) {
#ifdef _WIN32
    char command[100];
    sprintf(command, "mkdir %s", path);
    return system(command);
#else
    char command[100];
    sprintf(command, "mkdir -p %s", path);
    return system(command);
#endif
}

// 加载数据
TaskYear *load_data(int year) {
    char filename[100];
#ifdef _WIN32
    snprintf(filename, sizeof(filename), "C:\\%d.dat", year);
    // 检查并创建目录
    if (create_directory("C:\\") != 0) {
        printf("Failed to create directory.\n");
        return NULL;
    }
#else
    snprintf(filename, sizeof(filename), "/tmp/tl/%d.dat", year);
    // 检查并创建目录
    if (create_directory("/tmp/tl/") != 0) {
        printf("Failed to create directory.\n");
        return NULL;
    }
#endif

    struct stat buffer;
    int exists = (stat(filename, &buffer) == 0);
    FILE *file;
    if (!exists) {
        file = fopen(filename, "w");
        if (file) {
            fclose(file);
        }
    }

    TaskYear *year_tasks = init_year_tasks(year);
    if (!year_tasks) {
        return NULL;
    }

    file = fopen(filename, "r");
    if (file) {
        // 这里可以根据文件格式实现具体的读取逻辑
        // 目前只是简单打开并关闭，实际需要从文件中读取并填充 year_tasks 结构体
        fclose(file);
    }

    return year_tasks;
}