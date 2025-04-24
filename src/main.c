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
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", current_time);
    printf("Current time: %s\n", time_str);
}

int main(int argc, char *argv[])
{
    printf("Welcome to TaskList!----");
    display_current_time();
    printf("\n");
    int year, month, day;
    get_current_date(&year, &month, &day);
    printf("Today is %d-%d-%d\n", year, month, day);
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
        task_year->months[month - 1]->days != NULL &&
        day - 1 >= 0 && day - 1 < task_year->months[month - 1]->num_days)
    {
        index = task_year->months[month - 1]->days[day - 1]->size;
    }
    printf("index: %d\n", index);
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