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
        HELP,   /*帮助信息*/
        SHOW,   /*显示*/
        ADD,    /*添加*/
        DELETE, /*删除*/
        EDIT,   /*编辑*/
        DONE,   /*标记完成*/
        TOGGLE, /*翻转标记*/
        ERROR,  /*错误的类型*/
    } node_type;

    union
    {

        struct
        {
            T_date date;
        } SHOW; /*show节点需要使用的信息有日期*/
        struct
        {
            T_date date;
            string content;
        } ADD; /*add节点需要使用的信息有日期和内容*/
        struct
        {
            T_date date;
            int id;
        } DELETE; /*delete节点需要使用的信息有id和日期*/
        struct
        {
            T_date date;
            int id;
            EDIT_type edit_type;
            string content;
        } EDIT; /*edit节点需要使用的信息有id、日期和内容*/
        struct
        {
            T_date date;
            int id;
        } DONE; /*done节点需要使用的信息有id和日期*/
        struct
        {
            T_date date;
            int id;
        } TOGGLE; /*toggle节点需要使用的信息有id和日期*/
        E_error ERROR;
    } node_data;
} *N_node;

#endif