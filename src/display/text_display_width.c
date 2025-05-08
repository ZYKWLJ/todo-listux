#include "../../include/include.h"
// #define ASCI
#ifndef _WIN32
int text_display_width(const char *str)
{
    int width = 0;
    while (*str)
    {
        if ((unsigned char)*str >= 0x80)
        { // 中文字符
            width += 2;
            str += 3; // UTF-8中文字符通常占3字节
        }
        else
        {
            width += 1;
            str += 1;
        }
    }
    return width;
}
// 打印固定宽度的字符串，考虑中文字符
void text_print_padded(const char *str, int width)
{
    int str_width = text_display_width(str);
    printf("%s", str);
    for (int i = str_width; i < width; i++)
    {
        printf(" ");
    }
}

#else

/**
 * filename:text_display_width.c
 * description: 这是win下专属的格式，不会出错！
 * author:EthanYankang
 * create time:2025/05/08 13:41:56
 */
// 计算字符串显示宽度，支持宽字符
int text_display_width(const char *str)
{
    wchar_t wstr[1000];
    mbstowcs(wstr, str, sizeof(wstr) / sizeof(wstr[0]));

    int width = 0;
    for (int i = 0; wstr[i] != L'\0'; i++)
    {
        if (iswprint(wstr[i]))
        {
            if (wstr[i] < 0x80)
            {
                width += 1;
            }
            else
            {
                width += 2;
            }
        }
    }
    return width;
}

// 打印固定宽度的字符串，考虑中文字符
void text_print_padded(const char *str, int width)
{
    int str_width = text_display_width(str);
    printf("%s", str);
    for (int i = str_width; i < width; i++)
    {
        printf(" ");
    }
}

#endif
