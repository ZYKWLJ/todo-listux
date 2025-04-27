#include "../../include/include.h"
#define LOG
void all_execute(Date *date /*指定的日期，不指定默认为当前的日期*/, Date_Type *date_type, Total_File_Year_Date *total_file_year_date, Setting *setting, int argc, char **argv)
{
    printf("todo-listux execute start------!\n");

    // 格式正确，指定日期的话，解析日期
    if (*date_type != CURRENT_DAY)
    {
        // 个数判断，指定日期了，参数至少是4个！
        if (argc < 4)
        {
            COMMAND_ERROR(setting, argc, argv);
            printf("No args\n");
            exit(EXIT_FAILURE);
        }
        printf("all_execute: date_type!=CURRENT_DAY\n");
        // 这里开始读取第4个参数，也就是日期
        parse_date(*date_type, argv[3], date); // 所有的内容都通过指针传递！
    }
    // 参数小于2的判断都在main中的
    // 具体的判断还是在单独的函数中进行判断
    // 不断是指没指定日期，命令都是第二个参数，所以这里的函数命令统一为argv[1]！
    if (strcmp(argv[1], "show") == 0 || strcmp(argv[1], "s") == 0)
    {

        display(date /*默认的是当前日期，不需要修改*/, date_type, total_file_year_date, setting, argc, argv); // 默认显示当前日期(还是统一吧)
    }
    else if (strcmp(argv[1], "add") == 0 || strcmp(argv[1], "a") == 0)
    {

        add(date /*默认的是当前日期，不需要修改*/, date_type, total_file_year_date, setting, argc, argv);
    }
    else if (strcmp(argv[1], "delete") == 0 || strcmp(argv[1], "d") == 0)
    {

        delete_(date /*默认的是当前日期，不需要修改*/, date_type, total_file_year_date, setting, argc, argv);
    }
    else if (strcmp(argv[1], "modify") == 0 || strcmp(argv[1], "m") == 0)
    {
        modify(date /*默认的是当前日期，不需要修改*/, date_type, total_file_year_date, setting, argc, argv); // 修改的条和新的内容
    }
    else if (strcmp(argv[1], "done") == 0)
    {

        // 至于all还是具体下标，就放在里面判断
        done(date /*默认的是当前日期，不需要修改*/, date_type, total_file_year_date, setting, argc, argv);
    }
    else if (strcmp(argv[1], "undo") == 0) // 撤销完成标记
    {

        undo(date /*默认的是当前日期，不需要修改*/, date_type, total_file_year_date, setting, argc, argv);
    }
    else if (strcmp(argv[1], "set") == 0) // 进入设置
    {
        // 所有的进入在详细判断！
        set_setting(argc, argv);
    }
    else
    {
        COMMAND_ERROR(setting, argc, argv); // 专用的错误处理
    }
}
#ifdef draft
tl add - w 2025.04.1 content tl add content tl delete 1 tl modify 1 content tl modify 1 - append content tl done 1 tl undo 1 tl show - w 2025.04.1
#endif
