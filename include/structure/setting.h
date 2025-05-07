#ifndef SETTING_H
#define SETTING_H
#include "../include.h"
#define SETTING_COLOR_KEY "color"
#define SETTING_SHOW_KEY "show"
#define SETTING_COLOR_ALLOW_ON "on"
#define SETTING_COLOR_ALLOW_OFF "off"
#define SETTING_SHOW_ALLOW_YEAR "year"
#define SETTING_SHOW_ALLOW_MONTH "month"
#define SETTING_SHOW_ALLOW_WEEK "week"
#define SETTING_SHOW_ALLOW_DAY "day"
#define SETTING_SHOW_ALLOW_CURRENT_DAY "current_day"
#define SETTING_SHOW_ALLOW_ALL "all"
#define SHOW_DAY_1 "-d"
#define SHOW_DAY_2 "-day"
#define SHOW_WEEK_1 "-w"
#define SHOW_WEEK_2 "-week"
#define SHOW_MONTH_1 "-m"
#define SHOW_MONTH_2 "-month"
#define SHOW_YEAR_1 "-y"
#define SHOW_YEAR_2 "-year"

typedef struct KV__
{
    char key[10];
    char value[10];
} *KV_;

// 假设这些结构体已经在别处定义
typedef struct S_setting_item_
{
    char key[10];          // 设置key
    char value_set[10];    // 实际传入的
    char *value_allow[10]; // 允许的值
} *S_setting_item;

typedef struct S_setting_
{
    S_setting_item color;
    S_setting_item show;
} *S_setting;
S_setting_item S_setting_item_init(S_setting_item s);

S_setting S_setting_init(S_setting s);
void set_settings_init(S_setting settings);

void S_settings_print(S_setting settings);
int set_settings(S_setting setting, KV_ node);
#endif