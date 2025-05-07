#ifndef HELP_H
#define HELP_H
#include <stdio.h>
#include <stdarg.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <string.h>
#define SOFTWARE_NAME "tl"
#define PROCESS_NAME "process"
#define COMMAND "command"
#define ARGUMENTS1 "argument1"
#define ARGUMENTS2 "argument2"
#define ARGUMENTS3 "argument3"
#define ARGUMENTS4 "argument4"
#define INSTRUCTION "instruction"
#define HELP_TOKEN "?"
#define DISPLAY_TOKEN "^"
#define ADD_TOKEN "+"
#define COMPLETE_TOKEN "-"
#define DELETE_TOKEN "/"
#define TOGGLE_TOKEN "!"
#define CONFIGURATION_TOKEN "$"
#define EDIT_ALL_TOKEN "="
#define EDIT_PREFIX_TOKEN "=%"
#define EDIT_SUFFIX_TOKEN "%="
#define EQUAL "="

#define SETTING_COLOR_KEY "color"
#define SETTING_SHOW_KEY "show"

// 用户手册
// 这里引入我们对流层的编排系统，直接用编排系统的接口，实现标准的编排！
#define HEAD "TaskLite (tl) Command Reference"
#define USAGE "Usage: tl [command] [arguments]"
#define DATE_TYPE_HELP "Following date_type means -d/-day -w/-week -m/-month -y/-year"
#define DATE_FOMAT_HELP "Following fixed date_fomat : -d/-day=>xxxx.xx.xx\t-w/-week=>xxxx.xx.xx\t-m/-month=>xxxx.xx\t-y/-year=>xxxx"
#define TID_HELP "Following TID means task_index"
#define SHOW_COMMANDS "SHOW COMMANDS:"
#define ADD_COMMANDS "ADD COMMANDS:"
#define COMPLETE_COMMANDS "COMPLETE COMMANDS:"
#define DELETE_COMMANDS "DELETE COMMANDS:"
#define TOGGLE_COMMANDS "TOGGLE COMMANDS:"
#define CONFIGURATION "CONFIGURATION COMMANDS:"
#define EDIT_COMMANDS "EDIT COMMANDS:"
#define DATE_TYPE "date_type"
#define DATE_FOMAT "date_fomat"
#define TID "TID"
#define CONTENT "content"
#define USER_HELP "Show help"
#define DISPLAY_TODAY_TASK "Show task (today)"
#define DISPLAY_SPECIFIC_DATE_TASK "Show task (specific date)"
#define ADD_TASK_TO_TODAY "Add task (today)"
#define ADD_TASK_TO_SPECIFIC_DATE "Add task (specific date)"
#define MARK_TASK_AS_DONE_TODAY "Mark task as done (today)"
#define MARK_TASK_AS_DONE_SPECIFIC_DATE "Mark task as done (specific date)"
#define DELETE_TASK_TODAY "Delete task (today)"
#define DELETE_TASK_SPECIFIC_DATE "Delete task (specific date)"
#define TOGGLE_TASK_TODAY "Toggle task (today)"
#define TOGGLE_TASK_SPECIFIC_DATE "Toggle task (specific date)"
#define REPLACE_TASK_TODAY "Replace task (today)"
#define REPLACE_TASK_SPECIFIC_DATE "Replace task (specific date)"
#define PREPEND_TO_TASK_TODAY "Prepend to task (today)"
#define PREPEND_TO_TASK_SPECIFIC_DATE "Prepend to task (specific date)"
#define APPEND_TO_TASK_TODAY "Append to task (today)"
#define APPEND_TO_TASK_SPECIFIC_DATE "Append to task (specific date)"
#define SET_CONFIGURATION "Set configuration KEY to VALUE"
#define CONFIGURATION_HELP "Setting available keys:"
#define KV "key=value"
#define CONFIGURATION_COLOR "on/off"
#define CONFIGURATION_SHOW "d/day/w/week/m/month/y/year"
#define COLOR_ON "Enable colored output"
#define COLOR_OFF "Disable colored output"
#define SHOW_DAY "Default display mode (day)"
#define SHOW_WEEK "Default display mode (week)"
#define SHOW_MONTH "Default display mode (month)"
#define SHOW_YEAR "Default display mode (year)"
#define NO_WORD ""
#define TL SOFTWARE_NAME

void help();
void help_show();
void help_add();
void help_done();
void help_delete();
void help_toggle();
void help_edit();
void help_edit_all();
void help_edit_prefix();
void help_edit_suffix();
void help_set();

#endif