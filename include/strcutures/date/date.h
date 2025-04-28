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
    CURRENT_DAY,//当天的，默认显示
    ERROR_DATE_TYPE,
} Date_Type;
#define ERROR_FORMAT -1;
// 这就是完备的日期类型！
typedef struct Date
{
    int year;  // 当年
    int month; // 当月
    int week;  // 当周
    int day;   // 当天
    int error; // 是否满足格式！
    Date_Type date_type;
} Date;

void set_date(Date *date,int year,int month,int week,int day,Date_Type date_type);
void free_date(Date *date);