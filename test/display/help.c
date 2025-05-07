// #include <stdio.h>
// #include <stdarg.h>
// #include <locale.h>
// #include <wchar.h>
// #include <wctype.h>
// #include <string.h>

// #define SOFTWARE_NAME "tl"
// #define PROCESS_NAME "process"
// #define COMMAND "command"
// #define ARGUMENTS1 "arguments1"
// #define ARGUMENTS2 "arguments2"
// #define ARGUMENTS3 "arguments3"
// #define ARGUMENTS4 "arguments4"
// #define INSTRUCTION "instruction"
// #define HELP_TOKEN "?"
// #define DISPLAY_TOKEN "^"
// #define ADD_TOKEN "+"
// #define COMPLETE_TOKEN "-"
// #define DELETE_TOKEN "/"
// #define TOGGLE_TOKEN "!"
// #define CONFIGURATION_TOKEN "$"
// #define EDIT_ALL_TOKEN "="
// #define EDIT_PREFIX_TOKEN "=%"
// #define EDIT_SUFFIX_TOKEN "%="
// #define EQUAL "="

// #define SETTING_COLOR_KEY "color"
// #define SETTING_SHOW_KEY "show"

// // 用户手册
// #define HEAD "TaskLite (tl) Command Reference"
// #define USAGE "Usage: tl [command] [arguments]"
// #define DATE_TYPE_HELP "Following date_type means d/day w/week m/month y/year"
// #define DATE_FOMAT_HELP "Following fixed date_fomat : d/day=>xxxx.xx.xx\tw/week=>xxxx.xx.xx\tm/month=>xxxx.xx\ty/year=>xxxx"
// #define TID_HELP "Following TID means task_index"
// #define SHOW_COMMANDS "SHOW COMMANDS:"
// #define ADD_COMMANDS "ADD COMMANDS:"
// #define COMPLETE_COMMANDS "COMPLETE COMMANDS:"
// #define DELETE_COMMANDS "DELETE COMMANDS:"
// #define TOGGLE_COMMANDS "TOGGLE COMMANDS:"
// #define CONFIGURATION "CONFIGURATION COMMANDS:"
// #define EDIT_COMMANDS "EDIT COMMANDS:"
// #define DATE_TYPE "-date_type"
// #define DATE_FOMAT "-date_fomat"
// #define TID "TID"
// #define CONTENT "content"
// #define USER_HELP "Show help"
// #define DISPLAY_TODAY_TASK "Show task (today)"
// #define DISPLAY_SPECIFIC_DATE_TASK "Show task (specific date)"
// #define ADD_TASK_TO_TODAY "Add task (today)"
// #define ADD_TASK_TO_SPECIFIC_DATE "Add task (specific date)"
// #define MARK_TASK_AS_DONE_TODAY "Mark task as done (today)"
// #define MARK_TASK_AS_DONE_SPECIFIC_DATE "Mark task as done (specific date)"
// #define DELETE_TASK_TODAY "Delete task (today)"
// #define DELETE_TASK_SPECIFIC_DATE "Delete task (specific date)"
// #define TOGGLE_TASK_TODAY "Toggle task (today)"
// #define TOGGLE_TASK_SPECIFIC_DATE "Toggle task (specific date)"
// #define REPLACE_TASK_TODAY "Replace task (today)"
// #define REPLACE_TASK_SPECIFIC_DATE "Replace task (specific date)"
// #define PREPEND_TO_TASK_TODAY "Prepend to task (today)"
// #define PREPEND_TO_TASK_SPECIFIC_DATE "Prepend to task (specific date)"
// #define APPEND_TO_TASK_TODAY "Append to task (today)"
// #define APPEND_TO_TASK_SPECIFIC_DATE "Append to task (specific date)"
// #define SET_CONFIGURATION "Set configuration KEY to VALUE"
// #define CONFIGURATION_HELP "Setting available keys:"
// #define KV "KEY=VALUE"
// #define CONFIGURATION_COLOR "on/off"
// #define CONFIGURATION_SHOW "d/day/w/week/m/month/y/year"
// #define COLOR_ON "Enable colored output"
// #define COLOR_OFF "Disable colored output"
// #define SHOW_DAY "Default display mode (day)"
// #define SHOW_WEEK "Default display mode (week)"
// #define SHOW_MONTH "Default display mode (month)"
// #define SHOW_YEAR "Default display mode (year)"
// #define NO_WORD ""
// #define TL SOFTWARE_NAME

