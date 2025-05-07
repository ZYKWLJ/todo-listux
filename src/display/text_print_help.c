#include "../../include/include.h"
// #define BORDER_PLUS "+"
// #define BORDER_MINUS "-"
// #define BORDER_VERTICAL_LINE "|"

#define BORDER_PLUS " "
#define BORDER_MINUS " "
#define BORDER_VERTICAL_LINE " "
// 打印表格内容的函数（指令help版本）
void text_print_help(const char **str[], int columns_num)
{
    setlocale(LC_ALL, ""); // 设置本地化，支持宽字符

    // 1. 计算每列的最大宽度
    int col_max_widths[columns_num];
    for (int i = 0; i < columns_num; i++)
    {
        col_max_widths[i] = 0;
        for (int row = 0; str[i][row] != NULL; row++)
        {
            int width = text_display_width(str[i][row]);
            if (width > col_max_widths[i])
            {
                col_max_widths[i] = width;
            }
        }
    }

    // 2. 计算最大行数（以最长的列为准）
    int max_rows = 0;
    for (int i = 0; i < columns_num; i++)
    {
        int rows = 0;
        while (str[i][rows] != NULL)
        {
            rows++;
        }
        if (rows > max_rows)
        {
            max_rows = rows;
        }
    }

    // 3. 打印上边框
    for (int i = 0; i < columns_num; i++)
    {
        printf(BORDER_PLUS);
        for (int j = 0; j < col_max_widths[i] + 2; j++)
        {
            printf(BORDER_MINUS);
        }
    }
    printf("%s\n", BORDER_PLUS);

    // 4. 打印表头（第一行）
    // printf(BORDER_VERTICAL_LINE);
    printf(BORDER_VERTICAL_LINE);
    for (int i = 0; i < columns_num; i++)
    {
        printf(" ");
        // printf(BORDER_PLUS);
        text_print_padded(str[i][0], col_max_widths[i]);
        // printf(" %s",BORDER_VERTICAL_LINE);
        printf(" %s", BORDER_VERTICAL_LINE);
    }
    printf("\n");

    // 5. 打印表头和内容之间的分隔线
    for (int i = 0; i < columns_num; i++)
    {
        // printf(BORDER_PLUS);
        printf(BORDER_PLUS);

        for (int j = 0; j < col_max_widths[i] + 2; j++)
        {
            // printf(BORDER_MINUS);
            printf(BORDER_MINUS);
        }
    }
    // printf("%s\n",BORDER_PLUS);
    printf("%s\n", BORDER_PLUS);

    // 6. 打印表格内容（从第2行开始）
    for (int row = 1; row < max_rows; row++)
    {
        // printf(BORDER_VERTICAL_LINE);
        printf(BORDER_VERTICAL_LINE);
        for (int i = 0; i < columns_num; i++)
        {
            printf(" ");
            if (str[i][row] != NULL)
            {
                text_print_padded(str[i][row], col_max_widths[i]);
            }
            else
            {
                text_print_padded("", col_max_widths[i]);
            }
            printf(" %s", BORDER_VERTICAL_LINE);
            // printf(BORDER_VERTICAL_LINE);
        }
        printf("\n");
    }

    // 7. 打印下边框
    for (int i = 0; i < columns_num; i++)
    {
        // printf(BORDER_PLUS);
        printf(BORDER_PLUS);
        for (int j = 0; j < col_max_widths[i] + 2; j++)
        {
            // printf(BORDER_MINUS);
            printf(BORDER_MINUS);
        }
    }
    // printf("%s\n",BORDER_PLUS);
    printf("%s\n", BORDER_PLUS);
}

// 打印表格内容的函数（通用版本）
void text_print(const char **str[], int columns_num)
{
    setlocale(LC_ALL, ""); // 设置本地化，支持宽字符

    // 1. 计算每列的最大宽度
    int col_max_widths[columns_num];
    for (int i = 0; i < columns_num; i++)
    {
        col_max_widths[i] = 0;
        for (int row = 0; str[i][row] != NULL; row++)
        {
            int width = text_display_width(str[i][row]);
            if (width > col_max_widths[i])
            {
                col_max_widths[i] = width;
            }
        }
    }

    // 2. 计算最大行数（以最长的列为准）
    int max_rows = 0;
    for (int i = 0; i < columns_num; i++)
    {
        int rows = 0;
        while (str[i][rows] != NULL)
        {
            rows++;
        }
        if (rows > max_rows)
        {
            max_rows = rows;
        }
    }

    // 3. 打印上边框
    for (int i = 0; i < columns_num; i++)
    {
        printf(BORDER_PLUS);
        for (int j = 0; j < col_max_widths[i] + 2; j++)
        {
            printf(BORDER_MINUS);
        }
    }
    printf("%s\n", BORDER_PLUS);

    // 4. 打印表格内容（从第2行开始）
    for (int row = 0; row < max_rows; row++)
    {
        printf(BORDER_VERTICAL_LINE);
        for (int i = 0; i < columns_num; i++)
        {
            printf(" ");
            if (str[i][row] != NULL)
            {
                text_print_padded(str[i][row], col_max_widths[i]);
            }
            else
            {
                text_print_padded("", col_max_widths[i]);
            }
            printf(" %s", BORDER_VERTICAL_LINE);
        }
        printf("\n");
    }

    // 5. 打印下边框
    for (int i = 0; i < columns_num; i++)
    {
        printf(BORDER_PLUS);
        for (int j = 0; j < col_max_widths[i] + 2; j++)
        {
            printf(BORDER_MINUS);
        }
    }
    printf("%s\n", BORDER_PLUS);
}