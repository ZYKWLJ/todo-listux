#include "../../include/include.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#include <direct.h> // 用于 _wmkdir
#else
#include <unistd.h>
#endif

// #define LOG
#ifdef LOG1
//将所有的内容通过指针传入即可，一般返回值均为void
void load_data(Date *date, Total_File_Year_Date *total_file_year_date)
{
    LOG_PRINT("loading total data......\n");
    load_year_data(date->year,total_file_year_date->year_task);
    load_month_year_data(date->year,total_file_year_date->month_year_task);
    load_week_year_data(date->year,total_file_year_date->week_year_task);
    load_day_year_data(date->year,total_file_year_date->day_year_task);
    LOG_PRINT("loading total data over......\n");
}

#endif

// int main(){
//     for(int i=0;i<1000;i++)
//     printf("d");
//     return 0;
// }