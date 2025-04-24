#include "../include/include.h"
// int main() {
//     int year, month, day;
//     get_current_date(&year, &month, &day);

//     Task*** task_year = init_year_tasks(year);
//     load_data(year, task_year);

//     while (1) {
//         printf("\n1. Display current date tasks\n");
//         printf("2. Add task\n");
//         printf("3. Delete task\n");
//         printf("4. Modify task\n");
//         printf("5. Exit\n");
//         printf("Enter your choice: ");
//         int choice;
//         scanf("%d", &choice);
//         getchar(); // 消耗掉换行符

//         switch (choice) {
//             case 1:
//                 display_current_date_tasks(year, month, day, task_year);
//                 break;
//             case 2:
//                 add_task(year, month, day, task_year);
//                 break;
//             case 3:
//                 printf("Enter task index to delete: ");
//                 int delete_index;
//                 scanf("%d", &delete_index);
//                 getchar(); // 消耗掉换行符
//                 delete_task(year, month, day, task_year, delete_index);
//                 break;
//             case 4:
//                 printf("Enter task index to modify: ");
//                 int modify_index;
//                 scanf("%d", &modify_index);
//                 getchar(); // 消耗掉换行符
//                 modify_task(year, month, day, task_year, modify_index);
//                 break;
//             case 5:
//                 save_data(year, task_year);
//                 for (int i = 0; i < 12; i++) {
//                     for (int j = 0; j < 31; j++) {
//                         for (int k = 0; k < 10; k++) {
//                             free(task_year[i][j][k].task);
//                         }
//                         free(task_year[i][j]);
//                     }
//                     free(task_year[i]);
//                 }
//                 free(task_year);
//                 return 0;
//             default:
//                 printf("Invalid choice.\n");
//         }
//     }

//     return 0;
// }    


int main(int argc, char *argv[]) {
    int year, month, day;
    get_current_date(&year, &month, &day);

    Task*** task_year = init_year_tasks(year);
    load_data(year, task_year);

    if (argc < 2) {
        // 如果没有提供足够的命令行参数，显示帮助信息
        printf("Usage: tl [command] [arguments]\n");
        printf("Commands:\n");
        printf("  display    Display current date tasks\n");
        printf("  add        Add a new task\n");
        printf("  delete     Delete a task (Usage: tl delete <task_index>)\n");
        printf("  modify     Modify a task (Usage: tl modify <task_index>)\n");
        printf("  help       Show this help message\n");
        save_data(year, task_year);
        return 1;
    }

    // 解析命令行参数并调用相应的处理函数
    if (strcmp(argv[1], "display") == 0) {
        display_current_date_tasks(year, month, day, task_year);
    } else if (strcmp(argv[1], "add") == 0) {
        add_task(year, month, day, task_year);
    } else if (strcmp(argv[1], "delete") == 0) {
        if (argc!= 3) {
            printf("Usage: tl delete <task_index>\n");
            save_data(year, task_year);
            return 1;
        }
        int delete_index = atoi(argv[2]);
        delete_task(year, month, day, task_year, delete_index);
    } else if (strcmp(argv[1], "modify") == 0) {
        if (argc!= 3) {
            printf("Usage: tl modify <task_index>\n");
            save_data(year, task_year);
            return 1;
        }
        int modify_index = atoi(argv[2]);
        modify_task(year, month, day, task_year, modify_index);
    } else if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        printf("Usage: tl [command] [arguments]\n");
        printf("Commands:\n");
        printf("  display    Display current date tasks\n");
        printf("  add        Add a new task\n");
        printf("  delete     Delete a task (Usage: tl delete <task_index>)\n");
        printf("  modify     Modify a task (Usage: tl modify <task_index>)\n");
        printf("  help       Show this help message\n");
    } else {
        printf("Unknown command: %s\n", argv[1]);
        printf("Usage: tl [command] [arguments]\n");
        printf("Commands:\n");
        printf("  display    Display current date tasks\n");
        printf("  add        Add a new task\n");
        printf("  delete     Delete a task (Usage: tl delete <task_index>)\n");
        printf("  modify     Modify a task (Usage: tl modify <task_index>)\n");
        printf("  help       Show this help message\n");
    }

    save_data(year, task_year);

    return 0;
}