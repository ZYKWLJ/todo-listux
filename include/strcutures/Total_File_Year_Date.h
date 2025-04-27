#include "../include.h"
typedef struct Total_File_Year_Date
{
    Day_Year_Task *day_year_task;
    Month_Year_Task *month_year_task;
    Week_Year_Task *week_year_task;
    Year_Task *year_task;
} Total_File_Year_Date;

// 总的函数形式
// 在哪一年(直接传入当年的日期即可!)的哪一个类别下的那一天进行那些操作！
// void func(Date *date, Total_File_Year_Date *total_file_year_date, Date_Type *date_type, int argc, char **argv);