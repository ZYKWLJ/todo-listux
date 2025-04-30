#include "../../include/include.h"
// 打印任务信息
void print_task(Task *task, int size) {
    for (int i = 0; i < size; i++) {
        printf("  Task %d: Content: %s, Is Done: %s\n", i + 1, task[i].content, task[i].is_done ? "Yes" : "No");
    }
}

// 打印单日任务信息
void print_task_day(TaskDay *task_day) {
    printf("  Day Task: Size: %d, Capacity: %d\n", task_day->size, task_day->capacity);
    print_task(task_day->task, task_day->size);
}

// 打印单月任务信息
void print_task_month(TaskMonth *task_month) {
    printf("Month: %d, Num Days: %d\n", task_month->month, task_month->num_days);
    for (int i = 0; i < task_month->num_days; i++) {
        printf("  Day %d:\n", i + 1);
        print_task_day(&task_month->days[i]);
    }
}

// 打印当年每日任务信息
void print_day_year_task(Day_Year_Task *day_year_task) {
    printf("Year: %d (Daily Tasks)\n", day_year_task->year);
    for (int i = 0; i < 12; i++) {
        printf(" Month %d:\n", i + 1);
        print_task_month(&day_year_task->months[i]);
    }
}

// 打印单月任务信息（用于月任务）
void print_month_task(Month_Task *month_task) {
    printf("  Month Task (Month %d): Size: %d, Capacity: %d\n", month_task->month, month_task->size, month_task->capacity);
    print_task(month_task->task, month_task->size);
}

// 打印当年每月任务信息
void print_month_year_task(Month_Year_Task *month_year_task) {
    printf("Year: %d (Monthly Tasks)\n", month_year_task->year);
    for (int i = 0; i < 12; i++) {
        print_month_task(&month_year_task->months[i]);
    }
}

// 打印单周任务信息
void print_week_task(Week_Task *week_task) {
    printf("  Week Task: Size: %d, Capacity: %d\n", week_task->size, week_task->capacity);
    print_task(week_task->task, week_task->size);
}

// 打印单月周任务信息
void print_week_month_task(Week_Month_Task *week_month_task) {
    printf("Month: %d, Week: %d\n", week_month_task->month, week_month_task->num_week);
    print_week_task(week_month_task->week_tasks);
}

// 打印当年每周任务信息
void print_week_year_task(Week_Year_Task *week_year_task) {
    printf("Year: %d (Weekly Tasks)\n", week_year_task->year);
    for (int i = 0; i < 12; i++) {
        printf(" Month %d:\n", i + 1);
        print_week_month_task(&week_year_task->months[i]);
    }
}

// 打印当年任务信息
void print_year_task(Year_Task *year_task) {
    printf("Year: %d (Yearly Tasks): Size: %d, Capacity: %d\n", year_task->year, year_task->size, year_task->capacity);
    printf("Year: %d (Yearly Tasks): Size: %d, Capacity: %d\n", year_task->year, year_task->size, year_task->capacity);
    printf("Year: %d (Yearly Tasks): Size: %d, Capacity: %d\n", year_task->year, year_task->size, year_task->capacity);
    print_task(year_task->task, year_task->size);
}

// 打印设置项信息
void print_setting_item(SettingItem *setting_item) {
    if (setting_item == NULL) return;
    printf("  Key: %s\n", setting_item->key);
    printf("  Value Set: %s\n", setting_item->value_set);
    printf("  Allowed Values: ");
    for (int i = 0; setting_item->value_allow[i] != NULL; i++) {
        printf("%s ", setting_item->value_allow[i]);
    }
    printf("\n");
}

// 打印设置信息
void print_setting(Setting *setting) {
    if (setting == NULL) return;
    printf("Setting Information:\n");
    printf("Color Setting:\n");
    print_setting_item(setting->color);
    printf("Show Setting:\n");
    print_setting_item(setting->show);
}

// 打印全年任务数据信息
void print_total_file_year_date(Total_File_Year_Date *total_file_year_date) {
    if (total_file_year_date->day_year_task) {
        print_day_year_task(total_file_year_date->day_year_task);
    }
    if (total_file_year_date->month_year_task) {
        print_month_year_task(total_file_year_date->month_year_task);
    }
    if (total_file_year_date->week_year_task) {
        print_week_year_task(total_file_year_date->week_year_task);
    }
    if (total_file_year_date->year_task) {
        print_year_task(total_file_year_date->year_task);
    }
}

// 打印所有文件信息
void print_all_files(All_Files *all_files) {
    if (all_files->total_file_year_date) {
        print_total_file_year_date(all_files->total_file_year_date);
    }
    if (all_files->setting) {
        print_setting(all_files->setting);
    }
}
