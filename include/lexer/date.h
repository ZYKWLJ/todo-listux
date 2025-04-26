// 对第三个参数的处理，第一个参数肯定是tl，第二个是command，第三个就是日期了
// 宗旨： 针对所属任务范畴也就是年目标、月目标、周目标还是天目标的具体日期(哪一年、某年的哪一月、某年某月的第某周、某年某月某日)的那一条任务<task_index>，完成相应功能
// -y|year 2025
// -m|month 2025.04
// -w|week 2025.04.01
// -d|day 2025.04.01

typedef enum Date_Type
{
    YEAR,
    MONTH,
    WEEK,
    DAY,
} Date_Type;

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

// 四者只能四选一！
typedef union Date
{
    Date_Year year;
    Date_Month month;
    Date_Week week;
    Date_Day day;  
}Date;

// 解析第3个参数,判断日期类型
Date_Type parse_date_type(char *date_type);

// 解析第4个参数,判断日期类型下的具体日期
Date parse_date(Date_Type date_type,char *date);