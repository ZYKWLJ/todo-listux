#include "../../include/include.h"
// #include "command.h"

C_command C_command_init(C_command c, int argc, char** argv)
{
    C_command command = (C_command)checked_malloc(sizeof(*c));
    command->argc = argc;
    command->argv = argv;
    return command;
}
void C_command_print(C_command command)
{
    printf("argc: %d\n", command->argc);
    for (int i = 0; i < command->argc; i++)
    {
        printf("argv[%d]: %s\n", i, command->argv[i]);
    }
}