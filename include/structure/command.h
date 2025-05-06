#ifndef COMMAND_H
#define COMMAND_H
#include "../include.h"
typedef struct C_command_
{
    int argc;
    char** argv;
} *C_command;

C_command C_command_init(C_command command, int argc, char **argv);
void C_command_print(C_command command);
#endif