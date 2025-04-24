#include "../include/include.h"
int main() {
    int year, month, day;
    get_current_date(&year, &month, &day);

    Task*** task_year = init_year_tasks(year);
    load_data(year, task_year);

    while (1) {
        printf("\n1. Display current date tasks\n");
        printf("2. Add task\n");
        printf("3. Delete task\n");
        printf("4. Modify task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // 消耗掉换行符

        switch (choice) {
            case 1:
                display_current_date_tasks(year, month, day, task_year);
                break;
            case 2:
                add_task(year, month, day, task_year);
                break;
            case 3:
                printf("Enter task index to delete: ");
                int delete_index;
                scanf("%d", &delete_index);
                getchar(); // 消耗掉换行符
                delete_task(year, month, day, task_year, delete_index);
                break;
            case 4:
                printf("Enter task index to modify: ");
                int modify_index;
                scanf("%d", &modify_index);
                getchar(); // 消耗掉换行符
                modify_task(year, month, day, task_year, modify_index);
                break;
            case 5:
                save_data(year, task_year);
                for (int i = 0; i < 12; i++) {
                    for (int j = 0; j < 31; j++) {
                        for (int k = 0; k < 10; k++) {
                            free(task_year[i][j][k].task);
                        }
                        free(task_year[i][j]);
                    }
                    free(task_year[i]);
                }
                free(task_year);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}    