#include "../../../include/include.h"

void parse_command_args_3(NODE *node, All_Files *all_files, Command *command)
{
    // 有tl + content
    if (strcmp(command->argv[1], ADD_TOKEN) == 0)
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
    // tl /~- 1
    else if (strcmp(command->argv[1], DELETE_TOKEN) == 0 ||
             strcmp(command->argv[1], COMPLETE_TOKEN) == 0 ||
             strcmp(command->argv[1], TOGGLE_TOKEN) == 0)
    { // 添加、删除、完成、撤销完成,这几个后面一定跟上的数字
        if (is_all_digits(command->argv[2]))
        {
#ifdef LOG
            MY_INTERFACE_PRINT("%s", "Add, delete, complete, or undo completion for today");
            ARGS_RIGHT();
#endif
            if (strcmp(command->argv[1], DELETE_TOKEN) == 0)
                node->node_type = DELETE_;
            else if (strcmp(command->argv[1], COMPLETE_TOKEN) == 0)
                node->node_type = COMPLETE;
            else if (strcmp(command->argv[1], TOGGLE_TOKEN) == 0)
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

    else if (strcmp(command->argv[1], CONFIGURATION_TOKEN) == 0)
    {
        LOG_PRINT("%s", "this is set setting\n");
#define EQUAL_TOKEN '='
        // 1. 检查输入格式
        if (!command->argv[2] || !strchr(command->argv[2], EQUAL_TOKEN))
        {
            LOG_PRINT("Invalid format: use 'tl $ key=value'\n");
            return;
        }

        // 2. 安全分割 key=value（不使用strndup）
        char *equal_pos = strchr(command->argv[2], EQUAL_TOKEN);
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
        CONFIGURATION_NODE *configuration_node = malloc(sizeof(CONFIGURATION_NODE));
        if (!configuration_node)
        {
            free(k);
            free(v);
            return;
        }
        configuration_node->KEY = k;
        configuration_node->VALUE = v;

        int result = set_settings(all_files->setting, configuration_node);
        switch (result)
        {
        case 1:
            LOG_PRINT("Settings updated: %s=%s\n", k, v);
            node->node_type = CONFIGURATION;
            node->configuration_node = configuration_node;
            break;
        case 0:
            LOG_PRINT("Invalid key: %s\n", k);
            break;
        case 2:
            LOG_PRINT("Invalid value: %s\n", v);
            break;
        }

        // 4. 不能释放内存，因为后面还要使用
        return;
    }
    COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1);
    exit(EXIT_FAILURE);
}