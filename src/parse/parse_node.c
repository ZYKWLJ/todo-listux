#include "../../include/include.h"
extern KV_ kv;
extern S_setting setting;
int is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void validate_day_format(C_command command, char *date_str, T_date date)
{
    // 基础格式检查
    // if (!basic_check(date_str, 10, 10))
    if (strlen(date_str) != 10)
    {
        LOG_PRINT("exit!!!\n");
        COMMAND_ERROR(command, " --Error day date_type,it should be 10 characters like 2025.04.05, means the fifth day of April, 2025.But here is %s\n", date_str);
        exit(EXIT_FAILURE);
        return;
    }

    // 检查字符组成(和分隔符)
    for (int i = 0; i < 10; i++)
    {
        if ((i == 4 || i == 7) ? (date_str[i] != '.') : (!isdigit(date_str[i])))
        {
            LOG_PRINT("exit!!!\n");
            COMMAND_ERROR(command, " --Error day date_type,it should be 10 characters like 2025.04.05, means the fifth day of April, 2025.But here is %s\n", date_str);
            exit(EXIT_FAILURE);
            return;
        }
    }
    // 提取数值
    int day = (date_str[8] - '0') * 10 + (date_str[9] - '0');
    int month = (date_str[5] - '0') * 10 + (date_str[6] - '0');
    int year = (date_str[0] - '0') * 1000 + (date_str[1] - '0') * 100 +
               (date_str[2] - '0') * 10 + (date_str[3] - '0');

    char current_day[11] = {0};
    sprintf(current_day, "%04d.%02d.%02d",
            date->T_current_date->year, date->T_current_date->month, date->T_current_date->day);

    // 检查日期不小于今天
    if (year < date->T_current_date->year)
    {
        LOG_PRINT("exit!!!\n");
        COMMAND_ERROR(command, " --Error day date_type,it should be not less than today(%s),but here is %s\n", current_day, date_str);
        exit(EXIT_FAILURE);
        return;
    }
    else if (year == date->T_current_date->year)
    {
        if (month < date->T_current_date->month)
        {
            LOG_PRINT("exit!!!\n");
            COMMAND_ERROR(command, " --Error day date_type,it should be not less than today(%s),but here is %s\n", current_day, date_str);
            exit(EXIT_FAILURE);
            return;
        }
        else if (month == date->T_current_date->month)
        {
            if (day < date->T_current_date->day)
            {
                LOG_PRINT("exit!!!\n");
                COMMAND_ERROR(command, " --Error day date_type,it should be not less than today(%s),but here is %s\n", current_day, date_str);
                exit(EXIT_FAILURE);
            }
        }
    }

    // 月份检查
    if (month < 1 || month > 12)
    {
        LOG_PRINT("exit!!!\n");
        COMMAND_ERROR(command, " --month should between 1 and 12,but here is %s\n", date_str);
        exit(EXIT_FAILURE);
    }

    // 日期检查
    int max_day;
    switch (month)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        max_day = 30;
        break;
    case 2:
        max_day = is_leap_year(year) ? 29 : 28;
        break;
    default:
        max_day = 31;
    }

    if (day < 1 || day > max_day)
    {
        LOG_PRINT("exit!!!\n");
        COMMAND_ERROR(command, " --month should between 1 and %d,but here is %s\n", date_str, max_day);
        exit(EXIT_FAILURE);
    }
    /**
     * data descp: 到这里就将格式解析出来了！
     */
    // date->T_specific_date = (T_current_date)checked_malloc(sizeof(*date->T_specific_date));
    date->T_specific_date->date_type = D;
    date->T_specific_date->day = day;
    date->T_specific_date->month = month;
    date->T_specific_date->year = year;
    LOG_PRINT("validate_date_format success!!!\n");
}

