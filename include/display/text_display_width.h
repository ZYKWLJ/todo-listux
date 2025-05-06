# ifndef DISPLAY_WIDTH_H
# define DISPLAY_WIDTH_H
#include <stdio.h>
int text_display_width(const char *str);
// 打印固定宽度的字符串，考虑中文字符
void text_print_padded(const char *str, int width);
# endif