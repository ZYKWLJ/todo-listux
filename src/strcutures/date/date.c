#include "../../../include/include.h"
// #include "date.h"
// #include "date.h"
// 即解析第3个参数，第四个参数
void set_date(Date *date, int year, int month, int week, int day, Date_Type date_type)
{
    if (date == NULL)
    {
        printf("date haven't malloced! Can't assigned");
        return;
    }
    date->year = 0;
    date->month = 0;
    date->week = 0;
    date->day = 0;
    date->week = 0;
    date_type;
}

void free_date(Date *date)
{
    if (date == NULL)
    {
        printf("date is NULL! Can't free");
        return;
    }
    free(date);
}

