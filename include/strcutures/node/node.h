#ifndef NODE_H
#define NODE_H
#include "../../include.h"
// 这是命令实体，传参就传这一个就好了
// 大命令再划分为小日期命令
#define DISPLAY_TOKEN "^"
#define ADD_TOKEN "+"
#define COMPLETE_TOKEN "-"
#define DELETE_TOKEN "/"
#define TOGGLE_TOKEN "!"
#define CONFIGURATION_TOKEN "$"
#define EDIT_ALL_TOKEN "="
#define EDIT_PREFIX_TOKEN "=%"
#define EDIT_SUFFIX_TOKEN "%="
#define EQUAL "="
typedef enum Node_Type
{
    DISPLAY,
    ADD,
    DELETE_,
    EDIT,
    COMPLETE,
    TOGGLE,
    CONFIGURATION,
    HELP,
    ERROR_NODE, // 默认
} Node_Type;

typedef struct DISPLAY_NODE
{
    Date *date; // 日期
} DISPLAY_NODE;

typedef struct ADD_NODE
{
    Date *date;    // 日期
    char *content; // 内容
} ADD_NODE;

typedef struct DELETE_NODE
{
    Date *date; // 日期
    int num;    // 第几个
} DELETE_NODE;
typedef enum Edit_Type
{
    EDIT_ALL,
    EDIT_PREFIX,
    EDIT_SUFFIX,
} Edit_Type;
typedef struct EDIT_NODE
{
    Date *date;          // 日期
    int num;             // 第几个
    char *content;       // 内容
    Edit_Type edit_type; // 编辑类型
} EDIT_NODE;

typedef struct COMPLETE_NODE
{
    Date *date; // 日期
    int num;    // 第几个
} COMPLETE_NODE;

typedef struct TOGGLE_NODE
{
    Date *date; // 日期
    int num;    // 第几个
} TOGGLE_NODE;

typedef struct HELP_NODE
{

} HELP_NODE;

typedef struct CONFIGURATION_NODE
{
    char *KEY;
    char *VALUE;
} CONFIGURATION_NODE;

// 任何一个命令实体都是一个NODE，里面包含日期，命令类型
typedef struct NODE
{
    Node_Type node_type;        // 命令类型,初始化下面的，然后根据命令类型对应执行命令实体！
    DISPLAY_NODE *display_node; //
    ADD_NODE *add_node;
    DELETE_NODE *delete_node;
    EDIT_NODE *edit_node;
    COMPLETE_NODE *complete_node;
    TOGGLE_NODE *toggle_node;
    // HELP_NODE *help_node;
    CONFIGURATION_NODE *configuration_node;
} NODE;

// 初始化 DISPLAY_NODE
void set_display_node(DISPLAY_NODE *node, Date *date);

// 初始化 ADD_NODE
void set_add_node(ADD_NODE *node, Date *date, const char *content);

// 初始化 DELETE_NODE
void set_delete_node(DELETE_NODE *node, Date *date, int num);

// 初始化 EDIT_NODE
void set_edit_node(EDIT_NODE *node, Date *date, int num, const char *content, Edit_Type edit_type);
// 初始化 COMPLETE_NODE
void set_complete_node(COMPLETE_NODE *node, Date *date, int num);
// 初始化 TOGGLE_NODE
void set_toggle_node(TOGGLE_NODE *node, Date *date, int num);

// HELP_NODE 无数据，无需初始化函数
// 或者可以定义一个空的初始化函数：
void set_help_node(HELP_NODE *node);
// 初始化 CONFIGURATION_NODE
void set_configuration_node(CONFIGURATION_NODE *node, const char *key, const char *value);
// void set_node(NODE *node, Node_Type node_type, void *arg);
void set_node(NODE *node, Node_Type node_type, void *arg);

// 初始化 NODE 结构体的函数
void init_node(NODE *node, Node_Type node_type, DISPLAY_NODE *display_node, ADD_NODE *add_node,
               DELETE_NODE *delete_node, EDIT_NODE *edit_node, COMPLETE_NODE *complete_node,
               TOGGLE_NODE *toggle_node, CONFIGURATION_NODE *configuration_node);
void init_node1(NODE *node,Date*date);
#endif