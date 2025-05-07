#include "../include/include.h"

string exec_words[] = {
    "NONE",
    "?",
    "^",
    "+",
    "/",
    "=",
    "%=",
    "=%",
    "-",
    "!",
    "$",
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
int main(int argc, char **argv)
{
    /**
     * data descp: 本该如此，最先初始化的就是设置！
     */
    setting = S_setting_init(NULL);

    set_settings_init(setting);
    S_settings_print(setting);
    kv = (KV_)checked_malloc(sizeof(*kv));
    /**
     * data descp: 然后初始化时间！
     */
    T_date date = T_date_init(NULL);
    date->T_current_date = T_current_date_init(NULL);
    date->T_current_date->date_type = D;
    date->T_specific_date = T_current_date_init(NULL);
    date->T_specific_date->date_type = D;
    T_time_print(date->T_current_date);
    C_command command = C_command_init(NULL, argc, argv);
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
    exec(node, command, date);
    LOG_PRINT("exec over......\n");
}