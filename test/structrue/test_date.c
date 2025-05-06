#include "../../include/include.h"
// #define TEST_DATE
#ifdef TEST_DATE
int main(int argc, char **argv)
{
    T_time date=T_time_init(NULL);
    T_time_print(date);
    return 0;
}

#endif