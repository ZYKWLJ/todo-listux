#include "../../include/include.h"
// 用于替换PROCESS_NAME为等长空格的宏
#define REPLACE_NAME_WITH_SPACE(str) replace_name_with_space(str, sizeof(str))
extern S_setting setting;
// 修改后的替换函数，返回char*类型
char *replace_name_with_space(char *str)
{
    char *pos = (char *)checked_malloc(sizeof(char) * strlen(str));
    for (int i = 0; i < strlen(str); i++)
    {
        pos[i] = ' ';
    }
    // printf("%s\n", pos);
    return pos; // 返回修改后的字符串指针
}

void help()
{

    int flag = 0;
    if (strcmp(setting->color->value_set, "on") == 0)
    {
        strcpy(setting->color->value_set, "off");
        flag = 1;
    }
    printf("%s\n", HEAD);
    printf("%s\n", USAGE);
    printf("All invalid commands: %s\n", COMMANDS);
    printf("%s\n", DATE_TYPE_HELP);
    printf("%s\n", DATE_FOMAT_HELP);    
    printf("%s\n", TID_HELP);
#ifdef ONE
#else

    /* 第0列（序号列） */
    const char *index[] = {
        /*0*/ "Index",
        /*1*/ "0",
        /*2*/ "1",
        /*3*/ "2",
        /*4*/ "3",
        /*5*/ "4",
        /*6*/ "5",
        /*7*/ "6",
        /*8*/ "7",
        /*9*/ "8",
        /*10*/ "9",
        /*11*/ "10",
        /*12*/ "11",
        /*13*/ "12",
        /*14*/ "13",
        /*15*/ "14",
        /*16*/ "15",
        /*17*/ "16",
        /*17*/ "17",
        /*17*/ "18",
        /*17*/ "19",
        /*17*/ "20",
        /*17*/ "21",
        /*17*/ "22",
        /*17*/ "23",
        /*17*/ "24",
        /*17*/ "25",
        /*18*/ NULL};

    /* 第一列（进程名列） */
    const char *soft_name[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*4*/ TL,
        /*5*/ TL,
        /*6*/ TL,
        /*7*/ TL,
        /*8*/ TL,
        /*9*/ TL,
        /*10*/ TL,
        /*11*/ TL,
        /*12*/ TL,
        /*13*/ TL,
        /*14*/ TL,
        /*15*/ TL,
        /*16*/ TL,
        /*17*/ TL,
        /*10*/ TL,
        /*11*/ TL,
        /*12*/ TL,
        /*13*/ TL,
        /*14*/ TL,
        /*15*/ TL,
        /*16*/ TL,
        /*17*/ TL,
        /*17*/ TL,
        /*18*/ NULL};

    /* 第二列（命令列） */
    const char *command[] = {
        /*0*/ COMMAND,
        /*1*/ HELP_TOKEN,
        /*2*/ CONFIGURATION_TOKEN,
        /*3*/ DISPLAY_TOKEN,
        /*4*/ DISPLAY_TOKEN,
        /*5*/ DISPLAY_TOKEN,
        /*6*/ ADD_TOKEN,
        /*7*/ ADD_TOKEN,
        /*8*/ ADD_TOKEN,
        /*9*/ COMPLETE_TOKEN,
        /*9*/ COMPLETE_TOKEN,
        /*10*/ COMPLETE_TOKEN,
        /*11*/ DELETE_TOKEN,
        /*11*/ DELETE_TOKEN,
        /*12*/ DELETE_TOKEN,
        /*13*/ TOGGLE_TOKEN,
        /*14*/ TOGGLE_TOKEN,
        /*14*/ TOGGLE_TOKEN,
        /*15*/ EDIT_ALL_TOKEN,
        /*15*/ EDIT_ALL_TOKEN,
        /*16*/ EDIT_ALL_TOKEN,
        /*17*/ EDIT_PREFIX_TOKEN,
        /*17*/ EDIT_PREFIX_TOKEN,
        /*18*/ EDIT_PREFIX_TOKEN,
        /*19*/ EDIT_SUFFIX_TOKEN,
        /*19*/ EDIT_SUFFIX_TOKEN,
        /*20*/ EDIT_SUFFIX_TOKEN,
        /*21*/ NULL};

    /* 第三列（参数1列） */
    const char *arguments1[] = {
        /*0*/ ARGUMENTS1,
        /*1*/ "command",
        /*2*/ KV,
        /*3*/ NO_WORD,
        /*4*/ DATE_TYPE,
        /*5*/ DATE_TYPE,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        /*8*/ TID,
        /*8*/ TID,
        /*9*/ TID,
        /*10*/ TID,
        /*10*/ TID,
        /*11*/ TID,
        /*12*/ TID,
        /*12*/ TID,
        /*13*/ TID,
        /*14*/ TID,
        /*14*/ TID,
        /*15*/ TID,
        /*16*/ TID,
        /*16*/ TID,
        /*17*/ TID,
        /*17*/ TID,
        /*17*/ TID,
        /*18*/ TID,
        /*19*/ NULL};

    /* 第四列（参数2列） */
    const char *arguments2[] = {
        /*0*/ ARGUMENTS2,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        /*3*/ NO_WORD,
        /*4*/ NO_WORD,
        /*5*/ DATE_FOMAT,
        /*6*/ NO_WORD,
        /*6*/ DATE_TYPE,
        /*7*/ DATE_TYPE,
        /*8*/ NO_WORD,
        /*8*/ DATE_TYPE, // 10
        /*9*/ DATE_TYPE,
        /*10*/ NO_WORD,
        /*10*/ DATE_TYPE,
        /*11*/ DATE_TYPE,
        /*12*/ NO_WORD,
        /*12*/ DATE_TYPE,
        /*13*/ DATE_TYPE,
        /*14*/ CONTENT,
        /*14*/ CONTENT,
        /*15*/ CONTENT,
        /*16*/ CONTENT,
        /*16*/ CONTENT,
        /*17*/ CONTENT,
        /*18*/ CONTENT,
        /*18*/ CONTENT,
        /*19*/ CONTENT,
        /*20*/ NULL};

    /* 第五列（参数3列） */
    const char *arguments3[] = {
        /*0*/ ARGUMENTS3,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        /*3*/ NO_WORD,
        /*3*/ NO_WORD,
        /*4*/ NO_WORD,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        /*6*/ DATE_FOMAT,
        /*7*/ NO_WORD,
        /*8*/ NO_WORD,
        /*8*/ DATE_FOMAT,
        /*9*/ NO_WORD, // 12
        /*10*/ NO_WORD,
        /*10*/ DATE_FOMAT,
        /*11*/ NO_WORD,
        /*12*/ NO_WORD,
        /*13*/ DATE_FOMAT,
        /*13*/ NO_WORD, // 18
                        // /*13*/ DATE_FOMAT,
                        // /*14*/ NO_WORD,
        /*14*/ DATE_TYPE,
        /*15*/ DATE_TYPE,
        /*16*/ NO_WORD,
        /*16*/ DATE_TYPE,
        /*17*/ DATE_TYPE,
        /*18*/ NO_WORD,
        /*18*/ DATE_TYPE,
        /*19*/ DATE_TYPE,
        /*20*/ NULL};

    /* 第六列（参数4列） */
    const char *arguments4[] = {
        /*0*/ ARGUMENTS4,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        /*3*/ NO_WORD,
        /*3*/ NO_WORD,
        /*4*/ NO_WORD,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        /*6*/ NO_WORD,
        /*7*/ NO_WORD,
        /*8*/ NO_WORD,
        /*8*/ NO_WORD,
        /*9*/ NO_WORD,
        /*9*/ NO_WORD,
        /*10*/ NO_WORD,
        /*11*/ NO_WORD,
        /*11*/ NO_WORD,
        /*12*/ NO_WORD,
        /*13*/ NO_WORD,
        // /*13*/ NO_WORD,
        /*14*/ NO_WORD,
        /*15*/ DATE_FOMAT,
        /*16*/ NO_WORD,
        /*16*/ NO_WORD,
        /*17*/ DATE_FOMAT,
        /*18*/ NO_WORD,
        /*18*/ NO_WORD,
        /*19*/ DATE_FOMAT,
        /*20*/ NULL};

    /* 第七列（命令解释列） */
    const char *instruction[] = {
        /*0*/ INSTRUCTION,
        /*1*/ USER_HELP,
        /*2*/ SET_CONFIGURATION,
        /*3*/ DISPLAY_TODAY_TASK,
        /*4*/ DISPLAY_CURRENT_DATE_TASK,
        /*5*/ DISPLAY_SPECIFIC_DATE_TASK,
        /*6*/ ADD_TASK_TO_TODAY,
        /*6*/ ADD_TASK_TO_CURRENT_DATE,
        /*7*/ ADD_TASK_TO_SPECIFIC_DATE,
        /*8*/ MARK_TASK_AS_DONE_TODAY,
        /*9*/ MARK_TASK_AS_DONE_CURRENT_DATE,
        /*9*/ MARK_TASK_AS_DONE_SPECIFIC_DATE,
        /*10*/ DELETE_TASK_TODAY,
        /*11*/ DELETE_TASK_CURRENT_DATE,
        /*11*/ DELETE_TASK_SPECIFIC_DATE,
        /*12*/ TOGGLE_TASK_TODAY,
        /*13*/ TOGGLE_TASK_CURRENT_DATE,
        /*13*/ TOGGLE_TASK_SPECIFIC_DATE,
        /*14*/ REPLACE_TASK_TODAY,
        /*15*/ REPLACE_TASK_CURRENT_DATE,
        /*15*/ REPLACE_TASK_SPECIFIC_DATE,
        /*16*/ PREPEND_TO_TASK_TODAY,
        /*17*/ PREPEND_TO_TASK_CURRENT_DATE,
        /*17*/ PREPEND_TO_TASK_SPECIFIC_DATE,
        /*18*/ APPEND_TO_TASK_TODAY,
        /*19*/ APPEND_TO_TASK_CURRENT_DATE,
        /*19*/ APPEND_TO_TASK_SPECIFIC_DATE,
        /*20*/ NULL};

#endif
    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    // text_print(columns1, sizeof(columns1) / sizeof(columns1[0]));
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
    // 可选的设置全文
    printf("\n%s\n", CONFIGURATION_HELP);
    const char *KEY[] = {"KEY", SETTING_COLOR_KEY, SETTING_TIME_KEY, /*SETTING_SHOW_KEY,*/ SETTING_BORDER_KEY, NULL};
    const char *VALUE[] = {"VALUE", CONFIGURATION_COLOR, CONFIGURATION_TIME, /*CONFIGURATION_SHOW,*/ CONFIGURATION_BORDER, NULL};
    const char **columns2[] = {KEY, VALUE};
    // text_print(columns2, sizeof(columns2) / sizeof(columns2[0]));
    text_print_help(columns2, sizeof(columns2) / sizeof(columns2[0]));
    if (flag == 1)
    {
        strcpy(setting->color->value_set, "on");
    }
}

