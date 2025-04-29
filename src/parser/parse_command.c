#include "../../include/include.h"
// 判断命令参数数量是否合法和基本的命令含义是否合法
// Determine if the number of command arguments is valid
// 错误的情况有很多，这里仅仅枚举正确的的情况=======充分展现正难则反！
void parse_command(NODE *node, All_Files *all_files, Command *command)
{
    if (command->argc <= 2) // It must be 'tl', so display the help document
    {
        parse_command_args_2(node, all_files, command);
    }
    else if (command->argc == 3)
    {
        parse_command_args_3(node, all_files, command);
    }
    else if (command->argc == 4)
    {
        parse_command_args_4(node, all_files, command);
    }
    else if (command->argc == 5)
    {
        parse_command_args_5(node, all_files, command);
    }
    else if (command->argc == 6)

    {
        parse_command_args_6(node, all_files, command);
    }
    else
    {
        COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
        LOG_PRINT("The number of command arguments is valid\n");
        exit(EXIT_FAILURE);
    }
}
