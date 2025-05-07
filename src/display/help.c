#include "../../include/include.h"
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
    const char *soft_name[] = {PROCESS_NAME, TL, TL /*1*/, TL /*2*/, TL /*3*/, TL /*4*/, TL /*5*/, TL /*6*/, TL /*7*/, TL /*8*/, TL /*9*/, TL /*10*/, TL /*11*/, TL /*12*/, TL /*13*/, TL /*14*/, TL /*15*/, TL /*16*/, TL /*17*/, NULL};
    // 第二列命令
    const char *command[] = {COMMAND, HELP_TOKEN, CONFIGURATION_TOKEN /*17*/, DISPLAY_TOKEN /*1*/, DISPLAY_TOKEN /*2*/, ADD_TOKEN /*3*/, ADD_TOKEN /*4*/, COMPLETE_TOKEN /*5*/, COMPLETE_TOKEN /*6*/, DELETE_TOKEN /*7*/, DELETE_TOKEN /*8*/, TOGGLE_TOKEN /*9*/, TOGGLE_TOKEN /*10*/, EDIT_ALL_TOKEN /*11*/, EDIT_ALL_TOKEN /*12*/, EDIT_PREFIX_TOKEN /*13*/, EDIT_PREFIX_TOKEN /*14*/, EDIT_SUFFIX_TOKEN /*15*/, EDIT_SUFFIX_TOKEN /*16*/, NULL};
    // 第三列参数1
    const char *arguments1[] = {ARGUMENTS1, NO_WORD, KV /*17*/, NO_WORD /*1*/, DATE_TYPE /*2*/, CONTENT /*3*/, CONTENT /*4*/, TID /*5*/, TID /*6*/, TID /*7*/, TID /*8*/, TID /*9*/, TID /*10*/, TID /*11*/, TID /*12*/, TID /*13*/, TID /*14*/, TID /*15*/, TID /*16*/, NULL};
    // 第四列参数2
    const char *arguments2[] = {ARGUMENTS2, NO_WORD /*17*/, NO_WORD, NO_WORD /*1*/, DATE_FOMAT /*2*/, NO_WORD /*3*/, DATE_TYPE /*4*/, NO_WORD /*5*/, DATE_TYPE /*6*/, NO_WORD /*7*/, DATE_TYPE /*8*/, NO_WORD /*9*/, DATE_TYPE /*10*/, CONTENT /*11*/, CONTENT /*12*/, CONTENT /*13*/, CONTENT /*14*/, CONTENT /*15*/, CONTENT /*16*/, NULL};
    // 第五列参数3
    const char *arguments3[] = {ARGUMENTS3, NO_WORD /*17*/, NO_WORD, NO_WORD /*1*/, NO_WORD /*2*/, NO_WORD /*3*/, DATE_FOMAT /*4*/, NO_WORD /*5*/, DATE_FOMAT /*6*/, NO_WORD /*7*/, DATE_FOMAT /*8*/, NO_WORD /*9*/, DATE_FOMAT /*10*/, NO_WORD /*11*/, DATE_TYPE /*12*/, NO_WORD /*13*/, DATE_TYPE /*14*/, NO_WORD /*15*/, DATE_TYPE /*16*/, NULL};
    // 第六列参数4
    const char *arguments4[] = {ARGUMENTS4, NO_WORD, NO_WORD /*17*/, NO_WORD /*1*/, NO_WORD /*2*/, NO_WORD /*3*/, NO_WORD /*4*/, NO_WORD /*5*/, NO_WORD /*6*/, NO_WORD /*7*/, NO_WORD /*8*/, NO_WORD /*9*/, NO_WORD /*10*/, NO_WORD /*11*/, DATE_FOMAT /*12*/, NO_WORD /*13*/, DATE_FOMAT /*14*/, NO_WORD /*15*/, DATE_FOMAT /*16*/, NULL};
    // 第七列命令解释
    const char *instruction[] = {INSTRUCTION, USER_HELP, SET_CONFIGURATION /*17*/, DISPLAY_TODAY_TASK /*1*/, DISPLAY_SPECIFIC_DATE_TASK /*2*/, ADD_TASK_TO_TODAY /*3*/, ADD_TASK_TO_SPECIFIC_DATE /*4*/, MARK_TASK_AS_DONE_TODAY /*5*/, MARK_TASK_AS_DONE_SPECIFIC_DATE /*6*/, DELETE_TASK_TODAY /*7*/, DELETE_TASK_SPECIFIC_DATE /*8*/, TOGGLE_TASK_TODAY /*9*/, TOGGLE_TASK_SPECIFIC_DATE /*10*/, REPLACE_TASK_TODAY /*11*/, REPLACE_TASK_SPECIFIC_DATE /*12*/, PREPEND_TO_TASK_TODAY /*13*/, PREPEND_TO_TASK_SPECIFIC_DATE /*14*/, APPEND_TO_TASK_TODAY /*15*/, APPEND_TO_TASK_SPECIFIC_DATE /*16*/, NULL};
    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
    // 可选的设置全文
    printf("\n%s\n", CONFIGURATION_HELP);
    const char *KEY[] = {"KEY", SETTING_COLOR_KEY, SETTING_SHOW_KEY, NULL};
    const char *VALUE[] = {"VALUE", CONFIGURATION_COLOR, CONFIGURATION_SHOW, NULL};
    const char **columns2[] = {KEY, VALUE};
    text_print_help(columns2, sizeof(columns2) / sizeof(columns2[0]));
}

