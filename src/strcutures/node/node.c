#include "../../../include/include.h"

// 初始化 DISPLAY_NODE
void set_display_node(DISPLAY_NODE *node, Date *date)
{
    if (!node)
        return;
    node->date = date;
}

// 初始化 ADD_NODE
void set_add_node(ADD_NODE *node, Date *date, const char *content)
{
    if (!node)
        return;
    node->date = date;
    node->content = content ? strdup(content) : NULL; // 复制字符串
}

// 初始化 DELETE_NODE
void set_delete_node(DELETE_NODE *node, Date *date, int num)
{
    if (!node)
        return;
    node->date = date;
    node->num = num;
}

// 初始化 EDIT_NODE
void set_edit_node(EDIT_NODE *node, Date *date, int num, const char *content, Edit_Type edit_type)
{
    if (!node)
        return;
    node->date = date;
    node->num = num;
    node->content = content ? strdup(content) : NULL; // 复制字符串
    node->edit_type = edit_type;
}

// 初始化 COMPLETE_NODE
void set_complete_node(COMPLETE_NODE *node, Date *date, int num)
{
    if (!node)
        return;
    node->date = date;
    node->num = num;
}

// 初始化 TOGGLE_NODE
void set_toggle_node(TOGGLE_NODE *node, Date *date, int num)
{
    if (!node)
        return;
    node->date = date;
    node->num = num;
}

// HELP_NODE 无数据，无需初始化函数
// 或者可以定义一个空的初始化函数：
void set_help_node(HELP_NODE *node)
{
    // 无操作
}

// 初始化 CONFIGURATION_NODE
void set_configuration_node(CONFIGURATION_NODE *node, const char *key, const char *value)
{
    if (!node)
        return;
    node->KEY = key ? strdup(key) : NULL;       // 复制字符串
    node->VALUE = value ? strdup(value) : NULL; // 复制字符串
}
void set_node(NODE *node, Node_Type node_type, void *arg /*可以传入任何参数指针*/)
{
    if (!node)
        return;

    // 先释放旧数据（防止内存泄漏）
    switch (node->node_type)
    {
    case ADD:
        if (node->add_node)
        {
            free(node->add_node->content); // 释放字符串
            free(node->add_node);
        }
        break;
    case DELETE_:
        free(node->delete_node);
        break;
    case EDIT:
        if (node->edit_node)
        {
            free(node->edit_node->content); // 释放字符串
            free(node->edit_node);
        }
        break;
    case COMPLETE:
        free(node->complete_node);
        break;
    case TOGGLE:
        free(node->toggle_node);
        break;
    case CONFIGURATION:
        if (node->configuration_node)
        {
            free(node->configuration_node->KEY);   // 释放字符串
            free(node->configuration_node->VALUE); // 释放字符串
            free(node->configuration_node);
        }
        break;
    default:
        break; // DISPLAY/HELP 无需释放
    }

    // 设置新数据
    node->node_type = node_type;
    switch (node_type)
    {
    case DISPLAY:
        node->display_node = (DISPLAY_NODE *)arg;
        break;
    case ADD:
        node->add_node = (ADD_NODE *)arg;
        break;
    case DELETE_:
        node->delete_node = (DELETE_NODE *)arg;
        break;
    case EDIT:
        node->edit_node = (EDIT_NODE *)arg;
        break;
    case COMPLETE:
        node->complete_node = (COMPLETE_NODE *)arg;
        break;
    case TOGGLE:
        node->toggle_node = (TOGGLE_NODE *)arg;
        break;
    // case HELP:
    //     node->help_node = NULL; // 无数据
    //     break;
    case CONFIGURATION:
        node->configuration_node = (CONFIGURATION_NODE *)arg;
        break;
    default:
        break; // 未知类型
    }
}
void init_node(NODE *node, Node_Type node_type, DISPLAY_NODE *display_node, ADD_NODE *add_node, DELETE_NODE *delete_node, EDIT_NODE *edit_node, COMPLETE_NODE *complete_node, TOGGLE_NODE *toggle_node, CONFIGURATION_NODE *configuration_node)
{
    if (!node || !node_type || !display_node || !add_node || !delete_node || !edit_node ||
        !complete_node || !toggle_node || !configuration_node)
    {
        return;
    }

    // 初始化各个子结构体指针
    node->display_node = display_node;
    node->add_node = add_node;
    node->delete_node = delete_node;
    node->edit_node = edit_node;
    node->complete_node = complete_node;
    node->toggle_node = toggle_node;
    node->configuration_node = configuration_node;

    // 根据 date_type 初始化日期相关信息
    Date *date = display_node->date;
}

void init_node1(NODE *node, Date *date)
{

    DISPLAY_NODE *display_node = (DISPLAY_NODE *)malloc(sizeof(DISPLAY_NODE));
    {
        {
            display_node->date = (Date *)malloc(sizeof(Date));
            display_node->date = date;
        }
    }
    LOG_PRINT("%s", "display malloc passed!!\n");
    ADD_NODE *add_node = (ADD_NODE *)malloc(sizeof(ADD_NODE));
    {

        {
            add_node->date = (Date *)malloc(sizeof(Date));
            add_node->date = date;
            add_node->content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
        }
    }
    LOG_PRINT("%s", "add_node malloc passed!!\n");

    DELETE_NODE *delete_node = (DELETE_NODE *)malloc(sizeof(DELETE_NODE));
    {
        {
            delete_node->date = (Date *)malloc(sizeof(Date));
            delete_node->date = date;
            delete_node->num = 1;
        }
    }
    LOG_PRINT("%s", "delete_node malloc passed!!\n");

    EDIT_NODE *edit_node = (EDIT_NODE *)malloc(sizeof(EDIT_NODE));
    {
        {
            edit_node->date = (Date *)malloc(sizeof(Date));
            edit_node->date = date;
            edit_node->num = 1;
            char *content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
            edit_node->content = content;
            edit_node->edit_type = EDIT_ALL; // 默认全换
        }
    }
    LOG_PRINT("%s", "edit_node malloc passed!!\n");
    COMPLETE_NODE *complete_node = (COMPLETE_NODE *)malloc(sizeof(COMPLETE_NODE));
    {
        {
            complete_node->date = (Date *)malloc(sizeof(Date));
            complete_node->date = date;
            complete_node->num = 1;
        }
    }
    LOG_PRINT("%s", "complete_node malloc passed!!\n");
    TOGGLE_NODE *toggle_node = (TOGGLE_NODE *)malloc(sizeof(TOGGLE_NODE));
    {
        {

            toggle_node->date = (Date *)malloc(sizeof(Date));
            toggle_node->date = date;
            toggle_node->num = 1;
        }
    }
    LOG_PRINT("%s", "toggle_node malloc passed!!\n");

    CONFIGURATION_NODE *configuration_node = (CONFIGURATION_NODE *)malloc(sizeof(CONFIGURATION_NODE));
    {
        {
            configuration_node->KEY = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
            configuration_node->VALUE = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
            configuration_node->KEY = strdup("config_key");
            configuration_node->VALUE = strdup("config_value");
        }
    }
    LOG_PRINT("%s", "configuration_node malloc passed!!\n");

    // init Node
    init_node(node, ERROR_NODE, display_node, add_node, delete_node, edit_node, complete_node, toggle_node, configuration_node);
}