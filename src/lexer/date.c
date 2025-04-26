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

// 检查日期字符串中的分隔符是否一致且无连续分隔符
// 参数:
//   date - 要检查的日期字符串
//   delimiter - 用于返回找到的分隔符
// 返回值:
//   1 - 格式正确
//   0 - 格式错误
// 规定只能使用.作为分割符号

// 返回日期范畴并且返回具体的日期

// 新增数据结构，可以直接返回日期与格式类型！

typedef struct Date_Expected
{
    Date *date; // 返回日期！
    int expect; // 正确为1.错误为0
} Date_Expected;
// 深复制 Date 类型的函数示例
void copy_date(Date *destination, Date_Expected *source)
{
    memcpy(destination, &(source->date), sizeof(Date));
}

void validate_year_format(const char *date_str, Date_Expected *date_expected)
{
    // 基础检查
    if (strlen(date_str) != 4)
    {
        date_expected->expect = 0;
        return;
    }

    if (!(is_all_digits(date_str)))
    {
        date_expected->expect = 0;
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
        date_expected->expect = 0;
        return;
    }
    date_expected->date->year.year = year;
    date_expected->expect = 1;
    printf("date_expected->date->year.year: %d\n", date_expected->date->year.year);
    printf("year parser passed!!!\n");
}