void help_show()
{

    // 第一列进程名
    const char *soft_name[] = {PROCESS_NAME, TL /*1*/, TL /*2*/, NULL /*3*/, TL /*4*/, TL /*5*/, TL /*6*/, TL /*7*/, TL /*8*/, TL /*9*/, TL /*10*/, TL /*11*/, TL /*12*/, TL /*13*/, TL /*14*/, TL /*15*/, TL /*16*/, TL /*17*/, NULL};
    // 第二列命令
    const char *command[] = {COMMAND, DISPLAY_TOKEN /*1*/, DISPLAY_TOKEN /*2*/, NULL /*3*/, ADD_TOKEN /*4*/, COMPLETE_TOKEN /*5*/, COMPLETE_TOKEN /*6*/, DELETE_TOKEN /*7*/, DELETE_TOKEN /*8*/, TOGGLE_TOKEN /*9*/, TOGGLE_TOKEN /*10*/, EDIT_ALL_TOKEN /*11*/, EDIT_ALL_TOKEN /*12*/, EDIT_PREFIX_TOKEN /*13*/, EDIT_PREFIX_TOKEN /*14*/, EDIT_SUFFIX_TOKEN /*15*/, EDIT_SUFFIX_TOKEN /*16*/, CONFIGURATION_TOKEN /*17*/, NULL};
    // 第三列参数1
    const char *arguments1[] = {ARGUMENTS1, NO_WORD /*1*/, DATE_TYPE /*2*/, NULL /*3*/, CONTENT /*4*/, NO_WORD /*5*/, TID /*6*/, NO_WORD /*7*/, TID /*8*/, NO_WORD /*9*/, TID /*10*/, NO_WORD /*11*/, TID /*12*/, NO_WORD /*13*/, TID /*14*/, NO_WORD /*15*/, TID /*16*/, KV /*17*/, NULL};
    // 第四列参数2
    const char *arguments2[] = {ARGUMENTS2, NO_WORD /*1*/, DATE_FOMAT /*2*/, NULL /*3*/, DATE_TYPE /*4*/, NO_WORD /*5*/, DATE_TYPE /*6*/, NO_WORD /*7*/, DATE_TYPE /*8*/, NO_WORD /*9*/, DATE_TYPE /*10*/, NO_WORD /*11*/, CONTENT /*12*/, NO_WORD /*13*/, CONTENT /*14*/, NO_WORD /*15*/, CONTENT /*16*/, NO_WORD /*17*/, NULL};
    // 第五列参数3
    const char *arguments3[] = {ARGUMENTS3, NO_WORD /*1*/, NO_WORD /*2*/, NULL /*3*/, DATE_FOMAT /*4*/, NO_WORD /*5*/, DATE_FOMAT /*6*/, NO_WORD /*7*/, DATE_FOMAT /*8*/, NO_WORD /*9*/, DATE_FOMAT /*10*/, NO_WORD /*11*/, DATE_TYPE /*12*/, NO_WORD /*13*/, DATE_TYPE /*14*/, NO_WORD /*15*/, DATE_TYPE /*16*/, NO_WORD /*17*/, NULL};
    // 第六列参数4
    const char *arguments4[] = {ARGUMENTS4, NO_WORD /*1*/, NO_WORD /*2*/, NULL /*3*/, NO_WORD /*4*/, NO_WORD /*5*/, NO_WORD /*6*/, NO_WORD /*7*/, NO_WORD /*8*/, NO_WORD /*9*/, NO_WORD /*10*/, NO_WORD /*11*/, DATE_FOMAT /*12*/, NO_WORD /*13*/, DATE_FOMAT /*14*/, NO_WORD /*15*/, DATE_FOMAT /*16*/, NO_WORD /*17*/, NULL};
    // 第七列命令解释
    const char *instruction[] = {INSTRUCTION, DISPLAY_TODAY_TASK /*1*/, DISPLAY_SPECIFIC_DATE_TASK /*2*/, NULL /*3*/, ADD_TASK_TO_SPECIFIC_DATE /*4*/, MARK_TASK_AS_DONE_TODAY /*5*/, MARK_TASK_AS_DONE_SPECIFIC_DATE /*6*/, DELETE_TASK_TODAY /*7*/, DELETE_TASK_SPECIFIC_DATE /*8*/, TOGGLE_TASK_TODAY /*9*/, TOGGLE_TASK_SPECIFIC_DATE /*10*/, REPLACE_TASK_TODAY /*11*/, REPLACE_TASK_SPECIFIC_DATE /*12*/, PREPEND_TO_TASK_TODAY /*13*/, PREPEND_TO_TASK_SPECIFIC_DATE /*14*/, APPEND_TO_TASK_TODAY /*15*/, APPEND_TO_TASK_SPECIFIC_DATE /*16*/, SET_CONFIGURATION /*17*/, NULL};
    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
}

