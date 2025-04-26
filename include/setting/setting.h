#ifndef SETTING_H_
#define SETTING_H_
#define DATA_FILE_PATH
// day_task
#define DEFALUT_TASK_CHAR_LENGTH 2000 // 默认的任务描述字符长度，足够了
#define INIT_TASK_CAPACITY 20
#define MAX_TASK_SIZE 1000000 // 百万的字，为单条最大的任务，超过了也会截止这么多！

// week_task
#define DEFALUT_WEEK_TASK_SIZE 1000 // 每个周的1000条任务，足足的，不够再扩容呗！

// month_task
#define DEFALUT_MONTH_TASK_SIZE 1000 // 每个月的1000条任务，足足的，不够再扩容呗！

// year_task
#define DEFALUT_YEAR_TASK_SIZE 1000 // 每年的1000条任务，足足的，不够再扩容呗！

// const char* dataFilePath;//数据保存位置，写死的，不必添加
// const char* settingFilePath;//设置文件的保存位置
typedef struct Setting
{

    char color[4]; // on or off
    char show[6];  // year 、month、week、day、all
} Setting;

// 检查是不是在设置中，方可见效
int is_in_settings(char *str);
#endif