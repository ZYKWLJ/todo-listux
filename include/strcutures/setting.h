#ifndef SETTING_H_
#define SETTING_H_
#define DATA_FILE_PATH
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