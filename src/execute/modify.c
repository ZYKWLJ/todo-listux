#include "../../include/include.h"
// #include "modify.h"

void modify(Date *date, Date_Type *date_type, Total_File_Year_Date *total_file_year_date, Setting *setting, int argc, char **argv)
{
    // 这里新增一个追加功能，以免重新录入麻烦
    if (argc == 4)
    {
        if (!is_all_digits(argv[2]))
        {
            printf("将展示正确的modify命令的使用\n");
        }
        // modify(date /*默认的是当前日期，不需要修改*/, date_type, total_file_year_date->day_year_task, setting, argc, argv); // 修改的条和新的内容
    }
    else if (argc == 5 && strcmp(argv[3], "-append") == 0)
    {
        // 这里还需要改！要么先查出来原来的内容，要么新增一个函数，目前倾向于前者
        // modify(date /*默认的是当前日期，不需要修改*/, date_type, total_file_year_date->day_year_task, setting, argc, argv); // 修改的条和新的内容
    }
    else
    {
        printf("错误使用，将展示正确的delete命令的使用\n");
    }
}