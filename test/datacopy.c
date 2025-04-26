#include <stdio.h>
#include <string.h>

// 定义日期相关结构体
typedef struct Date_Year
{
    int year; // 具体的年份
} Date_Year;

typedef struct Date_Month
{
    int year;  // 具体的年份
    int month; // 具体的月份
} Date_Month;

typedef struct Date_Week
{
    int year;  // 具体的年份
    int month; // 具体的月份
    int week;  // 具体的周
} Date_Week;

typedef struct Date_Day
{
    int year;  // 具体的年份
    int month; // 具体的月份
    int day;   // 具体的日
} Date_Day;

#define ERROR_FORMAT -1

typedef struct Date_Error
{
    int error_code; // 错误码
} Date_Error;

// 定义日期联合体
typedef union Date
{
    Date_Year year;
    Date_Month month;
    Date_Week week;
    Date_Day day;
    Date_Error error;
} Date;

// 定义 Date_Expected 结构体
typedef struct Date_Expected
{
    Date date;
    int expect; // 正确为 1，错误为 0
} Date_Expected;

// 深复制 Date 类型的函数示例
void copy_date(Date *destination, Date_Expected *source) {
    memcpy(destination, &(source->date), sizeof(Date));
}

int main() {
    // 初始化 Date_Expected
    Date_Expected date_expected;
    date_expected.expect = 1;
    date_expected.date.month.year = 2025;
    date_expected.date.month.month = 10;

    // 初始化目标 Date 变量
    Date date;
    date.error.error_code = ERROR_FORMAT; // 先设置一个初始错误码

    // 复制操作
    copy_date(&date, &date_expected);

    // 检查复制后的结果
    if (date.month.year == date_expected.date.month.year &&
        date.month.month == date_expected.date.month.month) {
        printf("复制成功！\n");
        printf("Year: %d, Month: %d\n", date.month.year, date.month.month);
    } else {
        printf("复制失败！\n");
    }

    return 0;
}