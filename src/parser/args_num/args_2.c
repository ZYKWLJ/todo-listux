#include "../../../include/include.h"


#define LOG
// 判断命令参数数量是否合法和基本的命令含义是否合法
// Determine if the number of command arguments is valid
// 错误的情况有很多，这里仅仅枚举正确的的情况=======充分展现正难则反！
void parse_command_args_2(NODE *node, All_Files *all_files, Command *command)
{
    if (command->argc < 2) // It must be 'tl', so display the help document
    {
        node->node_type = HELP;
        // 先指定节点，后续统一执行
        // help();
        return;
    }
    else if (command->argc == 2)
    { // 一定只有tl ^ 查询
        if (strcmp(command->argv[1], DISPLAY_TOKEN) == 0)
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
}