// 重构validate_week_format函数
void validate_week_format(C_command command, char *date_str, T_date date)
{
    // 基础格式检查
    if (strlen(date_str) != 10)
    {

        LOG_PRINT("exit!!!\n");
        COMMAND_ERROR(command, " --Error week date_type,it should be 10 characters like 2025.04.04, means the fourth week of April, 2025. But here is %s\n", date_str);
        // help_show();
        exit(EXIT_FAILURE);
        return;
    }

    // 检查字符组成(和分隔符)
    for (int i = 0; i < 10; i++)
    {
        if ((i == 4 || i == 7) ? (date_str[i] != '.') : (!isdigit(date_str[i])))
        {
            COMMAND_ERROR(command, " --Error week date_type,it should be 10 characters like 2025.04.04, means the fourth week of April, 2025.But here is %s\n", date_str);
            // help_show();
            LOG_PRINT("exit!!!\n");
            exit(EXIT_FAILURE);
            return;
        }
    }

    // 提取数值
    int week = (date_str[8] - '0') * 10 + (date_str[9] - '0');
    int month = (date_str[5] - '0') * 10 + (date_str[6] - '0');
    int year = (date_str[0] - '0') * 1000 + (date_str[1] - '0') * 100 +
               (date_str[2] - '0') * 10 + (date_str[3] - '0');

    char current_week[11] = {0};
    sprintf(current_week, "%04d.%02d.%02d",
            date->T_current_date->year, date->T_current_date->month, date->T_current_date->week);

    // 检查日期不小于今天
    if (year < date->T_current_date->year)
    {
        LOG_PRINT("exit!!!\n");
        COMMAND_ERROR(command, " --Error day date_type,it should be not less than current week(%s),but here is %s\n", current_week, date_str);
        exit(EXIT_FAILURE);
        return;
    }
    else if (year == date->T_current_date->year)
    {
        if (month < date->T_current_date->month)
        {
            LOG_PRINT("exit!!!\n");
            COMMAND_ERROR(command, " --Error day date_type,it should be not less than current week(%s),but here is %s\n", current_week, date_str);
            exit(EXIT_FAILURE);
            return;
        }
        else if (month == date->T_current_date->month)
        {
            if (week < date->T_current_date->week)
            {
                LOG_PRINT("exit!!!\n");
                COMMAND_ERROR(command, " --Error day date_type,it should be not less than current week(%s),but here is %s\n", current_week, date_str);
                exit(EXIT_FAILURE);
            }
        }
    }

    /**
     * data descp: 到这里就将格式解析出来了！
     */

    // date->T_specific_date = (T_current_date)checked_malloc(sizeof(*date->T_specific_date));
    date->T_specific_date->date_type = W;

    date->T_specific_date->week = week;
    date->T_specific_date->month = month;
    date->T_specific_date->year = year;
    LOG_PRINT("week parser passed!!!\n");
}

void validate_month_format(C_command command, char *date_str, T_date date)
{
    // 基础检查
    if (strlen(date_str) != 7)
    {
        COMMAND_ERROR(command, " --Error month date_type,it should be 7 characters like 2025.04, means the fourth month of 2025.But here is %s\n", date_str);
        exit(EXIT_FAILURE);
    }

    // 检查字符组成(和分隔符)
    for (int i = 0; i < 7; i++)
    {
        if ((i == 4) ? (date_str[i] != '.') : (!isdigit(date_str[i])))
        {
            COMMAND_ERROR(command, " --Error month date_type,it should be 7 characters like 2025.04, means the fourth month of 2025.But here is %s\n", date_str);
            exit(EXIT_FAILURE);
        }
    }

    // 提取数值
    int month = (date_str[5] - '0') * 10 + (date_str[6] - '0');
    int year = (date_str[0] - '0') * 1000 + (date_str[1] - '0') * 100 +
               (date_str[2] - '0') * 10 + (date_str[3] - '0');

    char current_month[8] = {0};
    sprintf(current_month, "%04d.%02d",
            date->T_current_date->year, date->T_current_date->month);

    if (year < date->T_current_date->year || (year == date->T_current_date->year && month < date->T_current_date->month))
    {
        COMMAND_ERROR(command, " --Error month date_type,it should be not less than current month(%s),but here is %s", date_str, current_month);
        exit(EXIT_FAILURE);
        return;
    }
    // 月份检查
    if (month < 1 || month > 12)
    {
        LOG_PRINT("exit!!!\n");
        COMMAND_ERROR(command, " --month should between 1 and 12,but here is %s\n", date_str);
        exit(EXIT_FAILURE);
    }
    // date->T_specific_date = (T_current_date)checked_malloc(sizeof(*date->T_specific_date));
    date->T_specific_date->date_type = M;

    date->T_specific_date->year = year;
    date->T_specific_date->month = month;
    // LOG_PRINT("month parser passed!!!\n");
}

