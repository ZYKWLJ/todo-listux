#include "../../include/include.h"

void set_command(Command *command, int argc, char **argv)
{
    if (command == NULL)
    {
        LOG_PRINT("command is NULL\n");
        exit(EXIT_FAILURE);
    }
    command->argc = argc;
    command->argv = argv;
}
void free_command(Command *command)
{
    if (command == NULL)
    {
        LOG_PRINT("command is NULL\n");
        exit(EXIT_FAILURE);
    }
    free(command);
}