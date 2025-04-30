#include "../../../include/include.h"
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
// #include "load_year_file.h"
#endif

// #define LOG1

// #ifdef LOG1
void load_year_data(All_Files *all_files, char*path, Date *date)
{
    LOG_PRINT("loading %d all data files......\n",date->year);
    // 开始加载每一年的四个文件
    load_year_year_file(all_files, path, date);
    LOG_PRINT("load load_year_year_file over.....\n");
    load_month_year_file(all_files, path, date);
    LOG_PRINT("load load_month_year_file over.....\n");
    load_week_year_file(all_files, path, date);
    LOG_PRINT("load load_week_year_file over.....\n");
    load_day_year_file(all_files, path, date);
    LOG_PRINT("load load_day_year_file over.....\n");
}
//     for(int i=0;i<1000;i++)
//     printf("d");
//     return 0;
// }