int is_all_digits(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0; // 包含非数字字符
        }
    }
    return 1; // 所有字符都是数字
}
void validate_year_format(C_command command, char *date_str, T_date date)
{
    // 基础检查
    if (strlen(date_str) != 4)
    {
        COMMAND_ERROR(command, " --Error year date_type,it should be 4 characters like 2025, means the year of 2025.But here is %s\n", date_str);
        exit(EXIT_FAILURE);
    }

    if (!(is_all_digits(date_str)))
    {
        COMMAND_ERROR(command, " --Error year date_type,it should be 4 characters like 2025, means the year of 2025.But here is %s\n", date_str);
        exit(EXIT_FAILURE);
    }

    // 提取数值
    int year = (date_str[0] - '0') * 1000 + (date_str[1] - '0') * 100 +
               (date_str[2] - '0') * 10 + (date_str[3] - '0');

    char current_year[5] = {0};
    sprintf(current_year, "%04d",
            date->T_current_date->year);

    if (year < date->T_current_date->year)
    {

        LOG_PRINT("exit!!!\n");
        COMMAND_ERROR(command, " --Error year date_type,it should be not less than current month(%s),but here is %s", current_year, date_str);
        exit(EXIT_FAILURE);
    }

    // date->T_specific_date = (T_current_date)checked_malloc(sizeof(*date->T_specific_date));
    date->T_specific_date->date_type = Y;
    date->T_specific_date->year = year;
    // LOG_PRINT("year parser passed!!!\n");
}

void only_parse_date(C_command command, char *date_type, T_date date)
{
    if (strcmp(date_type, "-day") == 0 || strcmp(date_type, "-d") == 0)
    {
        date->T_specific_date->date_type = D;
        return;
    }
    else if (strcmp(date_type, "-week") == 0 || strcmp(date_type, "-w") == 0)
    {
        date->T_specific_date->date_type = W;
        return;
    }
    else if (strcmp(date_type, "-month") == 0 || strcmp(date_type, "-m") == 0)
    {
        date->T_specific_date->date_type = M;
        return;
    }
    else if (strcmp(date_type, "-year") == 0 || strcmp(date_type, "-y") == 0)
    {
        date->T_specific_date->date_type = Y;
        return;
    }
    else
    {
        COMMAND_ERROR(command, " --Error date_type,it should be -d/day,-w/week,-m/month,-y/year,but here is %s\n", date_type);
        help_help_tips();
        exit(EXIT_FAILURE);
    }
}

