#include "../../include/include.h"
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

// 固定数据结构，2025.01.04

void validate_year_format(const char *date_str, Date *date)
{
    // 基础检查
    if (strlen(date_str) != 4)
    {
        date->error = 1;
        return;
    }

    if (!(is_all_digits(date_str)))
    {
        date->error = 1;
        return;
    }

    // 提取数值
    int year = (date_str[0] - '0') * 1000 + (date_str[1] - '0') * 100 +
               (date_str[2] - '0') * 10 + (date_str[3] - '0');

    // 获取当前日期
    int current_year, current_month, current_day;
    get_current_date(&current_year, &current_month, &current_day);
    if (year < current_year)
    {
        date->error = 1;
        return;
    }
    date->year = year;
    date->error = 0;
    // printf("year parser passed!!!\n");
}

// 重构validate_year_month_format函数
// 2025.09
void validate_year_month_format(const char *date_str, Date *date)
{
    // 基础检查
    if (strlen(date_str) != 7)
    {
        date->error = 1;
        return;
    }

    // 检查字符组成(和分隔符)
    for (int i = 0; i < 7; i++)
    {
        if ((i == 4) ? (date_str[i] != '.') : (!isdigit(date_str[i])))
        {
            date->error = 1;
            return;
        }
    }

    // 提取数值
    int month = (date_str[5] - '0') * 10 + (date_str[6] - '0');
    int year = (date_str[0] - '0') * 1000 + (date_str[1] - '0') * 100 +
               (date_str[2] - '0') * 10 + (date_str[3] - '0');

    // 获取当前日期
    int current_year, current_month, current_day;
    get_current_date(&current_year, &current_month, &current_day);
    if (year < current_year || (year == current_year && month < current_month))
    {
        date->error = 1;
        return;
    }
    date->year = year;
    date->month = month;
    date->error = 0;
    // printf("month parser passed!!!\n");
}

// 重构validate_date_format函数
void validate_date_format(const char *date_str, Date *date)
{
    // 基础格式检查
    // if (!basic_check(date_str, 10, 10))
    if (strlen(date_str) != 10)
    {
        date->error = 1;
        return;
    }

    // 检查字符组成(和分隔符)
    for (int i = 0; i < 10; i++)
    {
        if ((i == 4 || i == 7) ? (date_str[i] != '.') : (!isdigit(date_str[i])))
        {
            date->error = 1;
            return;
        }
    }

    // 提取数值
    int day = (date_str[8] - '0') * 10 + (date_str[9] - '0');
    int month = (date_str[5] - '0') * 10 + (date_str[6] - '0');
    int year = (date_str[0] - '0') * 1000 + (date_str[1] - '0') * 100 +
               (date_str[2] - '0') * 10 + (date_str[3] - '0');

    // 获取当前日期
    int current_year, current_month, current_day;
    get_current_date(&current_year, &current_month, &current_day);

    // 检查日期不小于今天
    if (year < current_year)
    {
        date->error = 1;
        return;
    }
    else if (year == current_year)
    {
        if (month < current_month)
        {
            date->error = 1;
            return;
        }
        else if (month == current_month)
        {
            if (day < current_day)
            {
                date->error = 1;
                return;
            }
        }
    }

    // 月份检查
    if (month < 1 || month > 12)
    {
        date->error = 1;
        return;
    }

    // 日期检查
    int max_day;
    switch (month)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        max_day = 30;
        break;
    case 2:
        max_day = is_leap_year(year) ? 29 : 28;
        break;
    default:
        max_day = 31;
    }

    if (day < 1 || day > max_day)
    {
        date->error = 1;
        return;
    }

    date->year = year;
    date->month = month;
    date->day = day;
    date->error = 0;

    // printf("date parser passed!!!\n");
}

// 计算指定日期属于哪一周（每月固定4周）
int calculate_week_number(int day)
{
    if (day <= 7)
        return 1;
    if (day <= 14)
        return 2;
    if (day <= 21)
        return 3;
    return 4; // 第4周包含22日及以后的所有天数
}

// 重构validate_week_format函数
void validate_week_format(const char *date_str, Date *date)
{
    // 基础格式检查
    if (strlen(date_str) != 9)
    {
        date->error = 1;
        return;
    }

    // 检查字符组成(和分隔符)
    for (int i = 0; i < 9; i++)
    {
        if ((i == 4 || i == 7) ? (date_str[i] != '.') : (!isdigit(date_str[i])))
        {
            date->error = 1;
            return;
        }
    }

    // 提取数值
    int week = (date_str[8] - '0');
    int month = (date_str[5] - '0') * 10 + (date_str[6] - '0');
    int year = (date_str[0] - '0') * 1000 + (date_str[1] - '0') * 100 +
               (date_str[2] - '0') * 10 + (date_str[3] - '0');

    // 获取当前日期
    int current_year, current_month, current_day;
    get_current_date(&current_year, &current_month, &current_day);

    // 检查日期不小于今天
    if (year < current_year)
    {
        date->error = 1;
        return;
    }
    else if (year == current_year)
    {
        if (month < current_month || month < 1 || month > 12)
        {
            date->error = 1;
            return;
        }
        else if (month == current_month)
        {
            if (week < calculate_week_number(current_day)) // 不能小于当前周
            {
                date->error = 1;
                return;
            }
        }
    }
    date->year = year;
    date->month = month;
    date->week = week; // 这里day存周数
    date->error = 0;
    // printf("week parser passed!!!\n");
}

