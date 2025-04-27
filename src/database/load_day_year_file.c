#include "../../include/include.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#include <direct.h> // 用于 _wmkdir
#else
#include <unistd.h>
#include "load_day_year_file.h"
#endif

// #define LOG

void load_day_year_data(int year, Day_Year_Task *day_year_task)
{
    LOG_PRINT("loading data......\n");

    char filename[MAX_PATH];
    const char *base_path = get_appdata_path();

    snprintf(filename, sizeof(filename), "%s%c%d.dat",
             base_path,
#ifdef _WIN32
             '\\',
#else
             '/',
#endif
             year);

    // 创建目录（如果不存在）
    if (create_directory(base_path) != 0)
    {
        fprintf(stderr, "无法创建数据目录: %s\n", base_path);
        return NULL;
    }

    struct stat buffer;
    int exists = (stat(filename, &buffer) == 0);
    FILE *file;
    if (!exists)
    {
        file = fopen(filename, "w");
        if (file)
        {
            fclose(file);
        }
    }

    Day_Year_Task *year_tasks = init_year_tasks(year);
    if (!year_tasks)
    {
        return NULL;
    }

    file = fopen(filename, "r");
    if (file)
    {
        // 检查文件是否为空
        if (fseek(file, 0, SEEK_END) == 0)
        {
            long file_size = ftell(file);
            if (file_size == 0)
            {
                fclose(file);
                return year_tasks;
            }
            fseek(file, 0, SEEK_SET);
        }

        int loaded_year;
        if (fscanf(file, "%d", &loaded_year) != 1)
        {
            LOG_PRINT("Failed to read year from file.\n");
            fclose(file);
            free_year_tasks(year_tasks);
            return NULL;
        }
        // 消耗换行符
        fgetc(file);

        if (loaded_year != year)
        {
            LOG_PRINT("Year in file does not match requested year.\n");
            fclose(file);
            free_year_tasks(year_tasks);
            return NULL;
        }

        for (int m = 0; m < 12; m++)
        {
            TaskMonth *month_tasks = &year_tasks->months[m];
            for (int d = 0; d < month_tasks->num_days; d++)
            {
                TaskDay *day_tasks = &month_tasks->days[d];
                int month_num, day_num, size, capacity;

                // 检查文件结束
                if (feof(file))
                {
                    // 文件正常结束，没有更多数据
                    fclose(file);
                    return year_tasks;
                }

                // 读取4个整数
                int read_count = fscanf(file, "%d %d %d %d", &month_num, &day_num, &size, &capacity);
                LOG_PRINT("month_num=%d,day_num=%d,size=%d,capacity=%d\n", month_num, day_num, size, capacity);

                if (read_count != 4)
                {
                    // 可能是文件结束或格式错误
                    if (feof(file))
                    {
                        // 文件正常结束
                        fclose(file);
                        return year_tasks;
                    }
                    else
                    {
                        LOG_PRINT("Failed to read day tasks information from file.\n");
                        fclose(file);
                        free_year_tasks(year_tasks);
                        return NULL;
                    }
                }
                // 消耗换行符
                fgetc(file);

                // 检查并扩展容量
                while (size > day_tasks->capacity)
                {
                    expand_capacity(day_tasks);
                }

                day_tasks->size = size;
                day_tasks->capacity = capacity;

                for (int t = 0; t < size; t++)
                {
                    char line[1000000]; // 开的足够大，不怕读取不了！
                    if (fgets(line, sizeof(line), file) == NULL)
                    {
                        LOG_PRINT("Failed to read task line from file.\n");
                        fclose(file);
                        free_year_tasks(year_tasks);
                        return NULL;
                    }

                    // 移除末尾的换行符
                    line[strcspn(line, "\n")] = '\0';

                    // 查找最后一个空格来分隔任务内容和完成状态
                    char *last_space = strrchr(line, ' ');
                    if (last_space == NULL)
                    {

                        LOG_PRINT("Invalid task format: %s\n", line);
                        fclose(file);
                        free_year_tasks(year_tasks);
                        return NULL;
                    }

                    // 分隔任务内容和完成状态
                    *last_space = '\0';
                    char *task_content = line;
                    char *done_str = last_space + 1;

                    // 分配任务内存
                    size_t content_length = strlen(task_content);
                    if (content_length >= DEFALUT_TASK_CHAR_LENGTH)
                    {
                        char *new_task_str = (char *)realloc(day_tasks->task[t].task,
                                                             (content_length + 1) * sizeof(char));
                        if (new_task_str == NULL)
                        {
                            LOG_PRINT("Memory allocation failed.\n");
                            fclose(file);
                            free_year_tasks(year_tasks);
                            return NULL;
                        }
                        day_tasks->task[t].task = new_task_str;
                    }
                    strcpy(day_tasks->task[t].task, task_content);
                    day_tasks->task[t].is_done = atoi(done_str);
                }
            }
        }
        fclose(file);
    }
#ifdef LOG
    LOG_PRINT("Data loaded successfully.\n");
#endif
    return year_tasks;
}

// int main(){
//     for(int i=0;i<1000;i++)
//     printf("d");
//     return 0;
// }
