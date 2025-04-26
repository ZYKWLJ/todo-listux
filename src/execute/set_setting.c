// #include "../../include/include.h"
// // tl set color=yes
// // 读到第一个=为止，前面的是k，后面的是v
// // void set_setting(int argc, char**argv){
// //     if(argc==3){
// //         // 读到第一个=为止，前面的是k，后面的是v
// //     }else if(argc!=3){
// //         // 显示设置的正确方法
// //     }
// // }
#include "../../include/include.h"

// 设置设置
void set_setting(int argc, char **argv)
{
    if (argc == 3)
    {
        // 找到第一个 '=' 的位置
        char *equal_sign = strchr(argv[2], '=');
        if (equal_sign)
        {
            // 提取键和值
            char key[64];
            char value[64];
            strncpy(key, argv[2], equal_sign - argv[2]);
            key[equal_sign - argv[2]] = '\0';
            strcpy(value, equal_sign + 1);

            // 检查键是否在设置范围内
            if (!is_in_settings(key))
            {
                fprintf(stderr, "NO %s setting \n", key);
                return;
            }

            // 读取当前设置
            Setting* setting = (Setting*)malloc(sizeof(Setting));
            if (setting == NULL) {
                fprintf(stderr, "Memory allocation failed.\n");
                return;
            }

            Setting* result = read_setting(setting);
            if (result == NULL) {
                free(setting); // 释放已分配的内存
                return;
            }

            // 根据键更新设置
            if (strcmp(key, "color") == 0)
            {
                if (strcmp(value, "on") == 0 || strcmp(value, "off") == 0)
                {
                    strncpy(setting->color, value, sizeof(setting->color) - 1);
                    setting->color[sizeof(setting->color) - 1] = '\0';
                }
                else
                {
                    fprintf(stderr, "Invalid value for color setting. Expected 'on' or 'off'.\n");
                    free(setting); // 释放已分配的内存
                    return;
                }
            }
            else if (strcmp(key, "show") == 0)
            {
                // 检查值是否在设置范围内
                if (strcmp(value, "year") == 0 || strcmp(value, "month") == 0 ||
                    strcmp(value, "week") == 0 || strcmp(value, "day") == 0 ||
                    strcmp(value, "all") == 0)
                {
                    strncpy(setting->show, value, sizeof(setting->show) - 1);
                    setting->show[sizeof(setting->show) - 1] = '\0';
                }
                else
                {
                    fprintf(stderr, "Invalid value for show setting. Expected 'year', 'month', 'week', 'day', or 'all'.\n");
                    free(setting); // 释放已分配的内存
                    return;
                }
            }

            // 保存更新后的设置
            save_setting(setting);

            LOG_PRINT("Setting updated successfully.\n");

            free(setting); // 释放已分配的内存
        }
        else
        {
            fprintf(stderr, "Invalid setting format. Expected 'key=value'.\n");
        }
    }
    else if (argc != 3)
    {
        // 显示设置的正确方法
        fprintf(stderr, "Usage: %s <command> <setting>\n", argv[0]);
        fprintf(stderr, "Example: %s set color=yes\n", argv[0]);
    }
}

// int main(int argc, char **argv)
// {
//     if (argc < 2)
//     {
//         fprintf(stderr, "Usage: %s <command> [arguments]\n", argv[0]);
//         return 1;
//     }

//     if (strcmp(argv[1], "set") == 0)
//     {
//         set_setting(argc, argv);
//     }
//     else
//     {
//         fprintf(stderr, "Unrecognized command: %s\n", argv[1]);
//     }

//     return 0;
// }

// gcc D:\3software\todo-listux-1\todo-listux\src\execute\set_setting.c  D:\3software\todo-listux-1\todo-listux\src\database\save_setting.c D:\3software\todo-listux-1\todo-listux\src\database\filePath.c D:\3software\todo-listux-1\todo-listux\src\strcutures\setting.c -o D:\3software\todo-listux-1\todo-listux\src\execute\set_tings
// 以下假设其他函数的定义（save_setting, read_setting, get_appdata_path, create_directory）都已经包含在相应的头文件或其他源文件中
// 如果这里没有定义，你需要补充完整
// void save_setting(Setting *setting);
// void read_setting(Setting *setting);
// const char *get_appdata_path();
// int create_directory(const char *path);