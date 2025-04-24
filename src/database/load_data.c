// #include "../../include/include.h"
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <errno.h>

// #ifdef _WIN32
// #include <windows.h>
// #include <shlobj.h>
// #include <direct.h>  // 用于 _wmkdir
// #else
// #include <unistd.h>
// #endif

// // 跨平台安全的目录创建函数
// int create_directory(const char *path) {
// #ifdef _WIN32
//     // 将UTF-8路径转换为宽字符
//     wchar_t wpath[MAX_PATH];
//     if (MultiByteToWideChar(CP_UTF8, 0, path, -1, wpath, MAX_PATH) == 0) {
//         fprintf(stderr, "路径转换失败: %d\n", GetLastError());
//         return -1;
//     }

//     // 尝试直接创建目录
//     if (_wmkdir(wpath) == 0) {
//         return 0; // 创建成功
//     }

//     // 处理错误情况
//     switch (errno) {
//         case EEXIST:
//             return 0; // 目录已存在
//         case ENOENT: {
//             // 父目录不存在，尝试递归创建
//             char parent[MAX_PATH];
//             strncpy(parent, path, MAX_PATH);
//             char* slash = strrchr(parent, '\\');
//             if (slash) {
//                 *slash = '\0';
//                 return create_directory(parent) == 0 ? _wmkdir(wpath) == 0 || errno == EEXIST ? 0 : -1 : -1;
//             }
//             return -1;
//         }
//         default:
//             fprintf(stderr, "无法创建目录 '%s': %s\n", path, strerror(errno));
//             return -1;
//     }
// #else
//     // Linux/macOS使用mkdir -p
//     char command[512];
//     snprintf(command, sizeof(command), "mkdir -p \"%s\"", path);
//     return system(command);
// #endif
// }

// // 获取应用数据目录（跨平台）
// const char* get_appdata_path() {
//     static char path[MAX_PATH] = {0};

//     if (path[0] != '\0') return path;

// #ifdef _WIN32
//     // Windows获取AppData路径
//     wchar_t wpath[MAX_PATH];
//     if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, wpath))) {
//         WideCharToMultiByte(CP_UTF8, 0, wpath, -1, path, MAX_PATH, NULL, NULL);
//         strcat_s(path, MAX_PATH, "\\tl");
//     } else {
//         strcpy_s(path, MAX_PATH, ".\\data");  // 回退到当前目录
//     }
// #else
//     // Linux/macOS使用/tmp
//     strcpy(path, "/tmp/tl");
// #endif

//     return path;
// }

// TaskYear *load_data(int year) {
//     char filename[MAX_PATH];
//     const char* base_path = get_appdata_path();

//     snprintf(filename, sizeof(filename), "%s%c%d.dat",
//              base_path,
// #ifdef _WIN32
//              '\\',
// #else
//              '/',
// #endif
//              year);

//     // 创建目录（如果不存在）
//     if (create_directory(base_path) != 0) {
//         fprintf(stderr, "无法创建数据目录: %s\n", base_path);
//         return NULL;
//     }

//     // 检查文件是否存在
//     struct stat buffer;
//     int exists = (stat(filename, &buffer) == 0);

//     // 如果文件不存在则创建空文件
//     if (!exists) {
//         FILE* file = fopen(filename, "wb");
//         if (!file) {
//             fprintf(stderr, "无法创建数据文件: %s\n", filename);
//             return NULL;
//         }
//         fclose(file);
//     }

//     // 初始化数据结构
//     TaskYear *year_tasks = init_year_tasks(year);
//     if (!year_tasks) {
//         return NULL;
//     }

//     // 读取文件内容（原有逻辑保持不变）
//     FILE *file = fopen(filename, "rb");
//     if (file) {
//         // ...（保持原有文件读取逻辑不变）...
//         fclose(file);
//     }

//     return year_tasks;
// }

#include "../../include/include.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#include <direct.h> // 用于 _wmkdir
#else
#include <unistd.h>
#endif

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