void parse_date(C_command command, char *date_type, char *specific_date_str, T_date date)
{
    if (strcmp(date_type, "-day") == 0 || strcmp(date_type, "-d") == 0)
    {
        validate_day_format(command, specific_date_str, date);
        return;
    }
    else if (strcmp(date_type, "-week") == 0 || strcmp(date_type, "-w") == 0)
    {
        validate_week_format(command, specific_date_str, date);
        return;
    }
    else if (strcmp(date_type, "-month") == 0 || strcmp(date_type, "-m") == 0)
    {
        validate_month_format(command, specific_date_str, date);
        return;
    }
    else if (strcmp(date_type, "-year") == 0 || strcmp(date_type, "-y") == 0)
    {
        validate_year_format(command, specific_date_str, date);
        return;
    }
    else
    {
        COMMAND_ERROR(command, " --Error date_type,it should be -d/day,-w/week,-m/month,-y/year,but here is %s\n", date_type);
        help_help_tips();

        exit(EXIT_FAILURE);
    }
}
void parse_show_node(N_node node, C_command command, T_date date)
{
    /**
     * data descp: 这时就先数量，后质量了
     */
    if (command->argc == 2)
    {
        /**
         * data descp: 一定是tl ^,show all
         */
        TODO_PRINT("show all\n");
        // 日期默认当前，不必在做
        return; // 提前返回了
    }
/**
 * data descp: 应该新增三参数的指定当前周的任务的功能，比如tl ^ -w 就是直接显示当前周的计划，否则很麻烦
 */
#if 1
    else if (command->argc == 3)
    {
        only_parse_date(command, command->argv[2], date);
    }

#endif
    else if (command->argc == 4)
    {
        /**
         * data descp: 指定日期的显示，判断日期是否格式正确，是够合法(是不是今后的日期)
         */
        TODO_PRINT("show Specific date\tparser......\n");
        parse_date(command, command->argv[2], command->argv[3], date);
        LOG_PRINT("show Specific date\tparser passed!!!\n");
        return;
    }
    else
    {
        /**
         * data descp: 直接报错，提示参数错误，演示正确的参数格式
         * 1.直接show
         * 2.show ^ -date_type date
         */
        COMMAND_ERROR(command, " --The number of parameters does not match. \nthe correct format of the \"show(\\)\" command are as follows:");
        help_show_tips();
        exit(EXIT_FAILURE);
    }
}

void parse_add_node(N_node node, C_command command, T_date date)
{
    /**
     * data descp: 还是先数量，后质量
     */
    if (command->argc == 3)
    {
        /**
         * data descp: 新增当天的任务
         */
        TODO_PRINT("add today\n");
        /**
         * data descp: 交过后面的exec环节去解析，日期等等都已经指定了
         */
        sprintf(node->task->content, "%s", command->argv[2]);
        strcpy(node->task->content, command->argv[2]);
        return;
    }
    /**
     * data descp: 增加4各参数的指定当前日期的功能，如tl + xxxx -w指的是在当前周添加任务
     */
    else if (command->argc == 4)
    {
        only_parse_date(command, command->argv[3], date);
        strcpy(node->task->content, command->argv[2]);
    }
    else if (command->argc == 5)
    {
        /**
         * data descp: 新增指定日期的任务 tl + content -date_type date
         */
        TODO_PRINT("add Specific date\n");
        parse_date(command, command->argv[3], command->argv[4], date);
        sprintf(node->task->content, "%s", command->argv[2]);
        LOG_PRINT("show Specific date\tparser passed!!!\n");
        return;
    }
    else
    {
        /**
         * data descp: 参数数量不匹配
         */
        COMMAND_ERROR(command, " --The number of parameters does not match. \nthe correct format of the \"add(+)\" command are as follows:");
        help_add_tips();
        exit(EXIT_FAILURE);
    }
}

