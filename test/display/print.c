// #include <stdio.h>
// #include <stdarg.h>
// #include <locale.h>
// #include <wchar.h>
// #include <wctype.h>
// #include <string.h>

// // 假设的边框字符定义
// // #define BORDER_PLUS "+"
// // #define BORDER_MINUS "-"
// // #define BORDER_VERTICAL_LINE "|"

// #define BORDER_PLUS " "
// #define BORDER_MINUS " "
// #define BORDER_VERTICAL_LINE " "
// // 计算字符串显示宽度的函数
// int text_display_width(const char *str)
// {
//     if (!str)
//         return 0;

//     int width = 0;
//     mbstate_t state = {0};
//     const char *ptr = str;
//     wchar_t wc;
//     size_t len = strlen(str);

//     while (len > 0)
//     {
//         size_t rc = mbrtowc(&wc, ptr, len, &state);
//         if (rc == (size_t)-1 || rc == (size_t)-2)
//         {
//             // 处理错误情况
//             break;
//         }
//         if (rc == 0)
//             break; // 空字符

//         if (iswprint(wc))
//         {
//             width++;
//         }

//         ptr += rc;
//         len -= rc;
//     }
//     return width;
// }

// // 打印填充后的字符串
// void text_print_padded(const char *str, int width)
// {
//     if (!str)
//         str = "";
//     int len = text_display_width(str);
//     printf("%s", str);
//     for (int i = len; i < width; i++)
//     {
//         printf(" ");
//     }
// }

// // 打印表格内容的函数（指令help版本）
// void text_print_help(const char **str[], int columns_num, ...)
// {
//     setlocale(LC_ALL, ""); // 设置本地化，支持宽字符

//     va_list args;
//     va_start(args, columns_num);
//     int show_columns[columns_num];
//     int show_count = 0;
//     int col;
//     while ((col = va_arg(args, int)) != -1)
//     {
//         if (col >= 0 && col < columns_num)
//         {
//             show_columns[show_count++] = col;
//         }
//     }
//     va_end(args);

//     if (show_count == 0)
//     {
//         // 不指定列时显示全部列
//         for (int i = 0; i < columns_num; i++)
//         {
//             show_columns[i] = i;
//         }
//         show_count = columns_num;
//     }

//     // 1. 计算每列的最大宽度
//     int col_max_widths[columns_num];
//     for (int i = 0; i < columns_num; i++)
//     {
//         col_max_widths[i] = 0;
//         if (str[i])
//         {
//             for (int row = 0; str[i][row] != NULL; row++)
//             {
//                 int width = text_display_width(str[i][row]);
//                 if (width > col_max_widths[i])
//                 {
//                     col_max_widths[i] = width;
//                 }
//             }
//         }
//     }

//     // 2. 计算最大行数（以最长的列为准）
//     int max_rows = 0;
//     for (int i = 0; i < columns_num; i++)
//     {
//         if (str[i])
//         {
//             int rows = 0;
//             while (str[i][rows] != NULL)
//             {
//                 rows++;
//             }
//             if (rows > max_rows)
//             {
//                 max_rows = rows;
//             }
//         }
//     }

//     // 3. 打印上边框
//     for (int i = 0; i < show_count; i++)
//     {
//         int col_index = show_columns[i];
//         printf(BORDER_PLUS);
//         for (int j = 0; j < col_max_widths[col_index] + 2; j++)
//         {
//             printf(BORDER_MINUS);
//         }
//     }
//     printf("%s\n", BORDER_PLUS);

//     // 4. 打印表头（第一行）
//     if (max_rows > 0)
//     {
//         printf(BORDER_VERTICAL_LINE);
//         for (int i = 0; i < show_count; i++)
//         {
//             int col_index = show_columns[i];
//             printf(" ");
//             if (str[col_index] && str[col_index][0])
//             {
//                 text_print_padded(str[col_index][0], col_max_widths[col_index]);
//             }
//             else
//             {
//                 text_print_padded("", col_max_widths[col_index]);
//             }
//             printf(" %s", BORDER_VERTICAL_LINE);
//         }
//         printf("\n");

//         // 5. 打印表头和内容之间的分隔线
//         for (int i = 0; i < show_count; i++)
//         {
//             int col_index = show_columns[i];
//             printf(BORDER_PLUS);
//             for (int j = 0; j < col_max_widths[col_index] + 2; j++)
//             {
//                 printf(BORDER_MINUS);
//             }
//         }
//         printf("%s\n", BORDER_PLUS);
//     }

