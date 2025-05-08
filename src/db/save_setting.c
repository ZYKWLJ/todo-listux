#include "../../include/include.h"
#ifndef _WIN32
extern S_setting setting;
extern KV_ kv;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#define PATH_SEP '\\'
#define mkdir(path, mode) _mkdir(path)
#else
#define PATH_SEP '/'
#endif

#define MAX_PATH 260

void save_setting(const char *path, KV_ kv)
{
    // 先读取整个文件到内存
    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        printf("%s open failed\n", path);
        exit(EXIT_FAILURE);
    }

    // 动态分配缓冲区（更安全的方式）
    char *content = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *tmp = open_memstream(&content, &len);
    if (tmp == NULL)
    {
        fclose(fp);
        printf("Memory stream open failed\n");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    bool found = false;

    // 逐行处理
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *p = strchr(line, '=');
        if (p != NULL)
        {
            *p = '\0'; // 临时终止key部分
            if (strcmp(line, kv->key) == 0)
            {
                fprintf(tmp, "%s=%s\n", kv->key, kv->value);
                found = true;
                continue;
            }
            *p = '='; // 恢复原样
        }
        fputs(line, tmp);
    }

    // 如果没找到键，添加新的
    if (!found)
    {
        fprintf(tmp, "%s=%s\n", kv->key, kv->value);
    }

    fclose(fp);
    fclose(tmp);

    // 写回文件
    fp = fopen(path, "w");
    if (fp == NULL)
    {
        free(content);
        printf("%s open failed\n", path);
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%s", content);
    fclose(fp);
    free(content);

    LOG_PRINT("SET config over......");
}

#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#define PATH_SEP '\\'
#define mkdir(path, mode) _mkdir(path)
#else
#define PATH_SEP '/'
#endif

#define MAX_PATH 260

extern S_setting setting;
extern KV_ kv;

void save_setting(const char *path, KV_ kv)
{
    // 先读取整个文件到内存
    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        printf("%s open failed\n", path);
        exit(EXIT_FAILURE);
    }

    // 使用临时文件替代内存流
    char temp_path[MAX_PATH + 5]; // 额外空间用于".tmp"后缀
    snprintf(temp_path, sizeof(temp_path), "%s.tmp", path);
    FILE *tmp = fopen(temp_path, "w");
    if (tmp == NULL)
    {
        fclose(fp);
        printf("Temporary file open failed\n");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    bool found = false;

    // 逐行处理
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *p = strchr(line, '=');
        if (p != NULL)
        {
            *p = '\0'; // 临时终止key部分
            if (strcmp(line, kv->key) == 0)
            {
                fprintf(tmp, "%s=%s\n", kv->key, kv->value);
                found = true;
                continue;
            }
            *p = '='; // 恢复原样
        }
        fputs(line, tmp);
    }

    // 如果没找到键，添加新的
    if (!found)
    {
        fprintf(tmp, "%s=%s\n", kv->key, kv->value);
    }

    fclose(fp);
    fclose(tmp);

    // 替换原文件
#ifdef _WIN32
    // Windows需要先删除原文件
    remove(path);
#endif
    if (rename(temp_path, path) != 0)
    {
        printf("无法替换原文件\n");
        remove(temp_path);
        exit(EXIT_FAILURE);
    }

    LOG_PRINT("SET config over......");
}

#endif