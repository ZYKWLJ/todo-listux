#ifndef UTILS_H
#define UTILS_H
#include "include.h"
/**
 * func descp: 丐版，直接按照红色打印原来的命令
 */
void COMMAND_ERROR(C_command command, const char *format, ...);
/**
 * description: 日志模块
 * author:EthanYankang
 * create time:2025/05/01 14:41:31
 */

// #define LOG
#ifdef LOG
// #define LOG_PRINT(msg) printf("[LOG %s %s %s:%d] %s\n" __DATE__, __TIME__, __FILE__, __LINE__, msg)
#define LOG_PRINT(...)                                                    \
    printf("[LOG %s %s %s:%d] ", __DATE__, __TIME__, __FILE__, __LINE__); \
    printf(__VA_ARGS__);                                                  \
    printf("\n")
#else
#define LOG_PRINT(...) \
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

// #define TODO
#ifdef TODO
#define TODO_PRINT(...)                                                    \
    printf("[TODO %s %s %s:%d] ", __DATE__, __TIME__, __FILE__, __LINE__); \
    printf(__VA_ARGS__);                                                   \
    printf("\n")
#else
#define TODO_PRINT(...) \
    do                  \
    {                   \
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