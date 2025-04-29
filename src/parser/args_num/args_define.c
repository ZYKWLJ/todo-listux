#include "../../../include/include.h"
#define PRINT_NOT_DIGIT_ERROR(arg) LOG_PRINT("%s is not a digit\n", arg)
#define ARGS_RIGHT() LOG_PRINT("args right, continue with the interface...\n")
#define MY_INTERFACE
#ifdef MY_INTERFACE
#define MY_INTERFACE_PRINT(format, ...) LOG_PRINT("[%s %s %s:%s :%d] " format, __DATE__, __TIME__, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#else
#define MY_INTERFACE_PRINT(format, ...) \
    do                                  \
    {                                   \
    } while (0)
#endif
