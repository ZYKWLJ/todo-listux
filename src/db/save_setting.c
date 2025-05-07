#include "../../include/include.h"
extern S_setting setting;
extern KV_ kv;
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