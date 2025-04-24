#include "../../include/include.h"
// 显示当前日期的所有数据

void help()
{
    printf("Usage: tl [command] [arguments]\n");
    printf("Commands:\n");
    printf("  display    Display current date tasks\n");
    printf("  add        Add a new task\n");
    printf("  delete     Delete a task (Usage: tl delete <task_index>)\n");
    printf("  modify     Modify a task (Usage: tl modify <task_index>)\n");
    printf("  help       Show this help message\n");
}