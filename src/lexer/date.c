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
// 去掉字符串前导0
void remove_leading_zeros(char *str)
{
    while (*str == '0' && *(str + 1) != '\0' && isdigit(*(str + 1)))
    {
        str++;
    }
    memmove(str - (str - str), str, strlen(str) + 1);
}


// 检查日期字符串中的分隔符是否一致且无连续分隔符
// 参数:
//   date - 要检查的日期字符串
//   delimiter - 用于返回找到的分隔符
// 返回值:
//   1 - 格式正确
//   0 - 格式错误
int check_delimiter(char *date, char *delimiter) {
    char *p = date;
    *delimiter = '\0';  // 初始化分隔符
    
    // 检查空字符串
    if (*p == '\0') {
        return 0;
    }

    while (*p != '\0') {
        if (!isdigit(*p)) {
            // 找到非数字字符（可能是分隔符）
            if (*delimiter == '\0') {
                // 第一次遇到分隔符，记录下来
                *delimiter = *p;
            } else if (*p != *delimiter) {
                // 遇到与之前不同的分隔符
                return 0;
            }
            
            // 检查连续的分隔符
            if (*(p+1) != '\0' && !isdigit(*(p+1))) {
                return 0;
            }
        }
        p++;
    }
    
    // 检查是否至少找到了一个分隔符
    if (*delimiter == '\0') {
        return 0;  // 没有分隔符（纯数字）
    }
    
    return 1;
}

// 返回日期范畴并且返回具体的日期
Date parse_date(Date_Type date_type, char *date) {
    // 如果是year类型，不需要分隔符
    if (date_type == YEAR) {
        Date result;
        result.year.year = atoi(date);
        return result;
    }
    Date result;
    char delimiter;
    if (!check_delimiter(date, &delimiter)) {
        // 格式错误，年份置0
        result.year.year = -1;
        return result;
    }

    char *token;
    // 去掉前导0
    remove_leading_zeros(date);

    switch (date_type) {
    case YEAR:
        result.year.year = atoi(date);
        break;
    case MONTH:
        token = strtok(date, &delimiter);
        result.month.year = atoi(token);
        token = strtok(NULL, &delimiter);
        result.month.month = atoi(token);
        break;
    case WEEK:
        token = strtok(date, &delimiter);
        result.week.year = atoi(token);
        token = strtok(NULL, &delimiter);
        result.week.month = atoi(token);
        token = strtok(NULL, &delimiter);
        result.week.week = atoi(token);
        break;
    case DAY:
        token = strtok(date, &delimiter);
        result.day.year = atoi(token);
        token = strtok(NULL, &delimiter);
        result.day.month = atoi(token);
        token = strtok(NULL, &delimiter);
        result.day.day = atoi(token);
        break;
    default:
        // 错误的日期类型，年份置-1
        result.year.year = -1;
        break;
    }

    return result;
}

// 测试函数
// int main() {
//     // 测试 YEAR 类型
//     {
//         char date_str[] = "2025";
//         Date parsed_date = parse_date(YEAR, date_str);
//         printf("YEAR - Year: %d\n", parsed_date.year.year);
//     }

//     // 测试 MONTH 类型
//     {
//         char date_str[] = "2025-04";
//         Date parsed_date = parse_date(MONTH, date_str);
//         printf("MONTH - Year: %d, Month: %d\n", parsed_date.month.year, parsed_date.month.month);
//     }

//     // 测试 WEEK 类型
//     {
//         char date_str[] = "2025/04/10";
//         Date parsed_date = parse_date(WEEK, date_str);
//         printf("WEEK - Year: %d, Month: %d, Week: %d\n", parsed_date.week.year, parsed_date.week.month, parsed_date.week.week);
//     }

//     // 测试 DAY 类型
//     {
//         char date_str[] = "2025-04/26";
//         Date parsed_date = parse_date(DAY, date_str);
//         printf("DAY - Year: %d, Month: %d, Day: %d\n", parsed_date.day.year, parsed_date.day.month, parsed_date.day.day);
//     }

//     // 测试错误格式
//     {
//         char date_str[] = "2025--1-6";
//         Date parsed_date = parse_date(DAY, date_str);
//         printf("ERROR - Year: %d\n", parsed_date.year.year);
//     }

//     return 0;
// }