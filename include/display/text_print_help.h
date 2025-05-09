#ifndef _PRINT_H_
#define _PRINT_H_
#include <stdio.h>
#include <stdarg.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>
// #include"text_display_width.h"
void text_print_help_all(const char **str[], int columns_num);
void text_print_help_task(const char **str[], int columns_num);
void text_print_help(const char **str[], int columns_num);
void text_print_all(const char **str[], int columns_num);
void text_print(const char **str[], int columns_num);
#endif