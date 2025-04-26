#include "../include.h"
// 解析第3个参数,判断日期类型
Date_Type parse_date_type(char *date_type);

// 解析第4个参数,判断日期类型下的具体日期

Date *parse_date(Date_Type date_type, char *date_str, Date *date);