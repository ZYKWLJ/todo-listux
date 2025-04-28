#include "../include/include.h"
// #define LOG
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
    strftime(time_str, sizeof(time_str), "%H:%M:%S", current_time);
    printf("Current time: %s\n", time_str);
}

int main(int argc, char *argv[])
{
    // printf("Welcome to TaskList!----");
    display_current_time(); // 获取设置文件
    Setting *setting = (Setting *)malloc(sizeof(Setting));
    // 指令个数判断再次结束
    judge_command_nums(setting, argc, argv);
    int year, month, week, day;
    get_current_date(&year, &month, &day);
    week = calculate_week_number(day);
    // 获取当前日期
    Date *date = (Date *)malloc(sizeof(Date));
    date->year = year;
    date->month = month;
    date->week = week;
    date->day = day;
    date->error = 0;
    // 获取总文件数据
    Total_File_Year_Date *total_file_year_date = (Total_File_Year_Date *)malloc(sizeof(Total_File_Year_Date));

    // 初始化数据类型文件
    Date_Type *date_type = (Date_Type *)malloc(sizeof(Date_Type));
    *date_type = CURRENT_DAY;                                                                                       // 默认的日期类型
    lexer(date /*这是指定的日期，不指定的话默认为当前日期*/, date_type, total_file_year_date, setting, argc, argv); // 这就是完备的集合了！
    free(date);
    free(date_type);
    free(total_file_year_date);
}

