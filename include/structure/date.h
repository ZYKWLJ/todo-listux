#ifndef DATE_H
#define DATE_H
#include <time.h>
typedef struct T_time_
{
    /**
     * data descp: 在这里指定是哪一种类型时间
     */
    enum
    {
        D,
        W,
        M,
        Y,
    } date_type;
    int year;
    int month;
    int day;
    int week;
    int hour;
    int minute;
    int second;
} *T_current_date;

int calculate_week_number(int day);

T_current_date T_current_date_init(T_current_date t);
void T_time_print(T_current_date t);

typedef struct T_date_
{
    /**
     * data descp: 这里无论如何都要使用现在的时间，所以没必要使用union了
     */
    T_current_date T_current_date;
    T_current_date T_specific_date; /*最后传参一定是传这个具体时间*/

} *T_date;

T_date T_date_init(T_date t);
#endif