void parse_delete_node(N_node node, C_command command, T_date date)
{
    LOG_PRINT("parse_delete_node");
    /**
     * data descp: 还是先数量，后质量 tl / 1
     */
    if (command->argc == 3)
    {

        /**
         * data descp: 新增当天的任务
         */
        TODO_PRINT("add today\n");
        /**
         * data descp: 只判断是不是数字，其余给后面的exec环节去解析，日期等等都已经指定了
         */
        if (!is_all_digits(command->argv[2]))
        {
            COMMAND_ERROR(command, " --The TID should be a number, but here is %s\nthe correct format of the \"delete(/)\" command are as follows:", command->argv[2]);
            help_delete_tips();
            exit(EXIT_FAILURE);
        }
        node->task->id = atoi(command->argv[2]);
        LOG_PRINT("node_task_id=%d", node->task->id);
        return;
    }
    /**
     * data descp: 新增4个参数的指定当前日期的功能，如tl / 1 -w指的是删除当前周的某个任务
     */
    else if (command->argc == 4)
    {
        /**
         * data descp: 先判断日期类型是不是合法
         */
        only_parse_date(command, command->argv[3], date);
        /**
         * data descp: 再判断是不是id数字
         */
        if (!is_all_digits(command->argv[2]))
        {
            COMMAND_ERROR(command, " --The TID should be a number, but here is %s\nthe correct format of the \"delete(/)\" command are as follows:", command->argv[2]);
            help_delete_tips();
        }
        node->task->id = atoi(command->argv[2]);
        LOG_PRINT("node_task_id=%d", node->task->id);
    }
    /**
     * data descp: 新增指定日期的任务 tl / 1 -date_type date
     */
    else if (command->argc == 5)
    {

        TODO_PRINT("add Specific date\n");
        parse_date(command, command->argv[3], command->argv[4], date);
        if (!is_all_digits(command->argv[2]))
        {
            COMMAND_ERROR(command, " --The TID should be a number, but here is %s\nthe correct format of the \"delete(/)\" command are as follows:", command->argv[2]);
            help_delete_tips();
            exit(EXIT_FAILURE);
        }
        node->task->id = atoi(command->argv[2]);
        LOG_PRINT("show Specific date\tparser passed!!!\n");
        return;
    }
    else
    {
        /**
         * data descp: 参数数量不匹配
         */
        COMMAND_ERROR(command, " --The number of parameters does not match. \nthe correct format of the \"delete(/)\" command are as follows:");
        help_delete_tips();
        exit(EXIT_FAILURE);
    }
}

void parse_done_node(N_node node, C_command command, T_date date)
{
    /**
     * data descp: 还是先数量，后质量 tl - 1
     */
    if (command->argc == 3)
    {
        /**
         * data descp: 新增当天的任务
         */
        TODO_PRINT("add today\n");
        /**
         * data descp: 只判断是不是数字，其余给后面的exec环节去解析，日期等等都已经指定了
         */
        if (!is_all_digits(command->argv[2]))
        {
            COMMAND_ERROR(command, " --The TID should be a number, but here is %s\nthe correct format of the \"done(-)\" command are as follows:", command->argv[2]);
            help_done_tips();
            exit(EXIT_FAILURE);
        }
        node->task->id = atoi(command->argv[2]);
        return;
    }
    /**
     * data descp: 新增4个参数的指定当前日期的功能，如tl - 1 -w指的是在当前周完成任务
     */
    else if (command->argc == 4)
    {
        /**
         * data descp: 先判断日期类型是不是合法
         */
        only_parse_date(command, command->argv[3], date);
        /**
         * data descp: 再判断是不是id数字
         */
        if (!is_all_digits(command->argv[2]))
        {
            COMMAND_ERROR(command, " --The TID should be a number, but here is %s\nthe correct format of the \"delete(/)\" command are as follows:", command->argv[2]);
            help_done_tips();
        }
        node->task->id = atoi(command->argv[2]);
    }
    /**
     * data descp: 新增指定日期的任务 tl - 1 -date_type date
     */
    else if (command->argc == 5)
    {

        TODO_PRINT("add Specific date\n");
        parse_date(command, command->argv[3], command->argv[4], date);
        if (!is_all_digits(command->argv[2]))
        {
            COMMAND_ERROR(command, " --The TID should be a number, but here is %s\nthe correct format of the \"done(-)\" command are as follows:", command->argv[2]);
            help_done_tips();
            exit(EXIT_FAILURE);
        }
        node->task->id = atoi(command->argv[2]);
        LOG_PRINT("show Specific date\tparser passed!!!\n");
        return;
    }
    else
    {
        /**
         * data descp: 参数数量不匹配
         */
        COMMAND_ERROR(command, " --The number of parameters does not match. \nthe correct format of the \"done(-)\" command are as follows:");
        help_done_tips();
        exit(EXIT_FAILURE);
    }
}

