#include "../../include/include.h"
#define LOG
void execute(All_Files *all_files, NODE *node, Command *command)
{
    printf("todo-listux execute start------!\n");
    switch (node->node_type)
    {
    case HELP:
    {
        help();
        break;
    }
    case DISPLAY:
    {
        printDisplayNodeLog(node->display_node);
        printf("Performing display operation\n");
        // Add specific display function code here, such as calling a display - related function
        display(all_files, node); // 默认显示当前日期(还是统一吧)
        break;
    }
    case ADD:
    {
        printAddNodeLog(node->add_node);
        printf("Performing add operation\n");
        // Add specific add function code here, such as calling an add - related function
        break;
    }
    case DELETE_:
    {
        printDeleteNodeLog(node->delete_node);
        printf("Performing delete operation\n");
        // Add specific delete function code here, such as calling a delete - related function
        break;
    }
    case EDIT:
    {
        printEditNodeLog(node->edit_node);
        printf("Performing edit operation\n");
        // Add specific edit function code here, such as calling an edit - related function
        break;
    }
    case COMPLETE:
    {
        printCompleteNodeLog(node->complete_node);
        printf("Performing complete operation\n");
        // Add specific complete function code here, such as calling a complete - related function
        break;
    }
    case TOGGLE:
    {
        printToggleNodeLog(node->toggle_node);
        printf("Performing toggle operation\n");
        // Add specific toggle function code here, such as calling a toggle - related function
        break;
    }
    case CONFIGURATION:
    {
        printConfigurationNodeLog(node->configuration_node);
        printf("Performing configuration operation\n");
        save_setting(all_files->setting);
        // Add specific configuration function code here, such as calling a configuration - related function
        break;
    }
    default:
        COMMAND_ERROR(all_files->setting, command->argc - 1, command->argv + 1); // 专用的错误处理
        break;
    }
}