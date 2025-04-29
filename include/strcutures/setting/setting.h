
#include "../../include.h"
#ifndef SETTING_H_
#define SETTING_H_

#define DATA_FILE_PATH
// day_task
#define DEFALUT_DAY_TASK_SIZE 20 //一天最多20天任务，后面再扩容
#define DEFALUT_TASK_CHAR_LENGTH 2000 // 默认的任务描述字符长度，足够了
#define INIT_TASK_CAPACITY 20
#define MAX_TASK_SIZE 1000000 // 百万的字，为单条最大的任务，超过了也会截止这么多！

// week_task
#define DEFALUT_WEEK_TASK_SIZE 1000 // 每个周的1000条任务，足足的，不够再扩容呗！

// month_task
#define DEFALUT_MONTH_TASK_SIZE 1000 // 每个月的1000条任务，足足的，不够再扩容呗！

// year_task
#define DEFALUT_YEAR_TASK_SIZE 1000 // 每年的1000条任务，足足的，不够再扩容呗！
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

// 假设这些结构体已经在别处定义
typedef struct
{
    char *key;             // 设置key
    char *value_set;       // 实际传入的
    char **value_allow; // 允许的值
} SettingItem;

typedef struct
{
    SettingItem *color;
    SettingItem *show;
} Setting;

// 检查是不是在设置中，方可见效(判断成功直接设置了，不成功也没关系，还是原来的)
int set_settings(Setting *seting, CONFIGURATION_NODE *configuration_node);
void set_settings_init(Setting *settings); // 初始化设置
void free_setting_item(SettingItem *item);

void free_setting(Setting *s);

#endif