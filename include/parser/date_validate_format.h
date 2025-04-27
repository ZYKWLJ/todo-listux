#include "../include.h"
int is_all_digits(const char *str);
// 固定数据结构，2025.01.04
void validate_year_format(const char *date_str, Date *date);

// 重构validate_year_month_format函数
// 2025.09
void validate_year_month_format(const char *date_str, Date *date);

// 重构validate_date_format函数
void validate_date_format(const char *date_str, Date *date);

// 计算指定日期属于哪一周（每月固定4周）
int calculate_week_number(int day);

// 重构validate_week_format函数
void validate_week_format(const char *date_str, Date *date);