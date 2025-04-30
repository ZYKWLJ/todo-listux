#include "../../../include/include.h"
void parse_command_args_4(NODE *node, All_Files *all_files, Command *command)
{
    // 四参数的，一共有
    // 查询 tl ^ -week 2025.04.04
    // 修改 tl [%]=[%] index new_content
    if (strcmp(command->argv[1], EDIT_ALL_TOKEN) == 0 ||
        strcmp(command->argv[1], EDIT_PREFIX_TOKEN) == 0 ||
        strcmp(command->argv[1], EDIT_SUFFIX_TOKEN) == 0)
    { // 改动也可以是4参数
        // tl = 1 new_content
        if (is_all_digits(command->argv[2]))
        {

            if (strcmp(command->argv[1], EDIT_ALL_TOKEN) == 0)
            {
                node->node_type = EDIT;
                node->edit_node->edit_type = EDIT_ALL;
#ifdef LOG
                MY_INTERFACE_PRINT("%s", "Modify task for today( all)");
                ARGS_RIGHT();
#endif
            }

            else if (strcmp(command->argv[1], EDIT_PREFIX_TOKEN) == 0)
            {
                node->node_type = EDIT;
                node->edit_node->edit_type = EDIT_PREFIX;
#ifdef LOG

                MY_INTERFACE_PRINT("%s", "Modify task for today( prefix )");
                ARGS_RIGHT();
#endif
            }

            else if (strcmp(command->argv[1], EDIT_SUFFIX_TOKEN) == 0)
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
    else if (strcmp(command->argv[1], DISPLAY_TOKEN) == 0)
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
        node->date = date;
        return;
    }
}