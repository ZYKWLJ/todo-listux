#include "../../include/include.h"
#define SOFTWARE_NAME "tl"
#define PROCESS_NAME "process"
#define COMMAND "command"
#define ARGUMENTS1 "arguments1"
#define ARGUMENTS2 "arguments2"
#define ARGUMENTS3 "arguments3"
#define ARGUMENTS4 "arguments4"
#define INSTRUCTION "instruction"
// #define DISPLAY_TOKEN "^"
// #define ADD_TOKEN "+"
// #define COMPLETE_TOKEN "-"
// #define DELETE_TOKEN "/"
// #define TOGGLE_TOKEN "!"
// #define CONFIGURATION_TOKEN "$"
// #define EDIT_ALL_TOKEN "="
// #define EDIT_PREFIX_TOKEN "=%"
// #define EDIT_SUFFIX_TOKEN "%="
// #define EQUAL "="

// 用户手册
// 这里引入我们对流层的编排系统，直接用编排系统的接口，实现标准的编排！
#define HEAD "TaskLite (tl) Command Reference"
#define USAGE "Usage: tl [command] [arguments]"
#define DATE_TYPE_HELP "Following date_type means d/day w/week m/month y/year"
#define DATE_FOMAT_HELP "Following fixed date_fomat : d/day=>xxxx.xx.xx\tw/week=>xxxx.xx.xx\tm/month=>xxxx.xx\ty/year=>xxxx"
#define TID_HELP "Following TID means task_index"
#define SHOW_COMMANDS "SHOW COMMANDS:"
#define ADD_COMMANDS "ADD COMMANDS:"
#define COMPLETE_COMMANDS "COMPLETE COMMANDS:"
#define DELETE_COMMANDS "DELETE COMMANDS:"
#define TOGGLE_COMMANDS "TOGGLE COMMANDS:"
#define CONFIGURATION "CONFIGURATION COMMANDS:"
#define EDIT_COMMANDS "EDIT COMMANDS:"
#define DATE_TYPE "-date_type"
#define DATE_FOMAT "-date_fomat"
#define TID "TID"
#define CONTENT "content"
#define DISPLAY_TODAY_TASK "Show task (today)"
#define DISPLAY_SPECIFIC_DATE_TASK "Show task (specific date)"
#define ADD_TASK_TO_TODAY "Add task (today)"
#define ADD_TASK_TO_SPECIFIC_DATE "Add task (specific date)"
#define MARK_TASK_AS_DONE_TODAY "Mark task as done (today)"
#define MARK_TASK_AS_DONE_SPECIFIC_DATE "Mark task as done (specific date)"
#define DELETE_TASK_TODAY "Delete task (today)"
#define DELETE_TASK_SPECIFIC_DATE "Delete task (specific date)"
#define TOGGLE_TASK_TODAY "Toggle task (today)"
#define TOGGLE_TASK_SPECIFIC_DATE "Toggle task (specific date)"
#define REPLACE_TASK_TODAY "Replace task (today)"
#define REPLACE_TASK_SPECIFIC_DATE "Replace task (specific date)"
#define PREPEND_TO_TASK_TODAY "Prepend to task (today)"
#define PREPEND_TO_TASK_SPECIFIC_DATE "Prepend to task (specific date)"
#define APPEND_TO_TASK_TODAY "Append to task (today)"
#define APPEND_TO_TASK_SPECIFIC_DATE "Append to task (specific date)"
#define SET_CONFIGURATION "Set configuration KEY to VALUE"
#define CONFIGURATION_HELP "Setting available keys:"
#define KV "KEY=VALUE"
#define CONFIGURATION_COLOR "on/off"
#define CONFIGURATION_SHOW "d/day/w/week/m/month/y/year"
#define COLOR_ON "Enable colored output"
#define COLOR_OFF "Disable colored output"
#define SHOW_DAY "Default display mode (day)"
#define SHOW_WEEK "Default display mode (week)"
#define SHOW_MONTH "Default display mode (month)"
#define SHOW_YEAR "Default display mode (year)"
#define NO_WORD ""
#define TL SOFTWARE_NAME

