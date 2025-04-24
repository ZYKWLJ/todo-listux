#ifndef INIT_H
#define INIT_H
#include "../include.h"
// 初始化当天任务
Task *init_day_tasks();
// 初始化当年任务
Task ***init_year_tasks(int year);
#endif