#ifndef ALL_FILES_H
#define ALL_FILES_H
#include "../include.h"
// 都存在一个路径下。然后再开一个分目录。
// data

// data_2023
// data_2023_day.dat
// data_2023_month.dat
// data_2023_week.dat
// data_2023_year.dat
// data_2024
// data_2024_day.dat
// data_2024_month.dat
// data_2024_week.dat
// data_2024_year.dat
// data_2025
// data_2025_day.dat
// data_2025_month.dat
// data_2025_week.dat
// data_2025_year.dat

// config
// config.ini

typedef struct ALL_Files_Paths
{
    char *total_file_path;
    char *setting_file_path;
} ALL_Files_Paths;

// typedef struct Setting;

typedef struct All_Files
{
    Total_File_Year_Date *total_file_year_date; // 数据文件
    Setting *setting;                           // 配置文件
} All_Files;

void set_all_files(All_Files *all_files, Total_File_Year_Date *total_file_year_date, Setting *setting);
void free_all_files(All_Files *all_files);
void init_all_files(All_Files *all_files,Date*date);
#endif