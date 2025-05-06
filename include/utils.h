#ifndef UTILS_H
#define UTILS_H
#include "include.h"

/**
 * description: 日志模块
 * author:EthanYankang
 * create time:2025/05/01 14:41:31
 */

#define LOG
#ifdef LOG
// #define LOG_PRINT(msg) printf("[LOG %s %s %s:%d] %s\n" __DATE__, __TIME__, __FILE__, __LINE__, msg)
#define LOG_PRINT(...) printf("[LOG %s %s %s:%d] ", __DATE__, __TIME__, __FILE__, __LINE__); printf(__VA_ARGS__); printf("\n")
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
#define TODO_PRINT(msg) printf("[TODO %s %s %s:%d] %s\n", __DATE__, __TIME__, __FILE__, __LINE__, msg)
#else
#define TODO_PRINT(msg) \
    do                  \
    {                   \
    } while (0)
#endif


void *checked_malloc(int len) /*返回了通用指针 */;

#endif