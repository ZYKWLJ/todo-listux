// #include <spdlog/spdlog.h>
// #include <spdlog/sinks/stdout_color_sinks.h>

// // 声明函数
// void log_init();
// void log_info(const char *message);
// void log_error(const char *message);
#include "../include.h"
#define LOG
#ifdef LOG
#define LOG_PRINT(format, ...) printf("[%s %s %s:%d] " format, __DATE__, __TIME__, __FILE__,__LINE__, ##__VA_ARGS__)
#else
#define LOG_PRINT(format, ...) \
    do                         \
    {                          \
    } while (0)
#endif

// #define COMMAND_ERROR(format, ...) printf("[%s --Unkown Comand] ")