#include "../../include/include.h"
// 定义错误信息输出函数
void COMMAND_ERROR(Setting *setting, int argc, char *argv[])
{
    // 打印颜色前缀（如果设置颜色为"on"）
    if (setting != NULL && strcmp(setting->color->value_set, "on") == 0)
    {
        printf("%s", RED);
    }

    // 打印接收到的命令参数
    if (argc > 0)
    {
        printf("tl");
        for (int i = 0; i < argc; i++)
        {
            printf(" %s", argv[i]);
        }
    }

    // 打印错误后缀并重置颜色
    if (setting != NULL && strcmp(setting->color->value_set, "on") == 0)
    {
        printf("%s --Unknown command\n", RESET);
    }
    else
    {
        printf(" --Unknown command\n");
    }
}

// int main(int argc, char *argv[])
// {
//     // 初始化设置
//     Setting config = {.color = "on"}; // 启用彩色输出
//     COMMAND_ERROR(&config, argc - 1, argv + 1);

//     return 0;
// }