// 编译最原始的命令！
// gcc D:/3software/todo-listux/src/main.c D:/3software/todo-listux/src/database/add_data.c D:/3software/todo-listux/src/database/delete_data.c D:/3software/todo-listux/src/database/load_data.c D:/3software/todo-listux/src/database/modify_data.c D:/3software/todo-listux/src/database/save_data.c D:/3software/todo-listux/src/display/help.c D:/3software/todo-listux/src/display/show_data.c D:/3software/todo-listux/src/execute/add.c D:/3software/todo-listux/src/execute/delete.c D:/3software/todo-listux/src/execute/done.c D:/3software/todo-listux/src/execute/find.c D:/3software/todo-listux/src/execute/modify.c D:/3software/todo-listux/src/execute/undo.c D:/3software/todo-listux/src/strcutures/TaskDay.c D:/3software/todo-listux/src/strcutures/TaskMonth.c D:/3software/todo-listux/src/strcutures/TaskYear.c D:/3software/todo-listux/src/tools/MONTH.c D:/3software/todo-listux/src/tools/tools.c -o D:\3software\todo-listux\bin\tl
// gcc D:/3software/todo-listux/src/main.c D:/3software/todo-listux/src/database/add_data.c D:/3software/todo-listux/src/database/delete_data.c D:/3software/todo-listux/src/database/load_data.c D:/3software/todo-listux/src/database/modify_data.c D:/3software/todo-listux/src/database/save_data.c D:/3software/todo-listux/src/display/help.c D:/3software/todo-listux/src/display/show_data.c D:/3software/todo-listux/src/execute/add.c D:/3software/todo-listux/src/execute/delete.c D:/3software/todo-listux/src/execute/done.c D:/3software/todo-listux/src/execute/find.c D:/3software/todo-listux/src/execute/modify.c D:/3software/todo-listux/src/execute/undo.c D:/3software/todo-listux/src/strcutures/TaskDay.c D:/3software/todo-listux/src/strcutures/TaskMonth.c D:/3software/todo-listux/src/strcutures/TaskYear.c D:/3software/todo-listux/src/tools/MONTH.c D:/3software/todo-listux/src/tools/tools.c -o D:\3software\todo-listux\bin\tl
// gcc D:/3software/todo-listux/src/main.c D:/3software/todo-listux/src/database/add_data.c D:/3software/todo-listux/src/database/delete_data.c D:/3software/todo-listux/src/database/load_data.c D:/3software/todo-listux/src/database/modify_data.c D:/3software/todo-listux/src/database/save_data.c D:/3software/todo-listux/src/display/help.c D:/3software/todo-listux/src/display/show_data.c D:/3software/todo-listux/src/execute/add.c D:/3software/todo-listux/src/execute/delete.c D:/3software/todo-listux/src/execute/done.c D:/3software/todo-listux/src/execute/find.c D:/3software/todo-listux/src/execute/modify.c D:/3software/todo-listux/src/execute/undo.c D:/3software/todo-listux/src/strcutures/TaskDay.c D:/3software/todo-listux/src/strcutures/TaskMonth.c D:/3software/todo-listux/src/strcutures/TaskYear.c D:/3software/todo-listux/src/tools/MONTH.c D:/3software/todo-listux/src/tools/tools.c -o D:\3software\todo-listux\bin\tl
// gcc D:/3software/todo-listux-1/todo-listux/src/main.c D:/3software/todo-listux-1/todo-listux/src/database/add_data.c D:/3software/todo-listux-1/todo-listux/src/database/delete_data.c D:/3software/todo-listux-1/todo-listux/src/database/load_data.c D:/3software/todo-listux-1/todo-listux/src/database/modify_data.c D:/3software/todo-listux-1/todo-listux/src/database/save_data.c D:/3software/todo-listux-1/todo-listux/src/display/help.c D:/3software/todo-listux-1/todo-listux/src/display/show_data.c D:/3software/todo-listux-1/todo-listux/src/execute/add.c D:/3software/todo-listux-1/todo-listux/src/execute/delete.c D:/3software/todo-listux-1/todo-listux/src/execute/done.c D:/3software/todo-listux-1/todo-listux/src/execute/find.c D:/3software/todo-listux-1/todo-listux/src/execute/modify.c D:/3software/todo-listux-1/todo-listux/src/execute/undo.c D:/3software/todo-listux-1/todo-listux/src/strcutures/TaskDay.c D:/3software/todo-listux-1/todo-listux/src/strcutures/TaskMonth.c D:/3software/todo-listux-1/todo-listux/src/strcutures/TaskYear.c D:/3software/todo-listux-1/todo-listux/src/tools/MONTH.c D:/3software/todo-listux-1/todo-listux/src/tools/tools.c -o D:\3software\todo-listux-1\todo-listux\bin\tl
// gcc D:/3software/todo-listux-1/todo-listux/src/main.c D:/3software/todo-listux-1/todo-listux/src/database/add_data.c D:/3software/todo-listux-1/todo-listux/src/database/delete_data.c D:/3software/todo-listux-1/todo-listux/src/database/load_data.c D:/3software/todo-listux-1/todo-listux/src/database/modify_data.c D:/3software/todo-listux-1/todo-listux/src/database/save_data.c D:/3software/todo-listux-1/todo-listux/src/display/help.c D:/3software/todo-listux-1/todo-listux/src/display/show_data.c D:/3software/todo-listux-1/todo-listux/src/execute/add.c D:/3software/todo-listux-1/todo-listux/src/execute/delete.c D:/3software/todo-listux-1/todo-listux/src/execute/done.c D:/3software/todo-listux-1/todo-listux/src/execute/find.c D:/3software/todo-listux-1/todo-listux/src/execute/modify.c D:/3software/todo-listux-1/todo-listux/src/execute/undo.c D:/3software/todo-listux-1/todo-listux/src/strcutures/TaskDay.c D:/3software/todo-listux-1/todo-listux/src/strcutures/TaskMonth.c D:/3software/todo-listux-1/todo-listux/src/strcutures/TaskYear.c D:/3software/todo-listux-1/todo-listux/src/tools/MONTH.c D:/3software/todo-listux-1/todo-listux/src/tools/tools.c -o D:\3software\todo-listux-1\todo-listux\bin\tl
// D:/3software/todo-listux-1/todo-listux/src/main.c

//  python D:\3software\todo-listux-1\todo-listux\py\gcc.py