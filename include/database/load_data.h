#ifndef LOAD_DATA_H
#define LOAD_DATA_H
#include "../include.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/stat.h>
#endif
// 加载数据
Day_Year_Task *load_data(int year);
#endif