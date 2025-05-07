#ifndef TASK_H
#define TASK_H
#include "../include.h"
/**
 * data descp: 因为每个任务都要加上添加任务时间、完成任务时间、完成任务间隔等等，所以这里必须包含日期这个参数在任务列表里面！
 */

typedef struct T_task_
{
    char content[10000000]; // 10MB内容空间
    char status;            // 完成1，未完成0
    int id;                 /*任务的id*/
    char key[10];           /*设置的k-v*/
    char value[10];
    T_current_date add_time; /*从添加时间这里得知任务类型！*/
    T_current_date finish_time;
    T_current_date interval;
} *T_task;

#endif