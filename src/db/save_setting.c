#include "../../include/include.h"
extern S_setting setting;
extern KV_ kv;
#if 0
void save_setting(const char *path, KV_ kv)
{
    FILE *fp = fopen(path, "r+");
    if (fp == NULL)
    {
        printf("%s open failed\n", path);
        exit(EXIT_FAILURE);
    }

    char line[10001] = {0};
    long line_start = 0; // 记录当前行的起始位置
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *p = strstr(line, "=");
        if (p == NULL)
            continue; // 没有找到 '=' 则跳过该行

        char key[10];
        strncpy(key, line, p - line);
        key[p - line] = '\0'; // 手动添加字符串结束符

        if (strcmp(key, kv->key) == 0)
        {
            // 记录当前文件指针位置
            long current_pos = ftell(fp);
            // 回到当前行的起始位置
            fseek(fp, line_start, SEEK_SET);
            // 清空当前行
            for (int i = 0; i < strlen(line); i++)
            {
                fputc(' ', fp);
            }
            // 回到当前行的起始位置
            fseek(fp, line_start, SEEK_SET);
            // 写入新的键值对
            fprintf(fp, "%s=%s\n", kv->key, kv->value);
            // 调整文件指针到原来的位置
            fseek(fp, current_pos, SEEK_SET);
        }
        line_start = ftell(fp); // 更新下一行的起始位置
    }
    LOG_PRINT("SET config over......");
    fclose(fp);
}
#endif
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