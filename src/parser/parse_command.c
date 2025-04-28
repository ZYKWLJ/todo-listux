#include "../../include/include.h"
#define PRINT_NOT_DIGIT_ERROR(arg) LOG_PRINT("%s is not a digit\n", arg)
#define ARGS_RIGHT() LOG_PRINT("args right, continue with the interface...\n")
#define MY_INTERFACE
#ifdef MY_INTERFACE
#define MY_INTERFACE_PRINT(format, ...) LOG_PRINT("[%s %s %s:%s :%d] " format, __DATE__, __TIME__, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#else
#define MY_INTERFACE_PRINT(format, ...) \
    do                                  \
    {                                   \
    } while (0)
#endif

#define LOG
// 判断命令参数数量是否合法和基本的命令含义是否合法
// Determine if the number of command arguments is valid
// 错误的情况有很多，这里仅仅枚举正确的的情况=======充分展现正难则反！
void parse_command(NODE *node, All_Files *all_files, Command *command)
{
    if (command->argc < 2) // It must be 'tl', so display the help document
    {
        node->node_type = HELP;
        // 先指定节点，后续统一执行
        help();
        return;
    }
    else if (command->argc == 2)
    { // 一定只有tl ^ 查询
        if (strcmp(command->argv[1], "^") == 0)
        {
            node->node_type = DISPLAY; // 默认是当天的，不用改
#ifdef LOG
            MY_INTERFACE_PRINT("%s", "Query all tasks for today");
            ARGS_RIGHT();
#endif
            return;
            exit(0);
        }
        COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
        exit(EXIT_FAILURE);
    }
    else if (command->argc == 3)
    { // 有tl + content
        if (strcmp(command->argv[1], "+") == 0)
        {
            node->node_type = ADD;
            // 默认的是今天，所以date不变！
            node->add_node->content = strdup(command->argv[2]);

#ifdef LOG
            MY_INTERFACE_PRINT("%s", "Add, delete, complete, or undo completion for today");
            node->node_type = ADD;
            ARGS_RIGHT();
#endif

            return;
            exit(0);
        }
        // tl / 1
        else if (strcmp(command->argv[1], "/") == 0 ||
                 strcmp(command->argv[1], "-") == 0 ||
                 strcmp(command->argv[1], "~") == 0)
        { // 添加、删除、完成、撤销完成,这几个后面一定跟上的数字
            if (is_all_digits(command->argv[2]))
            {
#ifdef LOG
                MY_INTERFACE_PRINT("%s", "Add, delete, complete, or undo completion for today");
                ARGS_RIGHT();
#endif
                if (strcmp(command->argv[1], "/") == 0)
                    node->node_type = DELETE_;
                else if (strcmp(command->argv[1], "-") == 0)
                    node->node_type = COMPLETE;
                else if (strcmp(command->argv[1], "~") == 0)
                    node->node_type = TOGGLE;
                return;
                exit(0);
            }
            // 范围再具体的函数判断
            else
            {
                COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
                PRINT_NOT_DIGIT_ERROR(command->argv[2]);
                exit(EXIT_FAILURE);
            }
        }
   
        else if (strcmp(command->argv[1], "$") == 0)
        {
            LOG_PRINT("%s", "this is set setting\n");

            // 1. 检查输入格式
            if (!command->argv[2] || !strchr(command->argv[2], '='))
            {
                LOG_PRINT("Invalid format: use 'tl $ key=value'\n");
                return;
            }

            // 2. 安全分割 key=value（不使用strndup）
            char *equal_pos = strchr(command->argv[2], '=');
            if (!equal_pos)
            {
                LOG_PRINT("No '=' found in argument\n");
                return;
            }

            size_t key_len = equal_pos - command->argv[2];
            char *k = malloc(key_len + 1);
            if (!k)
                return;
            strncpy(k, command->argv[2], key_len);
            k[key_len] = '\0';

            char *v = strdup(equal_pos + 1);
            if (!v)
            {
                free(k);
                return;
            }
            if (!k || !v)
            {
                LOG_PRINT("Memory allocation failed\n");
                free(k);
                free(v);
                return;
            }

            // 3. 设置配置
            CONFIGURATION_NODE *node = malloc(sizeof(CONFIGURATION_NODE));
            if (!node)
            {
                free(k);
                free(v);
                return;
            }
            node->KEY = k;
            node->VALUE = v;

            int result = set_settings(all_files->setting, node);
            switch (result)
            {
            case 1:
                LOG_PRINT("Settings updated: %s=%s\n", k, v);
                break;
            case 0:
                LOG_PRINT("Invalid key: %s\n", k);
                break;
            case 2:
                LOG_PRINT("Invalid value: %s\n", v);
                break;
            }

            // 4. 释放内存
            free(node->KEY);
            free(node->VALUE);
            free(node);
            return;
        }
        COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
        exit(EXIT_FAILURE);
    }
    else if (command->argc == 4)
    {
        // 四参数的，一共有
        // 查询 tl ^ -week 2025.04.04
        // 修改 tl [%]=[%] index new_content
        if (strcmp(command->argv[1], "=") == 0 ||
            strcmp(command->argv[1], "=%") == 0 ||
            strcmp(command->argv[1], "%=") == 0)
        { // 改动也可以是4参数
            // tl = 1 new_content
            if (is_all_digits(command->argv[2]))
            {

                if (strcmp(command->argv[1], "=") == 0)
                {
                    node->node_type = EDIT;
                    node->edit_node->edit_type = EDIT_ALL;
#ifdef LOG
                    MY_INTERFACE_PRINT("%s", "Modify task for today( all)");
                    ARGS_RIGHT();
#endif
                }

                else if (strcmp(command->argv[1], "=%") == 0)
                {
                    node->node_type = EDIT;
                    node->edit_node->edit_type = EDIT_PREFIX;
#ifdef LOG

                    MY_INTERFACE_PRINT("%s", "Modify task for today( prefix )");
                    ARGS_RIGHT();
#endif
                }

                else if (strcmp(command->argv[1], "%=") == 0)
                {

                    node->node_type = EDIT;
                    node->edit_node->edit_type = EDIT_SUFFIX;
#ifdef LOG

                    MY_INTERFACE_PRINT("%s", "Modify task for today( suffix )");
                    ARGS_RIGHT();
#endif
                }
                return;
                exit(0);
            }
            else
            {
                COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
                PRINT_NOT_DIGIT_ERROR(command->argv[2]);
                exit(EXIT_FAILURE);
            }
        }
        else if (strcmp(command->argv[1], "^") == 0)
        { // 查询也可以是4参数
          // tl ^ -w 2025.06.03
          // 正确的参数验证
            Date *date = (Date *)malloc(sizeof(Date));
            // 这里就完成了类型的判断！
            date->date_type = parse_date_type(command->argv[2]);
            // 检测了-w\-d之类
            if (date->date_type == ERROR_DATE_TYPE)
            {
                LOG_PRINT("ERROR_DATE_TYPE\n");
                COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
                exit(EXIT_FAILURE);
            }
            // 检验了xxxx.xx.xx之类
            // 这里完成了具体日期的赋值
            // 这里也解析了日期格式xxxx.xx.xx
            parse_date(date->date_type, command->argv[3], date);
            if (date->error == 1)
            {
                LOG_PRINT("ERROR_DATE_TYPE\n");
                COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
                exit(EXIT_FAILURE);
            }
            node->display_node->date = date;
            node->node_type = DISPLAY;
            return;
        }
    }
    else if (command->argc == 5)
    {
        // tl + content -w 2025.04.04
        // tl - index -w 2025.04.04
        // tl / index -w 2025.04.04
        // 先判断后面的date_type和date是否正确！
        Date *date = (Date *)malloc(sizeof(Date));
        // 这里就完成了类型的判断！
        date->date_type = parse_date_type(command->argv[3]);
        // 检测了-w\-d之类
        if (date->date_type == ERROR_DATE_TYPE)
        {
            LOG_PRINT("ERROR_DATE_TYPE\n");

            COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
            exit(EXIT_FAILURE);
        }
        // 检验了xxxx.xx.xx之类
        // 这里完成了具体日期的赋值
        // 这里也解析了日期格式xxxx.xx.xx
        // tl + content -w 2025.04.04
        parse_date(date->date_type, command->argv[4], date);
        if (date->error == 1)
        {
            LOG_PRINT("ERROR_DATE_TYPE\n");
            COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
            exit(EXIT_FAILURE);
        }
        // 第一重防线
        // 五个参数的，只有+-/~

        if (strcmp(command->argv[2], "+") == 0)
        {
            node->add_node->date = date;
            node->add_node->content = strdup(command->argv[2]);
#ifdef LOG
            MY_INTERFACE_PRINT("%s", "Add for specific day");
            ARGS_RIGHT();
#endif
        }
        else if (
            strcmp(command->argv[1], "~") == 0 ||
            strcmp(command->argv[1], "/") == 0)
        { // 第二重防线
            // index一定是数字
            if (!is_all_digits(command->argv[2]))
            {
                PRINT_NOT_DIGIT_ERROR(command->argv[2]);
                COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
                exit(EXIT_FAILURE);
            }
            if (strcmp(command->argv[1], "~") == 0)
            {
                node->node_type = TOGGLE;
                node->toggle_node->date = date;
                node->toggle_node->num = atoi(command->argv[2]);
#ifdef LOG
                MY_INTERFACE_PRINT("%s", "Undo for specific day");
                ARGS_RIGHT();
#endif
            }
            else
            {
                node->node_type = DELETE_;
                node->delete_node->date = date;
                node->delete_node->num = atoi(command->argv[2]);
#ifdef LOG
                MY_INTERFACE_PRINT("%s", "Delete for specific day");
                ARGS_RIGHT();
#endif
            }
            return;
            exit(0);
        }
        // 其余的全报错
        COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
        exit(EXIT_FAILURE);
    }
    else if (command->argc == 6)

    {
        // tl = 1 new_content -w 2025.04.04
        // 第一重防线
        // 六个参数的，只有=
        if (strcmp(command->argv[1], "=") == 0 || strcmp(command->argv[1], "%=") == 0 || strcmp(command->argv[1], "=%") == 0)
        { // 第二重防线
            if (!is_all_digits(command->argv[2]))
            {
                PRINT_NOT_DIGIT_ERROR(command->argv[2]);
                COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
                exit(EXIT_FAILURE);
            }
            Date *date = (Date *)malloc(sizeof(Date));
            // 这里就完成了类型的判断！
            date->date_type = parse_date_type(command->argv[4]);
            // 检测了-w\-d之类
            if (date->date_type == ERROR_DATE_TYPE)
            {
                LOG_PRINT("ERROR_DATE_TYPE\n");
                COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
                exit(EXIT_FAILURE);
            }
            // 检验了xxxx.xx.xx之类
            // 这里完成了具体日期的赋值
            // 这里也解析了日期格式xxxx.xx.xx
            // tl %= 1 new_content -day 2025.04.04
            parse_date(date->date_type, command->argv[5], date);
            if (date->error == 1)
            {
                LOG_PRINT("ERROR_DATE_TYPE\n");
                COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
                exit(EXIT_FAILURE);
            }
            node->edit_node->date = date;
            node->edit_node->num = atoi(command->argv[2]);
            node->edit_node->content = strdup(command->argv[3]);
            if (strcmp(command->argv[1], "=") == 0)
            {
                node->edit_node->edit_type = EDIT_ALL;
#ifdef LOG
                MY_INTERFACE_PRINT("%s", "EDIT for specific day");
                ARGS_RIGHT();
#endif
            }
            else if (strcmp(command->argv[1], "=%") == 0)
            {
                node->edit_node->edit_type = EDIT_PREFIX;
#ifdef LOG
                MY_INTERFACE_PRINT("%s", "EDIT_PREFIX for specific day");
                ARGS_RIGHT();
#endif
            }
            else if (strcmp(command->argv[1], "=%") == 0)
            {
                node->edit_node->edit_type = EDIT_SUFFIX;
#ifdef LOG
                MY_INTERFACE_PRINT("%s", "EDIT_SUFFIX for specific day");
                ARGS_RIGHT();
#endif
            }
            else
            {
                COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
                exit(EXIT_FAILURE);
            }
            return;
            exit(0);
        }
        else
        {
            COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
        LOG_PRINT("The number of command arguments is valid\n");
        exit(EXIT_FAILURE);
    }
}
// int main(int command->argc, char **command->argv)
// {
//     Setting s = {"on"};
//     // 调用判断函数进行测试
//     judge_command_nums(&s, command->argc, command->argv);
//     return 0;
// }
//  gcc D:\3software\todo-listux-1\todo-listux\src\tools\judue_command_nums.c D:\3software\todo-listux-1\todo-listux\src\display\help.c D:\3software\todo-listux-1\todo-listux\src\tools\command_error.c D:\3software\todo-listux-1\todo-listux\src\tools\tools.c -o D:\3software\todo-listux-1\todo-listux\src\tools\judue_command_nums
#ifdef draft
列出所有可能命令
不带参数：
tl s / show tl add content tl delete index tl modify index tl done index / all tl undo index / all tl set k = v

                                                                                                                      带日期参数：
                                                                                                                          tl s /
                                                                                                                  show -
                                                                                                              w / week
                                                                                                                      tl add content -
                                                                                                              w / week 2025.04.4 tl delete index - w / week 2025.04.4 tl modify index - w / week 2025.04.4 tl done index / all - w / week 2025.04.4 tl undo index / all - w / week 2025.04.4 tl set k = v
#endif

    // 全部用字符代替会更好，因为减轻使用负担！有时候选择少一点就好一点，这就是选择的力量！
    // 添加
    // tl + sss取代tl a ddd//可能会更好 +
    // 完成
    // tl - 1取代tl done 1可能会更好
    // 查询
    // tl ^ 1 取代 tl s 1(倒也贴切!)（统配，叫做正则）
    // 删除
    // tl / 1 取代 tl delete 1
    // 改动
    // tl = 1 取代 tl modify 1
    // 取反(可以把完成变为不完成，不完成变为完成)
    // tl ~ 1 取代 tl undo 1
    // 设置
    // tl $ k=v取代tl set k=v(不保留文字)

    // 先别急，做一份指令表先
    // 二参数
    // tl ^
    // 三参数
    // tl $ k=v//设置一定是三参数
    // tl + ddddd//默认添加任务至当天的
    // tl - task_index//默认完成当天的
    // tl / task_index//默认删除当天的
    // tl ~ task_index//默认置反当天的

    // 四参数
    // tl ^ -w 2025.04.04//查询指定的周
    // 五参数
    // tl + content -w 2025.04.04//添加任务到指定的周
    // tl - task_index -w 2025.04.04//默认完成任务到指定的周
    // tl / task_index -w 2025.04.04//默认删除任务到指定的周
    // tl ~ task_index -w 2025.04.04//默认置反任务到指定的周