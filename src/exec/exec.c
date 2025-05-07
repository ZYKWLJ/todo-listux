#include "../../include/include.h"

char to_char(int type)
{
    switch (type)
    {
    case 0:
        return 'D';
    case 1:
        return 'W';
    case 2:
        return 'M';
    case 3:
        return 'Y';
    }
}

string get_db_prefix(T_date date)
{
    string prefix = (string)checked_malloc(sizeof(char) * 100);
    switch (to_char(date->T_specific_date->date_type))
    {
    case 'D':
        sprintf(prefix, "%c-%d.%d.%d", to_char(date->T_specific_date->date_type), date->T_specific_date->year, date->T_specific_date->month, date->T_specific_date->day);
        break;
    case 'W':
        sprintf(prefix, "%c-%d.%d.%d", to_char(date->T_specific_date->date_type), date->T_specific_date->year, date->T_specific_date->month, date->T_specific_date->week);
        break;
    case 'M':
        sprintf(prefix, "%c-%d.%d", to_char(date->T_specific_date->date_type), date->T_specific_date->year, date->T_specific_date->month);
        break;
    case 'Y':
        sprintf(prefix, "%c-%d", to_char(date->T_specific_date->date_type), date->T_specific_date->year);
    }
    return prefix;
}
void exec_show_node(T_date date)
{
    /**
     * func descp: 用构造好的前缀去磁盘里面找对应的行！
     */
    DB_show_task(date, get_db_prefix(date));
}
void exec_add_node(N_node node, T_date date)
{
    /**
     * func descp: 用构造好的前缀去磁盘里面找对应的行！
     */
    DB_add_task(node, date, get_db_prefix(date));
}

void exec_delete_task(N_node node, T_date date){
    /**
     * func descp: 用构造好的前缀去磁盘里面找对应的行！
     */
    DB_delete_task(node, date, get_db_prefix(date));
}

void exec_edit_all_task(N_node node, T_date date){
    /**
     * func descp: 用构造好的前缀去磁盘里面找对应的行！
     */
    DB_edit_all_task(node, date, get_db_prefix(date));
}
void exec_edit_prefix_task(N_node node, T_date date){
    /**
     * func descp: 用构造好的前缀去磁盘里面找对应的行！
     */
    DB_edit_prefix_task(node, date, get_db_prefix(date));
}
void exec_edit_suffix_task(N_node node, T_date date){
    /**
     * func descp: 用构造好的前缀去磁盘里面找对应的行！
     */
    DB_edit_suffix_task(node, date, get_db_prefix(date));
}
void exec_done_task(N_node node, T_date date){
    /**
     * func descp: 用构造好的前缀去磁盘里面找对应的行！
     */
    DB_done_task(node, date, get_db_prefix(date));
}   
void exec_toggle_task(N_node node, T_date date){
    /**
     * func descp: 用构造好的前缀去磁盘里面找对应的行！
     */
    DB_toggle_task(node, date, get_db_prefix(date));
}
void exec_set_config(N_node node, T_date date){
    /**
     * func descp: 用构造好的前缀去磁盘里面找对应的行！
     */
    DB_set_config(node, date, get_db_prefix(date));
}

void exec(N_node node, C_command command, T_date date)
{
    /**
     * func descp: 先将命令解析，没有错后，再在下面的环节执行命令！
     */
    parse_node(node, command, date);
    /**
     * func descp: 接下来的命令一定没有错，所以直接执行命令！
     */
    switch (node->node_type)
    {
    case 0:
        printf("unkown node type of %s\n", command->argv[1]);
        break;
    case 1:
        help();
        break;
    case 2:
        TODO_PRINT("show function ......");
        exec_show_node(date);
        break;
    case 3:
        TODO_PRINT("add function......");
        exec_add_node(node, date); /*task内容都在node里面包含着呢！*/
        break;
    case 4:
        TODO_PRINT("delete function......");
        exec_delete_task(node, date); /*找到指定前缀，在前面加上`/`即可*/
        break;
    case 5:
        TODO_PRINT("edit all function......");
        exec_edit_all_task(node, date); /*找到指定前缀，编辑即可*/
        break;
    case 6:
        TODO_PRINT("edit prefix function......");
        exec_edit_prefix_task(node, date); /*找到指定前缀，编辑即可*/
        break;
    case 7:
        TODO_PRINT("edit suffix function......");
        exec_edit_suffix_task(node, date); /*找到指定前缀，编辑即可*/
        break;
    case 8:
        TODO_PRINT("done function......");
        exec_done_task(node, date); /*找到指定前缀，修改status即可*/
        break;
    case 9:
        TODO_PRINT("toggle function......");
        exec_toggle_task(node, date); /*找到指定前缀，翻转status即可*/
        break;
    case 10:
        TODO_PRINT("setting config function......");
        exec_set_config(node, date); /*进入setting文件，修改config的K-V键值即可*/
        break;
    }
}
