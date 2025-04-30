#include "../../../include/include.h"
void load_config(Setting *setting, const char *path)
{
    // 检查配置文件是否存在，如果不存在则创建并写入默认配置
    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        LOG_PRINT("setting file not found, creating default config file...\n");
        fp = fopen(path, "w");
        if (fp == NULL)
        {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
        // 写入默认配置
        fprintf(fp, "%s=%s\n", SETTING_COLOR_KEY, SETTING_COLOR_ALLOW_ON);
        fprintf(fp, "%s=%s\n", SETTING_SHOW_KEY, SETTING_SHOW_ALLOW_CURRENT_DAY);
        fclose(fp);
        // 重新打开文件以读取
        fp = fopen(path, "r");
        if (fp == NULL)
        {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
    }
    LOG_PRINT("loaded setting file ......\n");
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        LOG_PRINT("load line:%s", line);
        line[strcspn(line, "\n")] = 0;
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "=");
        // 这里的setting的key固定好了？对的，在前面的初始化中
        if (key != NULL && value != NULL)
        {
            if (strcmp(setting->color->key, key) == 0)
            {
                setting->color->value_set = strdup(value);
            }
            else if (strcmp(setting->show->key, key) == 0)
            {
                setting->show->value_set = strdup(value);
            }
            else
            {
                LOG_PRINT("load setting data Unknown key: %s\n", key);
                // 不直接退出程序，继续处理其他键值对
            }
        }
        else
        {
            LOG_PRINT("Invalid key-value pair in config file: %s\n", line);
        }
    }
    LOG_PRINT("setting file loaded successfullyl......\n");
    fclose(fp);
}