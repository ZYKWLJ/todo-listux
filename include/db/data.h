#ifndef DATA_H
#define DATA_H
#include "../include.h"

// 函数声明
void DB_show_task(T_date date, string prefix);
void DB_add_task(N_node node, T_date date, string prefix);
void DB_delete_task(N_node node, T_date date, string prefix);
void DB_edit_all_task(N_node node, T_date date, string prefix);
void DB_edit_prefix_task(N_node node, T_date date, string prefix);
void DB_edit_suffix_task(N_node node, T_date date, string prefix);
void DB_done_task(N_node node, T_date date, string prefix);
void DB_toggle_task(N_node node, T_date date, string prefix);
void DB_set_config(KV_ kv);

#endif