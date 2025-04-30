#ifndef LOAD_DATA_H
#define LOAD_DATA_H
#include "../../include.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/stat.h>
#endif
// 加载数据
void load_all_files(All_Files *all_files, char *all_files_paths, Date *date);

#endif