#ifndef DATE_H
#define DATE_H
#include <time.h>
typedef struct T_time_
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} *T_current_date;

T_current_date T_current_date_init(T_current_date t);
void T_time_print(T_current_date t);

typedef struct T_date_
{
    enum
    {
        CURRENT_DATE,
        SPECIFIC_DATE
    } T_date_type;
    union
    {
        T_current_date T_current_date;
        T_current_date T_specific_date;
    } T_date_data;
} *T_date;

T_date T_date_init(T_date t);

#endif