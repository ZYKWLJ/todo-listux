#include "../../include/include.h"
// 判断是否为闰年
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取当前日期
void get_current_date(int* year, int* month, int* day) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    *year = tm.tm_year + 1900;
    *month = tm.tm_mon + 1;
    *day = tm.tm_mday;
}

// 计算当年第几天
int day_of_year(int year, int month, int day) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year)) {
        days[1] = 29;
    }
    int doy = 0;
    for (int i = 0; i < month - 1; i++) {
        doy += days[i];
    }
    doy += day;
    return doy;
}