void help()
{

    printf("\n\n%s\n", HEAD);
    printf("%s\n", USAGE);
    printf("%s\n", DATE_TYPE_HELP);
    printf("%s\n", DATE_FOMAT_HELP);
    printf("%s\n", TID_HELP);
    // 第0列（序号列）
    const char *index[] = {"Index", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", NULL};
    // 第一列进程名
    const char *soft_name[] = {PROCESS_NAME, TL /*1*/, TL /*2*/, TL /*3*/, TL /*4*/, TL /*5*/, TL /*6*/, TL /*7*/, TL /*8*/, TL /*9*/, TL /*10*/, TL /*11*/, TL /*12*/, TL /*13*/, TL /*14*/, TL /*15*/, TL /*16*/, TL /*17*/, NULL};
    // 第二列命令
    const char *command[] = {COMMAND, DISPLAY_TOKEN /*1*/, DISPLAY_TOKEN /*2*/, ADD_TOKEN /*3*/, ADD_TOKEN /*4*/, COMPLETE_TOKEN /*5*/, COMPLETE_TOKEN /*6*/, DELETE_TOKEN /*7*/, DELETE_TOKEN /*8*/, TOGGLE_TOKEN /*9*/, TOGGLE_TOKEN /*10*/, EDIT_ALL_TOKEN /*11*/, EDIT_ALL_TOKEN /*12*/, EDIT_PREFIX_TOKEN /*13*/, EDIT_PREFIX_TOKEN /*14*/, EDIT_SUFFIX_TOKEN /*15*/, EDIT_SUFFIX_TOKEN /*16*/, CONFIGURATION_TOKEN /*17*/, NULL};
    // 第三列参数1
    const char *arguments1[] = {ARGUMENTS1, NO_WORD /*1*/, DATE_TYPE /*2*/, NO_WORD /*3*/, CONTENT /*4*/, NO_WORD /*5*/, TID /*6*/, NO_WORD /*7*/, TID /*8*/, NO_WORD /*9*/, TID /*10*/, NO_WORD /*11*/, TID /*12*/, NO_WORD /*13*/, TID /*14*/, NO_WORD /*15*/, TID /*16*/, KV /*17*/, NULL};
    // 第四列参数2
    const char *arguments2[] = {ARGUMENTS2, NO_WORD /*1*/, DATE_FOMAT /*2*/, NO_WORD /*3*/, DATE_TYPE /*4*/, NO_WORD /*5*/, DATE_TYPE /*6*/, NO_WORD /*7*/, DATE_TYPE /*8*/, NO_WORD /*9*/, DATE_TYPE /*10*/, NO_WORD /*11*/, CONTENT /*12*/, NO_WORD /*13*/, CONTENT /*14*/, NO_WORD /*15*/, CONTENT /*16*/, NO_WORD /*17*/, NULL};
    // 第五列参数3
    const char *arguments3[] = {ARGUMENTS3, NO_WORD /*1*/, NO_WORD /*2*/, NO_WORD /*3*/, DATE_FOMAT /*4*/, NO_WORD /*5*/, DATE_FOMAT /*6*/, NO_WORD /*7*/, DATE_FOMAT /*8*/, NO_WORD /*9*/, DATE_FOMAT /*10*/, NO_WORD /*11*/, DATE_TYPE /*12*/, NO_WORD /*13*/, DATE_TYPE /*14*/, NO_WORD /*15*/, DATE_TYPE /*16*/, NO_WORD /*17*/, NULL};
    // 第六列参数4
    const char *arguments4[] = {ARGUMENTS4, NO_WORD /*1*/, NO_WORD /*2*/, NO_WORD /*3*/, NO_WORD /*4*/, NO_WORD /*5*/, NO_WORD /*6*/, NO_WORD /*7*/, NO_WORD /*8*/, NO_WORD /*9*/, NO_WORD /*10*/, NO_WORD /*11*/, DATE_FOMAT /*12*/, NO_WORD /*13*/, DATE_FOMAT /*14*/, NO_WORD /*15*/, DATE_FOMAT /*16*/, NO_WORD /*17*/, NULL};
    // 第七列命令解释
    const char *instruction[] = {INSTRUCTION, DISPLAY_TODAY_TASK /*1*/, DISPLAY_SPECIFIC_DATE_TASK /*2*/, ADD_TASK_TO_TODAY /*3*/, ADD_TASK_TO_SPECIFIC_DATE /*4*/, MARK_TASK_AS_DONE_TODAY /*5*/, MARK_TASK_AS_DONE_SPECIFIC_DATE /*6*/, DELETE_TASK_TODAY /*7*/, DELETE_TASK_SPECIFIC_DATE /*8*/, TOGGLE_TASK_TODAY /*9*/, TOGGLE_TASK_SPECIFIC_DATE /*10*/, REPLACE_TASK_TODAY /*11*/, REPLACE_TASK_SPECIFIC_DATE /*12*/, PREPEND_TO_TASK_TODAY /*13*/, PREPEND_TO_TASK_SPECIFIC_DATE /*14*/, APPEND_TO_TASK_TODAY /*15*/, APPEND_TO_TASK_SPECIFIC_DATE /*16*/, SET_CONFIGURATION /*17*/, NULL};
    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
    // 可选的设置全文
    printf("\n\n%s\n", CONFIGURATION_HELP);
    const char *KEY[] = {"KEY", SETTING_COLOR_KEY, SETTING_SHOW_KEY, NULL};
    const char *VALUE[] = {"VALUE", CONFIGURATION_COLOR, CONFIGURATION_SHOW, NULL};
    const char **columns2[] = {KEY, VALUE};
    text_print_help(columns2, sizeof(columns2) / sizeof(columns2[0]));
}