// // #define BORDER_PLUS "+"
// // #define BORDER_MINUS "-"
// // #define BORDER_VERTICAL_LINE "|"

// #define BORDER_PLUS " "
// #define BORDER_MINUS " "
// #define BORDER_VERTICAL_LINE " "

// // 计算字符串显示宽度
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
//             break;
//         if (rc == 0)
//             break;

//         if (iswprint(wc))
//             width++;

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
//         printf(" ");
// }

// // 帮助表格打印函数（支持变参指定列）
// void text_print_help(const char **columns[], int total_columns, ...)
// {
//     setlocale(LC_ALL, "");

//     // 收集要显示的列索引（保持输入顺序）
//     int show_columns[total_columns];
//     int show_count = 0;

//     va_list args;
//     va_start(args, total_columns);
//     int col;
//     while ((col = va_arg(args, int)) != -1)
//     {
//         if (col >= 0 && col < total_columns)
//         {
//             show_columns[show_count++] = col;
//         }
//     }
//     va_end(args);

//     if (show_count == 0)
//     {
//         // 不指定列时显示全部列（保持原始顺序）
//         for (int i = 0; i < total_columns; i++)
//         {
//             show_columns[i] = i;
//         }
//         show_count = total_columns;
//     }

//     // 计算每列最大宽度
//     int col_max_widths[total_columns];
//     for (int i = 0; i < total_columns; i++)
//     {
//         col_max_widths[i] = 0;
//         if (columns[i])
//         {
//             for (int row = 0; columns[i][row] != NULL; row++)
//             {
//                 int width = text_display_width(columns[i][row]);
//                 if (width > col_max_widths[i])
//                 {
//                     col_max_widths[i] = width;
//                 }
//             }
//         }
//     }

//     // 计算最大行数
//     int max_rows = 0;
//     for (int i = 0; i < total_columns; i++)
//     {
//         if (columns[i])
//         {
//             int rows = 0;
//             while (columns[i][rows] != NULL)
//                 rows++;
//             if (rows > max_rows)
//                 max_rows = rows;
//         }
//     }

//     // 打印上边框（按show_columns数组顺序）
//     for (int i = 0; i < show_count; i++)
//     {
//         printf(BORDER_PLUS);
//         int width = col_max_widths[show_columns[i]] + 2;
//         for (int j = 0; j < width; j++)
//             printf(BORDER_MINUS);
//     }
//     printf("%s\n", BORDER_PLUS);

//     // 打印表头（按show_columns数组顺序）
//     if (max_rows > 0)
//     {
//         printf(BORDER_VERTICAL_LINE);
//         for (int i = 0; i < show_count; i++)
//         {
//             int col_idx = show_columns[i]; // 关键：按存储顺序获取列索引
//             printf(" ");
//             if (columns[col_idx] && columns[col_idx][0])
//             {
//                 text_print_padded(columns[col_idx][0], col_max_widths[col_idx]);
//             }
//             else
//             {
//                 text_print_padded("", col_max_widths[col_idx]);
//             }
//             printf(" %s", BORDER_VERTICAL_LINE);
//         }
//         printf("\n");

