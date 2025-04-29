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

#define LOG1
#ifdef LOG1
// 将所有的内容通过指针传入即可，一般返回值均为void
void load_all_files(All_Files *all_files, ALL_Files_Paths *all_files_paths, Date *date)
{
    // 1.先加载配置文件(这个是main一开始就要加载的)
    LOG_PRINT("loading setting data......\n");
    load_config(all_files->setting,all_files_paths->setting_file_path);
    LOG_PRINT("loading %s total data......\n", date->year);
    // 这个是加载指定的年的所有文件(所以不同的年份，需要加载不同的文件，也就是说，执行命令时，需要判断是不是当年，不是就加载，是的话，就不变！因为本身就是按年为单位的，所以此而为之！)
    load_year_data(all_files, date->year); // 加载这一年的所有文件到内存中！
    LOG_PRINT("loading %s total data over......\n", date->year);
    // LOG_PRINT("loading total data over......\n");
}

#endif

// int main(){
//     for(int i=0;i<1000;i++)
//     printf("d");
//     return 0;
// }