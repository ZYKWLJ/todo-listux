#include "../include/include.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> // 用于检查文件是否存在

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

    printf("Saving settings to file: %s\n", filename);

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
        printf("Settings saved successfully.\n");
        printf("File path: %s\n", filename);
        printf("color: %s\n", setting->color);
        printf("show: %s\n", setting->show);
        // 检查文件是否存在
        struct stat st;
        if (stat(filename, &st) == 0) {
            printf("File exists, size: %ld bytes\n", (long)st.st_size);
        } else {
            perror("Failed to check file existence");
        }
    }
    else
    {
        fprintf(stderr, "can't open file %s to write\n", filename);
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

    printf("Reading settings from file: %s\n", filename);

    FILE *file = fopen(filename, "r");
    if (file)
    {
        char line[256];
        while (fgets(line, sizeof(line), file))
        {
            char key[64], value[64];
            if (sscanf(line, "%63[^=]=%63[^\n]", key, value) == 2)
            {
                printf("Read key: %s, value: %s\n", key, value);
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
        fclose(file);
        printf("Settings read successfully.\n");
    }
    else
    {
        fprintf(stderr, "can't open file %s to read\n", filename);
    }

    // 添加返回语句，返回传入的 setting 指针
    return setting;
}

// 设置设置
void set_setting(int argc, char **argv)
{
    if (argc == 3)
    {
        // 找到第一个 '=' 的位置
        char *equal_sign = strchr(argv[2], '=');
        if (equal_sign)
        {
            // 提取键和值
            char key[64];
            char value[64];
            strncpy(key, argv[2], equal_sign - argv[2]);
            key[equal_sign - argv[2]] = '\0';
            strcpy(value, equal_sign + 1);

            // 检查键是否在设置范围内
            if (!is_in_settings(key))
            {
                fprintf(stderr, "NO %s setting \n", key);
                return;
            }

            // 读取当前设置
            Setting setting;
            Setting* result = read_setting(&setting);
            if (result == NULL)
            {
                // 处理读取失败的情况
                return;
            }

            // 根据键更新设置
            if (strcmp(key, "color") == 0)
            {
                if (strcmp(value, "on") == 0 || strcmp(value, "off") == 0)
                {
                    strncpy(setting.color, value, sizeof(setting.color) - 1);
                    setting.color[sizeof(setting.color) - 1] = '\0';
                }
                else
                {
                    fprintf(stderr, "Invalid value for color setting. Expected 'on' or 'off'.\n");
                    return;
                }
            }
            else if (strcmp(key, "show") == 0)
            {
                // 检查值是否在设置范围内
                if (strcmp(value, "year") == 0 || strcmp(value, "month") == 0 ||
                    strcmp(value, "week") == 0 || strcmp(value, "day") == 0 ||
                    strcmp(value, "all") == 0)
                {
                    strncpy(setting.show, value, sizeof(setting.show) - 1);
                    setting.show[sizeof(setting.show) - 1] = '\0';
                }
                else
                {
                    fprintf(stderr, "Invalid value for show setting. Expected 'year','month', 'week', 'day', or 'all'.\n");
                    return;
                }
            }

            // 保存更新后的设置
            save_setting(&setting);
            printf("Setting updated successfully.\n");
        }
        else
        {
            fprintf(stderr, "Invalid setting format. Expected 'key=value'.\n");
        }
    }
    else if (argc != 3)
    {
        // 显示设置的正确方法
        fprintf(stderr, "Usage: %s <command> <setting>\n", argv[0]);
        fprintf(stderr, "Example: %s set color=yes\n", argv[0]);
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <command> [arguments]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "set") == 0)
    {
        set_setting(argc, argv);
    }
    else
    {
        fprintf(stderr, "Unrecognized command: %s\n", argv[1]);
    }

    return 0;
}