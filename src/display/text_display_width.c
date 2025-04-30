#include "../../include/include.h"

int text_display_width(const char *str) {
    int width = 0;
    while (*str) {
        if ((unsigned char)*str >= 0x80) { // 中文字符
            width += 2;
            str += 3; // UTF-8中文字符通常占3字节
        } else {
            width += 1;
            str += 1;
        }
    }
    return width;
}

// 打印固定宽度的字符串，考虑中文字符
void text_print_padded(const char *str, int width) {
    int str_width = text_display_width(str);
    printf("%s", str);
    for (int i = str_width; i < width; i++) {
        printf(" ");
    }
}