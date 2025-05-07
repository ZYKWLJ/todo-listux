#include "../../include/include.h"
extern S_setting setting;
/**
* func descp:
// 1.如果发现文件存在，就读取文件里面的数据，数据格式为k=v,读入到setting中
// 2.如果文件不存在，就创建文件，写入默认数据：
*/
void load_setting(const char *path)
{
    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        // 文件不存在，创建文件并写入默认数据
        fp = fopen(path, "w");
        if (fp == NULL)
        {
            perror("文件创建失败");
            return;
        }
        fprintf(fp, "color=on\n");
        fprintf(fp, "show=day\n");
        fclose(fp);

        // 同时将默认数据加载到setting中
        strcpy(setting->color->value_set, "on");
        strcpy(setting->show->value_set, "day");
    }
    else
    {
        // 文件存在，读取文件内容
        char line[100];
        while (fgets(line, sizeof(line), fp) != NULL)
        {
            char *key = strtok(line, "=");
            char *value = strtok(NULL, "\n");
            if (key != NULL && value != NULL)
            {
                if (strcmp(key, "color") == 0)
                {
                    strcpy(setting->color->value_set, value);
                }
                else if (strcmp(key, "show") == 0)
                {
                    strcpy(setting->show->value_set, value);
                }
            }
        }
        fclose(fp);
    }
}
