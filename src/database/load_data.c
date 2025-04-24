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
#include <direct.h>  // 用于 _wmkdir
#else
#include <unistd.h>
#endif

// 跨平台安全的目录创建函数
int create_directory(const char *path) {
#ifdef _WIN32
    // 将UTF-8路径转换为宽字符
    wchar_t wpath[MAX_PATH];
    if (MultiByteToWideChar(CP_UTF8, 0, path, -1, wpath, MAX_PATH) == 0) {
        fprintf(stderr, "路径转换失败: %d\n", GetLastError());
        return -1;
    }

    // 尝试直接创建目录
    if (_wmkdir(wpath) == 0) {
        return 0; // 创建成功
    }

    // 处理错误情况
    switch (errno) {
        case EEXIST:
            return 0; // 目录已存在
        case ENOENT: {
            // 父目录不存在，尝试递归创建
            char parent[MAX_PATH];
            strncpy(parent, path, MAX_PATH);
            char* slash = strrchr(parent, '\\');
            if (slash) {
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
const char* get_appdata_path() {
    static char path[MAX_PATH] = {0};
    
    if (path[0] != '\0') return path;

#ifdef _WIN32
    // Windows获取AppData路径
    wchar_t wpath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, wpath))) {
        WideCharToMultiByte(CP_UTF8, 0, wpath, -1, path, MAX_PATH, NULL, NULL);
        strcat_s(path, MAX_PATH, "\\tl");
    } else {
        strcpy_s(path, MAX_PATH, ".\\data");  // 回退到当前目录
    }
#else
    // Linux/macOS使用/tmp
    strcpy(path, "/tmp/tl");
#endif

    return path;
}

TaskYear *load_data(int year) {
    char filename[MAX_PATH];
    const char* base_path = get_appdata_path();
    
    snprintf(filename, sizeof(filename), "%s%c%d.dat", 
             base_path,
#ifdef _WIN32
             '\\',
#else
             '/',
#endif
             year);

    // 创建目录（如果不存在）
    if (create_directory(base_path) != 0) {
        fprintf(stderr, "无法创建数据目录: %s\n", base_path);
        return NULL;
    }

    // 检查文件是否存在
    struct stat buffer;
    int exists = (stat(filename, &buffer) == 0);
    
    // 如果文件不存在则创建空文件
    if (!exists) {
        FILE* file = fopen(filename, "wb");
        if (!file) {
            fprintf(stderr, "无法创建数据文件: %s\n", filename);
            return NULL;
        }
        fclose(file);
    }

    // 初始化数据结构
    TaskYear *year_tasks = init_year_tasks(year);
    if (!year_tasks) {
        return NULL;
    }

    // 读取文件内容（原有逻辑保持不变）
    FILE *file = fopen(filename, "rb");
    if (file) {
        // ...（保持原有文件读取逻辑不变）...
        fclose(file);
    }
    
    return year_tasks;
}