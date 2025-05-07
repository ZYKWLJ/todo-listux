#include "../../include/include.h"
// #include "date.h"
// #include "date.h"
// #include "date.h"
int calculate_week_number(int day)
{
    if (day <= 7)
        return 1;
    if (day <= 14)
        return 2;
    if (day <= 21)
        return 3;
    return 4; // 第4周包含22日及以后的所有天数
}

T_current_date T_current_date_init(T_current_date t)
{
    T_current_date time_ = (T_current_date)malloc(sizeof(*t));
    if (time_ == NULL)
    {
        fprintf(stderr, "内存分配失败\n");
        return NULL;
    }

    // 获取当前时间
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // 初始化结构体成员
    time_->year = timeinfo->tm_year + 1900;
    time_->month = timeinfo->tm_mon + 1;
    time_->week = calculate_week_number(timeinfo->tm_mday);
    time_->day = timeinfo->tm_mday;
    time_->hour = timeinfo->tm_hour;
    time_->minute = timeinfo->tm_min;
    time_->second = timeinfo->tm_sec;

    // LOG_PRINT("current time: %04d-%02d-%02d %02d:%02d:%02d,test passed!\n",
    //            time_->year, time_->month, time_->day, time_->hour, time_->minute, time_->second);
    return time_;
}

void T_time_print(T_current_date t)
{
    printf("current time: %04d-%02d-%02d %02d:%02d:%02d\n",
           t->year, t->month, t->day, t->hour, t->minute, t->second);
}

T_date T_date_init(T_date t)
{
    T_date date = (T_date)checked_malloc(sizeof(*t));
    /**
     * data descp:默认为当前时间的操作
     */
    // date->T_date_type = CURRENT_DATE;
    // date->T_current_date = T_current_date_init(t->T_current_date);
    return date;
}