//     // 6. 打印表格内容（从第2行开始）
//     for (int row = 1; row < max_rows; row++)
//     {
//         printf(BORDER_VERTICAL_LINE);
//         for (int i = 0; i < show_count; i++)
//         {
//             int col_index = show_columns[i];
//             printf(" ");
//             if (str[col_index] && row < max_rows && str[col_index][row] != NULL)
//             {
//                 text_print_padded(str[col_index][row], col_max_widths[col_index]);
//             }
//             else
//             {
//                 text_print_padded("", col_max_widths[col_index]);
//             }
//             printf(" %s", BORDER_VERTICAL_LINE);
//         }
//         printf("\n");
//     }

//     // 7. 打印下边框
//     for (int i = 0; i < show_count; i++)
//     {
//         int col_index = show_columns[i];
//         printf(BORDER_PLUS);
//         for (int j = 0; j < col_max_widths[col_index] + 2; j++)
//         {
//             printf(BORDER_MINUS);
//         }
//     }
//     printf("%s\n", BORDER_PLUS);
// }

// // 打印表格内容的函数（通用版本）
// void text_print(const char **str[], int columns_num, ...)
// {
//     setlocale(LC_ALL, ""); // 设置本地化，支持宽字符

//     va_list args;
//     va_start(args, columns_num);
//     int show_columns[columns_num];
//     int show_count = 0;
//     int col;
//     while ((col = va_arg(args, int)) != -1)
//     {
//         if (col >= 0 && col < columns_num)
//         {
//             show_columns[show_count++] = col;
//         }
//     }
//     va_end(args);

//     if (show_count == 0)
//     {
//         // 不指定列时显示全部列
//         for (int i = 0; i < columns_num; i++)
//         {
//             show_columns[i] = i;
//         }
//         show_count = columns_num;
//     }

//     // 1. 计算每列的最大宽度
//     int col_max_widths[columns_num];
//     for (int i = 0; i < columns_num; i++)
//     {
//         col_max_widths[i] = 0;
//         if (str[i])
//         {
//             for (int row = 0; str[i][row] != NULL; row++)
//             {
//                 int width = text_display_width(str[i][row]);
//                 if (width > col_max_widths[i])
//                 {
//                     col_max_widths[i] = width;
//                 }
//             }
//         }
//     }

//     // 2. 计算最大行数（以最长的列为准）
//     int max_rows = 0;
//     for (int i = 0; i < columns_num; i++)
//     {
//         if (str[i])
//         {
//             int rows = 0;
//             while (str[i][rows] != NULL)
//             {
//                 rows++;
//             }
//             if (rows > max_rows)
//             {
//                 max_rows = rows;
//             }
//         }
//     }

//     // 3. 打印上边框
//     for (int i = 0; i < show_count; i++)
//     {
//         int col_index = show_columns[i];
//         printf(BORDER_PLUS);
//         for (int j = 0; j < col_max_widths[col_index] + 2; j++)
//         {
//             printf(BORDER_MINUS);
//         }
//     }
//     printf("%s\n", BORDER_PLUS);

//     // 4. 打印表格内容（从第1行开始）
//     for (int row = 0; row < max_rows; row++)
//     {
//         printf(BORDER_VERTICAL_LINE);
//         for (int i = 0; i < show_count; i++)
//         {
//             int col_index = show_columns[i];
//             printf(" ");
//             if (str[col_index] && str[col_index][row] != NULL)
//             {
//                 text_print_padded(str[col_index][row], col_max_widths[col_index]);
//             }
//             else
//             {
//                 text_print_padded("", col_max_widths[col_index]);
//             }
//             printf(" %s", BORDER_VERTICAL_LINE);
//         }
//         printf("\n");
//     }

//     // 5. 打印下边框
//     for (int i = 0; i < show_count; i++)
//     {
//         int col_index = show_columns[i];
//         printf(BORDER_PLUS);
//         for (int j = 0; j < col_max_widths[col_index] + 2; j++)
//         {
//             printf(BORDER_MINUS);
//         }
//     }
//     printf("%s\n", BORDER_PLUS);
// }

// // int main()
// // {
// //     const char *col1[] = {"Header1", "Data1", "Data2", NULL};
// //     const char *col2[] = {"Header2", "Data3", "Data4", NULL};
// //     const char *col3[] = {"Header3", "Data5", "Data6", NULL};
// //     const char **str[] = {col1, col2, col3};

// //     // 显示所有列
// //     // text_print_help(str, 3, -1);

// //     // 只显示第1列和第3列
// //     text_print(str, 4, 2,2, 1, -1);

// //     return 0;
// // }