//         // 打印表头和内容之间的分隔线
//         for (int i = 0; i < show_count; i++)
//         {
//             printf(BORDER_PLUS);
//             int width = col_max_widths[show_columns[i]] + 2;
//             for (int j = 0; j < width; j++)
//                 printf(BORDER_MINUS);
//         }
//         printf("%s\n", BORDER_PLUS);
//     }

//     // 打印表格内容（从第2行开始）
//     for (int row = 1; row < max_rows; row++)
//     {
//         printf(BORDER_VERTICAL_LINE);
//         for (int i = 0; i < show_count; i++)
//         {
//             int col_idx = show_columns[i];
//             printf(" ");
//             if (columns[col_idx] && row < max_rows && columns[col_idx][row])
//             {
//                 text_print_padded(columns[col_idx][row], col_max_widths[col_idx]);
//             }
//             else
//             {
//                 text_print_padded("", col_max_widths[col_idx]);
//             }
//             printf(" %s", BORDER_VERTICAL_LINE);
//         }
//         printf("\n");
//     }

//     // 打印下边框
//     for (int i = 0; i < show_count; i++)
//     {
//         printf(BORDER_PLUS);
//         int width = col_max_widths[show_columns[i]] + 2;
//         for (int j = 0; j < width; j++)
//             printf(BORDER_MINUS);
//     }
//     printf("%s\n", BORDER_PLUS);
// }

// void help(int show_all, ...)
// {
//     printf("\n\n%s\n", HEAD);
//     printf("%s\n", USAGE);
//     printf("%s\n", DATE_TYPE_HELP);
//     printf("%s\n", DATE_FOMAT_HELP);
//     printf("%s\n", TID_HELP);

//     // 定义各列数据
//     const char *index[] = {"Index", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", NULL};
//     const char *soft_name[] = {PROCESS_NAME, TL, TL, TL, TL, TL, TL, TL, TL, TL, TL, TL, TL, TL, TL, TL, TL, TL, TL, NULL};
//     const char *command[] = {COMMAND, HELP_TOKEN, DISPLAY_TOKEN, DISPLAY_TOKEN, ADD_TOKEN, ADD_TOKEN, COMPLETE_TOKEN, COMPLETE_TOKEN,
//                              DELETE_TOKEN, DELETE_TOKEN, TOGGLE_TOKEN, TOGGLE_TOKEN, EDIT_ALL_TOKEN, EDIT_ALL_TOKEN,
//                              EDIT_PREFIX_TOKEN, EDIT_PREFIX_TOKEN, EDIT_SUFFIX_TOKEN, EDIT_SUFFIX_TOKEN, CONFIGURATION_TOKEN, NULL};
//     const char *arguments1[] = {ARGUMENTS1, NO_WORD, NO_WORD, DATE_TYPE, NO_WORD, CONTENT, NO_WORD, TID, NO_WORD, TID,
//                                 NO_WORD, TID, NO_WORD, TID, NO_WORD, TID, NO_WORD, TID, KV, NULL};
//     const char *arguments2[] = {ARGUMENTS2, NO_WORD, NO_WORD, DATE_FOMAT, NO_WORD, DATE_TYPE, NO_WORD, DATE_TYPE, NO_WORD, DATE_TYPE,
//                                 NO_WORD, DATE_TYPE, NO_WORD, CONTENT, NO_WORD, CONTENT, NO_WORD, CONTENT, NO_WORD, NULL};
//     const char *arguments3[] = {ARGUMENTS3, NO_WORD, NO_WORD, NO_WORD, NO_WORD, DATE_FOMAT, NO_WORD, DATE_FOMAT, NO_WORD, DATE_FOMAT,
//                                 NO_WORD, DATE_FOMAT, NO_WORD, DATE_TYPE, NO_WORD, DATE_TYPE, NO_WORD, DATE_TYPE, NO_WORD, NULL};
//     const char *arguments4[] = {ARGUMENTS4, NO_WORD, NO_WORD, NO_WORD, NO_WORD, NO_WORD, NO_WORD, NO_WORD, NO_WORD, NO_WORD,
//                                 NO_WORD, NO_WORD, NO_WORD, DATE_FOMAT, NO_WORD, DATE_FOMAT, NO_WORD, DATE_FOMAT, NO_WORD, NULL};
//     const char *instruction[] = {INSTRUCTION, USER_HELP, DISPLAY_TODAY_TASK, DISPLAY_SPECIFIC_DATE_TASK, ADD_TASK_TO_TODAY,
//                                  ADD_TASK_TO_SPECIFIC_DATE, MARK_TASK_AS_DONE_TODAY, MARK_TASK_AS_DONE_SPECIFIC_DATE,
//                                  DELETE_TASK_TODAY, DELETE_TASK_SPECIFIC_DATE, TOGGLE_TASK_TODAY, TOGGLE_TASK_SPECIFIC_DATE,
//                                  REPLACE_TASK_TODAY, REPLACE_TASK_SPECIFIC_DATE, PREPEND_TO_TASK_TODAY, PREPEND_TO_TASK_SPECIFIC_DATE,
//                                  APPEND_TO_TASK_TODAY, APPEND_TO_TASK_SPECIFIC_DATE, SET_CONFIGURATION, NULL};

