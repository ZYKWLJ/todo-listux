#include "../../include/include.h"
void lexer(Date *date, Date_Type *date_type, Total_File_Year_Date *total_file_year_date, Setting *setting, int argc, char **argv)
{

#ifdef LOG
    LOG_PRINT("Today is %d-%d-%d\n", year, month, day);
    LOG_PRINT("loading data......\n", year, month, day);
#endif
    // 这里的参数个数一定是大于1的了，至少两个！
    // 先加载总数据
    load_data(date, total_file_year_date);
    // 再读取设置
    read_setting(setting);

    // 再检查是否提供了日期参数
    if (argv[2] != NULL && argv[2][0] == '-')
    {
        // 解析日期类型参数，覆盖默认的。
        *date_type = parse_date_type(argv[2]); // 返回实体
        // -xxxx格式错误，直接返回了！
        if (*date_type == ERROR)
        {
            COMMAND_ERROR(setting, argc, argv);
            printf("Invalid date type argument.\n");
            return;
        }
    }
    //  最后到这里才来执行任何任务！
    all_execute(date, date_type, total_file_year_date, setting, argc, argv);
    LOG_PRINT("todo-listux end------!\n");
    // return;
}

#ifdef MAIN
int main()
{
    // 测试 YEAR 类型 - 有效
    {
        char date_str[] = "2025";
        Date *result = (Date *)malloc(sizeof(Date));
        init_date(result);
        result = parse_date(YEAR, date_str, result);
        if (result->error == 0)
        {
            printf("YEAR - Valid. Year: %d\n", result->year);
        }
        else
        {
            printf("YEAR - Invalid\n");
        }

        free(result);
    }

    // 测试 YEAR 类型 - 无效（年份过小）
    {
        char date_str[] = "2000";
        Date *result = (Date *)malloc(sizeof(Date));
        if (result->error == 0)
        {
            printf("YEAR - Valid (should be invalid)\n");
        }
        else
        {
            printf("YEAR - Invalid (correct)\n");
        }
        free(result);
    }

    // 测试 MONTH 类型 - 有效
    {
        char date_str[] = "2025.08";
        Date *result = (Date *)malloc(sizeof(Date));
        result = parse_date(MONTH, date_str, result);
        if (result->error == 0)
        {
            printf("MONTH - Valid. Year: %d, Month: %d\n",
                   result->year, result->month);
        }
        else
        {
            printf("MONTH - Invalid\n");
        }

        free(result);
    }

    // 测试 MONTH 类型 - 无效（格式错误）
    {
        char date_str[] = "2025/08";
        Date *result = (Date *)malloc(sizeof(Date));

        result = parse_date(MONTH, date_str, result);
        if (result->error == 0)
        {
            printf("MONTH - Valid (should be invalid)\n");
        }
        else
        {
            printf("MONTH - Invalid (correct)\n");
        }

        free(result);
    }

    // 测试 WEEK 类型 - 有效
    {
        char date_str[] = "2025.08.3";
        Date *result = (Date *)malloc(sizeof(Date));

        result = parse_date(WEEK, date_str, result);
        if (result->error == 0)
        {
            printf("WEEK - Valid. Year: %d, Month: %d, Week: %d\n",
                   result->year, result->month, result->week);
        }
        else
        {
            printf("WEEK - Invalid\n");
        }

        free(result);
    }

    // 测试 WEEK 类型 - 无效（周数过大）
    {
        char date_str[] = "2025.08.5";
        Date *result = (Date *)malloc(sizeof(Date));

        result = parse_date(WEEK, date_str, result);
        if (result->error == 0)
        {
            printf("WEEK - Valid (should be invalid)\n");
        }
        else
        {
            printf("WEEK - Invalid (correct)\n");
        }

        free(result);
    }

    // 测试 DAY 类型 - 有效
    {
        char date_str[] = "2025.08.15";
        Date *result = (Date *)malloc(sizeof(Date));
        result = parse_date(DAY, date_str, result);
        if (result->error == 0)
        {
            printf("DAY - Valid. Year: %d, Month: %d, Day: %d\n",
                   result->year, result->month, result->day);
        }
        else
        {
            printf("DAY - Invalid\n");
        }

        free(result);
    }

    // 测试 DAY 类型 - 无效（日期不存在）
    {
        char date_str[] = "2025.02.30";
        Date *result = (Date *)malloc(sizeof(Date));

        result = parse_date(DAY, date_str, result);
        if (result->error == 0)
        {
            printf("DAY - Valid (should be invalid)\n");
        }
        else
        {
            printf("DAY - Invalid (correct)\n");
        }
        free(result);
    }

    return 0;
}
#endif
// gcc D:\3software\todo-listux-1\todo-listux\src\lexer\date.c  D:\3software\todo-listux-1\todo-listux\src\tools\tools.c -o  D:\3software\todo-listux-1\todo-listux\src\lexer\date