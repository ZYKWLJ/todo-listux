#include "../../include/include.h"
#include <stdbool.h>
// extern KV_ kv;
extern C_command command;
extern S_setting setting;
T_current_date string2date(const char *date_str)
{
    // 分配并初始化内存
    T_current_date date = (T_current_date)checked_malloc(sizeof(*date));
    memset(date, 0, sizeof(*date));

    // 设置默认日期类型为天(D)
    date->date_type = D;

    if (date_str == NULL || strlen(date_str) < 19)
    {
        fprintf(stderr, "Invalid date string format\n");
        return date;
    }

    // 格式: "YYYY-MM-DD-HH:MM:SS"
    int count = sscanf(date_str, "%d-%d-%d-%d:%d:%d",
                       &date->year, &date->month, &date->day,
                       &date->hour, &date->minute, &date->second);

    if (count != 6)
    {
        fprintf(stderr, "Failed to parse date string: %s\n", date_str);
        memset(date, 0, sizeof(*date));
    }

    return date;
}
string date2string(T_current_date t)
{
    if (t == NULL)
    {
        // return "None";
        return "-------------------";
    }
    string ret = (string)checked_malloc(sizeof(char) * 100);
    sprintf(ret, "%04d-%02d-%02d-%02d:%02d:%02d",
            t->year, t->month, t->day, t->hour, t->minute, t->second);
    return ret;
}
// 2025-05-07-22:05:16
// -------------------
// 计算两个日期时间字符串的差值并返回结果字符串
// 计算两个日期时间结构体的差值并返回结果字符串
char *date_time_difference(T_current_date date1, T_current_date date2)
{
    if (date1 == NULL || date2 == NULL)
    {
        // return "None";
        return "-------------------";
    }
    struct tm tm1 = {0};
    struct tm tm2 = {0};
    time_t t1, t2;
    double diff;
    int total_seconds;
    int days, hours, minutes, seconds;
    char *result = (char *)malloc(100 * sizeof(char));
    if (result == NULL)
    {
        perror("内存分配失败");
        return NULL;
    }

    // 将结构体数据填充到 tm 结构体
    tm1.tm_year = date1->year - 1900;
    tm1.tm_mon = date1->month - 1;
    tm1.tm_mday = date1->day;
    tm1.tm_hour = date1->hour;
    tm1.tm_min = date1->minute;
    tm1.tm_sec = date1->second;

    tm2.tm_year = date2->year - 1900;
    tm2.tm_mon = date2->month - 1;
    tm2.tm_mday = date2->day;
    tm2.tm_hour = date2->hour;
    tm2.tm_min = date2->minute;
    tm2.tm_sec = date2->second;

    // 转换为时间戳
    t1 = mktime(&tm1);
    t2 = mktime(&tm2);

    // 计算时间差（秒）
    diff = difftime(t2, t1);
    if (diff < 0)
    {
        diff = -diff;
    }
    total_seconds = (int)diff;

    // 计算天数、小时数、分钟数和秒数
    days = total_seconds / (24 * 60 * 60);
    total_seconds %= (24 * 60 * 60);
    hours = total_seconds / (60 * 60);
    total_seconds %= (60 * 60);
    minutes = total_seconds / 60;
    seconds = total_seconds % 60;

    // 格式化结果字符串
    snprintf(result, 100, "%04d-%02d-%02d-%02d:%02d:%02d", 0, 0, days, hours, minutes, seconds);

    return result;
}
void DB_show_task(T_date date, string prefix)
{
/**
 * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
 */
#define TEST_SHOW
#ifdef TEST_SHOW
    // TODO_PRINT("DB_show_task......prefix=%s\n", prefix);
    FILE *fp = fopen(get_appdata_path(DATE_FILE), "r");
    int total = 0;
    char *line = (char *)checked_malloc(sizeof(char) * 100000);
    while (fgets(line, 100000, fp) != NULL)
    {
        /**
         * data descp: 先截断，在比较
         */
        line[strlen(prefix)] = '\0';
        if (strcmp(line, prefix) == 0)
        {
            total++;
        }
    }
    printf("Tasks for %s (Total: %d):\n", prefix, total);
    fseek(fp, 0, SEEK_SET);
    int index = 0;
            LOG_PRINT("settings before show:\n%s=%s\n%s=%s", setting->color->key, setting->color->value_set, setting->show->key, setting->show->value_set);

    while (fgets(line, 100000, fp) != NULL)
    {

        /// 去除换行符
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
        }

        char part[6][100000] = {0};
        char *token = strtok(line, " ");
        int i = 0;
        while (token != NULL && i < 6)
        {
            strcpy(part[i++], token);
            token = strtok(NULL, " ");
        }
#if 0
        printf("line=%s\n", line);
        for (int j = 0; j < 6; j++)
        {
            printf("part[%d]=%s\n", j, part[j]);
        }
#endif
        if (strcmp(line, prefix) == 0)
        {
            index++;
            const char *color_prefix = "";
            const char *color_suffix = "";
            const char *status = (strcmp(part[2], "1") == 0) ? "[-]" : "[+]";

            if (strcmp(setting->color->value_set, "on") == 0)
            {
                color_prefix = (strcmp(part[2], "1") == 0) ? GREEN
                                                           : RED;
                color_suffix = RESET;
            }

            printf("%s%2d. %s %s%s\n",
                   color_prefix,
                   index,
                   status,
                   part[1],
                   color_suffix);
        }
    }
    free(line);
    fclose(fp);
