#include "../../include/include.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/include.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 检查并创建目录
int create_directory(const char *path)
{
#ifdef _WIN32
    char command[100];
    sprintf(command, "mkdir %s", path);
    return system(command);
#else
    char command[100];
    sprintf(command, "mkdir -p %s", path);
    return system(command);
#endif
}

// 加载数据
// 加载数据
TaskYear *load_data(int year)
{
    // printf("Loading data for year %d.dat...\n", year);
    char filename[100];
#ifdef _WIN32
    snprintf(filename, sizeof(filename), "C:\\%d.dat", year);
    // 检查并创建目录
    if (create_directory("C:\\") != 0)
    {
        printf("Failed to create directory.\n");
        return NULL;
    }
#else
    snprintf(filename, sizeof(filename), "/tmp/tl/%d.dat", year);
    // 检查并创建目录
    if (create_directory("/tmp/tl/") != 0)
    {
        printf("Failed to create directory.\n");
        return NULL;
    }
#endif

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

    TaskYear *year_tasks = init_year_tasks(year);
    if (!year_tasks)
    {
        return NULL;
    }

    file = fopen(filename, "r");
    if (file)
    {
        // 检查文件是否为空
        if (buffer.st_size == 0) {
            fclose(file);
            return year_tasks;
        }

        int loaded_year;
        if (fscanf(file, "%d\n", &loaded_year) != 1) {
            printf("Failed to read year from file.\n");
            fclose(file);
            free_year_tasks(year_tasks);
            return NULL;
        }

        if (loaded_year != year)
        {
            printf("Year in file does not match requested year.\n");
            fclose(file);
            free_year_tasks(year_tasks);
            return NULL;
        }

        for (int m = 0; m < 12; m++)
        {
            TaskMonth *month_tasks = year_tasks->months[m];
            for (int d = 0; d < month_tasks->num_days; d++)
            {
                TaskDay *day_tasks = month_tasks->days[d];
                int month_num, day_num, size, capacity;
                if (fscanf(file, "%d %d %d %d\n", &month_num, &day_num, &size, &capacity) != 4) {
                    printf("Failed to read day tasks information from file.\n");
                    fclose(file);
                    free_year_tasks(year_tasks);
                    return NULL;
                }

                // 检查并扩展容量
                while (size > day_tasks->capacity) {
                    expand_capacity(day_tasks);
                }

                day_tasks->size = size;
                day_tasks->capacity = capacity;

                for (int t = 0; t < size; t++)
                {
                    char line[256];
                    if (fgets(line, sizeof(line), file) == NULL) {
                        printf("Failed to read task line from file.\n");
                        fclose(file);
                        free_year_tasks(year_tasks);
                        return NULL;
                    }
                    char *token = strtok(line, " ");
                    // 检查并扩展任务字符串容量
                    size_t content_length = strlen(token);
                    if (content_length >= MAX_TASK_CHAR_LENGTH) {
                        char *new_task_str = (char *)realloc(day_tasks->task[t].task, (content_length + 1) * sizeof(char));
                        if (new_task_str == NULL) {
                            printf("Memory allocation failed.\n");
                            fclose(file);
                            free_year_tasks(year_tasks);
                            return NULL;
                        }
                        day_tasks->task[t].task = new_task_str;
                    }
                    strcpy(day_tasks->task[t].task, token);
                    token = strtok(NULL, " \n");
                    day_tasks->task[t].is_done = atoi(token);
                }
            }
        }
        fclose(file);
    }
    // printf("Data loaded successfully.\n");
    return year_tasks;
}