void help_show()
{
    printf("Here are correct usage of show(\\) command\n");
    /* 第一列（进程名列） */
    const char *soft_name[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*18*/ NULL};

    /* 第二列（命令列） */
    const char *command[] = {
        /*0*/ COMMAND,
        /*6*/ DISPLAY_TOKEN,
        /*7*/ DISPLAY_TOKEN,
        /*8*/ DISPLAY_TOKEN,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments1[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ NO_WORD,
        /*6*/ DATE_TYPE,
        /*7*/ DATE_TYPE,
        NULL,
    };

    /* 第四列（参数2列） */
    const char *arguments2[] = {
        /*0*/ ARGUMENTS2,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        /*6*/ DATE_FOMAT,
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments3[] = {
        /*0*/ ARGUMENTS3,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        /*6*/ NO_WORD,
        NULL,
    };

    /* 第六列（参数4列） */
    const char *arguments4[] = {
        /*0*/ ARGUMENTS4,
        /*4*/ NO_WORD,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        NULL,
    };

    /* 第七列（命令解释列） */
    const char *instruction[] = {
        /*0*/ INSTRUCTION,
        /*6*/ DISPLAY_TODAY_TASK,
        /*6*/ DISPLAY_CURRENT_DATE_TASK,
        /*7*/ DISPLAY_SPECIFIC_DATE_TASK,
        NULL,
    };

    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    // text_print(columns1, sizeof(columns1) / sizeof(columns1[0]));
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
    printf(" Here are examples:%c", border_enabled() ? '\n' : ' ');
    /* 第一列（进程名列） */
    const char *soft_name_eg[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        NULL};

    /* 第二列（命令列） */
    const char *command_eg[] = {
        /*0*/ COMMAND,
        /*6*/ DISPLAY_TOKEN,
        /*7*/ DISPLAY_TOKEN,
        /*8*/ DISPLAY_TOKEN,
        /*6*/ DISPLAY_TOKEN,
        /*7*/ DISPLAY_TOKEN,
        /*8*/ DISPLAY_TOKEN,
        /*8*/ DISPLAY_TOKEN,
        /*8*/ DISPLAY_TOKEN,
        /*8*/ DISPLAY_TOKEN,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments1_eg[] = {
        /*0*/ ARGUMENTS1,
        /*1*/ NO_WORD,
        /*2*/ "-d",
        /*3*/ "-d",
        /*2*/ "-w",
        /*3*/ "-w",
        "-m",
        "-m",
        "-y",
        "-y",
        NULL,
    };

    /* 第四列（参数2列） */
    const char *arguments2_eg[] = {
        /*0*/ ARGUMENTS2,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        "2025.06.01",
        /*2*/ NO_WORD,
        /*3*/ "2025.06.01",
        /*4*/ NO_WORD,
        "2025.06",
        /*5*/ NO_WORD,
        "2025",
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments3_eg[] = {
        /*0*/ ARGUMENTS3,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        /*2*/ NO_WORD,
        NULL,
    };

    /* 第六列（参数4列） */
    const char *arguments4_eg[] = {
        /*0*/ ARGUMENTS4,
        /*4*/ NO_WORD,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        /*6*/ NO_WORD,
        /*7*/ NO_WORD,
        /*8*/ NO_WORD,
        /*8*/ NO_WORD,
        /*8*/ NO_WORD,
        /*8*/ NO_WORD,
        NULL,
    };

    /* 第七列（命令解释列） */
    const char *instruction_eg[] = {
        /*0*/ INSTRUCTION,
        /*6*/ DISPLAY_TODAY_TASK,
        /*6*/ DISPLAY_CURRENT_DATE_TASK,
        /*7*/ "Show tasks of June 1st, 2025",
        /*6*/ "Show tasks of current week",
        /*7*/ "Show tasks of the first week in June 2025",
        "Show the current month tasks",
        "Show the tasks of June 2025" /*2*/,
        "Show the current year tasks",
        "Show the tasks of 2025",
        NULL,

    };

    const char **columns1_eg[] = {soft_name_eg, command_eg, arguments1_eg, arguments2_eg, arguments3_eg, arguments4_eg, instruction_eg};
    text_print(columns1_eg, sizeof(columns1_eg) / sizeof(columns1_eg[0]));
}

void help_help()
{
    printf("Here are correct usage of help(?) command\n");
    /* 第一列（进程名列） */
    const char *soft_name[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*18*/ NULL};

    /* 第二列（命令列） */
    const char *command[] = {
        /*0*/ COMMAND,
        /*6*/ HELP_TOKEN,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments1[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ "command",
        NULL,
    };

    /* 第四列（参数2列） */
    const char *arguments2[] = {
        /*0*/ ARGUMENTS2,
        /*6*/ NO_WORD,
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments3[] = {
        /*0*/ ARGUMENTS3,
        /*5*/ NO_WORD,
        NULL,
    };

    /* 第六列（参数4列） */
    const char *arguments4[] = {
        /*0*/ ARGUMENTS4,
        /*6*/ NO_WORD,
        NULL,
    };

    /* 第七列（命令解释列） */
    const char *instruction[] = {
        /*0*/ INSTRUCTION,
        /*6*/ "Show command help information",
        NULL,
    };

    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    // text_print(columns1, sizeof(columns1) / sizeof(columns1[0]));
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
    printf(" Here are examples:%c", border_enabled() ? '\n' : ' ');
    /* 第一列（进程名列） */
    const char *soft_name_eg[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*3*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        NULL};

    /* 第二列（命令列） */
    const char *command_eg[] = {
        /*0*/ COMMAND,
        /*6*/ HELP_TOKEN,
        /*6*/ HELP_TOKEN,
        /*7*/ HELP_TOKEN,
        /*8*/ HELP_TOKEN,
        /*6*/ HELP_TOKEN,
        /*7*/ HELP_TOKEN,
        /*8*/ HELP_TOKEN,
        /*8*/ HELP_TOKEN,
        /*8*/ HELP_TOKEN,
        /*8*/ HELP_TOKEN,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments1_eg[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ HELP_TOKEN,
        /*7*/ CONFIGURATION_TOKEN,
        /*1*/ DISPLAY_TOKEN,
        /*2*/ ADD_TOKEN,
        /*3*/ COMPLETE_TOKEN,
        /*4*/ DELETE_TOKEN,
        /*5*/ TOGGLE_TOKEN,
        /*8*/ EDIT_ALL_TOKEN,
        /*9*/ EDIT_PREFIX_TOKEN,
        /*10*/ EDIT_SUFFIX_TOKEN,
        NULL,
    };

    /* 第四列（参数2列） */
    const char *arguments2_eg[] = {
        /*0*/ ARGUMENTS2,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,

        /*20*/ NULL};

    /* 第五列（参数3列） */
    const char *arguments3_eg[] = {
        /*0*/ ARGUMENTS3,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        NULL,
    };

    /* 第六列（参数4列） */
    const char *arguments4_eg[] = {
        /*0*/ ARGUMENTS4,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        /*1*/ NO_WORD,
        NULL,
    };

    /* 第七列（命令解释列） */
    const char *instruction_eg[] = {
        /*0*/ INSTRUCTION,
        "Show help command help information",
        "Show set command help information",
        "Show show command help information",
        "Show add command help information",
        "Show done command help information",
        "Show delete command help information",
        "Show toggle command help information",
        "Show replace command help information",
        "Show append command help information",
        "Show prepend command help information",
        NULL,

    };

    const char **columns1_eg[] = {soft_name_eg, command_eg, arguments1_eg, arguments2_eg, arguments3_eg, arguments4_eg, instruction_eg};
    text_print(columns1_eg, sizeof(columns1_eg) / sizeof(columns1_eg[0]));
}
void help_add()
{
    printf("Here are correct usage of add(+) command\n");
    /* 第一列（进程名列） */
    const char *soft_name[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*18*/ NULL};

    /* 第二列（命令列） */
    const char *command[] = {
        /*0*/ COMMAND,
        /*6*/ ADD_TOKEN,
        /*7*/ ADD_TOKEN,
        /*8*/ ADD_TOKEN,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments1[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        NULL,
    };

    /* 第四列（参数2列） */
    const char *arguments2[] = {
        /*0*/ ARGUMENTS2,
        /*6*/ NO_WORD,
        /*6*/ DATE_TYPE,
        /*7*/ DATE_TYPE,
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments3[] = {
        /*0*/ ARGUMENTS3,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        /*6*/ DATE_FOMAT,
        NULL,
    };

    /* 第六列（参数4列） */
    const char *arguments4[] = {
        /*0*/ ARGUMENTS4,
        /*4*/ NO_WORD,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        NULL,
    };

    /* 第七列（命令解释列） */
    const char *instruction[] = {
        /*0*/ INSTRUCTION,
        /*6*/ ADD_TASK_TO_TODAY,
        /*6*/ ADD_TASK_TO_CURRENT_DATE,
        /*7*/ ADD_TASK_TO_SPECIFIC_DATE,
        NULL,
    };

    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    // text_print(columns1, sizeof(columns1) / sizeof(columns1[0]));
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
    printf(" Here are examples:%c", border_enabled() ? '\n' : ' ');
    /* 第一列（进程名列） */
    const char *soft_name_eg[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        NULL};

    /* 第二列（命令列） */
    const char *command_eg[] = {
        /*0*/ COMMAND,
        /*6*/ ADD_TOKEN,
        /*7*/ ADD_TOKEN,
        /*8*/ ADD_TOKEN,
        /*6*/ ADD_TOKEN,
        /*7*/ ADD_TOKEN,
        /*8*/ ADD_TOKEN,
        /*8*/ ADD_TOKEN,
        /*8*/ ADD_TOKEN,
        /*8*/ ADD_TOKEN,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments1_eg[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        NULL,
    };

    /* 第四列（参数2列） */
    const char *arguments2_eg[] = {
        /*0*/ ARGUMENTS2,
        /*1*/ NO_WORD,
        /*2*/ "-d",
        /*3*/ "-d",
        /*2*/ "-w",
        /*3*/ "-w",
        "-m",
        "-m",
        "-y",
        "-y",
        /*20*/ NULL};

    /* 第五列（参数3列） */
    const char *arguments3_eg[] = {
        /*0*/ ARGUMENTS3,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        "2025.06.01",
        /*2*/ NO_WORD,
        /*3*/ "2025.06.01",
        /*4*/ NO_WORD,
        "2025.06",
        /*5*/ NO_WORD,
        "2025",
        NULL,
    };

    /* 第六列（参数4列） */
    const char *arguments4_eg[] = {
        /*0*/ ARGUMENTS4,
        /*4*/ NO_WORD,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,

        /*6*/ NO_WORD,
        /*7*/ NO_WORD,
        /*8*/ NO_WORD,
        /*8*/ NO_WORD,
        /*8*/ NO_WORD,
        /*8*/ NO_WORD,
        NULL,
    };

    /* 第七列（命令解释列） */
    const char *instruction_eg[] = {
        /*0*/ INSTRUCTION,
        /*6*/ ADD_TASK_TO_TODAY,
        /*6*/ ADD_TASK_TO_TODAY,
        /*7*/ "Add task to June 1st, 2025",
        /*6*/ "Add task to current week",
        /*7*/ "Add task to the first week of June 2025",
        "Add the current month tasks",
        "Add the tasks for June 2025" /*2*/,
        "Add the current year tasks",
        "Add the tasks for 2025",
        NULL,

    };

    const char **columns1_eg[] = {soft_name_eg, command_eg, arguments1_eg, arguments2_eg, arguments3_eg, arguments4_eg, instruction_eg};
    text_print(columns1_eg, sizeof(columns1_eg) / sizeof(columns1_eg[0]));
}

void help_delete()
{
    printf("Here are correct usage of delete(/) command\n");
    // 第0列（序号列）
    const char *index[] = {"Index", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", NULL};
    // 第一列进程名
    const char *soft_name[] = {PROCESS_NAME, TL /*4*/, TL /*5*/, NULL, TL /*6*/, TL /*7*/, TL /*8*/, TL /*9*/, TL /*10*/, TL /*11*/, TL /*12*/, TL /*13*/, TL /*14*/, TL /*15*/, TL /*16*/, TL /*17*/, NULL};
    // 第二列命令
    const char *command[] = {COMMAND, DELETE_TOKEN /*7*/, DELETE_TOKEN /*8*/, NULL, TOGGLE_TOKEN /*9*/, TOGGLE_TOKEN /*10*/, EDIT_ALL_TOKEN /*11*/, EDIT_ALL_TOKEN /*12*/, EDIT_PREFIX_TOKEN /*13*/, EDIT_PREFIX_TOKEN /*14*/, EDIT_SUFFIX_TOKEN /*15*/, EDIT_SUFFIX_TOKEN /*16*/, CONFIGURATION_TOKEN /*17*/, NULL};
    // 第三列参数1
    const char *arguments1[] = {ARGUMENTS1, TID /*7*/, TID /*8*/, NULL, NO_WORD /*9*/, TID /*10*/, NO_WORD /*11*/, TID /*12*/, NO_WORD /*13*/, TID /*14*/, NO_WORD /*15*/, TID /*16*/, KV /*17*/, NULL};
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
    printf(" Here are examples:%c", border_enabled() ? '\n' : ' ');

    /* 第一列（进程名列） */
    const char *soft_name_eg[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        NULL,
    };

    /* 第二列（命令列） */
    const char *command_eg[] = {
        /*0*/ COMMAND,
        /*11*/ DELETE_TOKEN,
        /*11*/ DELETE_TOKEN,
        /*12*/ DELETE_TOKEN,
        /*11*/ DELETE_TOKEN,
        /*11*/ DELETE_TOKEN,
        /*12*/ DELETE_TOKEN,
        /*11*/ DELETE_TOKEN,
        /*11*/ DELETE_TOKEN,
        /*12*/ DELETE_TOKEN,
        /*21*/ NULL};

    /* 第三列（参数1列） */
    const char *arguments1_eg[] = {
        /*0*/ ARGUMENTS1,
        /*10*/ TID,
        /*10*/ TID,
        /*11*/ TID,
        /*12*/ TID,
        /*12*/ TID,
        /*13*/ TID,
        /*14*/ TID,
        /*14*/ TID,
        /*15*/ TID,
        /*19*/ NULL};

    /* 第四列（参数2列） */
    const char *arguments2_eg[] = {
        /*0*/ ARGUMENTS2,
        /*1*/ NO_WORD,
        /*2*/ "-d",
        /*3*/ "-d",
        /*2*/ "-w",
        /*3*/ "-w",
        "-m",
        "-m",
        "-y",
        "-y",
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments3_eg[] = {
        /*0*/ ARGUMENTS3,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        "2025.06.01",
        /*2*/ NO_WORD,
        /*3*/ "2025.06.01",
        /*4*/ NO_WORD,
        "2025.06",
        /*5*/ NO_WORD,
        "2025",
        /*20*/ NULL};

    /* 第六列（参数4列） */
    const char *arguments4_eg[] = {
        /*0*/ ARGUMENTS4,
        /*10*/ NO_WORD,
        /*11*/ NO_WORD,
        /*11*/ NO_WORD,
        /*12*/ NO_WORD,
        /*13*/ NO_WORD,
        /*14*/ NO_WORD,
        /*11*/ NO_WORD,
        /*11*/ NO_WORD,
        /*12*/ NO_WORD,
        /*20*/ NULL};

    /* 第七列（命令解释列） */
    const char *instruction_eg[] = {
        /*0*/ INSTRUCTION,
        /*10*/ DELETE_TASK_TODAY,
        /*11*/ DELETE_TASK_CURRENT_DATE,
        /*7*/ "Delete task whose id equals TID in June 1st, 2025",
        /*6*/ "Delete task whose id equals TID in current week",
        /*7*/ "Delete task whose id equals TID in the first week of June 2025",
        "Delete the current month task whose id equals TID",
        /*7*/ "Delete task whose id equals TID in June 2025",
        "Delete the current year task whose id equals TID",
        "Delete the task whose id equals TID in 2025",
        NULL,
        /*20*/ NULL};

    const char **columns1_eg[] = {soft_name_eg, command_eg, arguments1_eg, arguments2_eg, arguments3_eg, arguments4_eg, instruction_eg};
    text_print(columns1_eg, sizeof(columns1_eg) / sizeof(columns1_eg[0]));
}

void help_done()
{
    printf("Here are correct usage of done(-) command\n");
    /* 第一列（进程名列） */
    const char *soft_name[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*18*/ NULL};

    /* 第二列（命令列） */
    const char *command[] = {
        /*0*/ COMMAND,
        /*6*/ COMPLETE_TOKEN,
        /*7*/ COMPLETE_TOKEN,
        /*8*/ COMPLETE_TOKEN,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments1[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ TID,
        /*6*/ TID,
        /*7*/ TID,
        NULL,
    };

    /* 第四列（参数2列） */
    const char *arguments2[] = {
        /*0*/ ARGUMENTS2,
        /*6*/ NO_WORD,
        /*6*/ DATE_TYPE,
        /*7*/ DATE_TYPE,
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments3[] = {
        /*0*/ ARGUMENTS3,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        /*6*/ DATE_FOMAT,
        NULL,
    };

    /* 第六列（参数4列） */
    const char *arguments4[] = {
        /*0*/ ARGUMENTS4,
        /*4*/ NO_WORD,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        NULL,
    };

    /* 第七列（命令解释列） */
    const char *instruction[] = {
        /*0*/ INSTRUCTION,
        /*6*/ MARK_TASK_AS_DONE_TODAY,
        /*6*/ MARK_TASK_AS_DONE_CURRENT_DATE,
        /*6*/ MARK_TASK_AS_DONE_SPECIFIC_DATE,
        NULL,
    };

    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));

    printf(" Here are examples:%c", border_enabled() ? '\n' : ' ');
    /* 第一列（进程名列） */
    const char *soft_name_eg[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        NULL,
    };

    /* 第二列（命令列） */
    const char *command_eg[] = {
        /*0*/ COMMAND,
        /*11*/ COMPLETE_TOKEN,
        /*11*/ COMPLETE_TOKEN,
        /*12*/ COMPLETE_TOKEN,
        /*11*/ COMPLETE_TOKEN,
        /*11*/ COMPLETE_TOKEN,
        /*12*/ COMPLETE_TOKEN,
        /*11*/ COMPLETE_TOKEN,
        /*11*/ COMPLETE_TOKEN,
        /*12*/ COMPLETE_TOKEN,
        /*21*/ NULL};

    /* 第三列（参数1列） */
    const char *arguments1_eg[] = {
        /*0*/ ARGUMENTS1,
        /*10*/ TID,
        /*10*/ TID,
        /*11*/ TID,
        /*12*/ TID,
        /*12*/ TID,
        /*13*/ TID,
        /*14*/ TID,
        /*14*/ TID,
        /*15*/ TID,
        /*19*/ NULL};

    /* 第四列（参数2列） */
    const char *arguments2_eg[] = {
        /*0*/ ARGUMENTS2,
        /*1*/ NO_WORD,
        /*2*/ "-d",
        /*3*/ "-d",
        /*2*/ "-w",
        /*3*/ "-w",
        "-m",
        "-m",
        "-y",
        "-y",
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments3_eg[] = {
        /*0*/ ARGUMENTS3,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        "2025.06.01",
        /*2*/ NO_WORD,
        /*3*/ "2025.06.01",
        /*4*/ NO_WORD,
        "2025.06",
        /*5*/ NO_WORD,
        "2025",
        /*20*/ NULL};

    /* 第六列（参数4列） */
    const char *arguments4_eg[] = {
        /*0*/ ARGUMENTS4,
        /*10*/ NO_WORD,
        /*11*/ NO_WORD,
        /*11*/ NO_WORD,
        /*12*/ NO_WORD,
        /*13*/ NO_WORD,
        /*14*/ NO_WORD,
        /*11*/ NO_WORD,
        /*11*/ NO_WORD,
        /*12*/ NO_WORD,
        /*20*/ NULL};

    /* 第七列（命令解释列） */
    const char *instruction_eg[] = {
        /*0*/ INSTRUCTION,
        /*6*/ MARK_TASK_AS_DONE_TODAY,
        /*6*/ MARK_TASK_AS_DONE_CURRENT_DATE,
        /*7*/ "Done task whose id equals TID in June 1st, 2025",
        /*6*/ "Done task whose id equals TID in current week",
        /*7*/ "Done task whose id equals TID in the first week of June 2025",
        "Done the current month task whose id equals TID",
        /*7*/ "Done task whose id equals TID in June 2025",
        "Done the current year task whose id equals TID",
        "Done the task whose id equals TID in 2025",
        /*20*/ NULL};

    const char **columns1_eg[] = {soft_name_eg, command_eg, arguments1_eg, arguments2_eg, arguments3_eg, arguments4_eg, instruction_eg};
    text_print(columns1_eg, sizeof(columns1_eg) / sizeof(columns1_eg[0]));
}

void help_toggle()
{
    printf("Here are correct usage of toggle(!) command\n");

    /* 第一列（进程名列） */
    const char *soft_name[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*18*/ NULL};

    /* 第二列（命令列） */
    const char *command[] = {
        /*0*/ COMMAND,
        /*6*/ TOGGLE_TOKEN,
        /*7*/ TOGGLE_TOKEN,
        /*8*/ TOGGLE_TOKEN,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments1[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ TID,
        /*6*/ TID,
        /*7*/ TID,
        NULL,
    };

    /* 第四列（参数2列） */
    const char *arguments2[] = {
        /*0*/ ARGUMENTS2,
        /*6*/ NO_WORD,
        /*6*/ DATE_TYPE,
        /*7*/ DATE_TYPE,
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments3[] = {
        /*0*/ ARGUMENTS3,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        /*6*/ DATE_FOMAT,
        NULL,
    };

    /* 第六列（参数4列） */
    const char *arguments4[] = {
        /*0*/ ARGUMENTS4,
        /*4*/ NO_WORD,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        NULL,
    };

    /* 第七列（命令解释列） */
    const char *instruction[] = {
        /*0*/ INSTRUCTION,
        /*6*/ MARK_TASK_AS_DONE_TODAY,
        /*6*/ MARK_TASK_AS_DONE_CURRENT_DATE,
        /*6*/ MARK_TASK_AS_DONE_SPECIFIC_DATE,
        NULL,
    };

    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));

    printf(" Here are examples:%c", border_enabled() ? '\n' : ' ');
    /* 第一列（进程名列） */
    const char *soft_name_eg[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        NULL,
    };

    /* 第二列（命令列） */
    const char *command_eg[] = {
        /*0*/ COMMAND,
        /*11*/ TOGGLE_TOKEN,
        /*11*/ TOGGLE_TOKEN,
        /*12*/ TOGGLE_TOKEN,
        /*11*/ TOGGLE_TOKEN,
        /*11*/ TOGGLE_TOKEN,
        /*12*/ TOGGLE_TOKEN,
        /*11*/ TOGGLE_TOKEN,
        /*11*/ TOGGLE_TOKEN,
        /*12*/ TOGGLE_TOKEN,
        /*21*/ NULL};

    /* 第三列（参数1列） */
    const char *arguments1_eg[] = {
        /*0*/ ARGUMENTS1,
        /*10*/ TID,
        /*10*/ TID,
        /*11*/ TID,
        /*12*/ TID,
        /*12*/ TID,
        /*13*/ TID,
        /*14*/ TID,
        /*14*/ TID,
        /*15*/ TID,
        /*19*/ NULL};

    /* 第四列（参数2列） */
    const char *arguments2_eg[] = {
        /*0*/ ARGUMENTS2,
        /*1*/ NO_WORD,
        /*2*/ "-d",
        /*3*/ "-d",
        /*2*/ "-w",
        /*3*/ "-w",
        "-m",
        "-m",
        "-y",
        "-y",
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments3_eg[] = {
        /*0*/ ARGUMENTS3,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        "2025.06.01",
        /*2*/ NO_WORD,
        /*3*/ "2025.06.01",
        /*4*/ NO_WORD,
        "2025.06",
        /*5*/ NO_WORD,
        "2025",
        /*20*/ NULL};

    /* 第六列（参数4列） */
    const char *arguments4_eg[] = {
        /*0*/ ARGUMENTS4,
        /*10*/ NO_WORD,
        /*11*/ NO_WORD,
        /*11*/ NO_WORD,
        /*12*/ NO_WORD,
        /*13*/ NO_WORD,
        /*14*/ NO_WORD,
        /*11*/ NO_WORD,
        /*11*/ NO_WORD,
        /*12*/ NO_WORD,
        /*20*/ NULL};

    /* 第七列（命令解释列） */
    const char *instruction_eg[] = {
        /*0*/ INSTRUCTION,
        /*10*/ TOGGLE_TASK_TODAY,
        /*11*/ TOGGLE_TASK_CURRENT_DATE,
        /*7*/ "Toggle task whose id equals TID in June 1st, 2025",
        /*6*/ "Toggle task whose id equals TID in current week",
        /*7*/ "Toggle task whose id equals TID in the first week of June 2025",
        "Toggle the current month task whose id equals TID",
        /*7*/ "Toggle task whose id equals TID in June 2025",
        "Toggle the current year task whose id equals TID",
        "Toggle the task whose id equals TID in 2025",
        NULL,
        /*20*/ NULL};

    const char **columns1_eg[] = {soft_name_eg, command_eg, arguments1_eg, arguments2_eg, arguments3_eg, arguments4_eg, instruction_eg};
    text_print(columns1_eg, sizeof(columns1_eg) / sizeof(columns1_eg[0]));
}
void help_edit()
{
    printf("Here are correct usage of edit_all(=) command\n");

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
    const char *instruction[] = {INSTRUCTION, REPLACE_TASK_TODAY /*11*/, REPLACE_TASK_SPECIFIC_DATE /*12*/, PREPEND_TO_TASK_TODAY /*13*/, PREPEND_TO_TASK_SPECIFIC_DATE /*14*/, APPEND_TO_TASK_TODAY /*15*/, APPEND_TO_TASK_SPECIFIC_DATE /*16*/, NULL, SET_CONFIGURATION /*17*/, NULL};
    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));
    printf(" Here are examples:%c", border_enabled() ? '\n' : ' ');
}

void help_edit_all()
{
    printf("Here are correct usage of edit(=) command\n");

    /* 第一列（进程名列） */
    const char *soft_name[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*18*/ NULL};

    /* 第二列（命令列） */
    const char *command[] = {
        /*0*/ COMMAND,
        /*6*/ EDIT_ALL_TOKEN,
        /*7*/ EDIT_ALL_TOKEN,
        /*8*/ EDIT_ALL_TOKEN,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments1[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ TID,
        /*6*/ TID,
        /*7*/ TID,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments2[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        NULL,
    };

    /* 第四列（参数2列） */
    const char *arguments3[] = {
        /*0*/ ARGUMENTS2,
        /*6*/ NO_WORD,
        /*6*/ DATE_TYPE,
        /*7*/ DATE_TYPE,
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments4[] = {
        /*0*/ ARGUMENTS3,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        /*6*/ DATE_FOMAT,
        NULL,
    };

    /* 第七列（命令解释列） */
    const char *instruction[] = {
        /*0*/ INSTRUCTION,
        /*6*/ REPLACE_TASK_TODAY,
        /*6*/ REPLACE_TASK_CURRENT_DATE,
        /*7*/ REPLACE_TASK_SPECIFIC_DATE,
        NULL,
    };

    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));

    printf(" Here are examples:%c", border_enabled() ? '\n' : ' ');
    /* 第一列（进程名列） */
    const char *soft_name_eg[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        NULL,
    };

    /* 第二列（命令列） */
    const char *command_eg[] = {
        /*0*/ COMMAND,
        /*11*/ EDIT_ALL_TOKEN,
        /*11*/ EDIT_ALL_TOKEN,
        /*12*/ EDIT_ALL_TOKEN,
        /*11*/ EDIT_ALL_TOKEN,
        /*11*/ EDIT_ALL_TOKEN,
        /*12*/ EDIT_ALL_TOKEN,
        /*11*/ EDIT_ALL_TOKEN,
        /*11*/ EDIT_ALL_TOKEN,
        /*12*/ EDIT_ALL_TOKEN,
        /*21*/ NULL};

    /* 第三列（参数1列） */
    const char *arguments1_eg[] = {
        /*0*/ ARGUMENTS1,
        /*10*/ TID,
        /*10*/ TID,
        /*11*/ TID,
        /*12*/ TID,
        /*12*/ TID,
        /*13*/ TID,
        /*14*/ TID,
        /*14*/ TID,
        /*15*/ TID,
        /*19*/ NULL};

    /* 第三列（参数1列） */
    const char *arguments2_eg[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        NULL,
    };
    /* 第四列（参数2列） */
    const char *arguments3_eg[] = {
        /*0*/ ARGUMENTS2,
        /*1*/ NO_WORD,
        /*2*/ "-d",
        /*3*/ "-d",
        /*2*/ "-w",
        /*3*/ "-w",
        "-m",
        "-m",
        "-y",
        "-y",
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments4_eg[] = {
        /*0*/ ARGUMENTS3,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        "2025.06.01",
        /*2*/ NO_WORD,
        /*3*/ "2025.06.01",
        /*4*/ NO_WORD,
        "2025.06",
        /*5*/ NO_WORD,
        "2025",
        /*20*/ NULL};

    /* 第七列（命令解释列） */
    const char *instruction_eg[] = {
        /*0*/ INSTRUCTION,
        /*10*/ REPLACE_TASK_TODAY,
        /*11*/ REPLACE_TASK_CURRENT_DATE,
        /*7*/ "Replace task whose id equals TID in June 1st, 2025",
        /*6*/ "Replace task whose id equals TID in current week",
        /*7*/ "Replace task whose id equals TID in the first week of June 2025",
        "Replace the current month task whose id equals TID",
        /*7*/ "Replace task whose id equals TID in June 2025",
        "Replace the current year task whose id equals TID",
        "Replace the task whose id equals TID in 2025",
        NULL,
        /*20*/ NULL};

    const char **columns1_eg[] = {soft_name_eg, command_eg, arguments1_eg, arguments2_eg, arguments3_eg, arguments4_eg, instruction_eg};
    text_print(columns1_eg, sizeof(columns1_eg) / sizeof(columns1_eg[0]));
}

void help_edit_prefix()
{
    printf("Here are correct usage of edit_prefix(=%%) command\n");

    /* 第一列（进程名列） */
    const char *soft_name[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*18*/ NULL};

    /* 第二列（命令列） */
    const char *command[] = {
        /*0*/ COMMAND,
        /*6*/ EDIT_PREFIX_TOKEN,
        /*7*/ EDIT_PREFIX_TOKEN,
        /*8*/ EDIT_PREFIX_TOKEN,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments1[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ TID,
        /*6*/ TID,
        /*7*/ TID,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments2[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        NULL,
    };

    /* 第四列（参数2列） */
    const char *arguments3[] = {
        /*0*/ ARGUMENTS2,
        /*6*/ NO_WORD,
        /*6*/ DATE_TYPE,
        /*7*/ DATE_TYPE,
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments4[] = {
        /*0*/ ARGUMENTS3,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        /*6*/ DATE_FOMAT,
        NULL,
    };

    /* 第七列（命令解释列） */
    const char *instruction[] = {
        /*0*/ INSTRUCTION,
        /*6*/ REPLACE_TASK_TODAY,
        /*6*/ REPLACE_TASK_CURRENT_DATE,
        /*7*/ REPLACE_TASK_SPECIFIC_DATE,
        NULL,
    };

    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));

    printf(" Here are examples:%c", border_enabled() ? '\n' : ' ');
    /* 第一列（进程名列） */
    const char *soft_name_eg[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        NULL,
    };

    /* 第二列（命令列） */
    const char *command_eg[] = {
        /*0*/ COMMAND,
        /*11*/ EDIT_PREFIX_TOKEN,
        /*11*/ EDIT_PREFIX_TOKEN,
        /*12*/ EDIT_PREFIX_TOKEN,
        /*11*/ EDIT_PREFIX_TOKEN,
        /*11*/ EDIT_PREFIX_TOKEN,
        /*12*/ EDIT_PREFIX_TOKEN,
        /*11*/ EDIT_PREFIX_TOKEN,
        /*11*/ EDIT_PREFIX_TOKEN,
        /*12*/ EDIT_PREFIX_TOKEN,
        /*21*/ NULL};

    /* 第三列（参数1列） */
    const char *arguments1_eg[] = {
        /*0*/ ARGUMENTS1,
        /*10*/ TID,
        /*10*/ TID,
        /*11*/ TID,
        /*12*/ TID,
        /*12*/ TID,
        /*13*/ TID,
        /*14*/ TID,
        /*14*/ TID,
        /*15*/ TID,
        /*19*/ NULL};

    /* 第三列（参数1列） */
    const char *arguments2_eg[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        NULL,
    };
    /* 第四列（参数2列） */
    const char *arguments3_eg[] = {
        /*0*/ ARGUMENTS2,
        /*1*/ NO_WORD,
        /*2*/ "-d",
        /*3*/ "-d",
        /*2*/ "-w",
        /*3*/ "-w",
        "-m",
        "-m",
        "-y",
        "-y",
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments4_eg[] = {
        /*0*/ ARGUMENTS3,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        "2025.06.01",
        /*2*/ NO_WORD,
        /*3*/ "2025.06.01",
        /*4*/ NO_WORD,
        "2025.06",
        /*5*/ NO_WORD,
        "2025",
        /*20*/ NULL};

    /* 第七列（命令解释列） */
    const char *instruction_eg[] = {
        /*0*/ INSTRUCTION,
        /*10*/ PREPEND_TO_TASK_TODAY,
        /*11*/ PREPEND_TO_TASK_CURRENT_DATE,
        /*7*/ "Prepend to task whose id equals TID in June 1st, 2025",
        /*6*/ "Prepend to task whose id equals TID in current week",
        /*7*/ "Prepend to task whose id equals TID in the first week of June 2025",
        "Prepend to the current month task whose id equals TID",
        /*7*/ "Prepend to task whose id equals TID in June 2025",
        "Prepend to the current year task whose id equals TID",
        "Prepend to the task whose id equals TID in 2025",
        NULL,
        /*20*/ NULL};

    const char **columns1_eg[] = {soft_name_eg, command_eg, arguments1_eg, arguments2_eg, arguments3_eg, arguments4_eg, instruction_eg};
    text_print(columns1_eg, sizeof(columns1_eg) / sizeof(columns1_eg[0]));
}

void help_edit_suffix()
{
    printf("Here are correct usage of edit_suffix(%%=) command\n");

    /* 第一列（进程名列） */
    const char *soft_name[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*18*/ NULL};

    /* 第二列（命令列） */
    const char *command[] = {
        /*0*/ COMMAND,
        /*6*/ EDIT_SUFFIX_TOKEN,
        /*7*/ EDIT_SUFFIX_TOKEN,
        /*8*/ EDIT_SUFFIX_TOKEN,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments1[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ TID,
        /*6*/ TID,
        /*7*/ TID,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments2[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        NULL,
    };

    /* 第四列（参数2列） */
    const char *arguments3[] = {
        /*0*/ ARGUMENTS2,
        /*6*/ NO_WORD,
        /*6*/ DATE_TYPE,
        /*7*/ DATE_TYPE,
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments4[] = {
        /*0*/ ARGUMENTS3,
        /*5*/ NO_WORD,
        /*6*/ NO_WORD,
        /*6*/ DATE_FOMAT,
        NULL,
    };

    /* 第七列（命令解释列） */
    const char *instruction[] = {
        /*0*/ INSTRUCTION,
        /*6*/ REPLACE_TASK_TODAY,
        /*6*/ REPLACE_TASK_CURRENT_DATE,
        /*7*/ REPLACE_TASK_SPECIFIC_DATE,
        NULL,
    };

    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));

    printf(" Here are examples:%c", border_enabled() ? '\n' : ' ');
    /* 第一列（进程名列） */
    const char *soft_name_eg[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        NULL,
    };

    /* 第二列（命令列） */
    const char *command_eg[] = {
        /*0*/ COMMAND,
        /*11*/ EDIT_SUFFIX_TOKEN,
        /*11*/ EDIT_SUFFIX_TOKEN,
        /*12*/ EDIT_SUFFIX_TOKEN,
        /*11*/ EDIT_SUFFIX_TOKEN,
        /*11*/ EDIT_SUFFIX_TOKEN,
        /*12*/ EDIT_SUFFIX_TOKEN,
        /*11*/ EDIT_SUFFIX_TOKEN,
        /*11*/ EDIT_SUFFIX_TOKEN,
        /*12*/ EDIT_SUFFIX_TOKEN,
        /*21*/ NULL};

    /* 第三列（参数1列） */
    const char *arguments1_eg[] = {
        /*0*/ ARGUMENTS1,
        /*10*/ TID,
        /*10*/ TID,
        /*11*/ TID,
        /*12*/ TID,
        /*12*/ TID,
        /*13*/ TID,
        /*14*/ TID,
        /*14*/ TID,
        /*15*/ TID,
        /*19*/ NULL};

    /* 第三列（参数1列） */
    const char *arguments2_eg[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        /*6*/ CONTENT,
        /*6*/ CONTENT,
        /*7*/ CONTENT,
        NULL,
    };
    /* 第四列（参数2列） */
    const char *arguments3_eg[] = {
        /*0*/ ARGUMENTS2,
        /*1*/ NO_WORD,
        /*2*/ "-d",
        /*3*/ "-d",
        /*2*/ "-w",
        /*3*/ "-w",
        "-m",
        "-m",
        "-y",
        "-y",
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments4_eg[] = {
        /*0*/ ARGUMENTS3,
        /*1*/ NO_WORD,
        /*2*/ NO_WORD,
        "2025.06.01",
        /*2*/ NO_WORD,
        /*3*/ "2025.06.01",
        /*4*/ NO_WORD,
        "2025.06",
        /*5*/ NO_WORD,
        "2025",
        /*20*/ NULL};

    /* 第七列（命令解释列） */
    const char *instruction_eg[] = {
        /*0*/ INSTRUCTION,
        /*10*/ APPEND_TO_TASK_TODAY,
        /*11*/ APPEND_TO_TASK_CURRENT_DATE,
        /*7*/ "Append to task whose id equals TID in June 1st, 2025",
        /*6*/ "Append to task whose id equals TID in current week",
        /*7*/ "Append to task whose id equals TID in the first week of June 2025",
        "Append to the current month task whose id equals TID",
        /*7*/ "Append to task whose id equals TID in June 2025",
        "Append to the current year task whose id equals TID",
        "Append to the task whose id equals TID in 2025",
        NULL,
        /*20*/ NULL};

    const char **columns1_eg[] = {soft_name_eg, command_eg, arguments1_eg, arguments2_eg, arguments3_eg, arguments4_eg, instruction_eg};
    text_print(columns1_eg, sizeof(columns1_eg) / sizeof(columns1_eg[0]));
}

void help_set()
{
    printf("Here are correct usage of set($) command\n");

    /* 第一列（进程名列） */
    const char *soft_name[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        NULL};

    /* 第二列（命令列） */
    const char *command[] = {
        /*0*/ COMMAND,
        /*6*/ CONFIGURATION_TOKEN,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments1[] = {
        /*0*/ ARGUMENTS1,
        KV,
        NULL,
    };

    /* 第三列（参数1列） */
    const char *arguments2[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ NO_WORD,
        NULL,
    };

    /* 第四列（参数2列） */
    const char *arguments3[] = {
        /*0*/ ARGUMENTS2,
        /*6*/ NO_WORD,
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments4[] = {
        /*0*/ ARGUMENTS3,
        /*5*/ NO_WORD,
        NULL,
    };

    /* 第七列（命令解释列） */
    const char *instruction[] = {
        /*0*/ INSTRUCTION,
        SET_CONFIGURATION,
        NULL,
    };

    const char **columns1[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
    text_print_help(columns1, sizeof(columns1) / sizeof(columns1[0]));

    printf(" Here are examples:%c", border_enabled() ? '\n' : ' ');
    /* 第一列（进程名列） */
    const char *soft_name_eg[] = {
        /*0*/ PROCESS_NAME,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        /*1*/ TL,
        /*2*/ TL,
        /*3*/ TL,
        NULL,
    };

    /* 第二列（命令列） */
    const char *command_eg[] = {
        /*0*/ COMMAND,
        /*11*/ CONFIGURATION_TOKEN,
        /*11*/ CONFIGURATION_TOKEN,
        /*12*/ CONFIGURATION_TOKEN,
        /*11*/ CONFIGURATION_TOKEN,
        /*11*/ CONFIGURATION_TOKEN,
        /*12*/ CONFIGURATION_TOKEN,
        /*21*/ NULL};

    /* 第三列（参数1列） */
    const char *arguments1_eg[] = {
        /*0*/ ARGUMENTS1,
        /*10*/ "color=on",
        /*10*/ "color=off",
        /*11*/ "time=on",
        /*12*/ "time=off",
        /*12*/ "border=on",
        /*13*/ "border=off",
        /*19*/ NULL};

    /* 第三列（参数1列） */
    const char *arguments2_eg[] = {
        /*0*/ ARGUMENTS1,
        /*6*/ NO_WORD,
        /*6*/ NO_WORD,
        /*7*/ NO_WORD,
        /*6*/ NO_WORD,
        /*6*/ NO_WORD,
        /*7*/ NO_WORD,
        NULL,
    };
    /* 第四列（参数2列） */
    const char *arguments3_eg[] = {
        /*0*/ ARGUMENTS2,
        /*6*/ NO_WORD,
        /*6*/ NO_WORD,
        /*7*/ NO_WORD,
        /*6*/ NO_WORD,
        /*6*/ NO_WORD,
        /*7*/ NO_WORD,
        NULL,
    };

    /* 第五列（参数3列） */
    const char *arguments4_eg[] = {
        /*0*/ ARGUMENTS3,
        /*6*/ NO_WORD,
        /*6*/ NO_WORD,
        /*7*/ NO_WORD,
        /*6*/ NO_WORD,
        /*6*/ NO_WORD,
        /*7*/ NO_WORD,
        NULL,
    };

    /* 第七列（命令解释列） */
    const char *instruction_eg[] = {
        /*0*/ SET_CONFIGURATION,
        SET_COLOR_ON,
        SET_COLOR_OFF,
        SET_TIME_ON,
        SET_TIME_OFF,
        SET_BORDER_ON,
        SET_BORDER_OFF,
        NULL,
    };

    const char **columns1_eg[] = {soft_name_eg, command_eg, arguments1_eg, arguments2_eg, arguments3_eg, arguments4_eg, instruction_eg};
    text_print(columns1_eg, sizeof(columns1_eg) / sizeof(columns1_eg[0]));
}
void help_show_more_tips()
{
    printf("Type command ");
    GREEN_PRINT("\"tl \\\"");
    printf(" to see all data.\n");
}

void help_show_tips()
{
    printf("Type command ");
    GREEN_PRINT("\"tl ? \\\"");
    printf(" to get help of show(\\) command information\n");
}

void help_add_tips()
{
    printf("Type command ");
    GREEN_PRINT("\"tl ? +\"");
    printf(" to get help of add(+) command information\n");
}

void help_done_tips()
{
    printf("Type command ");
    GREEN_PRINT("\"tl ? -\"");
    printf(" to get help of done(-) command information\n");
}

void help_delete_tips()
{
    printf("Type command ");
    GREEN_PRINT("\"tl ? /\"");
    printf(" to get help of delete(/) command information\n");
}

void help_toggle_tips()
{
    printf("Type command ");
    GREEN_PRINT("\"tl ? !\"");
    printf(" to get help of toggle(!) command information\n");
}

void help_replace_tips()
{
    printf("Type command ");
    GREEN_PRINT("\"tl ? =\"");
    printf(" to get help of replace(=) command information\n");
}

void help_append_tips()
{
    printf("Type command ");
    GREEN_PRINT("\"tl ? =%\"");
    printf(" to get help of append(=%%) command information\n");
}

void help_prepend_tips()
{
    printf("Type command ");
    GREEN_PRINT("\"tl ? %%=\"");
    printf(" to get help of prepend(%%=) command information\n");
}

void help_set_tips()
{
    printf("Type command ");
    GREEN_PRINT("\"tl ? $\"");
    printf(" to get help of set($) command information\n");
}

void help_help_tips()
{
    printf("Type command \"");
    GREEN_PRINT("tl ? ?");
    printf("\" to get help of help(?) command information\n");
}