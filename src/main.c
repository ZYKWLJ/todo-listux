#include "../include/include.h"
// 实时显示时间的函数
void display_current_time()
{
    time_t now;
    struct tm *current_time;

    // 获取当前时间
    time(&now);

    // 将时间转换为结构体
    current_time = localtime(&now);

    // 格式化并输出时间
    char time_str[26];
    // strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", current_time);
    strftime(time_str, sizeof(time_str), "%H:%M:%S", current_time);
    printf("Current time: %s\n", time_str);
}

int main(int argc, char *argv[])
{
    // printf("Welcome to TaskList!----");
    display_current_time();
    int year, month, day;
    get_current_date(&year, &month, &day);
    // printf("Today is %d-%d-%d\n", year, month, day);
    TaskYear *task_year = load_data(year);

    if (argc < 2)
    {
        // 如果没有提供足够的命令行参数，显示帮助信息
        help();
        return 1;
    }
    // 修正这里
    int index = 0;
    if (task_year != NULL && task_year->months != NULL &&
        month - 1 >= 0 && month - 1 < 12 &&
        &task_year->months[month - 1].days != NULL &&
        day - 1 >= 0 && day - 1 < task_year->months[month - 1].num_days)
    {
        index = task_year->months[month - 1].days[day - 1].size;
    }
    // printf("index: %d\n", index);
    // 解析命令行参数并调用相应的处理函数
    if (strcmp(argv[1], "show") == 0 || strcmp(argv[1], "s") == 0)
    {
        display_current_date_tasks(task_year, year, month, day);
    }
    else if (strcmp(argv[1], "add") == 0 || strcmp(argv[1], "a") == 0)
    {
        add(task_year, year, month, day, index, argc, argv);
    }
    else if (strcmp(argv[1], "delete") == 0 || strcmp(argv[1], "d") == 0)
    {
        delete_(task_year, year, month, day, index, argc, argv);
    }
    else if (strcmp(argv[1], "modify") == 0 || strcmp(argv[1], "m") == 0)
    {
        modify(task_year, year, month, day, index, argc, argv);
    }
    else if (strcmp(argv[1], "done") == 0)
    {
        done(task_year, year, month, day, index, argc, argv);
    }
    else if (strcmp(argv[1], "undo") == 0) // 撤销完成标记
    {
        undo(task_year, year, month, day, index, argc, argv);
    }else if (strcmp(argv[1], "set") == 0) // 进入设置
    {
        set_setting(argc, argv);
    }
    else if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "h") == 0)
    {
        help();
    }
    else
    {
        printf("Unknown command: %s\n", argv[1]);
        help();
    }
    save_data(task_year, year);

    return 0;
}
// 编译最原始的命令！
// gcc D:/3software/todo-listux/src/main.c D:/3software/todo-listux/src/database/add_data.c D:/3software/todo-listux/src/database/delete_data.c D:/3software/todo-listux/src/database/load_data.c D:/3software/todo-listux/src/database/modify_data.c D:/3software/todo-listux/src/database/save_data.c D:/3software/todo-listux/src/display/help.c D:/3software/todo-listux/src/display/show_data.c D:/3software/todo-listux/src/execute/add.c D:/3software/todo-listux/src/execute/delete.c D:/3software/todo-listux/src/execute/done.c D:/3software/todo-listux/src/execute/find.c D:/3software/todo-listux/src/execute/modify.c D:/3software/todo-listux/src/execute/undo.c D:/3software/todo-listux/src/strcutures/TaskDay.c D:/3software/todo-listux/src/strcutures/TaskMonth.c D:/3software/todo-listux/src/strcutures/TaskYear.c D:/3software/todo-listux/src/tools/MONTH.c D:/3software/todo-listux/src/tools/tools.c -o D:\3software\todo-listux\bin\tl
// gcc D:/3software/todo-listux/src/main.c D:/3software/todo-listux/src/database/add_data.c D:/3software/todo-listux/src/database/delete_data.c D:/3software/todo-listux/src/database/load_data.c D:/3software/todo-listux/src/database/modify_data.c D:/3software/todo-listux/src/database/save_data.c D:/3software/todo-listux/src/display/help.c D:/3software/todo-listux/src/display/show_data.c D:/3software/todo-listux/src/execute/add.c D:/3software/todo-listux/src/execute/delete.c D:/3software/todo-listux/src/execute/done.c D:/3software/todo-listux/src/execute/find.c D:/3software/todo-listux/src/execute/modify.c D:/3software/todo-listux/src/execute/undo.c D:/3software/todo-listux/src/strcutures/TaskDay.c D:/3software/todo-listux/src/strcutures/TaskMonth.c D:/3software/todo-listux/src/strcutures/TaskYear.c D:/3software/todo-listux/src/tools/MONTH.c D:/3software/todo-listux/src/tools/tools.c -o D:\3software\todo-listux\bin\tl
// gcc D:/3software/todo-listux/src/main.c D:/3software/todo-listux/src/database/add_data.c D:/3software/todo-listux/src/database/delete_data.c D:/3software/todo-listux/src/database/load_data.c D:/3software/todo-listux/src/database/modify_data.c D:/3software/todo-listux/src/database/save_data.c D:/3software/todo-listux/src/display/help.c D:/3software/todo-listux/src/display/show_data.c D:/3software/todo-listux/src/execute/add.c D:/3software/todo-listux/src/execute/delete.c D:/3software/todo-listux/src/execute/done.c D:/3software/todo-listux/src/execute/find.c D:/3software/todo-listux/src/execute/modify.c D:/3software/todo-listux/src/execute/undo.c D:/3software/todo-listux/src/strcutures/TaskDay.c D:/3software/todo-listux/src/strcutures/TaskMonth.c D:/3software/todo-listux/src/strcutures/TaskYear.c D:/3software/todo-listux/src/tools/MONTH.c D:/3software/todo-listux/src/tools/tools.c -o D:\3software\todo-listux\bin\tl
// gcc D:/3software/todo-listux-1/todo-listux/src/main.c D:/3software/todo-listux-1/todo-listux/src/database/add_data.c D:/3software/todo-listux-1/todo-listux/src/database/delete_data.c D:/3software/todo-listux-1/todo-listux/src/database/load_data.c D:/3software/todo-listux-1/todo-listux/src/database/modify_data.c D:/3software/todo-listux-1/todo-listux/src/database/save_data.c D:/3software/todo-listux-1/todo-listux/src/display/help.c D:/3software/todo-listux-1/todo-listux/src/display/show_data.c D:/3software/todo-listux-1/todo-listux/src/execute/add.c D:/3software/todo-listux-1/todo-listux/src/execute/delete.c D:/3software/todo-listux-1/todo-listux/src/execute/done.c D:/3software/todo-listux-1/todo-listux/src/execute/find.c D:/3software/todo-listux-1/todo-listux/src/execute/modify.c D:/3software/todo-listux-1/todo-listux/src/execute/undo.c D:/3software/todo-listux-1/todo-listux/src/strcutures/TaskDay.c D:/3software/todo-listux-1/todo-listux/src/strcutures/TaskMonth.c D:/3software/todo-listux-1/todo-listux/src/strcutures/TaskYear.c D:/3software/todo-listux-1/todo-listux/src/tools/MONTH.c D:/3software/todo-listux-1/todo-listux/src/tools/tools.c -o D:\3software\todo-listux-1\todo-listux\bin\tl
// D:/3software/todo-listux-1/todo-listux/src/main.c