void parse_toggle_node(N_node node, C_command command, T_date date)
{
    /**
     * data descp: 还是先数量，后质量 tl - 1
     */
    if (command->argc == 3)
    {
        /**
         * data descp: 新增当天的任务
         */
        TODO_PRINT("add today\n");
        /**
         * data descp: 只判断是不是数字，其余给后面的exec环节去解析，日期等等都已经指定了
         */
        if (!is_all_digits(command->argv[2]))
        {
            COMMAND_ERROR(command, " --The TID should be a number, but here is %s, the correct format of the \"toggle(!)\" command are as follows:\n", command->argv[2]);
            help_toggle_tips();

            exit(EXIT_FAILURE);
        }
        node->task->id = atoi(command->argv[2]);
        return;
    }
    /**
     * data descp: 新增4个参数的指定当前日期的功能，如tl ! 1 -w指的是翻转当前周的某个任务
     */
    else if (command->argc == 4)
    {
        /**
         * data descp: 先判断日期类型是不是合法
         */
        only_parse_date(command, command->argv[3], date);
        /**
         * data descp: 再判断是不是id数字
         */
        if (!is_all_digits(command->argv[2]))
        {
            COMMAND_ERROR(command, " --The TID should be a number, but here is %s\nthe correct format of the \"toggle(!)\" command are as follows:", command->argv[2]);
            help_toggle_tips();
        }
        node->task->id = atoi(command->argv[2]);
    }
    /**
     * data descp: 新增指定日期的任务 tl ! 1 -date_type date
     */
    else if (command->argc == 5)
    {

        TODO_PRINT("add Specific date\n");
        parse_date(command, command->argv[3], command->argv[4], date);
        if (!is_all_digits(command->argv[2]))
        {
            COMMAND_ERROR(command, " --The TID should be a number, but here is %s\nthe correct format of the \"toggle(!)\" command are as follows:", command->argv[2]);
            help_toggle_tips();

            exit(EXIT_FAILURE);
        }
        node->task->id = atoi(command->argv[2]);
        LOG_PRINT("show Specific date\tparser passed!!!\n");
        return;
    }
    else
    {
        /**
         * data descp: 参数数量不匹配
         */
        COMMAND_ERROR(command, " --The number of parameters does not match.\nthe correct format of the \"toggle(!)\" command are as follows:");
        help_toggle_tips();
        exit(EXIT_FAILURE);
    }
}

