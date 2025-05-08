#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#include <io.h>
#include <direct.h> // 添加这个头文件以使用 _wmkdir
#define open _open
#define close _close
#endif

#define MAX_PATH 260

// 文件类型枚举
typedef enum
{
    DATE_FILE,
    SETTING_FILE
} FILE_TYPE;

// 跨平台安全的目录创建函数
int create_directory(const char *path)
{
#ifdef _WIN32
    // 将 UTF-8 路径转换为宽字符
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
    char *p = (char *)path;
    char dir[MAX_PATH];
    int len = strlen(path);

    // 检查路径是否为空
    if (len == 0)
    {
        fprintf(stderr, "路径为空\n");
        return -1;
    }

    // 初始化目录字符串
    strcpy(dir, path);

    // 遍历路径，逐个创建目录
    for (p = dir + 1; *p; p++)
    {
        if (*p == '/')
        {
            *p = '\0';
            if (mkdir(dir, 0755) == -1 && errno != EEXIST)
            {
                perror("无法创建目录");
                return -1;
            }
            *p = '/';
        }
    }

    // 创建最后一个目录
    if (mkdir(dir, 0755) == -1 && errno != EEXIST)
    {
        perror("无法创建目录");
        return -1;
    }

    return 0;
#endif
}

// 获取应用数据目录（跨平台）
char *get_appdata_path(FILE_TYPE file_type)
{
    char *path = (char *)malloc(MAX_PATH * sizeof(char));
    if (path == NULL)
    {
        fprintf(stderr, "内存分配失败\n");
        return NULL;
    }
    path[0] = '\0';

#ifdef _WIN32
    // Windows 获取 AppData 路径
    wchar_t wpath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, wpath)))
    {
        WideCharToMultiByte(CP_UTF8, 0, wpath, -1, path, MAX_PATH, NULL, NULL);
        strcat(path, "\\tl");
        // 确保目录存在
        if (create_directory(path) != 0)
        {
            fprintf(stderr, "无法创建目录: %s\n", path);
            free(path);
            return NULL;
        }
    }
    else
    {
        strcpy(path, ".\\data"); // 回退到当前目录
        if (create_directory(path) != 0)
        {
            fprintf(stderr, "无法创建目录: %s\n", path);
            free(path);
            return NULL;
        }
    }
#else
    // Linux/macOS 使用 /tmp/tl
    strcpy(path, "/tmp/tl");
    if (create_directory(path) != 0)
    {
        fprintf(stderr, "无法创建目录: %s\n", path);
        free(path);
        return NULL;
    }
#endif

    if (file_type == DATE_FILE)
    {
#ifdef _WIN32
        strcat(path, "\\data.dat");
#else
        strcat(path, "/data.dat");
#endif
    }
    else if (file_type == SETTING_FILE)
    {
#ifdef _WIN32
        strcat(path, "\\setting.ini");
#else
        strcat(path, "/setting.ini");
#endif
    }

    return path;
}

// 创建文件并检查结果
int create_file(const char *path)
{
    int fd = open(path, O_CREAT | O_WRONLY, 0644);
    if (fd == -1)
    {
        perror("无法创建文件");
        return -1;
    }
    close(fd);
    return 0;
}
