#ifndef EXEC_H
#define EXEC_H
#include "../../include/include.h"

void exec(N_node node, C_command command, T_date date)
{
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
        break;
    case 3:
        TODO_PRINT("add function......");
        break;
    case 4:
        TODO_PRINT("delete function......");
        break;
    case 5:
        TODO_PRINT("edit all function......");
        break;
    case 6:
        TODO_PRINT("edit prefix function......");
        break;
    case 7:
        TODO_PRINT("edit suffix function......");
        break;
    case 8:
        TODO_PRINT("done function......");
        break;
    case 9:
        TODO_PRINT("toggle function......");
        break;
    case 10:
        TODO_PRINT("setting config function......");
        break;
    }
}

#endif