void edit_type_tips(N_node node, C_command command, T_date date)
{
    switch (node->node_type)
    {
    case EDIT_ALL:
    {
        help_edit_all();
        return;
    }
    case EDIT_PREFIX:
    {
        help_edit_prefix();
        return;
    }
    case EDIT_SUFFIX:
    {
        help_edit_suffix();
        return;
    }
    }
}
void parse_edit_node(N_node node, C_command command, T_date date)
{
    /**
     * data descp: 还是先数量，后质量 tl = 1 content
     */
    if (command->argc == 4)
    {
        /**
         * data descp: 新增当天的任务
         */
        TODO_PRINT("[%%]edit[%%] today\n");
        /**
         * data descp: 只判断是不是数字，其余给后面的exec环节去解析，日期等等都已经指定了
         */
        if (!is_all_digits(command->argv[2]))
        {
            COMMAND_ERROR(command, " --The TID should be a number, but here is %s\nthe correct format of the \"edit(=)\" command are as follows:\n", command->argv[2]);
            edit_type_tips(node,command,date);

            exit(EXIT_FAILURE);
        }
        node->task->id = atoi(command->argv[2]);
        sprintf(node->task->content, "%s", command->argv[3]);
        return;
    }
    /**
     * data descp: 新增4个参数的指定当前日期的功能，如tl = 1 -w指的是编辑当前周的某个任务
     */
    else if (command->argc == 4)
    {
        /**
         * data descp: 先判断日期类型是不是合法
         */
        only_parse_date(command, command->argv[3], date);
        /**
         * data descp: 再判断是不是id数字
         */
        if (!is_all_digits(command->argv[2]))
        {
            COMMAND_ERROR(command, " --The TID should be a number, but here is %s\nthe correct format of the \"edit(=)\" command are as follows:", command->argv[2]);
            edit_type_tips(node,command,date);
        }
        node->task->id = atoi(command->argv[2]);
        sprintf(node->task->content, "%s", command->argv[3]);
        return;
    }
    /**
     * data descp: 新增指定日期的任务 tl = id content -date_type
     */
    else if (command->argc == 5)
    {

        TODO_PRINT("add Specific date\n");
        /**
         * data descp: 先判断日期类型是不是合法
         */
        only_parse_date(command, command->argv[4], date);
        /**
         * data descp: 再判断是不是id数字
         */
        if (!is_all_digits(command->argv[2]))
        {
            COMMAND_ERROR(command, " --The TID should be a number, but here is %s\nthe correct format of the \"edit(=)\" command are as follows:", command->argv[2]);
            edit_type_tips(node,command,date);
        }
        node->task->id = atoi(command->argv[2]);
        sprintf(node->task->content, "%s", command->argv[3]);
        LOG_PRINT("show Specific date\tparser passed!!!\n");
        return;
    }
    /**
     * data descp: 新增指定日期的任务 tl = id content -date_type date
     */
    else if (command->argc == 6)
    {

        TODO_PRINT("add Specific date\n");
        parse_date(command, command->argv[4], command->argv[5], date);
        if (!is_all_digits(command->argv[2]))
        {
            COMMAND_ERROR(command, " --The TID should be a number, but here is %s\nthe correct format of the \"edit(=)\" command are as follows:\n", command->argv[2]);
            edit_type_tips(node,command,date);
            exit(EXIT_FAILURE);
        }
        node->task->id = atoi(command->argv[2]);
        /**
         * data descp: 这里在根据后面的类型进行判断是否是前缀还是后缀或者全部
         */
        sprintf(node->task->content, "%s", command->argv[3]);
        LOG_PRINT("show Specific date\tparser passed!!!\n");
        return;
    }
    else
    {
        /**
         * data descp: 参数数量不匹配
         */
        COMMAND_ERROR(command, " --The number of parameters does not match.\nthe correct format of the \"edit(=)\" command are as follows:");
        // help_edit();
        edit_type_tips(node,command,date);
        exit(EXIT_FAILURE);
    }
}
void parse_set_node(N_node node, C_command command, T_date date)
{
    /**
     * data descp: 还是先数量，后质量 tl $ color=red
     */
    if (command->argc == 3)
    {

#define EQUAL_TOKEN '='
        // 1. 检查输入格式
        if (!command->argv[2] || !strchr(command->argv[2], EQUAL_TOKEN))
        {
            LOG_PRINT("Invalid format: use 'tl $ key=value'\n");
            COMMAND_ERROR(command, " --Invalid format.\n");
            help_set_tips();

            exit(EXIT_FAILURE);
        }

        // 2. 安全分割 key=value（不使用strndup）
        char *equal_pos = strchr(command->argv[2], EQUAL_TOKEN);
        if (!equal_pos)
        {
            LOG_PRINT("No '=' found in argument\n");
            COMMAND_ERROR(command, " --Parameters does not match.\n");
            help_set_tips();
            exit(EXIT_FAILURE);
            return;
        }

        size_t key_len = equal_pos - command->argv[2];
        strncpy(kv->key, command->argv[2], key_len);
        kv->key[key_len] = '\0';

        char *v = strdup(equal_pos + 1);
        strncpy(kv->value, v, strlen(v));
        kv->value[strlen(v)] = '\0';
        free(v);
        // 4. 不能释放内存，因为后面还要使用
        LOG_PRINT("key: %s, value: %s\n", kv->key, kv->value);

        switch (set_settings(setting, kv))
        {
        case 0:
            COMMAND_ERROR(command, " --Invalid key .It should be color/time/border, but here is %s\n", kv->key);
            help_set_tips();
            exit(EXIT_FAILURE);
        case 2:
            COMMAND_ERROR(command, " --Invalid value %s\n", kv->value);
            help_set_tips();
            exit(EXIT_FAILURE);
        }
        return;
    }
    else
    {
        /**
         * data descp: 参数数量不匹配
         */
        COMMAND_ERROR(command, " --The number of parameters does not match. \n");
        help_set_tips();
        exit(EXIT_FAILURE);
    }
}

