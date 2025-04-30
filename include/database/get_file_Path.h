#ifndef FILE_PATH_H
#define FILE_PATH_H
#include "../include.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#include <direct.h>

#else
#include <unistd.h>
#include <sys/stat.h>
#endif
#define MAX_PATH 260
typedef enum FILE_TYPE
{
    DATE_FILE,
    SETTING_FILE,
} FILE_TYPE;

// 获取应用数据目录（跨平台）
char *get_appdata_path(int year, FILE_TYPE file_type);
// 跨平台安全的目录创建函数
int create_directory(const char *path);
#endif