//     const char **columns[] = {soft_name, command, arguments1, arguments2, arguments3, arguments4, instruction};
//     int total_columns = sizeof(columns) / sizeof(columns[0]);

//     if (show_all)
//     {
//         // 显示所有列
//         text_print_help(columns, total_columns, -1);
//         printf("\n\n%s\n", CONFIGURATION_HELP);
//         const char *KEY[] = {"KEY", SETTING_COLOR_KEY, SETTING_SHOW_KEY, NULL};
//         const char *VALUE[] = {"VALUE", CONFIGURATION_COLOR, CONFIGURATION_SHOW, NULL};
//         const char **config_columns[] = {KEY, VALUE};
//         text_print_help(config_columns, 2, -1);
//     }
//     // else
//     // {
//     //     // 使用变参指定要显示的列
//     //     va_list args;
//     //     va_start(args, show_all);
//     //     text_print_help(columns, total_columns,
//     //                     va_arg(args, int),
//     //                     va_arg(args, int),
//     //                     va_arg(args, int),
//     //                     -1);
//     //     va_end(args);
//     // }
//     else
//     {
//         // 使用变参指定要显示的列
//         #define MAX_COLUMNS 16
//         va_list args;
//         va_start(args, show_all);
//         int col_indices[MAX_COLUMNS]; // 假设最大列数不超过 MAX_COLUMNS，可根据实际情况调整
//         int col_count = 0;

//         // 读取可变参数并存储到数组中
//         int col;
//         while ((col = va_arg(args, int)) != -1)
//         {
//             if (col_count < MAX_COLUMNS)
//             {
//                 col_indices[col_count++] = col;
//             }
//         }

//         // 逆序调用 text_print_help
//         int reversed_args[MAX_COLUMNS];
//         for (int i = 0; i < col_count; i++)
//         {
//             reversed_args[i] = col_indices[col_count - i - 1];
//         }

//         // 构建参数列表并调用 text_print_help
//         int temp_args[MAX_COLUMNS + 1];
//         for (int i = 0; i < col_count; i++)
//         {
//             temp_args[i] = reversed_args[i];
//         }
//         temp_args[col_count] = -1;

//         text_print_help(columns, total_columns, temp_args[0], temp_args[1], temp_args[2], -1);
//         va_end(args);
//     }
// }

// int main()
// {
//     // 显示所有列
//     printf("Full help:\n");
//     help(1);

//     // 只显示指定列（例如第0、2、5列）
//     printf("\nPartial help (columns 0, 2, 5):\n");
//     help(0, 0, 2, 5,4, -1);
//     // help(0, 5, 2, 0 - 1);

//     return 0;
// }