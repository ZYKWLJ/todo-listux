#include "../../include/include.h"
// 显示当前日期的所有数据
void display_current_date_tasks( TaskYear* task_year,int year, int month, int day) {
    // 这里假设存在函数 day_of_year 用于计算日期是一年中的第几天
    // 但函数未给出具体实现，需要你根据实际情况补充
    int doy = day_of_year(year, month, day); 

    // 月份和日期减1是因为数组索引从0开始
    month--;
    day--;

    printf("Date: %d-%d-%d\n", year, month + 1, day + 1);

    // 获取当前日期的任务列表
    TaskDay* current_day_tasks = task_year->months[month].days;

    // 遍历任务列表并打印任务
    for (int i = 0; i < current_day_tasks->size; i++) {
        printf("[%s] %s\n", current_day_tasks->task[i].is_done? "X" : " ", current_day_tasks->task[i].task);
    }
}