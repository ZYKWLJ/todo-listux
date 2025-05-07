#ifndef UTILS_H
#define UTILS_H
#include "include.h"
// void COMMAND_ERROR(Setting *setting, int argc, char *argv[])
// {
//     // 打印颜色前缀（如果设置颜色为"on"）
//     if (setting != NULL && strcmp(setting->color->value_set, "on") == 0)
//     {
//         printf("%s", RED);
//     }

//     // 打印接收到的命令参数
//     if (argc > 0)
//     {
//         printf("tl");
//         for (int i = 0; i < argc; i++)
//         {
//             printf(" %s", argv[i]);
//         }
//     }

//     // 打印错误后缀并重置颜色
//     if (setting != NULL && strcmp(setting->color->value_set, "on") == 0)
//     {
//         printf("%s --Unknown command\n", RESET);
//     }
//     else
//     {
//         printf(" --Unknown command\n");
//     }
// }
/**
 * func descp: 丐版，直接按照红色打印原来的命令
 */
void COMMAND_ERROR(C_command command, const char *format, ...);
/**
 * description: 日志模块
 * author:EthanYankang
 * create time:2025/05/01 14:41:31
 */

#define LOG
#ifdef LOG
// #define LOG_PRINT(msg) printf("[LOG %s %s %s:%d] %s\n" __DATE__, __TIME__, __FILE__, __LINE__, msg)
#define LOG_PRINT(...)                                                    \
    printf("[LOG %s %s %s:%d] ", __DATE__, __TIME__, __FILE__, __LINE__); \
    printf(__VA_ARGS__);                                                  \
    printf("\n")
#else
#define LOG_PRINT(msg) \
    do                 \
    {                  \
    } while (0)
#endif

/**
 * filename:util.h
 * description: TODO模块
 * author:EthanYankang
 * create time:2025/05/01 14:42:08
 */

#define TODO
#ifdef TODO
#define TODO_PRINT(...)                                                    \
    printf("[TODO %s %s %s:%d] ", __DATE__, __TIME__, __FILE__, __LINE__); \
    printf(__VA_ARGS__);                                                  \
    printf("\n")
#else
#define TODO_PRINT(msg) \
    do                 \
    {                  \
    } while (0)
#endif

/**
 * func descp: 红色打印，专注于错误信息
 */
// #define RED_PRINT(msg) printf("%s%s%s\n", RED, msg, RESET)
#define RED_PRINT(...)   \
    printf(RED);         \
    printf(__VA_ARGS__); \
    printf("%s", RESET);
void *checked_malloc(int len) /*返回了通用指针 */;


#endif