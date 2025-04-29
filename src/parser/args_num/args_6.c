#include "../../../include/include.h"
void parse_command_args_6(NODE *node, All_Files *all_files, Command *command)
{
    // tl = 1 new_content -w 2025.04.04
    // 第一重防线
    // 六个参数的，只有=
    if (strcmp(command->argv[1], EDIT_ALL_TOKEN) == 0 || strcmp(command->argv[1], EDIT_SUFFIX_TOKEN) == 0 || strcmp(command->argv[1], EDIT_PREFIX_TOKEN) == 0)
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
        node->node_type = EDIT;
        node->edit_node->num = atoi(command->argv[2]);
        node->edit_node->content = strdup(command->argv[3]);
        if (strcmp(command->argv[1], EDIT_ALL_TOKEN) == 0)
        {
            node->edit_node->edit_type = EDIT_ALL;

#ifdef LOG
            MY_INTERFACE_PRINT("%s", "EDIT for specific day");
            ARGS_RIGHT();
#endif
        }
        else if (strcmp(command->argv[1], EDIT_PREFIX_TOKEN) == 0)
        {
            node->edit_node->edit_type = EDIT_PREFIX;

#ifdef LOG
            MY_INTERFACE_PRINT("%s", "EDIT_PREFIX for specific day");
            ARGS_RIGHT();
#endif
        }
        else if (strcmp(command->argv[1], EDIT_SUFFIX_TOKEN) == 0)
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