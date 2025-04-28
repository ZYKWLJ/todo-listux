#include <stdio.h>

void help()
{
    printf("TaskLite (tl) Command Reference\n");
    printf("Usage: tl [command] [arguments]\n");
    printf("Following dateType means -d/-day -w/-week -m/-month -y/-year \n");

    printf("SEARCH COMMANDS:\n");
    printf("  tl ^                     Show current week view\n");
    printf("  tl ^ -dateType YYYY.MM.DD       Show specific day/week/month/year view\n\n");

    printf("ADD COMMANDS:\n");
    printf("  tl + \"task content\"      Add task to today\n");
    printf("  tl + \"content\" -dateType YYYY.MM.DD   Add to specific date\n\n");

    printf("COMPLETE COMMANDS:\n");
    printf("  tl - task_index          Mark task as done (today)\n");
    printf("  tl - index -dateType YYYY.MM.DD Complete task (specific date)\n\n");

    printf("DELETE COMMANDS:\n");
    printf("  tl / task_index          Delete task (today)\n");
    printf("  tl / index -dateType YYYY.MM.DD Delete task (specific date)\n\n");

    printf("TOGGLE COMMANDS:\n");
    printf("  tl ~ task_index          Toggle task status (today)\n");
    printf("  tl ~ index -dateType YYYY.MM.DD Toggle task (specific date)\n\n");

    printf("EDIT COMMANDS:\n");
    printf("  Today Operations:\n");
    printf("    tl = index \"new_content\"       Replace task (today)\n");
    printf("    tl = index \"new_content\" -dateType YYYY.MM.DD  Replace task (specific date)\n");
    printf("    tl =%% index \"prefix_content\"           Prepend to task(today)\n");
    printf("    tl =%% index \"prefix_content\" -dateType YYYY.MM.DD Prepend to task(specific date)\n");
    printf("    tl %%= index \"suffix_content\"           Append to task(today)\n");
    printf("    tl %%= index \"suffix_content\" -dateType YYYY.MM.DD Append to task (specific date)\n\n");

    printf("CONFIGURATION:\n");
    printf("  tl $ key=value            Set configuration\n");
    printf("      Available keys:\n");
    printf("      - color: on/off       Enable/disable colored output\n");
    printf("      - view: week/day      Default display mode\n");
}

int main()
{
    help();
    return 0;
}