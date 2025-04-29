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
    // 1.先获取日期
    Date *date = (Date *)malloc(sizeof(Date));
    {
        date->date_type = CURRENT_DAY; // 默认设置为当天
        date->error = ERROR_DATE_TYPE;
        get_current_date(date);
    }
    LOG_PRINT("%s", "Date malloc passed!!\n");

    // printf("Welcome to TaskList!----");
    display_current_time();
    // 2.再解析命令，构造命令节点，防止命令是错的还加载，浪费资源
    NODE *node = (NODE *)malloc(sizeof(NODE));
    {
        DISPLAY_NODE *display_node = (DISPLAY_NODE *)malloc(sizeof(DISPLAY_NODE));
        {
            {
                display_node->date = (Date *)malloc(sizeof(Date));
                display_node->date = date;
            }
        }
        LOG_PRINT("%s", "display malloc passed!!\n");
        ADD_NODE *add_node = (ADD_NODE *)malloc(sizeof(ADD_NODE));
        {

            {
                add_node->date = (Date *)malloc(sizeof(Date));
                add_node->date = date;
                add_node->content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
            }
        }
        LOG_PRINT("%s", "add_node malloc passed!!\n");

        DELETE_NODE *delete_node = (DELETE_NODE *)malloc(sizeof(DELETE_NODE));
        {
            {
                delete_node->date = (Date *)malloc(sizeof(Date));
                delete_node->date = date;
                delete_node->num = 1;
            }
        }
        LOG_PRINT("%s", "delete_node malloc passed!!\n");

        EDIT_NODE *edit_node = (EDIT_NODE *)malloc(sizeof(EDIT_NODE));
        {
            {
                edit_node->date = (Date *)malloc(sizeof(Date));
                edit_node->date = date;
                edit_node->num = 1;
                char *content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
                edit_node->content = content;
                edit_node->edit_type = EDIT_ALL; // 默认全换
            }
        }
        LOG_PRINT("%s", "edit_node malloc passed!!\n");
        COMPLETE_NODE *complete_node = (COMPLETE_NODE *)malloc(sizeof(COMPLETE_NODE));
        {
            {
                complete_node->date = (Date *)malloc(sizeof(Date));
                complete_node->date = date;
                complete_node->num = 1;
            }
        }
        LOG_PRINT("%s", "complete_node malloc passed!!\n");
        TOGGLE_NODE *toggle_node = (TOGGLE_NODE *)malloc(sizeof(TOGGLE_NODE));
        {
            {

                toggle_node->date = (Date *)malloc(sizeof(Date));
                toggle_node->date = date;
                toggle_node->num = 1;
            }
        }
        LOG_PRINT("%s", "toggle_node malloc passed!!\n");

        CONFIGURATION_NODE *configuration_node = (CONFIGURATION_NODE *)malloc(sizeof(CONFIGURATION_NODE));
        {
            {
                configuration_node->KEY = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
                configuration_node->VALUE = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
                configuration_node->KEY = strdup("config_key");
                configuration_node->VALUE = strdup("config_value");
            }
        }
        LOG_PRINT("%s", "configuration_node malloc passed!!\n");

        // init Node
        init_node(node, ERROR_NODE, display_node, add_node, delete_node, edit_node, complete_node, toggle_node, configuration_node);
    }
    LOG_PRINT("%s", "node malloc passed!!\n");
    // 3.之后再加载文件，init All_files
    All_Files *all_files = (All_Files *)malloc(sizeof(All_Files));
    {
        Total_File_Year_Date *total_file_year_date = (Total_File_Year_Date *)malloc(sizeof(Total_File_Year_Date));
        {

            Day_Year_Task *day_year_task = (Day_Year_Task *)malloc(sizeof(Day_Year_Task));
            {
                TaskMonth *months = (TaskMonth *)malloc(sizeof(TaskMonth));
                {
                    TaskDay *days = (TaskDay *)malloc(sizeof(TaskDay));
                    {
                        Task *task = (Task *)malloc(sizeof(Task));
                        char *content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
                        set_task(task, content, 0);
                        set_day_tasks(days, 0, task, DEFALUT_DAY_TASK_SIZE);
                        set_day_month_tasks(months, 0, DEFALUT_MONTH_TASK_SIZE, days);
                        set_day_year_tasks(day_year_task, date->year, months);
                    }
                }
            }
            LOG_PRINT("%s", "day_year_task malloc passed!!\n");

            Week_Year_Task *week_year_task = (Week_Year_Task *)malloc(sizeof(Week_Year_Task));
            {
                Week_Month_Task *week_month_task = (Week_Month_Task *)malloc(sizeof(Week_Month_Task));

                {
                    Week_Task *weeks = (Week_Task *)malloc(sizeof(Week_Task));
                    {
                        Task *task = (Task *)malloc(sizeof(Task));
                        char *content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
                        set_task(task, content, 0);
                        set_week_tasks(weeks, 0, DEFALUT_MONTH_TASK_SIZE, task);
                        set_week_month_tasks(week_month_task, date->month, date->week, weeks);
                        set_week_Year_task(week_year_task, date->year, week_month_task);
                    }
                }
            }
            LOG_PRINT("%s", "week_year_task malloc passed!!\n");

            Month_Year_Task *month_year_task = (Month_Year_Task *)malloc(sizeof(Month_Year_Task));
            {
                Month_Task *months = (Month_Task *)malloc(sizeof(Month_Task));
                {
                    Task *task = (Task *)malloc(sizeof(Task));
                    char *content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
                    set_task(task, content, 0);
                    set_month_month_task(months, date->month, 0, DEFALUT_MONTH_TASK_SIZE, task);
                    set_month_month_year_tasks(month_year_task, date->year, months);
                }
            }
            LOG_PRINT("%s", "month_year_task malloc passed!!\n");

            Year_Task *year_task = (Year_Task *)malloc(sizeof(Year_Task));
            {
                Task *task = (Task *)malloc(sizeof(Task));
                char *content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
                set_task(task, content, 0);
                set_year_task(year_task, date->year, 0, DEFALUT_YEAR_TASK_SIZE, task);
            }
            LOG_PRINT("%s", "year_task malloc passed!!\n");
        }
        LOG_PRINT("%s", "total_file_year_date malloc passed!!\n");

        Setting *setting = (Setting *)malloc(sizeof(Setting));
        {
            SettingItem *color = (SettingItem *)malloc(sizeof(SettingItem));
            {
                char *key = (char *)malloc(sizeof(char) * 10);
                char *value_set = (char *)malloc(sizeof(char) * 10);
                char **value_allow = (char **)malloc(sizeof(char *) * 10);
                for (int i = 0; i < 10; i++)
                {
                    value_allow[i] = (char *)malloc(sizeof(char) * 10);
                }
                color->key = key;
                color->value_set = value_set;
                color->value_allow = value_allow;
            }
            SettingItem *show = (SettingItem *)malloc(sizeof(SettingItem));
            {
                char *key = (char *)malloc(sizeof(char) * 10);
                char *value_set = (char *)malloc(sizeof(char) * 10);
                char **value_allow = (char **)malloc(sizeof(char *) * 10);
                for (int i = 0; i < 10; i++)
                {
                    value_allow[i] = (char *)malloc(sizeof(char) * 10);
                }
                show->key = key;
                show->value_set = value_set;
                show->value_allow = value_allow;
            }
            setting->color = color;
            setting->show = show;
            LOG_PRINT("%s", "Begin to malloc setting\n");
            set_settings_init(setting);
            LOG_PRINT("%s", " set_settings_init(setting) malloc passed!!\n");
        }
        all_files->setting->color->value_set = strdup("on");
        set_all_files(all_files, total_file_year_date, setting);
        LOG_PRINT("%s", " set_all_files malloc passed!!\n");
    }
    LOG_PRINT("%s", "All_Files malloc passed!!\n");

    Command *command = (Command *)malloc(sizeof(Command));
    {
        // init command
        // 构建整体参数结构体
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