#include "../include/include.h"
extern S_setting setting;
int color_enabled()
{
    // 这里假设您有一个全局的 setting 结构体
    // 实际实现可能需要根据您的项目结构调整
    return (setting != NULL &&
            setting->color != NULL &&
            strcmp(setting->color->value_set, "on") == 0);
}
void *checked_malloc(int len)
{
    void *p = calloc(1, len);
    if (!p)
    {
        fprintf(stderr, "\nRan out of memory!\n");
        exit(1);
    }
    return p;
}
// extern S_setting setting;
void COMMAND_ERROR(C_command command, const char *format, ...)
{
    /**
     * func descp: 方式第一个命令是全路径的可执行文件，这里直接使用tl替换之，确保win和linux的兼容性
     */
    // if (strcmp(setting->color->value_set, "on") == 0)
    if (color_enabled())
    {
        RED_PRINT("tl");
        for (int i = 1 /*直接从第一个开始，兼容性*/; i < command->argc; i++)
        {
            RED_PRINT(" %s", command->argv[i]);
        }
    }
    else
    {
        printf("tl");
        for (int i = 1 /*直接从第一个开始，兼容性*/; i < command->argc; i++)
        {
            printf(" %s", command->argv[i]);
        }
    }

    va_list args;
    va_start(args, format);

    // 输出格式化的错误信息
    vprintf(format, args);
    printf("\n");

    va_end(args);
}

#if 0
 if (strcmp(setting->time->value_set, "on") != 0)
            {
                if (index == 1)
                {
                    printf("\n");
                }
                LOG_PRINT("time is off\n");
                printf(" %s%2d. %s %s%s\n",
                       color_prefix,
                       index,
                       status,
                       part[1],
                       color_suffix);
            }
            else
            {
                LOG_PRINT("time is on\n");

#endif