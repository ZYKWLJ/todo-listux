// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>
// #include <stdbool.h>

// typedef struct T_time_
// {
//     enum
//     {
//         day,
//         week,
//         month,
//         year,
//     } date_type;
//     int year;
//     int month;
//     int day;
//     int week;
//     int hour;
//     int minute;
//     int second;
// } *T_current_date;

// typedef struct T_task_type_
// {
//     char content[10000000]; // 10MB内容空间
//     char status;            // 完成1，未完成0
//     T_current_date add_time;
//     T_current_date finish_time;
//     T_current_date interval;
//     T_current_date time;
// } *T_task_type;

// // 将日期类型转换为字符
// char date_type_to_char(enum {day, week, month, year} type)
// {
//     switch (type)
//     {
//     case day:
//         return 'd';
//     case week:
//         return 'w';
//     case month:
//         return 'm';
//     case year:
//         return 'y';
//     default:
//         return 'd';
//     }
// }

// // 将日期结构转换为字符串
// void date_to_string(T_current_date date, char *buffer, bool full)
// {
//     if (full)
//     {
//         snprintf(buffer, 32, "%04d.%02d.%02d-%02d:%02d:%02d",
//                  date->year, date->month, date->day,
//                  date->hour, date->minute, date->second);
//     }
//     else
//     {
//         switch (date->date_type)
//         {
//         case day:
//             snprintf(buffer, 32, "%04d.%02d.%02d",
//                      date->year, date->month, date->day);
//             break;
//         case week:
//             snprintf(buffer, 32, "%04d.%02d.%02d",
//                      date->year, date->month, date->week);
//             break;
//         case month:
//             snprintf(buffer, 32, "%04d.%02d",
//                      date->year, date->month);
//             break;
//         case year:
//             snprintf(buffer, 32, "%04d", date->year);
//             break;
//         }
//     }
// }

// // 写入任务到文件
// void write_task(FILE *file, T_task_type task, bool is_deleted)
// {
//     // 写入删除标记
//     if (is_deleted)
//     {
//         fputc('/', file);
//     }

//     // 写入状态和时间类型
//     fprintf(file, "%c%c", task->status, date_type_to_char(task->time->date_type));

//     // 写入时间数据
//     char time_data[32];
//     date_to_string(task->time, time_data, false);
//     fprintf(file, "%s", time_data);

//     // 写入内容
//     fprintf(file, " %s", task->content);

//     // 写入时间信息
//     char add_time[32], finish_time[32], interval[32];
//     date_to_string(task->add_time, add_time, true);
//     date_to_string(task->finish_time, finish_time, true);
//     date_to_string(task->interval, interval, true);

//     fprintf(file, " %s %s %s\n", add_time, finish_time, interval);
// }

// // 从字符串解析日期
// void parse_date(const char *str, T_current_date date, bool full)
// {
//     if (full)
//     {
//         sscanf(str, "%d.%d.%d-%d:%d:%d",
//                &date->year, &date->month, &date->day,
//                &date->hour, &date->minute, &date->second);
//     }
//     else
//     {
//         switch (date->date_type)
//         {
//         case day:
//             sscanf(str, "%d.%d.%d", &date->year, &date->month, &date->day);
//             break;
//         case week:
//             sscanf(str, "%d.%d.%d", &date->year, &date->month, &date->week);
//             break;
//         case month:
//             sscanf(str, "%d.%d", &date->year, &date->month);
//             break;
//         case year:
//             sscanf(str, "%d", &date->year);
//             break;
//         }
//     }
// }

// // 从文件读取任务
// T_task_type read_task(FILE *file)
// {
//     char line[10000050]; // 10MB内容 + 50字节其他信息
//     if (fgets(line, sizeof(line), file) == NULL)
//     {
//         return NULL;
//     }

//     T_task_type task = (T_task_type)malloc(sizeof(struct T_task_type_));
//     if (!task)
//         return NULL;