// 重构validate_year_month_format函数
// 2025.09
void validate_year_month_format(const char *date_str, Date_Expected *date_expected)
{
    // 基础检查
    if (strlen(date_str) != 7)
    {
        date_expected->expect = 0;
        return;
    }

    // 检查字符组成(和分隔符)
    for (int i = 0; i < 7; i++)
    {
        if ((i == 4) ? (date_str[i] != '.') : (!isdigit(date_str[i])))
        {
            date_expected->expect = 0;
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
        date_expected->expect = 0;
        return;
    }
    date_expected->date->year.year = year;
    date_expected->date->month.month = month;
    date_expected->expect = 1;
    printf("date_expected->date->year.year: %d\n", date_expected->date->year.year);
    printf("date_expected->date->month.month: %d\n", date_expected->date->month.month);

    printf("month parser passed!!!\n");
}

// 重构validate_date_format函数
void validate_date_format(const char *date_str, Date_Expected *date_expected)
{
    // 基础格式检查
    // if (!basic_check(date_str, 10, 10))
    if (strlen(date_str) != 10)
    {
        date_expected->expect = 0;
        return;
    }

    // 检查字符组成(和分隔符)
    for (int i = 0; i < 10; i++)
    {
        if ((i == 4 || i == 7) ? (date_str[i] != '.') : (!isdigit(date_str[i])))
        {
            date_expected->expect = 0;
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
        date_expected->expect = 0;
        return;
    }
    else if (year == current_year)
    {
        if (month < current_month)
        {
            date_expected->expect = 0;
            return;
        }
        else if (month == current_month)
        {
            if (day < current_day)
            {
                date_expected->expect = 0;
                return;
            }
        }
    }

    // 月份检查
    if (month < 1 || month > 12)
    {
        date_expected->expect = 0;
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
        date_expected->expect = 0;
        return;
    }

    date_expected->date->year.year = year;
    date_expected->date->month.month = month;
    date_expected->date->day.day = day;
    date_expected->expect = 1;
    printf("date_expected->date->year.year: %d\n", date_expected->date->year.year);
    printf("date_expected->date->month.month: %d\n", date_expected->date->month.month);
    printf("date_expected->date->day.day: %d\n", date_expected->date->day.day);
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
void validate_week_format(const char *date, Date_Expected *date_expected)
{
    // 基础格式检查
    if (strlen(date) != 9)
    {
        date_expected->expect = 0;
        return;
    }

    // 检查字符组成(和分隔符)
    for (int i = 0; i < 9; i++)
    {
        if ((i == 4 || i == 7) ? (date[i] != '.') : (!isdigit(date[i])))
        {
            date_expected->expect = 0;
            return;
        }
    }

    // 提取数值
    int week = (date[8] - '0');
    int month = (date[5] - '0') * 10 + (date[6] - '0');
    int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 +
               (date[2] - '0') * 10 + (date[3] - '0');

    // 获取当前日期
    int current_year, current_month, current_day;
    get_current_date(&current_year, &current_month, &current_day);

    // 检查日期不小于今天
    if (year < current_year)
    {
        date_expected->expect = 0;
        return;
    }
    else if (year == current_year)
    {
        if (month < current_month || month < 1 || month > 12)
        {
            date_expected->expect = 0;
            return;
        }
        else if (month == current_month)
        {
            if (week < calculate_week_number(current_day)) // 不能小于当前周
            {
                date_expected->expect = 0;
                return;
            }
        }
    }
    date_expected->date->year.year = year;
    date_expected->date->month.month = month;
    date_expected->date->week.week = week; // 这里day存周数
    date_expected->expect = 1;
    printf("date_expected->date->year.year: %d\n", date_expected->date->year.year);
    printf("date_expected->date->month.month: %d\n", date_expected->date->month.month);
    printf("date_expected->date->week.week: %d\n", date_expected->date->week.week);
    printf("week parser passed!!!\n");
}

Date parse_date(Date_Type date_type, char *date_str, Date *date)
{
    Date_Expected *date_expected = (Date_Expected *)malloc(sizeof(Date_Expected));
    date_expected->expect = 0;
    date_expected->date = (Date *)malloc(sizeof(Date));
    switch (date_type)
    {
    case DAY:
        validate_date_format(date_str, date_expected);
        break;
    case WEEK:
        validate_week_format(date_str, date_expected);
        break;
    case MONTH:
        validate_year_month_format(date_str, date_expected);
        break;
    case YEAR:
        validate_year_format(date_str, date_expected);
        break;
    }
    // 有效的
    if (date_expected->expect == 1)
    {
        printf("date_expected->expect == 1-valid date format\n");
        date_expected->date->error.error_code = 0;
        date->error.error_code = 0;
        copy_date(date, date_expected);
        printf("date_expected->date->error.error_code: %d\n", date_expected->date->error.error_code);
        printf("date->error.error_code: %d\n", date->error.error_code);
        printf("date_expected->date->year.year: %d\n", date_expected->date->year.year);
        printf("date->year.year: %d\n", date->year.year);
        printf("date_expected->date->month.month: %d\n", date_expected->date->month.month);
        printf("date->month.month: %d\n", date->month.month);
        printf("date_expected->date->week.week: %d\n", date_expected->date->week.week);
        printf("date->week.week: %d\n", date->week.week);
        printf("date_expected->date->day.day: %d\n", date_expected->date->day.day);
        printf("date->day.day: %d\n", date->day.day);

        return *date;
    }
    // 无效的
    else
    {
        printf("date_expected->expect == 0-InValid date format\n");
        date_expected->date->error.error_code = 1;
        date->error.error_code = 1;
        printf("date_expected->date->error.error_code: %d\n", date_expected->date->error.error_code);
        printf("date->error.error_code: %d\n", date->error.error_code);
        printf("date_expected->date->year.year: %d\n", date_expected->date->year.year);
        printf("date->year.year: %d\n", date->year.year);
        printf("date_expected->date->month.month: %d\n", date_expected->date->month.month);
        printf("date->month.month: %d\n", date->month.month);
        printf("date_expected->date->week.week: %d\n", date_expected->date->week.week);
        printf("date->week.week: %d\n", date->week.week);
        printf("date_expected->date->day.day: %d\n", date_expected->date->day.day);
        printf("date->day.day: %d\n", date->day.day);
        return *date;
    }
}

int main()
{
    // 测试 YEAR 类型
    {
        char date_str[] = "2025";
        Date_Type date_type = YEAR;
        Date *date = (Date *)malloc(sizeof(Date));
        Date result = parse_date(date_type, date_str, date);
        if (result.error.error_code == 0)
        {
            printf("YEAR - Valid. Year: %d\n", result.year.year);
        }
        else
        {
            printf("YEAR - Invalid\n");
        }
    }

    // // 测试 MONTH 类型
    // {
    //     char date_str[] = "2025.08";
    //     Date_Type date_type = MONTH;
    //     Date *date = (Date *)malloc(sizeof(Date));
    //     Date result = parse_date(date_type, date_str, date);
    //     if (result.error.error_code == 0)
    //     {
    //         printf("MONTH - Valid. Year: %d, Month: %d\n", result.month.year, result.month.month);
    //     }
    //     else
    //     {
    //         printf("MONTH - Invalid\n");
    //     }
    // }

    // // 测试 WEEK 类型
    // {
    //     char date_str[] = "2025.08.3";
    //     Date_Type date_type = WEEK;
    //     Date *date = (Date *)malloc(sizeof(Date));
    //     Date result = parse_date(date_type, date_str, date);
    //     if (result.error.error_code == 0)
    //     {
    //         printf("WEEK - Valid. Year: %d, Month: %d, Week: %d\n", result.week.year, result.week.month, result.week.week);
    //     }
    //     else
    //     {
    //         printf("WEEK - Invalid\n");
    //     }
    // }

    // // 测试 DAY 类型
    // {
    //     char date_str[] = "2025.08.15";
    //     Date_Type date_type = DAY;
    //     Date *date = (Date *)malloc(sizeof(Date));
    //     Date result = parse_date(date_type, date_str, date);
    //     if (result.error.error_code == 0)
    //     {
    //         printf("DAY - Valid. Year: %d, Month: %d, Day: %d\n", result.day.year, result.day.month, result.day.day);
    //     }
    //     else
    //     {
    //         printf("DAY - Invalid\n");
    //     }
    // }

    // // 测试错误格式的情况
    // {
    //     char date_str[] = "2025-08"; // 错误的分隔符
    //     Date_Type date_type = MONTH;
    //     Date *date = (Date *)malloc(sizeof(Date));
    //     Date result = parse_date(date_type, date_str, date);
    //     if (result.error.error_code == 0)
    //     {
    //         printf("Error Case - Valid (should be invalid)\n");
    //     }
    //     else
    //     {
    //         printf("Error Case - Invalid (correct)\n");
    //     }
    // }

    return 0;
}
// gcc D:\3software\todo-listux-1\todo-listux\src\lexer\date.c  D:\3software\todo-listux-1\todo-listux\src\tools\tools.c -o  D:\3software\todo-listux-1\todo-listux\src\lexer\date