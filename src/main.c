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
// 要做什么事，有什么，做什么，怎么做。有文件(加载的数据文件、配置文件)、输入参数。做什么：执行命令。通过什么做：执行节点。
// 所以所有的参数最多只有3个，超过了，就是说明自己没想清楚！

int main(int argc, char *argv[])
{
#ifdef draft
// All_Files*all_files,Node*node,Command *command
#endif
    // 0.欲加载配置文件，先创建总文件
    // 1.先获取日期
    Date *date = (Date *)malloc(sizeof(Date));
    {
        date->date_type = CURRENT_DAY; // 默认设置为当天
        date->error = ERROR_DATE_TYPE;
        get_current_date(date);
    }
    LOG_PRINT("%s", "Date malloc passed!!\n");
    display_current_time();
    // 2.之后再加载文件，init All_files
    All_Files *all_files = (All_Files *)malloc(sizeof(All_Files));

    {
        init_all_files(all_files, date);
    }
    load_config(all_files->setting, get_appdata_path(0, SETTING_FILE) /*在这个路径下加载配置文件*/);
    load_all_files(all_files, date);
    // 3.再构造命令节点
    NODE *node = (NODE *)malloc(sizeof(NODE));
    {
        init_node1(node, date);
    }
    LOG_PRINT("%s", "node malloc passed!!\n");

    LOG_PRINT("%s", "All_Files malloc passed!!\n");
    // 4.最后在构造命令，解析+判断，因为这里的判断会涉及文件，所以要先加载文件，虽然每次执行一次都要加载，但是为了统一，只有这样做了！
    Command *command = (Command *)malloc(sizeof(Command));
    {
        set_command(command, argc, argv);
    }
    LOG_PRINT("%s", "Command malloc passed!!\n");
    // 4.指令个数判断判断(同时解析了指令类型和节点)
    parse_command(node, all_files, command);
    LOG_PRINT("%s", "parse_command passed!!\n");
    // 5.默认的日期类型
    execute(all_files, node, command); // 这就是完备的集合了！
    LOG_PRINT("%s", "execute passed!!\n");
}
//  python D:\3software\todo-listux-1\todo-listux\py\gcc.py