#endif
}

void DB_add_task(N_node node, T_date date, string prefix)
{
    /**
     * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
     */
    TODO_PRINT("DB_add_task......prefix=%s\n", prefix);

    FILE *fp = fopen(get_appdata_path(DATE_FILE), "r+");
    if (fp == NULL)
    {
        printf("%s open failed", get_appdata_path(DATE_FILE));
        exit(EXIT_FAILURE);
    }
    char line[100000] = {0};
    node->task->add_time = T_current_date_init(NULL);
    node->task->finish_time = NULL;
    node->task->interval = NULL;
    node->task->status = '0';
    /**
     * data descp: 一定是追加到最后的,这个基调确定了就好了,每添加一次,扫盘
     */
    fseek(fp, 0, SEEK_END);
    fprintf(fp, "%s %s %c %s %s %s\n", prefix, node->task->content, node->task->status, date2string(node->task->add_time), date2string(node->task->finish_time), date_time_difference(node->task->finish_time, node->task->add_time));
    fclose(fp);
    DB_show_task(date, prefix);
}

void DB_delete_task(N_node node, T_date date, string prefix)
{
    // TODO_PRINT("DB_delete_task......prefix=%s\n", prefix);

    // 1. 打开原始文件和临时文件
    FILE *fp = fopen(get_appdata_path(DATE_FILE), "r");
    if (fp == NULL)
    {
        printf("%s open failed", get_appdata_path(DATE_FILE));
        exit(EXIT_FAILURE);
    }

    FILE *tmp_fp = tmpfile();
    if (tmp_fp == NULL)
    {
        fclose(fp);
        printf("Failed to create temporary file");
        exit(EXIT_FAILURE);
    }

    char line[100000];
    int index = 0;
    int found = 0;

    // 2. 逐行处理
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // 检查是否匹配前缀
        char temp = line[strlen(prefix)];
        line[strlen(prefix)] = '\0';

        if (strcmp(line, prefix) == 0)
        {
            if (index == node->task->id - 1)
            {
                found = 1;
                // 在行首插入 /
                fputs("/ ", tmp_fp);
            }
            index++;
        }

        // 恢复原始行
        line[strlen(prefix)] = temp;

        // 写入完整行（可能已添加前缀）
        fputs(line, tmp_fp);
    }

    fclose(fp);

    // 3. 检查是否找到
    if (!found)
    {
        fclose(tmp_fp);

        DB_show_task(date, prefix);
        printf("\n");
        COMMAND_ERROR(command, "--task id: %d is not found", node->task->id);
        exit(EXIT_FAILURE);
    }

    // 4. 将临时文件内容写回原文件
    fp = fopen(get_appdata_path(DATE_FILE), "w");
    if (fp == NULL)
    {
        fclose(tmp_fp);
        printf("%s open failed", get_appdata_path(DATE_FILE));
        exit(EXIT_FAILURE);
    }

    rewind(tmp_fp);
    while (fgets(line, sizeof(line), tmp_fp) != NULL)
    {
        fputs(line, fp);
    }

    fclose(tmp_fp);
    fclose(fp);

    // 5. 显示更新后的任务列表
    DB_show_task(date, prefix);
}
// void DB_edit_all_task(N_node node, T_date date, string prefix)
// {
//     /**
//      * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
//      */
//     TODO_PRINT("DB_edit_all_task......prefix=%s\n", prefix);
// }