//     task->time = (T_current_date)malloc(sizeof(struct T_time_));
//     task->add_time = (T_current_date)malloc(sizeof(struct T_time_));
//     task->finish_time = (T_current_date)malloc(sizeof(struct T_time_));
//     task->interval = (T_current_date)malloc(sizeof(struct T_time_));

//     char *ptr = line;

//     // 检查删除标记
//     if (*ptr == '/')
//     {
//         ptr++; // 跳过删除标记
//     }

//     // 读取状态
//     task->status = *ptr++ - '0';

//     // 读取日期类型
//     switch (*ptr++)
//     {
//     case 'd':
//         task->time->date_type = day;
//         break;
//     case 'w':
//         task->time->date_type = week;
//         break;
//     case 'm':
//         task->time->date_type = month;
//         break;
//     case 'y':
//         task->time->date_type = year;
//         break;
//     default:
//         task->time->date_type = day;
//         break;
//     }

//     // 读取时间数据
//     char time_data[32];
//     int i = 0;
//     while (*ptr != ' ' && *ptr != '\0' && i < 31)
//     {
//         time_data[i++] = *ptr++;
//     }
//     time_data[i] = '\0';
//     parse_date(time_data, task->time, false);

//     // 读取内容
//     if (*ptr == ' ')
//         ptr++;
//     char *content_end = strstr(ptr, " 20"); // 查找时间开始位置
//     if (!content_end)
//         content_end = line + strlen(line);

//     size_t content_len = content_end - ptr;
//     if (content_len > 0)
//     {
//         strncpy(task->content, ptr, content_len);
//         task->content[content_len] = '\0';
//         ptr += content_len;
//     }
//     else
//     {
//         task->content[0] = '\0';
//     }

//     // 读取时间信息
//     char time_str[3][32];
//     if (sscanf(ptr, "%31s %31s %31s", time_str[0], time_str[1], time_str[2]) == 3)
//     {
//         parse_date(time_str[0], task->add_time, true);
//         parse_date(time_str[1], task->finish_time, true);
//         parse_date(time_str[2], task->interval, true);
//     }

//     return task;
// }

// // 释放任务内存
// void free_task(T_task_type task)
// {
//     if (task)
//     {
//         free(task->time);
//         free(task->add_time);
//         free(task->finish_time);
//         free(task->interval);
//         free(task);
//     }
// }

// int main()
// {
//     // 创建日任务
//     T_current_date time = (T_current_date)malloc(sizeof(struct T_time_));
//     time->date_type = day;
//     time->year = 2023;
//     time->month = 12;
//     time->day = 25;

//     T_current_date add_time = (T_current_date)malloc(sizeof(struct T_time_));
//     *add_time = (struct T_time_){
//         .date_type = day,
//         .year = 2023,
//         .month = 12,
//         .day = 25,
//         .hour = 10,
//         .minute = 30,
//         .second = 0};

//     T_task_type task = (T_task_type)malloc(sizeof(struct T_task_type_));

//     task->status = 0;
//     task->time = time;
//     task->add_time = add_time;
//     task->finish_time = (T_current_date)malloc(sizeof(struct T_time_));
//     task->interval = (T_current_date)malloc(sizeof(struct T_time_));
//     strcpy(task->content, "圣诞节完成项目部署");

//     // 写入文件
//     FILE *file = fopen("tasks.dat", "a");
//     if (file)
//     {
//         write_task(file, task, false); // 未删除任务
//         fclose(file);
//     }

//     // 读取文件
//     file = fopen("tasks.dat", "r");
//     if (file)
//     {
//         T_task_type loaded_task;
//         while ((loaded_task = read_task(file)) != NULL)
//         {
//             if (loaded_task->status != 2)
//             { // 过滤已删除
//                 printf("Task: %s\n", loaded_task->content);
//                 printf("Type: %d\n", loaded_task->time->date_type);
//             }
//             free_task(loaded_task);
//         }
//         fclose(file);
//     }

//     // 清理
//     free_task(task);
//     return 0;
// }