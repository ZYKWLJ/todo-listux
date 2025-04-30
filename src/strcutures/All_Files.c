// #include "All_Files.h"

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
    Total_File_Year_Date *total_file_year_date = (Total_File_Year_Date *)malloc(sizeof(Total_File_Year_Date));
    {

        Day_Year_Task *day_year_task = (Day_Year_Task *)malloc(sizeof(Day_Year_Task));
        {
            TaskMonth *months = (TaskMonth *)malloc(sizeof(TaskMonth));
            {
                TaskDay *days = (TaskDay *)malloc(sizeof(TaskDay));
                {
                    Task *task = (Task *)malloc(sizeof(Task));
                    char *content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
                    set_task(task, content, 0);
                    set_day_tasks(days, 0, task, DEFALUT_DAY_TASK_SIZE);
                    set_day_month_tasks(months, 0, DEFALUT_MONTH_TASK_SIZE, days);
                    set_day_year_tasks(day_year_task, date->year, months);
                }
            }
        }
        LOG_PRINT("%s", "day_year_task malloc passed!!\n");

        Week_Year_Task *week_year_task = (Week_Year_Task *)malloc(sizeof(Week_Year_Task));
        {
            Week_Month_Task *week_month_task = (Week_Month_Task *)malloc(sizeof(Week_Month_Task));

            {
                Week_Task *weeks = (Week_Task *)malloc(sizeof(Week_Task));
                {
                    Task *task = (Task *)malloc(sizeof(Task));
                    char *content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
                    set_task(task, content, 0);
                    set_week_tasks(weeks, 0, DEFALUT_MONTH_TASK_SIZE, task);
                    set_week_month_tasks(week_month_task, date->month, date->week, weeks);
                    set_week_Year_task(week_year_task, date->year, week_month_task);
                }
            }
        }
        LOG_PRINT("%s", "week_year_task malloc passed!!\n");

        Month_Year_Task *month_year_task = (Month_Year_Task *)malloc(sizeof(Month_Year_Task));
        {
            Month_Task *months = (Month_Task *)malloc(sizeof(Month_Task));
            {
                Task *task = (Task *)malloc(sizeof(Task));
                char *content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
                set_task(task, content, 0);
                set_month_month_task(months, date->month, 0, DEFALUT_MONTH_TASK_SIZE, task);
                set_month_month_year_tasks(month_year_task, date->year, months);
            }
        }
        LOG_PRINT("%s", "month_year_task malloc passed!!\n");

        Year_Task *year_task = (Year_Task *)malloc(sizeof(Year_Task));
        {
            Task *task = (Task *)malloc(sizeof(Task));
            char *content = (char *)malloc(sizeof(char) * DEFALUT_TASK_CHAR_LENGTH);
            set_task(task, content, 0);
            set_year_task(year_task, date->year, 0, DEFALUT_YEAR_TASK_SIZE, task);
        }
        LOG_PRINT("%s", "year_task malloc passed!!\n");
    }
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
        set_settings_init(setting);
        LOG_PRINT("%s", " set_settings_init(setting) malloc passed!!\n");
    }
    all_files->setting->color->value_set = strdup("on");
    set_all_files(all_files, total_file_year_date, setting);
    LOG_PRINT("%s", " set_all_files malloc passed!!\n");
}
