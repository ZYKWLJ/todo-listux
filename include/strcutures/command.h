
typedef struct Command
{
    char **argv;
    int argc;
} Command;

void set_command(Command *command,int argc,char **argv);
void free_command(Command *command);
// void init_command(Command *command,int argc,char **argv,Command_Type command_type);
