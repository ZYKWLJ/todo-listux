#include "../../include/include.h"

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
    "$",
};
int get_exec_index(string word)
{
    for (int i = 0; i < sizeof(exec_words) / sizeof(string); i++)
    {
        if (strcmp(word, exec_words[i]) == 0)
        {
            return i;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    T_date date = T_date_init(NULL);
    date->T_date_type = CURRENT_DATE;
    date->T_date_data.T_current_date = T_current_date_init(NULL);
    T_time_print(date->T_date_data.T_current_date);
    C_command command = C_command_init(NULL, argc, argv);
    if (argc < 2)
    {
        help();
        return 0;
    }
    N_node node = N_node_init(NULL);
    node->node_type = get_exec_index(command->argv[1]);
    LOG_PRINT("node_type: %d\n", node->node_type);
    exec(node, command, date);
}