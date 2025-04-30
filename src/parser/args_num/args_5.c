#include "../../../include/include.h"
#define LOG
void parse_command_args_5(NODE *node, All_Files *all_files, Command *command)
{

    // 先判断后面的date_type和date是否正确！
    // 这里判断了-w -d -m -y

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
    LOG_PRINT("passed date_type!!!\n");

    // 这里解析了日期格式xxxx.xx.xx
    // tl + content -w 2025.04.04
    parse_date(date->date_type, command->argv[4], date);
    if (date->error == 1)
    {
        LOG_PRINT("%s", "ERROR_DATE_TYPE");
        COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
        exit(EXIT_FAILURE);
    }
    LOG_PRINT("passed date!!!\n");
    node->date = date;
    LOG_PRINT("%s\n", "date assigned");
    // 第一重防线
    // 五个参数的，只有+-/~

    if (strcmp(command->argv[1], "+") == 0)
    {
        node->add_node->date = date;
        node->add_node->content = strdup(command->argv[2]);
        node->node_type = ADD;
#ifdef LOG
        MY_INTERFACE_PRINT("%s", "Add for specific day");
        ARGS_RIGHT();
#endif
        return;
    }
    else if (
        strcmp(command->argv[1], TOGGLE_TOKEN) == 0 ||
        strcmp(command->argv[1], DELETE_TOKEN) == 0 ||
        strcmp(command->argv[1], COMPLETE_TOKEN) == 0)
    { // 第二重防线
        // index一定是数字
        if (!is_all_digits(command->argv[2]))
        {
            PRINT_NOT_DIGIT_ERROR(command->argv[2]);
            COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
            exit(EXIT_FAILURE);
        }
        if (strcmp(command->argv[1], TOGGLE_TOKEN) == 0)
        {
            node->node_type = TOGGLE;
            node->toggle_node->date = date;
            node->toggle_node->num = atoi(command->argv[2]);
#ifdef LOG
            MY_INTERFACE_PRINT("%s", "Undo for specific day");
            ARGS_RIGHT();
#endif
        }
        else if (strcmp(command->argv[1], DELETE_TOKEN) == 0)
        {
            node->node_type = DELETE_;
            node->delete_node->date = date;
            node->delete_node->num = atoi(command->argv[2]);
#ifdef LOG
            MY_INTERFACE_PRINT("%s", "Delete for specific day");
            ARGS_RIGHT();
#endif
        }
        else if (strcmp(command->argv[1], COMPLETE_TOKEN) == 0)
        {
            node->node_type = COMPLETE;
            node->delete_node->date = date;
            node->delete_node->num = atoi(command->argv[2]);
#ifdef LOG
            MY_INTERFACE_PRINT("%s", "Delete for specific day");
            ARGS_RIGHT();
#endif
        }
        return;
    }
    // 其余的全报错
    COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
    exit(EXIT_FAILURE);
}