#include "../../include/include.h"
// 判断是否为闰年
const int MONTH_DAYS_IS_LEAP[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int MONTH_DAYS_IS_NOT_LEAP[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int get_month_of_day(int year,int month)
{
    return is_leap_year(year) ? MONTH_DAYS_IS_LEAP[month] : MONTH_DAYS_IS_NOT_LEAP[month];
}
// 获取当前日期
void get_current_date(Date *date)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    date->year = tm.tm_year + 1900;
    date->month = tm.tm_mon + 1;
    date->day = tm.tm_mday;
    date->week = calculate_week_number(date->day);
}

// 计算当年第几天
int day_of_year(int year, int month, int day)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year))
    {
        days[1] = 29;
    }
    int doy = 0;
    for (int i = 0; i < month - 1; i++)
    {
        doy += days[i];
    }
    doy += day;
    return doy;
}

int get_year(int *year)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    *year = tm.tm_year + 1900;
}

int get_month(int *month)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    *month = tm.tm_mon + 1;
}

int get_day(int *day)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    *day = tm.tm_mday;
}
int is_all_digits(const char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0; // 只要有一个字符不是数字，返回0
        }
    }
    return 1; // 所有字符都是数字，返回1
}