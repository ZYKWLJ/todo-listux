#include "../include/include.h"
#define MAIN
#ifdef MAIN
#if 0
string exec_words[] = {
    "NONE",
    "?",
    "\\",
    "+",
    "/",
    "=",
    "%=",
    "=%",
    "-",
    "!",
    "$",
};
#endif

string exec_words[] = {
    ERROR_TOKEN,
    HELP_TOKEN,
    DISPLAY_TOKEN,
    ADD_TOKEN,
    DELETE_TOKEN,
    EDIT_ALL_TOKEN,
    EDIT_PREFIX_TOKEN,
    EDIT_SUFFIX_TOKEN,
    COMPLETE_TOKEN,
    TOGGLE_TOKEN,
    CONFIGURATION_TOKEN,
};
int get_exec_index(string word)
{

    for (int i = 0; i < sizeof(exec_words) / sizeof(string); i++)
    {
        // LOG_PRINT("get_exec_index: %s\n", exec_words[i]);
        if (strcmp(word, exec_words[i]) == 0)
        {
            return i;
        }
    }
    // LOG_PRINT("get_exec_index: %s\n", word);
    return 0;
}
/**
 * data descp: 设置的K-V
 */
KV_ kv;
S_setting setting;
C_command command;
T_date date;
// string S_setting_path="/tmp/";
int main(int argc, char **argv)
{
    LOG_PRINT("MAIN_start......");
    /**
     * data descp: 本该如此，最先初始化的就是设置！
     */
    create_file(get_appdata_path(SETTING_FILE));
    create_file(get_appdata_path(DATE_FILE));

    setting = S_setting_init(NULL);
    set_settings_init(setting);
    load_setting(get_appdata_path(SETTING_FILE));
    S_settings_print(setting);
    kv = (KV_)checked_malloc(sizeof(*kv));
    /**
     * data descp: 然后初始化时间！
     */
    date = T_date_init(NULL);
    date->T_current_date = T_current_date_init(NULL);
    date->T_current_date->date_type = D;
    date->T_specific_date = T_current_date_init(NULL);
    date->T_specific_date->date_type = D;
    T_time_print(date->T_current_date);
    command = C_command_init(NULL, argc, argv);
    // C_command_print(command);
    if (argc < 2)
    {
        help();
        return 0;
    }
    N_node node = N_node_init(NULL);
    node->node_type = get_exec_index(command->argv[1]);
    node->task = T_task_init(NULL);
    LOG_PRINT("node_type: %d\n", node->node_type);
    /**
     * func descp: 先将命令解析，没有错后，再在下面的环节执行命令！
     */
    parse_node(node, command, date);
    /**
     * func descp: 真正开始执行命令！(内含解析命令)
     */
    exec(node, command, date);
    LOG_PRINT("exec over......... \n");
// printf("hello ");
#if 0
    RED_PRINT("hello world\n");
#endif
}

#endif