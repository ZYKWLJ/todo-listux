#ifndef DATA_H
#define DATA_H
#include "../include.h"
/**
 * data descp: 因为每个任务都要加上添加任务时间、完成任务时间、完成任务间隔等等，所以这里必须包含日期这个参数在任务列表里面！
 */

/**
 * data descp: 定义天任务的结构体
 */

#define MONTHS_IN_YEAR 12
/**
 * data descp: 定义是不是闰年的结构体
 */

typedef struct T_day_task_
{
    int year;
    struct
    {
        int month;
        int num_days;
        struct
        {
            int size;
            int capacity;
            struct
            {
                string content;
                int is_done;
                T_current_date add_time;
                T_current_date finish_time;
                T_current_date interval_time;
            } *task;
        } *days;
    } months[MONTHS_IN_YEAR];
} *T_day_task;

/**
 * data descp: 周任务结构体
 */
typedef struct T_week_task_
{
    int year;
    struct
    {
        int month;
        int num_weeks;
        struct
        {
            int size;
            int capacity;
            struct
            {
                string content;
                int is_done;
                T_current_date add_time;
                T_current_date finish_time;
                T_current_date interval_time;
            } *task;
        } *weeks;
    } months[MONTHS_IN_YEAR];
} *T_week_task;

/**
 * data descp: 月任务结构体
 */
typedef struct T_month_task_
{
    int year;
    struct
    {
        int size;
        int capacity;
        struct
        {
            string content;
            int is_done;
            T_current_date add_time;
            T_current_date finish_time;
            T_current_date interval_time;
        } *task;
    } months[MONTHS_IN_YEAR]; /*12个月固定的*/
} *T_month_task;

/**
 * data descp: 年任务结构体
 */
typedef struct T_year_task_
{
    int year;
    int size;
    int capacity;
    struct
    {
        string content;
        int is_done;
        T_current_date add_time;
        T_current_date finish_time;
        T_current_date interval_time;
    } *task;
} *T_year_task;

/**
 * data descp: 从天到年的日期类型和任务类型,这里还是使用分类的方式来进行管理
 */

typedef struct T_task_type_
{
    enum
    {

        DAY,
        WEEK,
        MONTH,
        YEAR,
    } task_type;
    union
    {
        T_day_task day_task;
        T_week_task week_task;
        T_month_task month_task;
        T_year_task year_task;
    };

} *T_task_type;

typedef struct T_is_leap_year_
{
    enum
    {
        is_leap_year,
        not_leap_year,
    } year_type;

    union
    {
        // 平年每个月的天数
        int common_year_days[MONTHS_IN_YEAR];
        // 闰年每个月的天数
        int leap_year_days[MONTHS_IN_YEAR];
    } month_days;
} *T_is_leap_year;

#endif