// 获取应用数据目录（跨平台）
const char *get_appdata_path()
{
    static char path[MAX_PATH] = {0};

    if (path[0] != '\0')
        return path;

#ifdef _WIN32
    // Windows获取AppData路径
    wchar_t wpath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, wpath)))
    {
        WideCharToMultiByte(CP_UTF8, 0, wpath, -1, path, MAX_PATH, NULL, NULL);
        strcat_s(path, MAX_PATH, "\\tl");
    }
    else
    {
        strcpy_s(path, MAX_PATH, ".\\data"); // 回退到当前目录
    }
#else
    // Linux/macOS使用/tmp
    strcpy(path, "/tmp/tl");
#endif

    return path;
}

TaskYear *load_data(int year)
{
    // printf("load_data....\n");
    char filename[MAX_PATH];
    const char *base_path = get_appdata_path();

    snprintf(filename, sizeof(filename), "%s%c%d.dat",
             base_path,
#ifdef _WIN32
             '\\',
#else
             '/',
#endif
             year);

    // 创建目录（如果不存在）
    if (create_directory(base_path) != 0)
    {
        fprintf(stderr, "无法创建数据目录: %s\n", base_path);
        return NULL;
    }

    struct stat buffer;
    int exists = (stat(filename, &buffer) == 0);
    FILE *file;
    if (!exists)
    {
        file = fopen(filename, "w");
        if (file)
        {
            fclose(file);
        }
    }

    TaskYear *year_tasks = init_year_tasks(year);
    if (!year_tasks)
    {
        return NULL;
    }

    file = fopen(filename, "r");
    if (file)
    {
        // 检查文件是否为空
        if (buffer.st_size == 0)
        {
            fclose(file);
            return year_tasks;
        }

        int loaded_year;
        if (fscanf(file, "%d\n", &loaded_year) != 1)
        {
            printf("Failed to read year from file.\n");
            fclose(file);
            free_year_tasks(year_tasks);
            return NULL;
        }

        if (loaded_year != year)
        {
            printf("Year in file does not match requested year.\n");
            fclose(file);
            free_year_tasks(year_tasks);
            return NULL;
        }

        for (int m = 0; m < 12; m++)
        {
            TaskMonth *month_tasks = year_tasks->months[m];
            for (int d = 0; d < month_tasks->num_days; d++)
            {
                TaskDay *day_tasks = month_tasks->days[d];
                int month_num, day_num, size, capacity;
                if (fscanf(file, "%d %d %d %d\n", &month_num, &day_num, &size, &capacity) != 4)
                {
                    printf("Failed to read day tasks information from file.\n");
                    fclose(file);
                    free_year_tasks(year_tasks);
                    return NULL;
                }

                // 检查并扩展容量
                while (size > day_tasks->capacity)
                {
                    expand_capacity(day_tasks);
                }

                day_tasks->size = size;
                day_tasks->capacity = capacity;

                for (int t = 0; t < size; t++)
                {
                    char line[256];
                    if (fgets(line, sizeof(line), file) == NULL)
                    {
                        printf("Failed to read task line from file.\n");
                        fclose(file);
                        free_year_tasks(year_tasks);
                        return NULL;
                    }
                    char *token = strtok(line, " ");
                    // 检查并扩展任务字符串容量
                    size_t content_length = strlen(token);
                    if (content_length >= MAX_TASK_CHAR_LENGTH)
                    {
                        char *new_task_str = (char *)realloc(day_tasks->task[t].task, (content_length + 1) * sizeof(char));
                        if (new_task_str == NULL)
                        {
                            printf("Memory allocation failed.\n");
                            fclose(file);
                            free_year_tasks(year_tasks);
                            return NULL;
                        }
                        day_tasks->task[t].task = new_task_str;
                    }
                    strcpy(day_tasks->task[t].task, token);
                    token = strtok(NULL, " \n");
                    day_tasks->task[t].is_done = atoi(token);
                }
            }
        }
        fclose(file);
    }
    // printf("Data loaded successfully.\n");
    return year_tasks;
}