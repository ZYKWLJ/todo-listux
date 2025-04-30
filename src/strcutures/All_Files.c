// 基于此，请你纠正这段代码// #include "All_Files.h"

#include "../../include/include.h"
// #include "All_Files.h"
// #include "All_Files.h"

void set_all_files(All_Files *all_files, Total_File_Year_Date *total_file_year_date, Setting *setting)
{
    if (all_files == NULL)
    {
        LOG_PRINT("all_files is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (total_file_year_date == NULL)
    {
        LOG_PRINT("total_file_year_date is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (setting == NULL)
    {
        LOG_PRINT("setting is NULL\n");
        exit(EXIT_FAILURE);
    }
    all_files->total_file_year_date = total_file_year_date;
    all_files->setting = setting;
}

void free_all_files(All_Files *all_files)
{
    if (all_files == NULL)
    {
        LOG_PRINT("all_files is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (all_files->total_file_year_date == NULL)
    {
        LOG_PRINT("all_files->total_file_year_date is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (all_files->setting == NULL)
    {
        LOG_PRINT("all_files->setting is NULL\n");
        exit(EXIT_FAILURE);
    }
    free_total_file_year_date(all_files->total_file_year_date);
    free(all_files->setting);
    free(all_files);
}

void init_all_files(All_Files *all_files, Date *date)
{
    // 加载对应年份下的文件

    Total_File_Year_Date *total_file_year_date = (Total_File_Year_Date *)malloc(sizeof(Total_File_Year_Date));
    {
        int YEAR_OF_MONTH_COUNT = 12;
        Day_Year_Task *day_year_task = (Day_Year_Task *)malloc(sizeof(Day_Year_Task));
        {
            // 初始化第i月
            TaskMonth *months = (TaskMonth *)malloc(sizeof(TaskMonth) * YEAR_OF_MONTH_COUNT);
            for (int i = 0; i < YEAR_OF_MONTH_COUNT; i++)
            {
                months[i].num_days = get_month_of_day(date->year, i);
                months[i].month = i;
                // 初始化第i月的第j天
                TaskDay *days = (TaskDay *)malloc(sizeof(TaskDay) * months->num_days);
                for (int j = 0; j < months->num_days; j++)
                {

                    Task *task = (Task *)malloc(sizeof(Task) * DEFALUT_DAY_TASK_SIZE);
                    //  初始化第i月的第j天的第k个任务
                    for (int k = 0; k < DEFALUT_DAY_TASK_SIZE; k++)
                    {
                        task[k].content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
                        sprintf(task[k].content, "content_%d", k);
                        // LOG_PRINT("day task[%d] is assigned over......\n", k);
                    }
                    days[j].task = task;
                    days[j].size = DEFALUT_DAY_TASK_SIZE;
                    days[j].capacity = DEFALUT_DAY_TASK_SIZE;
                    // LOG_PRINT("day task is assigned over......\n");
                }
                months[i].days = days;
                // LOG_PRINT("day month[%d] is assigned over......\n", i);
            }
            day_year_task->year = date->year;
            day_year_task->months = months;
        }
        LOG_PRINT("%s", "day_year_task malloc passed!!\n");
        total_file_year_date->day_year_task = day_year_task;
        // print_day_year_task(day_year_task);
        // exit(0);
        Week_Year_Task *week_year_task = (Week_Year_Task *)malloc(sizeof(Week_Year_Task));
        {
            // 12个月
            Week_Month_Task *months = (Week_Month_Task *)malloc(sizeof(Week_Month_Task) * YEAR_OF_MONTH_COUNT);
            for (int i = 0; i < YEAR_OF_MONTH_COUNT; i++)
            {
                int MONTH_OF_WEEK_COUNT = 4;

                // 每个月每周
                Week_Task *week_task = (Week_Task *)malloc(sizeof(Week_Task) * DEFALUT_WEEK_TASK_SIZE);

                for (int j = 0; j < MONTH_OF_WEEK_COUNT /*初始化这4周*/; j++)
                { // 初始化第i月的第j个周第k个任务
                    Task *task = (Task *)malloc(sizeof(Task) * DEFALUT_WEEK_TASK_SIZE);
                    for (int k = 0; k < DEFALUT_WEEK_TASK_SIZE; k++)
                    {
                        task[k].content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
                        sprintf(task[k].content, "content_%d", k);
                        // LOG_PRINT("week task[%d] is assigned over......\n", k);
                    }
                    week_task[j].task = task;
                    week_task[j].size = DEFALUT_WEEK_TASK_SIZE;
                    week_task[j].capacity = DEFALUT_WEEK_TASK_SIZE;
                    // LOG_PRINT("week_task is assigned over......\n");
                }
                months[i].week_tasks = week_task;
                months[i].num_week = MONTH_OF_WEEK_COUNT;
                months[i].month = i;
                // LOG_PRINT("week month[%d] is assigned over......\n", i);
            }
            week_year_task->year = date->year;
            week_year_task->months = months;
        }
        LOG_PRINT("%s", "week_year_task malloc passed!!\n");
        // print_week_year_task(week_year_task);
        total_file_year_date->week_year_task;
        Month_Year_Task *month_year_task = (Month_Year_Task *)malloc(sizeof(Month_Year_Task));
        {
            Month_Task *months = (Month_Task *)malloc(sizeof(Month_Task) * YEAR_OF_MONTH_COUNT);

            for (int i = 0; i < YEAR_OF_MONTH_COUNT; i++)
            {
                Task *task = (Task *)malloc(sizeof(Task) * DEFALUT_MONTH_TASK_SIZE);
                for (int j = 0; j < DEFALUT_MONTH_TASK_SIZE; j++)
                {
                    task[j].content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
                    sprintf(task[j].content, "content_%d", i);
                    task[j].is_done = 0;
                    // LOG_PRINT("month task[%d] is assigned over......\n", j);
                }
                months[i].task = task;
                months[i].size = DEFALUT_MONTH_TASK_SIZE;
                months[i].month = i;
                months[i].capacity = DEFALUT_MONTH_TASK_SIZE;
                // LOG_PRINT("week month[%d] is assigned over......\n", i);
            }
            month_year_task->year = date->year;
            month_year_task->months = months;
        }
        // LOG_PRINT("%s", "month_year_task malloc passed!!\n");
        // print_month_year_task(month_year_task);
        total_file_year_date->month_year_task = month_year_task;
        Year_Task *year_task = (Year_Task *)malloc(sizeof(Year_Task));
        {
            Task *task = (Task *)malloc(sizeof(Task) * DEFALUT_YEAR_TASK_SIZE);
            for (int i = 0; i < DEFALUT_YEAR_TASK_SIZE; i++)
            {
                task[i].content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
                sprintf(task[i].content, "content_%d", i);
                task[i].is_done = 0;
                // LOG_PRINT("year task[%d] is assigned over......\n", i);
            }
            year_task->task = task;
            year_task->size = DEFALUT_YEAR_TASK_SIZE;
            year_task->capacity = DEFALUT_YEAR_TASK_SIZE;
            year_task->year = date->year;
        }
        // LOG_PRINT("%s", "year_task malloc passed!!\n");
        // print_year_task(year_task);
        // exit(0);
        total_file_year_date->year_task = year_task;
    }
    // all_files->total_file_year_date = total_file_year_date;
    LOG_PRINT("%s", "total_file_year_date malloc passed!!\n");

    Setting *setting = (Setting *)malloc(sizeof(Setting));
    {
        SettingItem *color = (SettingItem *)malloc(sizeof(SettingItem));
        {
            char *key = (char *)malloc(sizeof(char) * 10);
            char *value_set = (char *)malloc(sizeof(char) * 10);
            char **value_allow = (char **)malloc(sizeof(char *) * 10);
            for (int i = 0; i < 10; i++)
            {
                value_allow[i] = (char *)malloc(sizeof(char) * 10);
            }
            color->key = key;
            color->value_set = value_set;
            color->value_allow = value_allow;
        }
        SettingItem *show = (SettingItem *)malloc(sizeof(SettingItem));
        {
            char *key = (char *)malloc(sizeof(char) * 10);
            char *value_set = (char *)malloc(sizeof(char) * 10);
            char **value_allow = (char **)malloc(sizeof(char *) * 10);
            for (int i = 0; i < 10; i++)
            {
                value_allow[i] = (char *)malloc(sizeof(char) * 10);
            }
            show->key = key;
            show->value_set = value_set;
            show->value_allow = value_allow;
        }
        setting->color = color;
        setting->show = show;
        LOG_PRINT("%s", "Begin to malloc setting\n");
        // 在这里，设置就已经默认配置了！
        LOG_PRINT("%s", "Begin to init setting.......\n");

        LOG_PRINT("%s", " set_settings_init(setting) malloc passed!!\n");
    }
    // 默认开启颜色
    all_files->setting->color->value_set = strdup("on");
    set_all_files(all_files, total_file_year_date, setting);
    LOG_PRINT("%s", " set_all_files malloc passed!!\n");
}