void help_add()
{

    // 第0列（序号列）
    const char *index[] = {"Index", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", NULL};
    // 第一列进程名
    const char *soft_name[] = {PROCESS_NAME, TL /*4*/, TL /*5*/, NULL, TL /*6*/, TL /*7*/, TL /*8*/, TL /*9*/, TL /*10*/, TL /*11*/, TL /*12*/, TL /*13*/, TL /*14*/, TL /*15*/, TL /*16*/, TL /*17*/, NULL};
    // 第二列命令
    const char *command[] = {COMMAND, ADD_TOKEN /*4*/, ADD_TOKEN /*4*/, COMPLETE_TOKEN /*5*/, COMPLETE_TOKEN /*6*/, NULL, DELETE_TOKEN /*7*/, DELETE_TOKEN /*8*/, TOGGLE_TOKEN /*9*/, TOGGLE_TOKEN /*10*/, EDIT_ALL_TOKEN /*11*/, EDIT_ALL_TOKEN /*12*/, EDIT_PREFIX_TOKEN /*13*/, EDIT_PREFIX_TOKEN /*14*/, EDIT_SUFFIX_TOKEN /*15*/, EDIT_SUFFIX_TOKEN /*16*/, CONFIGURATION_TOKEN /*17*/, NULL};
    // 第三列参数1
    const char *arguments1[] = {ARGUMENTS1, NO_WORD /*5*/, CONTENT /*4*/, NULL, TID /*6*/, NO_WORD /*7*/, TID /*8*/, NO_WORD /*9*/, TID /*10*/, NO_WORD /*11*/, TID /*12*/, NO_WORD /*13*/, TID /*14*/, NO_WORD /*15*/, TID /*16*/, KV /*17*/, NULL};
    // 第四列参数2
    const char *arguments2[] = {ARGUMENTS2, NO_WORD /*5*/, DATE_TYPE /*4*/, NULL, DATE_TYPE /*6*/, NO_WORD /*7*/, DATE_TYPE /*8*/, NO_WORD /*9*/, DATE_TYPE /*10*/, NO_WORD /*11*/, CONTENT /*12*/, NO_WORD /*13*/, CONTENT /*14*/, NO_WORD /*15*/, CONTENT /*16*/, NO_WORD /*17*/, NULL};
    // 第五列参数3
    const char *arguments3[] = {ARGUMENTS3, NO_WORD /*5*/, DATE_FOMAT /*4*/, NULL, DATE_FOMAT /*6*/, NO_WORD /*7*/, DATE_FOMAT /*8*/, NO_WORD /*9*/, DATE_FOMAT /*10*/, NO_WORD /*11*/, DATE_TYPE /*12*/, NO_WORD /*13*/, DATE_TYPE /*14*/, NO_WORD /*15*/, DATE_TYPE /*16*/, NO_WORD /*17*/, NULL};
    // 第六列参数4
    const char *arguments4[] = {ARGUMENTS4, NO_WORD /*5*/, NO_WORD /*4*/, NULL, NO_WORD /*6*/, NO_WORD /*7*/, NO_WORD /*8*/, NO_WORD /*9*/, NO_WORD /*10*/, NO_WORD /*11*/, DATE_FOMAT /*12*/, NO_WORD /*13*/, DATE_FOMAT /*14*/, NO_WORD /*15*/, DATE_FOMAT /*16*/, NO_WORD /*17*/, NULL};
    // 第七列命令解释
    const char *instruction[] = {INSTRUCTION, ADD_TASK_TO_SPECIFIC_DATE /*4*/, MARK_TASK_AS_DONE_TODAY /*5*/, NULL, MARK_TASK_AS_DONE_SPECIFIC_DATE /*6*/, DELETE_TASK_TODAY /*7*/, DELETE_TASK_SPECIFIC_DATE /*8*/, TOGGLE_TASK_TODAY /*9*/, TOGGLE_TASK_SPECIFIC_DATE /*10*/, REPLACE_TASK_TODAY /*11*/, REPLACE_TASK_SPECIFIC_DATE /*12*/, PREPEND_TO_TASK_TODAY /*13*/, PREPEND_TO_TASK_SPECIFIC_DATE /*14*/, APPEND_TO_TASK_TODAY /*15*/, APPEND_TO_TASK_SPECIFIC_DATE /*16*/, SET_CONFIGURATION /*17*/, NULL};
    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
}

void help_delete()
{

    // 第0列（序号列）
    const char *index[] = {"Index", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", NULL};
    // 第一列进程名
    const char *soft_name[] = {PROCESS_NAME, TL /*4*/, TL /*5*/, NULL, TL /*6*/, TL /*7*/, TL /*8*/, TL /*9*/, TL /*10*/, TL /*11*/, TL /*12*/, TL /*13*/, TL /*14*/, TL /*15*/, TL /*16*/, TL /*17*/, NULL};
    // 第二列命令
    const char *command[] = {COMMAND, DELETE_TOKEN /*7*/, DELETE_TOKEN /*8*/, NULL, TOGGLE_TOKEN /*9*/, TOGGLE_TOKEN /*10*/, EDIT_ALL_TOKEN /*11*/, EDIT_ALL_TOKEN /*12*/, EDIT_PREFIX_TOKEN /*13*/, EDIT_PREFIX_TOKEN /*14*/, EDIT_SUFFIX_TOKEN /*15*/, EDIT_SUFFIX_TOKEN /*16*/, CONFIGURATION_TOKEN /*17*/, NULL};
    // 第三列参数1
    const char *arguments1[] = {ARGUMENTS1, NO_WORD /*7*/, TID /*8*/, NULL, NO_WORD /*9*/, TID /*10*/, NO_WORD /*11*/, TID /*12*/, NO_WORD /*13*/, TID /*14*/, NO_WORD /*15*/, TID /*16*/, KV /*17*/, NULL};
    // 第四列参数2
    const char *arguments2[] = {ARGUMENTS2, NO_WORD /*7*/, DATE_TYPE /*8*/, NULL, NO_WORD /*9*/, DATE_TYPE /*10*/, NO_WORD /*11*/, CONTENT /*12*/, NO_WORD /*13*/, CONTENT /*14*/, NO_WORD /*15*/, CONTENT /*16*/, NO_WORD /*17*/, NULL};
    // 第五列参数3
    const char *arguments3[] = {ARGUMENTS3, NO_WORD /*7*/, DATE_FOMAT /*8*/, NULL, NO_WORD /*9*/, DATE_FOMAT /*10*/, NO_WORD /*11*/, DATE_TYPE /*12*/, NO_WORD /*13*/, DATE_TYPE /*14*/, NO_WORD /*15*/, DATE_TYPE /*16*/, NO_WORD /*17*/, NULL};
    // 第六列参数4
    const char *arguments4[] = {ARGUMENTS4, NO_WORD /*8*/, NO_WORD /*9*/, NULL, NO_WORD /*10*/, NO_WORD /*11*/, DATE_FOMAT /*12*/, NO_WORD /*13*/, DATE_FOMAT /*14*/, NO_WORD /*15*/, DATE_FOMAT /*16*/, NO_WORD /*17*/, NULL};
    // 第七列命令解释
    const char *instruction[] = {INSTRUCTION, DELETE_TASK_TODAY /*7*/, DELETE_TASK_SPECIFIC_DATE /*8*/, NULL, TOGGLE_TASK_TODAY /*9*/, TOGGLE_TASK_SPECIFIC_DATE /*10*/, REPLACE_TASK_TODAY /*11*/, REPLACE_TASK_SPECIFIC_DATE /*12*/, PREPEND_TO_TASK_TODAY /*13*/, PREPEND_TO_TASK_SPECIFIC_DATE /*14*/, APPEND_TO_TASK_TODAY /*15*/, APPEND_TO_TASK_SPECIFIC_DATE /*16*/, SET_CONFIGURATION /*17*/, NULL};
    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
}

void help_done()
{
    // 第0列（序号列）
    const char *index[] = {"Index", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", NULL};
    // 第一列进程名
    const char *soft_name[] = {PROCESS_NAME, TL /*5*/, TL /*6*/, NULL, TL /*7*/, TL /*8*/, TL /*9*/, TL /*10*/, TL /*11*/, TL /*12*/, TL /*13*/, TL /*14*/, TL /*15*/, TL /*16*/, TL /*17*/, NULL};
    // 第二列命令
    const char *command[] = {COMMAND, COMPLETE_TOKEN /*5*/, COMPLETE_TOKEN /*6*/, NULL, DELETE_TOKEN /*7*/, DELETE_TOKEN /*8*/, TOGGLE_TOKEN /*9*/, TOGGLE_TOKEN /*10*/, EDIT_ALL_TOKEN /*11*/, EDIT_ALL_TOKEN /*12*/, EDIT_PREFIX_TOKEN /*13*/, EDIT_PREFIX_TOKEN /*14*/, EDIT_SUFFIX_TOKEN /*15*/, EDIT_SUFFIX_TOKEN /*16*/, CONFIGURATION_TOKEN /*17*/, NULL};
    // 第三列参数1
    const char *arguments1[] = {ARGUMENTS1, NO_WORD /*5*/, TID /*6*/, NULL, NO_WORD /*7*/, TID /*8*/, NO_WORD /*9*/, TID /*10*/, NO_WORD /*11*/, TID /*12*/, NO_WORD /*13*/, TID /*14*/, NO_WORD /*15*/, TID /*16*/, KV /*17*/, NULL};
    // 第四列参数2
    const char *arguments2[] = {ARGUMENTS2, NO_WORD /*5*/, DATE_TYPE /*6*/, NULL, NO_WORD /*7*/, DATE_TYPE /*8*/, NO_WORD /*9*/, DATE_TYPE /*10*/, NO_WORD /*11*/, CONTENT /*12*/, NO_WORD /*13*/, CONTENT /*14*/, NO_WORD /*15*/, CONTENT /*16*/, NO_WORD /*17*/, NULL};
    // 第五列参数3
    const char *arguments3[] = {ARGUMENTS3, NO_WORD /*5*/, DATE_FOMAT /*6*/, NULL, NO_WORD /*7*/, DATE_FOMAT /*8*/, NO_WORD /*9*/, DATE_FOMAT /*10*/, NO_WORD /*11*/, DATE_TYPE /*12*/, NO_WORD /*13*/, DATE_TYPE /*14*/, NO_WORD /*15*/, DATE_TYPE /*16*/, NO_WORD /*17*/, NULL};
    // 第六列参数4
    const char *arguments4[] = {ARGUMENTS4, NO_WORD /*5*/, NO_WORD /*6*/, NULL, NO_WORD /*7*/, NO_WORD /*8*/, NO_WORD /*9*/, NO_WORD /*10*/, NO_WORD /*11*/, DATE_FOMAT /*12*/, NO_WORD /*13*/, DATE_FOMAT /*14*/, NO_WORD /*15*/, DATE_FOMAT /*16*/, NO_WORD /*17*/, NULL};
    // 第七列命令解释
    const char *instruction[] = {INSTRUCTION, MARK_TASK_AS_DONE_TODAY /*5*/, MARK_TASK_AS_DONE_SPECIFIC_DATE /*6*/, NULL, DELETE_TASK_TODAY /*7*/, DELETE_TASK_SPECIFIC_DATE /*8*/, TOGGLE_TASK_TODAY /*9*/, TOGGLE_TASK_SPECIFIC_DATE /*10*/, REPLACE_TASK_TODAY /*11*/, REPLACE_TASK_SPECIFIC_DATE /*12*/, PREPEND_TO_TASK_TODAY /*13*/, PREPEND_TO_TASK_SPECIFIC_DATE /*14*/, APPEND_TO_TASK_TODAY /*15*/, APPEND_TO_TASK_SPECIFIC_DATE /*16*/, SET_CONFIGURATION /*17*/, NULL};
    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
}

void help_toggle()
{
    // 第0列（序号列）
    const char *index[] = {"Index", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", NULL};
    // 第一列进程名
    const char *soft_name[] = {PROCESS_NAME, TL /*5*/, TL /*6*/, NULL, TL /*7*/, TL /*8*/, TL /*9*/, TL /*10*/, TL /*11*/, TL /*12*/, TL /*13*/, TL /*14*/, TL /*15*/, TL /*16*/, TL /*17*/, NULL};
    // 第二列命令
    const char *command[] = {COMMAND, TOGGLE_TOKEN /*9*/, TOGGLE_TOKEN /*10*/, NULL, EDIT_ALL_TOKEN /*11*/, EDIT_ALL_TOKEN /*12*/, EDIT_PREFIX_TOKEN /*13*/, EDIT_PREFIX_TOKEN /*14*/, EDIT_SUFFIX_TOKEN /*15*/, EDIT_SUFFIX_TOKEN /*16*/, CONFIGURATION_TOKEN /*17*/, NULL};
    // 第三列参数1
    const char *arguments1[] = {ARGUMENTS1, TID /*9*/, TID /*10*/, NULL, NO_WORD /*11*/, TID /*12*/, NO_WORD /*13*/, TID /*14*/, NO_WORD /*15*/, TID /*16*/, KV /*17*/, NULL};
    // 第四列参数2
    const char *arguments2[] = {ARGUMENTS2, NO_WORD /*9*/, DATE_TYPE /*10*/, NULL, NO_WORD /*11*/, CONTENT /*12*/, NO_WORD /*13*/, CONTENT /*14*/, NO_WORD /*15*/, CONTENT /*16*/, NO_WORD /*17*/, NULL};
    // 第五列参数3
    const char *arguments3[] = {ARGUMENTS3, NO_WORD /*9*/, DATE_FOMAT /*10*/, NULL, NO_WORD /*11*/, DATE_TYPE /*12*/, NO_WORD /*13*/, DATE_TYPE /*14*/, NO_WORD /*15*/, DATE_TYPE /*16*/, NO_WORD /*17*/, NULL};
    // 第六列参数4
    const char *arguments4[] = {ARGUMENTS4, NO_WORD /*9*/, NO_WORD /*10*/, NULL, NO_WORD /*11*/, DATE_FOMAT /*12*/, NO_WORD /*13*/, DATE_FOMAT /*14*/, NO_WORD /*15*/, DATE_FOMAT /*16*/, NO_WORD /*17*/, NULL};
    // 第七列命令解释
    const char *instruction[] = {INSTRUCTION, TOGGLE_TASK_TODAY /*9*/, TOGGLE_TASK_SPECIFIC_DATE /*10*/, NULL, REPLACE_TASK_TODAY /*11*/, REPLACE_TASK_SPECIFIC_DATE /*12*/, PREPEND_TO_TASK_TODAY /*13*/, PREPEND_TO_TASK_SPECIFIC_DATE /*14*/, APPEND_TO_TASK_TODAY /*15*/, APPEND_TO_TASK_SPECIFIC_DATE /*16*/, SET_CONFIGURATION /*17*/, NULL};
    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
}
void help_edit()
{
    // 第0列（序号列）
    const char *index[] = {"Index", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", NULL};
    // 第一列进程名
    const char *soft_name[] = {PROCESS_NAME, TL /*5*/, TL /*6*/, TL /*7*/, TL /*8*/, TL /*9*/, TL /*10*/, NULL, TL /*11*/, TL /*12*/, TL /*13*/, TL /*14*/, TL /*15*/, TL /*16*/, TL /*17*/, NULL};
    // 第二列命令
    const char *command[] = {COMMAND, EDIT_ALL_TOKEN /*11*/, EDIT_ALL_TOKEN /*12*/, EDIT_PREFIX_TOKEN /*13*/, EDIT_PREFIX_TOKEN /*14*/, EDIT_SUFFIX_TOKEN /*15*/, EDIT_SUFFIX_TOKEN /*16*/, NULL, CONFIGURATION_TOKEN /*17*/, NULL};
    // 第三列参数1
    const char *arguments1[] = {ARGUMENTS1, TID /*11*/, TID /*12*/, TID /*13*/, TID /*14*/, TID /*15*/, TID /*16*/, NULL, KV /*17*/, NULL};
    // 第四列参数2
    const char *arguments2[] = {ARGUMENTS2, CONTENT /*11*/, CONTENT /*12*/, CONTENT /*13*/, CONTENT /*14*/, CONTENT /*15*/, CONTENT /*16*/, NULL, NO_WORD /*17*/, NULL};
    // 第五列参数3
    const char *arguments3[] = {ARGUMENTS3, NO_WORD /*11*/, DATE_TYPE /*12*/, NO_WORD /*13*/, DATE_TYPE /*14*/, NO_WORD /*15*/, DATE_TYPE /*16*/, NULL, NO_WORD /*17*/, NULL};
    // 第六列参数4
    const char *arguments4[] = {ARGUMENTS4, NO_WORD /*11*/, DATE_FOMAT /*12*/, NO_WORD /*13*/, DATE_FOMAT /*14*/, NO_WORD /*15*/, DATE_FOMAT /*16*/, NULL, NO_WORD /*17*/, NULL};
    // 第七列命令解释
    const char *instruction[] = {INSTRUCTION, REPLACE_TASK_TODAY /*11*/, REPLACE_TASK_SPECIFIC_DATE /*12*/, NULL, PREPEND_TO_TASK_TODAY /*13*/, PREPEND_TO_TASK_SPECIFIC_DATE /*14*/, APPEND_TO_TASK_TODAY /*15*/, APPEND_TO_TASK_SPECIFIC_DATE /*16*/, NULL, SET_CONFIGURATION /*17*/, NULL};
    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
}

void help_edit_all()
{
    // 第0列（序号列）
    const char *index[] = {"Index", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", NULL};
    // 第一列进程名
    const char *soft_name[] = {PROCESS_NAME, TL /*5*/, TL /*6*/, NULL, TL /*7*/, TL /*8*/, TL /*9*/, TL /*10*/, TL /*11*/, TL /*12*/, TL /*13*/, TL /*14*/, TL /*15*/, TL /*16*/, TL /*17*/, NULL};
    // 第二列命令
    const char *command[] = {COMMAND, EDIT_ALL_TOKEN /*11*/, EDIT_ALL_TOKEN /*12*/, NULL, EDIT_PREFIX_TOKEN /*13*/, EDIT_PREFIX_TOKEN /*14*/, EDIT_SUFFIX_TOKEN /*15*/, EDIT_SUFFIX_TOKEN /*16*/, CONFIGURATION_TOKEN /*17*/, NULL};
    // 第三列参数1
    const char *arguments1[] = {ARGUMENTS1, NO_WORD /*11*/, TID /*12*/, NULL, NO_WORD /*13*/, TID /*14*/, NO_WORD /*15*/, TID /*16*/, KV /*17*/, NULL};
    // 第四列参数2
    const char *arguments2[] = {ARGUMENTS2, NO_WORD /*11*/, CONTENT /*12*/, NULL, NO_WORD /*13*/, CONTENT /*14*/, NO_WORD /*15*/, CONTENT /*16*/, NO_WORD /*17*/, NULL};
    // 第五列参数3
    const char *arguments3[] = {ARGUMENTS3, NO_WORD /*11*/, DATE_TYPE /*12*/, NULL, NO_WORD /*13*/, DATE_TYPE /*14*/, NO_WORD /*15*/, DATE_TYPE /*16*/, NO_WORD /*17*/, NULL};
    // 第六列参数4
    const char *arguments4[] = {ARGUMENTS4, NO_WORD /*11*/, DATE_FOMAT /*12*/, NULL, NO_WORD /*13*/, DATE_FOMAT /*14*/, NO_WORD /*15*/, DATE_FOMAT /*16*/, NO_WORD /*17*/, NULL};
    // 第七列命令解释
    const char *instruction[] = {INSTRUCTION, REPLACE_TASK_TODAY /*11*/, REPLACE_TASK_SPECIFIC_DATE /*12*/, NULL, PREPEND_TO_TASK_TODAY /*13*/, PREPEND_TO_TASK_SPECIFIC_DATE /*14*/, APPEND_TO_TASK_TODAY /*15*/, APPEND_TO_TASK_SPECIFIC_DATE /*16*/, SET_CONFIGURATION /*17*/, NULL};
    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
}

void help_edit_prefix()
{
    // 第0列（序号列）
    const char *index[] = {"Index", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", NULL};
    // 第一列进程名
    const char *soft_name[] = {PROCESS_NAME, TL /*5*/, TL /*6*/, NULL, TL /*7*/, TL /*8*/, TL /*9*/, TL /*10*/, TL /*11*/, TL /*12*/, TL /*13*/, TL /*14*/, TL /*15*/, TL /*16*/, TL /*17*/, NULL};
    // 第二列命令
    const char *command[] = {COMMAND, EDIT_PREFIX_TOKEN /*13*/, EDIT_PREFIX_TOKEN /*14*/, NULL, EDIT_SUFFIX_TOKEN /*15*/, EDIT_SUFFIX_TOKEN /*16*/, CONFIGURATION_TOKEN /*17*/, NULL};
    // 第三列参数1
    const char *arguments1[] = {ARGUMENTS1, NO_WORD /*13*/, TID /*14*/, NULL, NO_WORD /*15*/, TID /*16*/, KV /*17*/, NULL};
    // 第四列参数2
    const char *arguments2[] = {ARGUMENTS2, NO_WORD /*13*/, CONTENT /*14*/, NULL, NO_WORD /*15*/, CONTENT /*16*/, NO_WORD /*17*/, NULL};
    // 第五列参数3
    const char *arguments3[] = {ARGUMENTS3, NO_WORD /*13*/, DATE_TYPE /*14*/, NULL, NO_WORD /*15*/, DATE_TYPE /*16*/, NO_WORD /*17*/, NULL};
    // 第六列参数4
    const char *arguments4[] = {ARGUMENTS4, NO_WORD /*13*/, DATE_FOMAT /*14*/, NULL, NO_WORD /*15*/, DATE_FOMAT /*16*/, NO_WORD /*17*/, NULL};
    // 第七列命令解释
    const char *instruction[] = {INSTRUCTION, PREPEND_TO_TASK_TODAY /*13*/, PREPEND_TO_TASK_SPECIFIC_DATE /*14*/, APPEND_TO_TASK_TODAY /*15*/, APPEND_TO_TASK_SPECIFIC_DATE /*16*/, SET_CONFIGURATION /*17*/, NULL};
    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
}

void help_edit_suffix()
{
    // 第0列（序号列）
    const char *index[] = {"Index", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", NULL};
    // 第一列进程名
    const char *soft_name[] = {PROCESS_NAME, TL /*5*/, TL /*6*/, NULL, TL /*7*/, TL /*8*/, TL /*9*/, TL /*10*/, TL /*11*/, TL /*12*/, TL /*13*/, TL /*14*/, TL /*15*/, TL /*16*/, TL /*17*/, NULL};
    // 第二列命令
    const char *command[] = {COMMAND, EDIT_SUFFIX_TOKEN /*15*/, EDIT_SUFFIX_TOKEN /*16*/, CONFIGURATION_TOKEN /*17*/, NULL};
    // 第三列参数1
    const char *arguments1[] = {ARGUMENTS1, NO_WORD /*15*/, TID /*16*/, NULL, KV /*17*/, NULL};
    // 第四列参数2
    const char *arguments2[] = {ARGUMENTS2, NO_WORD /*15*/, CONTENT /*16*/, NULL, NO_WORD /*17*/, NULL};
    // 第五列参数3
    const char *arguments3[] = {ARGUMENTS3, NO_WORD /*15*/, DATE_TYPE /*16*/, NULL, NO_WORD /*17*/, NULL};
    // 第六列参数4
    const char *arguments4[] = {ARGUMENTS4, NO_WORD /*15*/, DATE_FOMAT /*16*/, NULL, NO_WORD /*17*/, NULL};
    // 第七列命令解释
    const char *instruction[] = {INSTRUCTION, APPEND_TO_TASK_TODAY /*15*/, APPEND_TO_TASK_SPECIFIC_DATE /*16*/, SET_CONFIGURATION /*17*/, NULL};
    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
}

void help_set()
{
    // 第0列（序号列）
    const char *index[] = {"Index", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", NULL};
    // 第一列进程名
    const char *soft_name[] = {PROCESS_NAME, TL /*5*/, TL /*6*/, NULL, TL /*7*/, TL /*8*/, TL /*9*/, TL /*10*/, TL /*11*/, TL /*12*/, TL /*13*/, TL /*14*/, TL /*15*/, TL /*16*/, TL /*17*/, NULL};
    // 第二列命令
    const char *command[] = {COMMAND, CONFIGURATION_TOKEN /*17*/, NULL};
    // 第三列参数1
    const char *arguments1[] = {ARGUMENTS1, KV /*17*/, NULL};
    // 第四列参数2
    const char *arguments2[] = {ARGUMENTS2, NO_WORD /*17*/, NULL};
    // 第五列参数3
    const char *arguments3[] = {ARGUMENTS3, NO_WORD /*17*/, NULL};
    // 第六列参数4
    const char *arguments4[] = {ARGUMENTS4, NO_WORD /*17*/, NULL};
    // 第七列命令解释
    const char *instruction[] = {INSTRUCTION, SET_CONFIGURATION /*17*/, NULL};
    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
    // 可选的设置全文
    printf("\n%s\n", CONFIGURATION_HELP);
    const char *KEY[] = {"KEY", SETTING_COLOR_KEY, SETTING_SHOW_KEY, NULL};
    const char *VALUE[] = {"VALUE", CONFIGURATION_COLOR, CONFIGURATION_SHOW, NULL};
    const char **columns2[] = {KEY, VALUE};
    text_print_help(columns2, sizeof(columns2) / sizeof(columns2[0]));
}