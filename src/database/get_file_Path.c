#include "../../include/include.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <errno.h>

#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#endif

#define MAX_PATH 260
// #define LOG1

// 获取应用数据目录（跨平台）
const char *get_appdata_path(int year, FILE_TYPE file_type) // 通用，如果是date类型，还需要使用year以判断进一层路径，如果是setting类型，就直接返回路径
{
    char *path = (char *)malloc(MAX_PATH * sizeof(char));
    if (path == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    path[0] = '\0';

#ifdef _WIN32
    // Windows获取AppData路径
    wchar_t wpath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, wpath)))
    {
        WideCharToMultiByte(CP_UTF8, 0, wpath, -1, path, MAX_PATH, NULL, NULL);
        strcat(path, "\\tl");
        // 确保目录存在
        _mkdir(path);
    }
    else
    {
        strcpy(path, ".\\data"); // 回退到当前目录
        _mkdir(path);
    }
#else
    // Linux/macOS使用/tmp/tl
    strcpy(path, "/tmp/tl");
    if (mkdir(path, 0755) == -1 && errno != EEXIST)
    {
        perror("Failed to create directory");
    }
#endif

    if (file_type == DATE_FILE)
    {
        char year_str[10];
        snprintf(year_str, sizeof(year_str), "%d", year);
#ifdef _WIN32
        strcat(path, "\\");
#else
        strcat(path, "/");
#endif
        strcat(path, year_str);
        if (create_directory(path) != 0)
        {
            fprintf(stderr, "Failed to create year directory: %s\n", path);
        }
        // 添加 DATE_FILE 对应的文件名
        char filename[20];
        snprintf(filename, sizeof(filename), "%d.dat", year);
#ifdef _WIN32
        strcat(path, "\\");
#else
        strcat(path, "/");
#endif
        strcat(path, filename);
    }
    else if (file_type == SETTING_FILE)
    {
        // 添加 SETTING_FILE 对应的文件名
#ifdef _WIN32
        strcat(path, "\\");
#else
        strcat(path, "/");
#endif
        strcat(path, "setting.ini");
    }

#ifdef LOG1
    printf("%s,%s,%d,AppData path: %s\n", __FILE__, __func__, __LINE__, path);
#endif
    return path;
}

// 跨平台安全的目录创建函数
int create_directory(const char *path)
{
#ifdef _WIN32
    // 将UTF-8路径转换为宽字符
    wchar_t wpath[MAX_PATH];
    if (MultiByteToWideChar(CP_UTF8, 0, path, -1, wpath, MAX_PATH) == 0)
    {
        fprintf(stderr, "路径转换失败: %d\n", GetLastError());
        return -1;
    }

    // 尝试直接创建目录
    if (_wmkdir(wpath) == 0)
    {
#ifdef LOG
        // printf("cerate_directory: %s\n");
        printf("%s,%s,%d,cerate_directory: %s\n", __FILE__, __func__, __LINE__, "successed!");
#endif

        return 0; // 创建成功
    }

    // 处理错误情况
    switch (errno)
    {
    case EEXIST:
        return 0; // 目录已存在
    case ENOENT:
    {
        // 父目录不存在，尝试递归创建
        char parent[MAX_PATH];
        strncpy(parent, path, MAX_PATH);
        char *slash = strrchr(parent, '\\');
        if (slash)
        {
            *slash = '\0';
            return create_directory(parent) == 0 ? _wmkdir(wpath) == 0 || errno == EEXIST ? 0 : -1 : -1;
        }
        return -1;
    }
    default:
        fprintf(stderr, "无法创建目录 '%s': %s\n", path, strerror(errno));
        return -1;
    }
#else
    // Linux/macOS使用mkdir -p
    char command[512];
    snprintf(command, sizeof(command), "mkdir -p \"%s\"", path);
    return system(command);
#endif
}