#ifndef INCLUDE_H
#define INCLUDE_H
// 此文件用于包含所有头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdarg.h>
#include "strcutures/task_day/Task.h"
#include "strcutures/task_day/TaskDay.h"
#include "strcutures/task_day/TaskMonth.h"
#include "strcutures/task_day/Day_Year_Task.h"
#include "strcutures/task_week/Week_Task.h"
#include "strcutures/task_week/Week_Month_Task.h"
#include "strcutures/task_Week/Week_Year_Task.h"
#include "strcutures/task_month/Month_Task.h"
#include "strcutures/task_month/Month_Year_Task.h"
#include "strcutures/task_year/Year_Task.h"
#include "strcutures/Total_File_Year_Date.h"
#include "strcutures/command.h"
#include "strcutures/date/date.h"
#include "strcutures/node/node.h"
#include "strcutures/setting/setting.h"
#include "strcutures/All_Files.h"


// #include "strcutures/command/Command.h"
#include "strcutures/Total_File_Year_Date.h"
#include "display/display.h"
#include "display/color.h"
#include "tools/tools.h"
#include "tools/MONTH.h"
#include "tools/command_error.h"
#include "parser/parse_command.h"
#include "database/load_data.h"
#include "database/save_data.h"
#include "database/delete_data.h"
#include "database/modify_data.h"
#include "database/add_data.h"
#include "database/filePath.h"
#include "database/save_setting.h"
#include "database/load_day_year_file.h"
#include "database/load_week_year_file.h"
#include "database/load_month_year_file.h"
#include "database/load_year_file.h"
#include "execute/find.h"
#include "execute/delete.h"
#include "execute/modify.h"
#include "execute/add.h"
#include "display/help.h"
#include "execute/done.h"
#include "execute/undo.h"
// #include "execute/command_type.h"
#include "execute/set_setting.h"
#include "execute/execute.h"
#include "log/log.h"
// #include "lexer/lexer_date.h"
#include "parser/date_validate_format.h"
#include "parser/parse_date.h"
#include "parser/parse_date_type.h"

#endif