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
#endif
// typedef struct All_Files
// {
//     Total_File_Year_Date *total_file_year_date; // 数据文件
//     Setting *setting;                           // 配置文件
// } All_Files;

#define LOG1
#ifdef LOG1
// 将所有的内容通过指针传入即可，一般返回值均为void
// 这个传递进来的只是一个目录，里面的四个文件需要全部再次加入到内存只能中！
void load_all_files(All_Files *all_files, char *all_files_paths, Date *date)
{
    LOG_PRINT("loading %d date_files_paths data......\n", date->year);
    // 这个是加载指定的年的所有文件(所以不同的年份，需要加载不同的文件，也就是说，执行命令时，需要判断是不是当年，不是就加载，是的话，就不变！因为本身就是按年为单位的，所以此而为之！)
    load_year_data(all_files, all_files_paths, date); // 加载这一年的所有文件到内存中！
    LOG_PRINT("loading %d date_files_paths data over......\n", date->year);
}
#endif

// int main(){
//     for(int i=0;i<1000;i++)
//     printf("d");
//     return 0;
// }
