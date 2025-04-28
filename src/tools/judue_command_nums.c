#include "../../include/include.h"
#define PRINT_NOT_DIGIT_ERROR(arg) printf("%s is not a digit\n", arg)
#define ARGS_RIGHT() printf("args right, continue with the interface...\n")
#define MY_INTERFACE
#ifdef MY_INTERFACE
#define MY_INTERFACE_PRINT(format, ...) printf("[%s %s %s:%s :%d] " format, __DATE__, __TIME__, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#else
#define MY_INTERFACE_PRINT(format, ...) \
    do                                  \
    {                                   \
    } while (0)
#endif
// 判断命令参数数量是否合法和基本的命令含义是否合法
// Determine if the number of command arguments is valid
// 错误的情况有很多，这里仅仅枚举正确的的情况=======充分展现正难则反！
void judge_command_nums(Setting *setting, int argc, char **argv)
{
    if (argc < 2) // It must be 'tl', so display the help document
    {
        help();
        exit(0);
    }
    else if (argc == 2)
    { // 一定只有tl ^ 查询
        if (strcmp(argv[1], "^") == 0)
        {
            MY_INTERFACE_PRINT("%s", "Query all tasks for today");
            ARGS_RIGHT();
            exit(0);
        }
        COMMAND_ERROR(setting, argc - 1, argv + 1);
        exit(EXIT_FAILURE);
    }
    else if (argc == 3)
    { // 有tl * -w
        if (strcmp(argv[1], "+") == 0)
        {
            MY_INTERFACE_PRINT("%s", "Add, delete, complete, or undo completion for today");
            ARGS_RIGHT();
            exit(0);
        }
        else if (strcmp(argv[1], "/") == 0 || strcmp(argv[1], "-") == 0 || strcmp(argv[1], "~") == 0)
        { // 添加、删除、完成、撤销完成,这几个后面一定跟上的数字
            if (is_all_digits(argv[2]))
            {
                MY_INTERFACE_PRINT("%s", "Add, delete, complete, or undo completion for today");
                ARGS_RIGHT();
                exit(0);
            }
            // 范围再具体的函数判断
            else
            {
                COMMAND_ERROR(setting, argc - 1, argv + 1);
                PRINT_NOT_DIGIT_ERROR(argv[2]);
                exit(EXIT_FAILURE);
            }
        }
        else if (strcmp(argv[1], "$") == 0)
        { // 三参数的最后一道防线就是tl set color=off，如果连这个都不是，那就拜拜了！
            MY_INTERFACE_PRINT("%s", "Setting...");
            ARGS_RIGHT();
            exit(0);
        }
        COMMAND_ERROR(setting, argc - 1, argv + 1);
        exit(EXIT_FAILURE);
    }
    else if (argc == 4)
    {
        // 四参数的，一共有
        // 查询 tl ^ -week 2025.04.04
        // 修改 tl [%]=[%] index new_content
        if (strcmp(argv[1], "=") == 0 || strcmp(argv[1], "=%") == 0 || strcmp(argv[1], "%=") == 0)
        { // 改动也可以是4参数
            // tl = 1 nre_content
            if (is_all_digits(argv[2]))
            {
                MY_INTERFACE_PRINT("%s", "Modify task for today( prefix | suffix | all)");
                ARGS_RIGHT();
                exit(0);
            }
            else
            {
                COMMAND_ERROR(setting, argc - 1, argv + 1);
                PRINT_NOT_DIGIT_ERROR(argv[2]);
                exit(EXIT_FAILURE);
            }
        }
        else if (strcmp(argv[1], "^") == 0)
        { // 查询也可以是4参数
          // tl ^ -w 2025.06.03

            if (strcmp(argv[2], "-day") || strcmp(argv[2], "-d") || strcmp(argv[2], "-week") || strcmp(argv[2], "-w") || strcmp(argv[2], "-month") || strcmp(argv[2], "-m") || strcmp(argv[2], "-year") || strcmp(argv[2], "-y"))
            {
                MY_INTERFACE_PRINT("%s", "Query tasks for a specified date");

                ARGS_RIGHT();
                exit(0);
            }
        }
        COMMAND_ERROR(setting, argc - 1, argv + 1);
        exit(EXIT_FAILURE);
    }
    else if (argc == 5)
    { // tl + content -w 2025.04.04
        // 第一重防线
        // 五个参数的，只有+-/~
        if (strcmp(argv[1], "+") == 0 || strcmp(argv[1], "-") == 0 || strcmp(argv[1], "~") == 0 || strcmp(argv[1], "/") == 0)
        { // 第二重防线
            // 带-的一定是以下的单词！
            if (strcmp(argv[3], "-day") || strcmp(argv[3], "-d") || strcmp(argv[3], "-week") || strcmp(argv[3], "-w") || strcmp(argv[3], "-month") || strcmp(argv[3], "-m") || strcmp(argv[3], "-year") || strcmp(argv[3], "-y"))
            {
                MY_INTERFACE_PRINT("%s", "Add, complete, reverse, or delete tasks for a specified date");
                ARGS_RIGHT();
                exit(0);
            }
        }
        COMMAND_ERROR(setting, argc - 1, argv + 1);
        exit(EXIT_FAILURE);
    }
    else if (argc == 6)
    {
        // tl = 1 new_content -w 2025.04.04
        // 第一重防线
        // 六个参数的，只有=
        if (strcmp(argv[1], "=") == 0)
        { // 第二重防线
            if (is_all_digits(argv[2]))
            {
                // 第三重防线
                if (!strcmp(argv[4], "-day") || !strcmp(argv[4], "-d") || !strcmp(argv[4], "-week") || !strcmp(argv[4], "-w") || !strcmp(argv[4], "-month") || !strcmp(argv[4], "-m") || !strcmp(argv[4], "-year") || !strcmp(argv[4], "-y"))
                {
                    MY_INTERFACE_PRINT("%s", "Modify tasks for a specified date");
                    ARGS_RIGHT();
                    exit(0);
                }
            }
            else
            {
                PRINT_NOT_DIGIT_ERROR(argv[2]);
                COMMAND_ERROR(setting, argc - 1, argv + 1);
                exit(EXIT_FAILURE);
            }
        }
        COMMAND_ERROR(setting, argc - 1, argv + 1);
        exit(EXIT_FAILURE);
    }
    else
    {
        COMMAND_ERROR(setting, argc - 1, argv + 1);
        // The number of command arguments is valid
        printf("The number of command arguments is valid\n");
        exit(EXIT_FAILURE);
    }
}

// int main(int argc, char **argv)
// {
//     Setting s = {"on"};
//     // 调用判断函数进行测试
//     judge_command_nums(&s, argc, argv);
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