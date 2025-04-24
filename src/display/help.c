#include "../../include/include.h"
// 显示当前日期的所有数据

void help()
{
    printf("Usage: tl [command] [arguments]\n");
    printf("Commands:\n");
    printf("  show|s       Display current date tasks\n");
    printf("  add|a        Add a new task\n");
    printf("  delete|d     Delete a task (Usage: tl delete <task_index>)\n");
    printf("  modify|m     Modify a task (Usage: tl modify <task_index>)\n");
    printf("  done         Mark a task as completed (Usage: tl done <task_index>)\n");
    printf("  undo         Undo the completion mark of a task (Usage: tl undo <task_index>)\n");
    printf("  help|h       Show this help message\n");
}