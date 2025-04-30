#include "../include.h"

// 打印任务信息
void print_task(Task *task, int size);
// 打印单日任务信息
void print_task_day(TaskDay *task_day) ;
// 打印单月任务信息
void print_task_month(TaskMonth *task_month) ;


// 打印当年每日任务信息
void print_day_year_task(Day_Year_Task *day_year_task) ;

// 打印单月任务信息（用于月任务）
void print_month_task(Month_Task *month_task) ;

// 打印当年每月任务信息
void print_month_year_task(Month_Year_Task *month_year_task) ;

// 打印单周任务信息
void print_week_task(Week_Task *week_task);
// 打印单月周任务信息
void print_week_month_task(Week_Month_Task *week_month_task) ;

// 打印当年每周任务信息
void print_week_year_task(Week_Year_Task *week_year_task);

// 打印当年任务信息
void print_year_task(Year_Task *year_task) ;

// 打印设置项信息
void print_setting_item(SettingItem *setting_item) ;

// 打印设置信息
void print_setting(Setting *setting) ;

// 打印全年任务数据信息
void print_total_file_year_date(Total_File_Year_Date *total_file_year_date);
// 打印所有文件信息
void print_all_files(All_Files *all_files) ;