#ifndef NODE_H
#define NODE_H

#include "../include.h"
typedef char *string;
/**
 * data descp: 编辑类型, 可以是全部编辑，也可以是前缀编辑，也可以是后缀编辑
 */
typedef enum EDIT_type_
{
    ALL,
    PREFIX,
    SUFFIX,
} * EDIT_type;
/**
 * data descp: 这是贯穿始终的执行节点，所有都围绕其展开
 */
typedef struct N_node_
{
    enum /*匿名枚举*/
    {
        ERROR,   /*错误节点*/
        HELP,   /*帮助信息*/
        SHOW,   /*显示*/
        ADD,    /*添加*/
        DELETE, /*删除*/
        EDIT_ALL,   /*编辑*/
        EDIT_PREFIX,/*编辑前缀*/
        EDIT_SUFFIX,/*编辑后缀*/
        DONE,   /*标记完成*/
        TOGGLE, /*翻转标记*/
        SET,    /*设置*/
    } node_type;

    union
    {

        struct /*必须为每一个节点都配备一个报错信息，用来报错确认节点之后的错误信息*/
        {
            T_date date;
            E_error ERROR;
        } SHOW; /*show节点需要使用的信息有日期*/
        struct
        {
            T_date date;
            string content;
            E_error ERROR;
        } ADD; /*add节点需要使用的信息有日期和内容*/
        struct
        {
            T_date date;
            int id;
            E_error ERROR;
        } DELETE; /*delete节点需要使用的信息有id和日期*/
        struct
        {
            T_date date;
            int id;
            EDIT_type edit_type;
            string content;
            E_error ERROR;
        } EDIT; /*edit节点需要使用的信息有id、日期和内容*/
        struct
        {
            T_date date;
            int id;
            E_error ERROR;
        } DONE; /*done节点需要使用的信息有id和日期*/
        struct
        {
            T_date date;
            int id;
            E_error ERROR;
        } TOGGLE; /*toggle节点需要使用的信息有id和日期*/

    } node_data;
} *N_node;

N_node N_node_init(N_node node);
#endif