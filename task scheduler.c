#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    char name[50];
    char description[100];
    char date[12];
    char time[8];  
    char period[3];  
};

void addTask(struct Task tasks[], int *taskCount) {
    if (*taskCount < 100) {
        struct Task newTask;
        printf("Enter Task Name: ");
        fgets(newTask.name, sizeof(newTask.name), stdin);
        newTask.name[strcspn(newTask.name, "\r\n")] = '\0'; 

        printf("Enter Task Description: ");
        fgets(newTask.description, sizeof(newTask.description), stdin);
        newTask.description[strcspn(newTask.description, "\r\n")] = '\0';  

        printf("Enter Task Date (dd/mm/yyyy): ");
        fgets(newTask.date, sizeof(newTask.date), stdin);
        newTask.date[strcspn(newTask.date, "\r\n")] = '\0';  

        printf("Enter Task Time (hh:mm AM/PM): ");
        fgets(newTask.time, sizeof(newTask.time), stdin);
        newTask.time[strcspn(newTask.time, "\r\n")] = '\0';  
        printf("Enter Task Period (AM/PM): ");
        fgets(newTask.period, sizeof(newTask.period), stdin);
        newTask.period[strcspn(newTask.period, "\r\n")] = '\0';  

        tasks[*taskCount] = newTask;
        (*taskCount)++;

        printf("Task added successfully!\n");
    } else {
        printf("Task Scheduler is full. Cannot add more tasks.\n");
    }
}

void viewTasks(struct Task tasks[], int taskCount) {
    if (taskCount > 0) {
        printf("Task List:\n");
        for (int i = 0; i < taskCount; i++) {
            printf("Task %d:\n", i + 1);
            printf("Name: %s\n", tasks[i].name);
            printf("Description: %s\n", tasks[i].description);
            printf("Date: %s\n", tasks[i].date);
            printf("Time: %s %s\n", tasks[i].time, tasks[i].period);
            printf("----------------------\n");
        }
    } else {
        printf("Task Scheduler is empty.\n");
    }
}

void deleteTask(struct Task tasks[], int *taskCount) {
    if (*taskCount > 0) {
        int taskNumber;
        viewTasks(tasks, *taskCount);
        printf("Enter the task number to delete: ");
        scanf("%d", &taskNumber);

        if (taskNumber >= 1 && taskNumber <= *taskCount) {
            for (int i = taskNumber - 1; i < *taskCount - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            (*taskCount)--;
            printf("Task deleted successfully!\n");
        } else {
            printf("Invalid task number.\n");
        }
    } else {
        printf("Task Scheduler is empty. No task to delete.\n");
    }
}

void editTask(struct Task tasks[], int taskCount) {
    if (taskCount > 0) {
        int taskNumber;
        viewTasks(tasks, taskCount);
        printf("Enter the task number to edit: ");
        scanf("%d", &taskNumber);

        if (taskNumber >= 1 && taskNumber <= taskCount) {
            struct Task editedTask;
            getchar();  

            printf("Enter edited Task Name: ");
            fgets(editedTask.name, sizeof(editedTask.name), stdin);
            editedTask.name[strcspn(editedTask.name, "\r\n")] = '\0';  

            printf("Enter edited Task Description: ");
            fgets(editedTask.description, sizeof(editedTask.description), stdin);
            editedTask.description[strcspn(editedTask.description, "\r\n")] = '\0';  

            printf("Enter edited Task Date (dd/mm/yyyy): ");
            fgets(editedTask.date, sizeof(editedTask.date), stdin);
            editedTask.date[strcspn(editedTask.date, "\r\n")] = '\0';  

            printf("Enter edited Task Time (hh:mm AM/PM): ");
            fgets(editedTask.time, sizeof(editedTask.time), stdin);
            editedTask.time[strcspn(editedTask.time, "\r\n")] = '\0';  
            printf("Enter edited Task Period (AM/PM): ");
            fgets(editedTask.period, sizeof(editedTask.period), stdin);
            editedTask.period[strcspn(editedTask.period, "\r\n")] = '\0';  

            tasks[taskNumber - 1] = editedTask;
            printf("Task edited successfully!\n");
        } else {
            printf("Invalid task number.\n");
        }
    } else {
        printf("Task Scheduler is empty. No task to edit.\n");
    }
}

int main() {
    struct Task tasks[100];
    int taskCount = 0;
    int choice;

    while (1) {
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Edit Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getchar();  
                addTask(tasks, &taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                deleteTask(tasks, &taskCount);
                break;
            case 4:
                editTask(tasks, taskCount);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

