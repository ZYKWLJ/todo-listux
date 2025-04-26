#include "../../include/include.h"
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
// 保存设置到文件
void save_setting(Setting *setting)
{
    char filename[MAX_PATH];
    const char *base_path = get_appdata_path();

    // 构建 settings.ini 文件路径
#ifdef _WIN32
    snprintf(filename, sizeof(filename), "%s\\settings.ini", base_path);
#else
    snprintf(filename, sizeof(filename), "%s/settings.ini", base_path);
#endif

    // 后续创建目录、文件写入等代码保持不变
    // 创建目录（如果不存在）
    if (create_directory(base_path) != 0)
    {
        fprintf(stderr, "can't create dir: %s\n", base_path);
        return;
    }

    FILE *file = fopen(filename, "w");
    if (file)
    {
        fprintf(file, "color=%s\n", setting->color);
        fprintf(file, "show=%s\n", setting->show);
        fclose(file);
        
        LOG_PRINT("saving settings to file: %s\n", filename);
        LOG_PRINT("color: %s\n", setting->color);
        LOG_PRINT("show: %s\n", setting->show);
        LOG_PRINT("settings saved in %s\n", filename);
        printf("settings saved\n");
    }
    else
    {
        fprintf(stderr, "can open file %s to write\n", filename);
    }
}

// 从文件读取设置到结构体
Setting *read_setting(Setting *setting)
{
    char filename[MAX_PATH];
    const char *base_path = get_appdata_path();

    // 构建 settings.ini 文件路径
#ifdef _WIN32
    snprintf(filename, sizeof(filename), "%s\\settings.ini", base_path);
#else
    snprintf(filename, sizeof(filename), "%s/settings.ini", base_path);
#endif

    FILE *file = fopen(filename, "r");
    if (file)
    {
        char line[256];
        while (fgets(line, sizeof(line), file))
        {
            char key[64], value[64];
            if (sscanf(line, "%63[^=]=%63[^\n]", key, value) == 2)
            {
                if (strcmp(key, "color") == 0)
                {
                    strncpy(setting->color, value, sizeof(setting->color) - 1);
                    setting->color[sizeof(setting->color) - 1] = '\0';
                }
                else if (strcmp(key, "show") == 0)
                {
                    strncpy(setting->show, value, sizeof(setting->show) - 1);
                    setting->show[sizeof(setting->show) - 1] = '\0';
                }
            }
        }
        #ifdef LOG
        LOG_PRINT("reading settings from file: %s\n", filename);
        LOG_PRINT("color: %s\n", setting->color);
        LOG_PRINT("show: %s\n", setting->show);
        #endif
        fclose(file);
        // printf("settings read from %s over\n", filename);
    }
    else
    {
        fprintf(stderr, "can't open file %s to read\n", filename);
    }

    // 添加返回语句，返回传入的 setting 指针
    return setting;
}

// int main()
// {
//     Setting setting;
//     read_setting(&setting);
//     return 0;
// }

// gcc D:\3software\todo-listux-1\todo-listux\src\database\save_setting.c D:\3software\todo-listux-1\todo-listux\src\database\filePath.c -o D:\3software\todo-listux-1\todo-listux\src\database\setting