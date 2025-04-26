#include "../../include/include.h"
// 显示当前日期的所有数据

// void help()
// {
//     printf("Usage: tl [command] [arguments]\n");
//     printf("Commands:\n");
//     printf("  show|s       Display current date tasks\n");
//     printf("  add|a        Add a new task\n");
//     printf("  delete|d     Delete a task (Usage: tl delete <task_index>)\n");
//     printf("  modify|m     Modify a task (Usage: tl modify <task_index>)\n");
//     printf("  done         Mark a task as completed (Usage: tl done <task_index>)\n");
//     printf("  undo         Undo the completion mark of a task (Usage: tl undo <task_index>)\n");
//     printf("  help|h       Show this help message\n");
// }


void help()
{
    printf("Usage: tl [command] [arguments]\n");
    printf("Commands:\n");
    printf("  show|s  [-year|y/-month|m/-week|w/-day|d]  Display current the future days date tasks\n");
    printf("           -year|y: Display tasks for the specified year.\n");
    printf("           -month|m: Display tasks for the specified month.\n");
    printf("           -week|w: Display tasks for the specified week.\n");
    printf("           -day|d: Display tasks for the specified day.\n");
    printf("  add|a [-DateType Date]  <task_content>   Add a new task to the specified date.\n");
    printf("           -DateType can be one of: -year|y, -month|m, -week|w, -day|d.\n");
    printf("           Date should be in the appropriate format according to the DateType.\n");
    printf("  delete|d  [-DateType Date]  <task_index>  Delete a task.\n");
    printf("           Usage example: tl delete -day 2025-04-27 <task_index>\n");
    printf("  modify|m  [-DateType Date]  <task_index>  <task_new_content>  Modify a task.\n");
    printf("           Usage example: tl modify -week 2025-04-10 <task_index> new_task_content\n");
    printf("  done   [-DateType Date]  <task_index>      Mark a task as completed.\n");
    printf("           Usage example: tl done -month 2025-04 <task_index>\n");
    printf("  undo   [-DateType Date]  <task_index>      Undo the completion mark of a task.\n");
    printf("           Usage example: tl undo -year 2025 <task_index>\n");
    printf("  set    <key>=<value>                        Set a configuration setting.\n");
    printf("           Available keys and their valid values:\n");
    printf("             color: Valid values are 'on' or 'off'. Used to set the color setting.\n");
    printf("             show: Valid values are 'year','month', 'week', 'day', or 'all'.\n");
    printf("                   Used to set what level of tasks to display (e.g., all tasks for a year, month, etc.).\n");
    printf("           Usage example: tl set color=on\n");
    printf("  help|h       Show this help message\n");
}