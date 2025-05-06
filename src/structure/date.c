#include "../../include/include.h"
// #include "date.h"
// #include "date.h"

T_time T_time_init(T_time t)
{
    T_time time_ = (T_time)malloc(sizeof(*t));
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
    time_->day = timeinfo->tm_mday;
    time_->hour = timeinfo->tm_hour;
    time_->minute = timeinfo->tm_min;
    time_->second = timeinfo->tm_sec;

    return time_;
}

void T_time_print(T_time t)
{
    printf("current time: %04d-%02d-%02d %02d:%02d:%02d\n",
           t->year, t->month, t->day, t->hour, t->minute, t->second);
}