void DB_edit_all_task(N_node node, T_date date, string prefix)
{
    TODO_PRINT("DB_edit_task_content......prefix=%s\n", prefix);

    // 1. 打开文件
    FILE *fp = fopen(get_appdata_path(DATE_FILE), "r");
    if (fp == NULL)
    {
        printf("%s open failed\n", get_appdata_path(DATE_FILE));
        exit(EXIT_FAILURE);
    }

    // 2. 创建临时文件
    char tmp_file[256];
    snprintf(tmp_file, sizeof(tmp_file), "%s.tmp", get_appdata_path(DATE_FILE));
    FILE *tmp_fp = fopen(tmp_file, "w");
    if (tmp_fp == NULL)
    {
        fclose(fp);
        printf("Failed to create temp file\n");
        exit(EXIT_FAILURE);
    }

    char line[100000];
    bool changed = false;
    int index = 0;
    // 3. 处理每一行
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // 检查是否匹配前缀
        if (strncmp(line, prefix, strlen(prefix)) == 0)
        {
            index++;
            if (index == node->task->id)
            {
                // 解析原有行内容
                char old_prefix[100], old_desc[1000], old_status[10];
                char old_create_time[20], old_complete_time[20], old_duration[20];

                int count = sscanf(line, "%s %s %s %s %s %s",
                                   old_prefix, old_desc, old_status,
                                   old_create_time, old_complete_time, old_duration);

                if (count == 6)
                {
                    // 只替换描述部分，其他保持不变
                    char new_line[100000];
                    snprintf(new_line, sizeof(new_line), "%s %s %s %s %s %s\n",
                             old_prefix,
                             node->task->content, // 新描述
                             old_status,
                             old_create_time,
                             old_complete_time,
                             old_duration);

                    fputs(new_line, tmp_fp);
                    changed = true;
                    continue;
                }
            }
        }
        // 不匹配或解析失败的行原样写入
        fputs(line, tmp_fp);
    }

    fclose(fp);
    fclose(tmp_fp);

    // 4. 替换原文件
    if (changed)
    {
        if (rename(tmp_file, get_appdata_path(DATE_FILE)) != 0)
        {
            printf("Failed to replace file\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        remove(tmp_file);
        printf("No matching tasks found\n");
    }
    DB_show_task(date, prefix);
}
void DB_edit_prefix_task(N_node node, T_date date, string prefix)
{
    TODO_PRINT("DB_edit_task_content......prefix=%s\n", prefix);

    // 1. 打开文件
    FILE *fp = fopen(get_appdata_path(DATE_FILE), "r");
    if (fp == NULL)
    {
        printf("%s open failed\n", get_appdata_path(DATE_FILE));
        exit(EXIT_FAILURE);
    }

    // 2. 创建临时文件
    char tmp_file[256];
    snprintf(tmp_file, sizeof(tmp_file), "%s.tmp", get_appdata_path(DATE_FILE));
    FILE *tmp_fp = fopen(tmp_file, "w");
    if (tmp_fp == NULL)
    {
        fclose(fp);
        printf("Failed to create temp file\n");
        exit(EXIT_FAILURE);
    }

    char line[100000];
    bool changed = false;
    int index = 0;
    // 3. 处理每一行
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // 检查是否匹配前缀
        if (strncmp(line, prefix, strlen(prefix)) == 0)
        {
            index++;
            if (index == node->task->id)
            {
                // 解析原有行内容
                char old_prefix[100], old_desc[1000], old_status[10];
                char old_create_time[20], old_complete_time[20], old_duration[20];

                int count = sscanf(line, "%s %s %s %s %s %s",
                                   old_prefix, old_desc, old_status,
                                   old_create_time, old_complete_time, old_duration);

                if (count == 6)
                {
                    // 只替换描述部分，其他保持不变
                    char new_line[100000];
                    snprintf(new_line, sizeof(new_line), "%s %s %s %s %s %s\n",
                             old_prefix,
                             strcat(old_desc, node->task->content), // 新描述
                             old_status,
                             old_create_time,
                             old_complete_time,
                             old_duration);

                    fputs(new_line, tmp_fp);
                    changed = true;
                    continue;
                }
            }
        }
        // 不匹配或解析失败的行原样写入
        fputs(line, tmp_fp);
    }

    fclose(fp);
    fclose(tmp_fp);

    // 4. 替换原文件
    if (changed)
    {
        if (rename(tmp_file, get_appdata_path(DATE_FILE)) != 0)
        {
            printf("Failed to replace file\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        remove(tmp_file);
        printf("No matching tasks found\n");
    }
    DB_show_task(date, prefix);
}

// void DB_edit_suffix_task(N_node node, T_date date, string prefix)
// {
//     /**
//      * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
//      */
//     TODO_PRINT("DB_edit_suffix_task......prefix=%s\n", prefix);
// }

void DB_edit_suffix_task(N_node node, T_date date, string prefix)
{
    TODO_PRINT("DB_edit_task_content......prefix=%s\n", prefix);

    // 1. 打开文件
    FILE *fp = fopen(get_appdata_path(DATE_FILE), "r");
    if (fp == NULL)
    {
        printf("%s open failed\n", get_appdata_path(DATE_FILE));
        exit(EXIT_FAILURE);
    }

    // 2. 创建临时文件
    char tmp_file[256];
    snprintf(tmp_file, sizeof(tmp_file), "%s.tmp", get_appdata_path(DATE_FILE));
    FILE *tmp_fp = fopen(tmp_file, "w");
    if (tmp_fp == NULL)
    {
        fclose(fp);
        printf("Failed to create temp file\n");
        exit(EXIT_FAILURE);
    }

    char line[100000];
    bool changed = false;
    int index = 0;
    // 3. 处理每一行
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // 检查是否匹配前缀
        if (strncmp(line, prefix, strlen(prefix)) == 0)
        {
            index++;
            if (index == node->task->id)
            {
                // 解析原有行内容
                char old_prefix[100], old_desc[1000], old_status[10];
                char old_create_time[20], old_complete_time[20], old_duration[20];

                int count = sscanf(line, "%s %s %s %s %s %s",
                                   old_prefix, old_desc, old_status,
                                   old_create_time, old_complete_time, old_duration);

                if (count == 6)
                {
                    // 只替换描述部分，其他保持不变
                    char new_line[100000];
                    snprintf(new_line, sizeof(new_line), "%s %s %s %s %s %s\n",
                             old_prefix,
                             strcat(node->task->content, old_desc), // 新描述
                             old_status,
                             old_create_time,
                             old_complete_time,
                             old_duration);

                    fputs(new_line, tmp_fp);
                    changed = true;
                    continue;
                }
            }
        }
        // 不匹配或解析失败的行原样写入
        fputs(line, tmp_fp);
    }

    fclose(fp);
    fclose(tmp_fp);

    // 4. 替换原文件
    if (changed)
    {
        if (rename(tmp_file, get_appdata_path(DATE_FILE)) != 0)
        {
            printf("Failed to replace file\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        remove(tmp_file);
        printf("No matching tasks found\n");
    }
    DB_show_task(date, prefix);
}

void DB_done_task(N_node node, T_date date, string prefix)
{
    TODO_PRINT("DB_done_task......prefix=%s\n", prefix);

    // 1. 打开原始文件
    char *filename = get_appdata_path(DATE_FILE);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("%s open failed\n", filename);
        exit(EXIT_FAILURE);
    }

    // 2. 创建临时文件
    char tmp_filename[256];
    snprintf(tmp_filename, sizeof(tmp_filename), "%s.tmp", filename);
    FILE *tmp_fp = fopen(tmp_filename, "w");
    if (tmp_fp == NULL)
    {
        fclose(fp);
        printf("Failed to create temporary file\n");
        exit(EXIT_FAILURE);
    }

    char line[100000];
    int index = 0;
    bool found = false;

    // 3. 逐行处理
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char original_line[100000];
        strcpy(original_line, line); // 保存原始行

        // 去除换行符
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
        }

        // 检查前缀匹配
        if (strncmp(line, prefix, strlen(prefix)) == 0)
        {
            index++;

            if (index == node->task->id)
            {
                found = true;

                // 解析行内容
                char *parts[6] = {0};
                char *token = strtok(line, " ");
                int i = 0;
                while (token != NULL && i < 6)
                {
                    parts[i++] = token;
                    token = strtok(NULL, " ");
                }

                if (i >= 3)
                { // 确保至少有3个字段
                    // 更新任务状态
                    char new_line[100000];
                    snprintf(new_line, sizeof(new_line), "%s %s %c %s %s %s\n",
                             parts[0],                               // 前缀
                             parts[1],                               // 任务描述
                             '1',                                    // 状态更新为完成
                             parts[3],                               // 创建时间保持不变
                             date2string(T_current_date_init(NULL)), // 完成时间
                             date_time_difference(string2date(parts[3]),
                                                  T_current_date_init(NULL))); // 持续时间

                    fputs(new_line, tmp_fp);
                    continue;
                }
            }
        }

        // 写入未修改的行
        fputs(original_line, tmp_fp);
    }

    fclose(fp);
    fclose(tmp_fp);

    // 4. 检查是否找到任务
    if (!found)
    {
        remove(tmp_filename);
        COMMAND_ERROR(command, "--task id: %d is not found", node->task->id);
        exit(EXIT_FAILURE);
    }

    // 5. 替换原文件
    if (rename(tmp_filename, filename) != 0)
    {
        printf("Failed to replace original file\n");
        exit(EXIT_FAILURE);
    }
    DB_show_task(date, prefix);
}
void DB_toggle_task(N_node node, T_date date, string prefix)
{
    /**
     * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
     */
    TODO_PRINT("DB_toggle_task......prefix=%s\n", prefix);
    TODO_PRINT("DB_done_task......prefix=%s\n", prefix);

    // 1. 打开原始文件
    char *filename = get_appdata_path(DATE_FILE);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("%s open failed\n", filename);
        exit(EXIT_FAILURE);
    }

    // 2. 创建临时文件
    char tmp_filename[256];
    snprintf(tmp_filename, sizeof(tmp_filename), "%s.tmp", filename);
    FILE *tmp_fp = fopen(tmp_filename, "w");
    if (tmp_fp == NULL)
    {
        fclose(fp);
        printf("Failed to create temporary file\n");
        exit(EXIT_FAILURE);
    }

    char line[100000];
    int index = 0;
    bool found = false;

    // 3. 逐行处理
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char original_line[100000];
        strcpy(original_line, line); // 保存原始行

        // 去除换行符
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
        }

        // 检查前缀匹配
        if (strncmp(line, prefix, strlen(prefix)) == 0)
        {
            index++;

            if (index == node->task->id)
            {
                found = true;

                // 解析行内容
                char *parts[6] = {0};
                char *token = strtok(line, " ");
                int i = 0;
                while (token != NULL && i < 6)
                {
                    parts[i++] = token;
                    token = strtok(NULL, " ");
                }

                if (i >= 3)
                { // 确保至少有3个字段
                    // 更新任务状态
                    char new_line[100000];
                    snprintf(new_line, sizeof(new_line), "%s %s %c %s %s %s\n",
                             parts[0],                                 // 前缀
                             parts[1],                                 // 任务描述
                             (strcmp(parts[2], "0") == 0) ? '1' : '0', // 状态更新为完成
                             parts[3],                                 // 创建时间保持不变
                             date2string(T_current_date_init(NULL)),   // 完成时间
                             date_time_difference(string2date(parts[3]),
                                                  T_current_date_init(NULL))); // 持续时间

                    fputs(new_line, tmp_fp);
                    continue;
                }
            }
        }

        // 写入未修改的行
        fputs(original_line, tmp_fp);
    }

    fclose(fp);
    fclose(tmp_fp);

    // 4. 检查是否找到任务
    if (!found)
    {
        remove(tmp_filename);
        COMMAND_ERROR(command, "--task id: %d is not found", node->task->id);
        exit(EXIT_FAILURE);
    }

    // 5. 替换原文件
    if (rename(tmp_filename, filename) != 0)
    {
        printf("Failed to replace original file\n");
        exit(EXIT_FAILURE);
    }
    DB_show_task(date, prefix);
}

void DB_set_config(KV_ kv)
{
    /**
     * data descp: 解析出要查找的任务的日期类型和日期即可，都在date里面，不需要参数node.至于查找的路径，已经被写死了，不用传参！
     */
    TODO_PRINT("DB_set_config......K=%s\tv=%s\n", kv->key, kv->value);
    LOG_PRINT("settings before set:\n%s=%s\n%s=%s", setting->color->key, setting->color->value_set, setting->show->key, setting->show->value_set);
    save_setting(get_appdata_path(SETTING_FILE), kv);
    load_setting(get_appdata_path(SETTING_FILE));
    LOG_PRINT("settings after set:\n%s=%s\n%s=%s", setting->color->key, setting->color->value_set, setting->show->key, setting->show->value_set);
}