void parse_help_node(N_node node, C_command command, T_date date)
{
    LOG_PRINT("parse_help_node......");
    switch (command->argc)
    {
    case 2:
        help_help();
        return;
    case 3:

        if (strcmp(command->argv[2], HELP_TOKEN) == 0)
        {
            help_help();
        }
        else if (strcmp(command->argv[2], CONFIGURATION_TOKEN) == 0)
        {
            // help_config();
            TODO_PRINT("help_set()");
            // printf("help_set\n");
            help_set();
            exit(0);
        }
        else if (strcmp(command->argv[2], DISPLAY_TOKEN) == 0)
        {
            help_show();
            exit(0);
        }
        else if (strcmp(command->argv[2], ADD_TOKEN) == 0)
        {
            TODO_PRINT("help_add()");
            help_add();
            exit(0);
        }
        else if (strcmp(command->argv[2], COMPLETE_TOKEN) == 0)
        {
            TODO_PRINT("help_done()");
            help_done();
            exit(0);
        }
        else if (strcmp(command->argv[2], DELETE_TOKEN) == 0)
        {
            TODO_PRINT("help_delete()");
            help_delete();
            exit(0);
        }
        else if (strcmp(command->argv[2], TOGGLE_TOKEN) == 0)
        {
            TODO_PRINT("help_toggle()");
            help_toggle();
            exit(0);
        }
        else if (strcmp(command->argv[2], EDIT_ALL_TOKEN) == 0)
        {
            TODO_PRINT("edit_set()");
            help_edit_all();
            exit(0);
        }
        else if (strcmp(command->argv[2], EDIT_PREFIX_TOKEN) == 0)
        {
            TODO_PRINT("edit_prefix_set()");
            help_edit_prefix();
            exit(0);
        }
        else if (strcmp(command->argv[2], EDIT_SUFFIX_TOKEN) == 0)
        {
            TODO_PRINT("edit_suffix_set()");
            help_edit_suffix();
            exit(0);
        }
        else
        {

            COMMAND_ERROR(command, " --unkown command type of %s\nThe valid command type is as follows:", command->argv[2]);
            // printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "?", "$", "\\", "+", "-", "/", "!", "=", "=%", "%=");
            GREEN_PRINT("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n\n",
                        HELP_TOKEN, CONFIGURATION_TOKEN, DISPLAY_TOKEN, ADD_TOKEN, COMPLETE_TOKEN, DELETE_TOKEN, TOGGLE_TOKEN, EQUAL, EDIT_PREFIX_TOKEN, EDIT_SUFFIX_TOKEN);

            help_help_tips();
        }

        return;
    default:
        COMMAND_ERROR(command, " --too many paramters, the correct format of help(?) are as follows: ");

        // printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "?", "$", "\\", "+", "-", "/", "!", "=", "=%", "%=");
        GREEN_PRINT("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n\n",
                    HELP_TOKEN, CONFIGURATION_TOKEN, DISPLAY_TOKEN, ADD_TOKEN, COMPLETE_TOKEN, DELETE_TOKEN, TOGGLE_TOKEN, EQUAL, EDIT_PREFIX_TOKEN, EDIT_SUFFIX_TOKEN);
        help_help_tips();
        return;
    }
}
void parse_node(N_node node, C_command command, T_date date)
{
    LOG_PRINT("parse_node......");
    /**
     * func descp: 解析语法树
     */
    switch (node->node_type)
    {
    case SHOW:
        parse_show_node(node, command, date);
        break;
    case ADD:
        parse_add_node(node, command, date);
        break;
    case DELETE_:
        LOG_PRINT("delete_node......");
        parse_delete_node(node, command, date);
        break;
    case EDIT_ALL:
    case EDIT_PREFIX:
    case EDIT_SUFFIX:
        parse_edit_node(node, command, date);
        break;
    case DONE:
        parse_done_node(node, command, date);
        break;
    case TOGGLE:
        parse_toggle_node(node, command, date);
        break;
    case SET:
        parse_set_node(node, command, date);
        break;
    case HELP:
        parse_help_node(node, command, date);
        break;
    }
}
