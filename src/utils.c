#include "../include/include.h"
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

void COMMAND_ERROR(C_command command, const char *format, ...)
{
    /**
     * func descp: 方式第一个命令是全路径的可执行文件，这里直接使用tl替换之，确保win和linux的兼容性
     */
    RED_PRINT("tl");
    for (int i = 1 /*直接从第一个开始，兼容性*/; i < command->argc; i++)
    {
        RED_PRINT(" %s", command->argv[i]);
    }

    va_list args;
    va_start(args, format);

    // 输出格式化的错误信息
    vprintf(format, args);
    printf("\n");

    va_end(args);
}