#include "../../include/include.h"

// extern "C"
// {
//     void log_init()
//     {
//         auto logger = spdlog::stdout_color_mt("console");
//         // 你可以在这里进行更多的日志配置
//     }

//     void log_info(const char *message)
//     {
//         spdlog::get("console")->info(message);
//     }

//     void log_error(const char *message)
//     {
//         spdlog::get("console")->error(message);
//     }
// }
// #ifdef LOG
//     #define LOG_PRINT(format, ...) printf("[%s %s %s:%s :%d] " format, __DATE__, __TIME__, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
// #else
//     #define LOG_PRINT(format, ...) do {} while(0)
// #endif

// int main() {
//     LOG_PRINT("This is a log message.\n");
//     return 0;
// }

// python D:\3software\todo-listux-1\todo-listux\py\gcc.py
// gcc D:/3software/todo-listux-1/todo-listux/src/main.c D:/3software/todo-listux-1/todo-listux/src/database/add_data.c D:/3software/todo-listux-1/todo-listux/src/database/delete_data.c D:/3software/todo-listux-1/todo-listux/src/database/filePath.c D:/3software/todo-listux-1/todo-listux/src/database/load_data.c D:/3software/todo-listux-1/todo-listux/src/database/modify_data.c D:/3software/todo-listux-1/todo-listux/src/database/save_data.c D:/3software/todo-listux-1/todo-listux/src/database/save_setting.c D:/3software/todo-listux-1/todo-listux/src/display/help.c D:/3software/todo-listux-1/todo-listux/src/display/show_data.c D:/3software/todo-listux-1/todo-listux/src/execute/add.c D:/3software/todo-listux-1/todo-listux/src/execute/delete.c D:/3software/todo-listux-1/todo-listux/src/execute/done.c D:/3software/todo-listux-1/todo-listux/src/execute/find.c D:/3software/todo-listux-1/todo-listux/src/execute/modify.c D:/3software/todo-listux-1/todo-listux/src/execute/set_setting.c D:/3software/todo-listux-1/todo-listux/src/execute/undo.c D:/3software/todo-listux-1/todo-listux/src/log/log.c D:/3software/todo-listux-1/todo-listux/src/strcutures/setting.c D:/3software/todo-listux-1/todo-listux/src/strcutures/TaskDay.c D:/3software/todo-listux-1/todo-listux/src/strcutures/TaskMonth.c D:/3software/todo-listux-1/todo-listux/src/strcutures/TaskYear.c D:/3software/todo-listux-1/todo-listux/src/tools/MONTH.c D:/3software/todo-listux-1/todo-listux/src/tools/tools.c -o D:/3software/todo-listux-1/todo-listux/bin/tl