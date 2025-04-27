#include "../include/include.h"
// 定义错误信息输出函数
void COMMAND_ERROR(Setting *setting, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    char on[]="on";
    if (setting != NULL && strcmp(setting->color,on)==0)
    {
        printf("%s", RED);
        vprintf(format, args);
        printf("%s --Unknown Command\n", RESET);
    }
    else
    {
        vprintf(format, args);
        printf(" --Unknown Command\n");
    }

    va_end(args);
}

int main(int argc, char **argv) {
    // Correct initialization of a Setting structure
    Setting setting = {
        .color = "on",  // Direct string literal assignment
        .show = "day"   // Initialize show field
    };

    // If you really need a pointer:
    Setting *setting_ptr = &setting;

    COMMAND_ERROR(setting_ptr, "%s", "hello world");
    return 0;
}