#include "../../include/include.h"
// #define TEST_COMMAND
#ifdef TEST_COMMAND
int main(int argc, char **argv)
{
    C_command command = C_command_init(NULL, argc, argv);
    C_command_print(command);
}

#endif