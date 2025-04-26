#include "../../include/include.h"
// 即解析第3个参数，第四个参数
Date_Type parse_date_type(char *date_type)
{
    if (strcmp(date_type, "day") == 0 || strcmp(date_type, "d") == 0)
    {
        return DAY;
    }
    else if (strcmp(date_type, "week") == 0 || strcmp(date_type, "w") == 0)
    {
        return WEEK;
    }
    else if (strcmp(date_type, "month") == 0 || strcmp(date_type, "m") == 0)
    {
        return MONTH;
    }
    else if (strcmp(date_type, "year") == 0 || strcmp(date_type, "y") == 0)
    {
        return YEAR;
    }
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

// 固定数据结构，2025.01.04

void validate_year_format(const char *date_str, Date *date)
{
    // 基础检查
    if (strlen(date_str) != 4)
    {
        date->Error->error_code = 1;
        return;
    }

    if (!(is_all_digits(date_str)))
    {
        date->Error->error_code = 1;
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
        date->Error->error_code = 1;
        return;
    }
    date->Year->year = year;
    date->Error->error_code = 0;
    printf("year parser passed!!!\n");
}

// 重构validate_year_month_format函数
// 2025.09
void validate_year_month_format(const char *date_str, Date *date)
{
    // 基础检查
    if (strlen(date_str) != 7)
    {
        date->Error->error_code = 1;
        return;
    }

    // 检查字符组成(和分隔符)
    for (int i = 0; i < 7; i++)
    {
        if ((i == 4) ? (date_str[i] != '.') : (!isdigit(date_str[i])))
        {
            date->Error->error_code = 1;
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
        date->Error->error_code = 1;
        return;
    }
    date->Year->year = year;
    date->Month->month = month;
    date->Error->error_code = 0;
    printf("month parser passed!!!\n");
}

// 重构validate_date_format函数
void validate_date_format(const char *date_str, Date *date)
{
    // 基础格式检查
    // if (!basic_check(date_str, 10, 10))
    if (strlen(date_str) != 10)
    {
        date->Error->error_code = 1;
        return;
    }

    // 检查字符组成(和分隔符)
    for (int i = 0; i < 10; i++)
    {
        if ((i == 4 || i == 7) ? (date_str[i] != '.') : (!isdigit(date_str[i])))
        {
            date->Error->error_code = 1;
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
        date->Error->error_code = 1;
        return;
    }
    else if (year == current_year)
    {
        if (month < current_month)
        {
            date->Error->error_code = 1;
            return;
        }
        else if (month == current_month)
        {
            if (day < current_day)
            {
                date->Error->error_code = 1;
                return;
            }
        }
    }

    // 月份检查
    if (month < 1 || month > 12)
    {
        date->Error->error_code = 1;
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
        date->Error->error_code = 1;
        return;
    }

    date->Year->year = year;
    date->Month->month = month;
    date->Day->day = day;
    date->Error->error_code = 0;

    printf("date parser passed!!!\n");
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
        date->Error->error_code = 1;
        return;
    }

    // 检查字符组成(和分隔符)
    for (int i = 0; i < 9; i++)
    {
        if ((i == 4 || i == 7) ? (date_str[i] != '.') : (!isdigit(date_str[i])))
        {
            date->Error->error_code = 1;
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
        date->Error->error_code = 1;
        return;
    }
    else if (year == current_year)
    {
        if (month < current_month || month < 1 || month > 12)
        {
            date->Error->error_code = 1;
            return;
        }
        else if (month == current_month)
        {
            if (week < calculate_week_number(current_day)) // 不能小于当前周
            {
                date->Error->error_code = 1;
                return;
            }
        }
    }
    date->Year->year = year;
    date->Month->month = month;
    date->Week->week = week; // 这里day存周数
    date->Error->error_code = 0;
    printf("week parser passed!!!\n");
}

Date* parse_date(Date_Type date_type, char *date_str,Date*date)
{
    // Date date = {0};
    switch (date_type)
    {
    case DAY:
        validate_date_format(date_str, date);
        break;
    case WEEK:
        validate_week_format(date_str, date);
        break;
    case MONTH:
        validate_year_month_format(date_str, date);
        break;
    case YEAR:
        validate_year_format(date_str, date);
        break;
    }
    return date;
}


// int main()
// {
//     // 测试 YEAR 类型 - 有效
//     {
//         char date_str[] = "2025";
//         Date* result = (Date*)malloc(sizeof(Date));
//         result->Day=(Date_Day*)malloc(sizeof(Date_Day));
//         result->Month=(Date_Month*)malloc(sizeof(Date_Month));
//         result->Week=(Date_Week*)malloc(sizeof(Date_Week));
//         result->Year=(Date_Year*)malloc(sizeof(Date_Year));
//         result->Error=(Date_Error*)malloc(sizeof(Date_Error));
//         result = parse_date(YEAR, date_str,result);
//         if (result->Error->error_code == 0)
//         {
//             printf("YEAR - Valid. Year: %d\n", result->Year->year);
//         }
//         else
//         {
//             printf("YEAR - Invalid\n");
//         }
//         free(result->Day);
//         free(result->Month);
//         free(result->Week);
//         free(result->Year);
//         free(result->Error);
//         free(result);
//     }

//     // 测试 YEAR 类型 - 无效（年份过小）
//     {
//         char date_str[] = "2000";
//         Date* result = (Date*)malloc(sizeof(Date));
//         result->Day=(Date_Day*)malloc(sizeof(Date_Day));
//         result->Month=(Date_Month*)malloc(sizeof(Date_Month));
//         result->Week=(Date_Week*)malloc(sizeof(Date_Week));
//         result->Year=(Date_Year*)malloc(sizeof(Date_Year));
//         result->Error=(Date_Error*)malloc(sizeof(Date_Error));
//         result = parse_date(YEAR, date_str,result);
//         if (result->Error->error_code == 0)
//         {
//             printf("YEAR - Valid (should be invalid)\n");
//         }
//         else
//         {
//             printf("YEAR - Invalid (correct)\n");
//         }
//         free(result->Day);
//         free(result->Month);
//         free(result->Week);
//         free(result->Year);
//         free(result->Error);
//         free(result);
//     }

//     // 测试 MONTH 类型 - 有效
//     {
//         char date_str[] = "2025.08";
//         Date* result = (Date*)malloc(sizeof(Date));
//         result->Day=(Date_Day*)malloc(sizeof(Date_Day));
//         result->Month=(Date_Month*)malloc(sizeof(Date_Month));
//         result->Week=(Date_Week*)malloc(sizeof(Date_Week));
//         result->Year=(Date_Year*)malloc(sizeof(Date_Year));
//         result->Error=(Date_Error*)malloc(sizeof(Date_Error));
//         result = parse_date(MONTH, date_str,result);
//         if (result->Error->error_code == 0)
//         {
//             printf("MONTH - Valid. Year: %d, Month: %d\n",
//                    result->Year->year, result->Month->month);
//         }
//         else
//         {
//             printf("MONTH - Invalid\n");
//         }
//         free(result->Day);
//         free(result->Month);
//         free(result->Week);
//         free(result->Year);
//         free(result->Error);
//         free(result);
//     }

//     // 测试 MONTH 类型 - 无效（格式错误）
//     {
//         char date_str[] = "2025/08";
//         Date* result = (Date*)malloc(sizeof(Date));
//         result->Day=(Date_Day*)malloc(sizeof(Date_Day));
//         result->Month=(Date_Month*)malloc(sizeof(Date_Month));
//         result->Week=(Date_Week*)malloc(sizeof(Date_Week));
//         result->Year=(Date_Year*)malloc(sizeof(Date_Year));
//         result->Error=(Date_Error*)malloc(sizeof(Date_Error));
//         result = parse_date(MONTH, date_str,result);
//         if (result->Error->error_code == 0)
//         {
//             printf("MONTH - Valid (should be invalid)\n");
//         }
//         else
//         {
//             printf("MONTH - Invalid (correct)\n");
//         }
//         free(result->Day);
//         free(result->Month);
//         free(result->Week);
//         free(result->Year);
//         free(result->Error);
//         free(result);
//     }

//     // 测试 WEEK 类型 - 有效
//     {
//         char date_str[] = "2025.08.3";
//         Date* result = (Date*)malloc(sizeof(Date));
//         result->Day=(Date_Day*)malloc(sizeof(Date_Day));
//         result->Month=(Date_Month*)malloc(sizeof(Date_Month));
//         result->Week=(Date_Week*)malloc(sizeof(Date_Week));
//         result->Year=(Date_Year*)malloc(sizeof(Date_Year));
//         result->Error=(Date_Error*)malloc(sizeof(Date_Error));
//         result = parse_date(WEEK, date_str,result);
//         if (result->Error->error_code == 0)
//         {
//             printf("WEEK - Valid. Year: %d, Month: %d, Week: %d\n",
//                    result->Year->year, result->Month->month, result->Week->week);
//         }
//         else
//         {
//             printf("WEEK - Invalid\n");
//         }
//         free(result->Day);
//         free(result->Month);
//         free(result->Week);
//         free(result->Year);
//         free(result->Error);
//         free(result);
//     }

//     // 测试 WEEK 类型 - 无效（周数过大）
//     {
//         char date_str[] = "2025.08.5";
//         Date* result = (Date*)malloc(sizeof(Date));
//         result->Day=(Date_Day*)malloc(sizeof(Date_Day));
//         result->Month=(Date_Month*)malloc(sizeof(Date_Month));
//         result->Week=(Date_Week*)malloc(sizeof(Date_Week));
//         result->Year=(Date_Year*)malloc(sizeof(Date_Year));
//         result->Error=(Date_Error*)malloc(sizeof(Date_Error));
//         result = parse_date(WEEK, date_str,result);
//         if (result->Error->error_code == 0)
//         {
//             printf("WEEK - Valid (should be invalid)\n");
//         }
//         else
//         {
//             printf("WEEK - Invalid (correct)\n");
//         }
//         free(result->Day);
//         free(result->Month);
//         free(result->Week);
//         free(result->Year);
//         free(result->Error);
//         free(result);
//     }

//     // 测试 DAY 类型 - 有效
//     {
//         char date_str[] = "2025.08.15";
//         Date* result = (Date*)malloc(sizeof(Date));
//         result->Day=(Date_Day*)malloc(sizeof(Date_Day));
//         result->Month=(Date_Month*)malloc(sizeof(Date_Month));
//         result->Week=(Date_Week*)malloc(sizeof(Date_Week));
//         result->Year=(Date_Year*)malloc(sizeof(Date_Year));
//         result->Error=(Date_Error*)malloc(sizeof(Date_Error));
//         result = parse_date(DAY, date_str,result);
//         if (result->Error->error_code == 0)
//         {
//             printf("DAY - Valid. Year: %d, Month: %d, Day: %d\n",
//                    result->Year->year, result->Month->month, result->Day->day);
//         }
//         else
//         {
//             printf("DAY - Invalid\n");
//         }
//         free(result->Day);
//         free(result->Month);
//         free(result->Week);
//         free(result->Year);
//         free(result->Error);
//         free(result);
//     }

//     // 测试 DAY 类型 - 无效（日期不存在）
//     {
//         char date_str[] = "2025.02.30";
//         Date* result = (Date*)malloc(sizeof(Date));
//         result->Day=(Date_Day*)malloc(sizeof(Date_Day));
//         result->Month=(Date_Month*)malloc(sizeof(Date_Month));
//         result->Week=(Date_Week*)malloc(sizeof(Date_Week));
//         result->Year=(Date_Year*)malloc(sizeof(Date_Year));
//         result->Error=(Date_Error*)malloc(sizeof(Date_Error));
//         result = parse_date(DAY, date_str,result);
//         if (result->Error->error_code == 0)
//         {
//             printf("DAY - Valid (should be invalid)\n");
//         }
//         else
//         {
//             printf("DAY - Invalid (correct)\n");
//         }
//         free(result->Day);
//         free(result->Month);
//         free(result->Week);
//         free(result->Year);
//         free(result->Error);
//         free(result);
//     }

//     return 0;
// }
// gcc D:\3software\todo-listux-1\todo-listux\src\lexer\date.c  D:\3software\todo-listux-1\todo-listux\src\tools\tools.c -o  D:\3software\todo-listux-1\todo-listux\src\lexer\date