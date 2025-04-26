// #define LOG
#ifdef LOG
    #define LOG_PRINT(format, ...) printf("[%s %s %s:%s :%d] " format, __DATE__, __TIME__, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#else
    #define LOG_PRINT(format, ...) do {} while(0)
#endif