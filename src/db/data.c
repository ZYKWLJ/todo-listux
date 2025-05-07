#include "../../include/include.h"
// extern KV_ kv;
void DB_show_task(T_date date, string prefix)
{
    /**
     * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
     */
    TODO_PRINT("DB_show_task......prefix=%s\n", prefix);
}

void DB_add_task(N_node node, T_date date, string prefix)
{
    /**
     * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
     */
    TODO_PRINT("DB_add_task......prefix=%s\n", prefix);
}
void DB_delete_task(N_node node, T_date date, string prefix)
{
    /**
     * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
     */
    TODO_PRINT("DB_delete_task......prefix=%s\n", prefix);
}
void DB_edit_all_task(N_node node, T_date date, string prefix)
{
    /**
     * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
     */
    TODO_PRINT("DB_edit_all_task......prefix=%s\n", prefix);
}
void DB_edit_prefix_task(N_node node, T_date date, string prefix)
{
    /**
     * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
     */
    TODO_PRINT("DB_edit_prefix_task......prefix=%s\n", prefix);
}
void DB_edit_suffix_task(N_node node, T_date date, string prefix)
{
    /**
     * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
     */
    TODO_PRINT("DB_edit_suffix_task......prefix=%s\n", prefix);
}

void DB_done_task(N_node node, T_date date, string prefix)
{
    /**
     * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
     */
    TODO_PRINT("DB_done_task......prefix=%s\n", prefix);
}

void DB_toggle_task(N_node node, T_date date, string prefix)
{
    /**
     * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
     */
    TODO_PRINT("DB_toggle_task......prefix=%s\n", prefix);
}

void DB_set_config(KV_ kv)
{
    /**
     * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
     */
    TODO_PRINT("DB_set_config......K=%s\tv=%s\n", kv->key, kv->value);
    save_setting(get_appdata_path(SETTING_FILE),kv);
    
}