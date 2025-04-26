#include "../../include/include.h"
// 默认的配置文件
const char *all_settings[] = {"color", "show"}; // 要检查在不在这里面，不在设置不起效果
int is_in_settings(char *str){
    for (int i = 0; i < sizeof(all_settings) / sizeof(char *); i++){
        if (strcmp(str, all_settings[i]) == 0){
            return 1; 
        }
    }
    return 0;
}