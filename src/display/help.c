#include "../../include/include.h"
// 用户手册

void help()
{
    printf("TaskLite (%s) Command Reference\n",SOFTWARE_NAME);
    printf("Usage: %s [command] [arguments]\n", SOFTWARE_NAME);
    printf("Following dateType means -d/-day -w/-week -m/-month -y/-year \n");
    printf("Following TID means task_index\n\n");

    printf("SHOW COMMANDS:\n");
    printf("  %s %s                            Show today task\n", SOFTWARE_NAME, DISPLAY_TOKEN);
    printf("  %s %s -dateType YYYY.MM.DD       Show specific day/week/month/year task\n\n", SOFTWARE_NAME, DISPLAY_TOKEN);

    printf("ADD COMMANDS:\n");
    printf("  %s %s \"task_content\"                   Add task to today\n", SOFTWARE_NAME, ADD_TOKEN);
    printf("  %s %s \"content\" -dateType YYYY.MM.DD   Add to specific date\n\n", SOFTWARE_NAME, ADD_TOKEN);

    printf("COMPLETE COMMANDS:\n");
    printf("  %s %s TID                      Mark task as done (today)\n", SOFTWARE_NAME, COMPLETE_TOKEN);
    printf("  %s %s TID -dateType YYYY.MM.DD Mark task as done (specific date)\n\n", SOFTWARE_NAME, COMPLETE_TOKEN);

    printf("DELETE COMMANDS:\n");
    printf("  %s %s TID                      Delete task (today)\n", SOFTWARE_NAME, DELETE_TOKEN);
    printf("  %s %s TID -dateType YYYY.MM.DD Delete task (specific date)\n\n", SOFTWARE_NAME, DELETE_TOKEN);

    printf("TOGGLE COMMANDS:\n");
    printf("  %s %s TID                      Toggle task status (today)\n", SOFTWARE_NAME, TOGGLE_TOKEN);
    printf("  %s %s TID -dateType YYYY.MM.DD Toggle task (specific date)\n\n", SOFTWARE_NAME, TOGGLE_TOKEN);

    printf("EDIT COMMANDS:\n");
    printf("  %s %s TID \"all_content\"                         Replace task (today)\n", SOFTWARE_NAME, EDIT_ALL_TOKEN);
    printf("  %s %s TID \"all_content\"    -dateType YYYY.MM.DD Replace task (specific date)\n", SOFTWARE_NAME, EDIT_ALL_TOKEN);
    printf("  %s %s TID \"prefix_content\"                      Prepend to task(today)\n", SOFTWARE_NAME, EDIT_PREFIX_TOKEN);
    printf("  %s %s TID \"prefix_content\" -dateType YYYY.MM.DD Prepend to task(specific date)\n", SOFTWARE_NAME, EDIT_PREFIX_TOKEN);
    printf("  %s %s TID \"suffix_content\"                      Append to task(today)\n", SOFTWARE_NAME, EDIT_SUFFIX_TOKEN);
    printf("  %s %s TID \"suffix_content\" -dateType YYYY.MM.DD Append to task (specific date)\n\n", SOFTWARE_NAME, EDIT_SUFFIX_TOKEN);

    printf("CONFIGURATION:\n");
    printf("  %s $ key%svalue            Set configuration\n",SOFTWARE_NAME, EQUAL);
    printf("      Available keys:\n");
    printf("      - %s: %s/%s       Enable/disable colored output\n",SETTING_COLOR_KEY,SETTING_COLOR_ALLOW_ON,SETTING_COLOR_ALLOW_OFF);
    printf("      - %s: %s/%s/%s/%s/%s/%s/%s/%s      Default display mode\n",SETTING_SHOW_KEY, SHOW_DAY_1,SHOW_DAY_2, SHOW_WEEK_1, SHOW_WEEK_2, SHOW_MONTH_1, SHOW_MONTH_2, SHOW_YEAR_1, SHOW_YEAR_2);
}
