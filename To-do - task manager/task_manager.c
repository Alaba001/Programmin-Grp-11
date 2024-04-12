#define _CRT_SECURE_NO_WARNINGS
#include "task_manager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Group Project- Todo list // Activity Manager
//Prog71985
// Author Names : Daniel Byamungu, Kirston Rozairo, Alaba Ibukunoluwa Adedoyin 
//Todolist interface

// Principal Editor: Daniel Byamungu
// Reviewed by: Alaba Ibukunoluwa 



//Initializing the start of the file - By Daniel 
void init_task_manager(TaskManager* manager) {
    manager->num_tasks = 0;
    load_tasks(manager); 
}

//adding a new task to the list- By Alaba
void add_task(TaskManager* manager) {
    if (manager->num_tasks < MAX_TASKS) {
        Task new_task;
        printf("Enter task title: ");
        getchar(); 
        fgets(new_task.title, MAX_TITLE_LENGTH, stdin);
        printf("Enter task description: ");
        fgets(new_task.description, MAX_DESCRIPTION_LENGTH, stdin);
        manager->tasks[manager->num_tasks++] = new_task;
        printf("Task added successfully!\n");
    }
    else {
        printf("Task limit reached. Cannot add more tasks.\n");
    }
}

//delete the task from the list - By Daniel
void delete_task(TaskManager* manager) {
    if (manager->num_tasks > 0) {
        int index;
        printf("Enter the index of the task to delete (1-%d): ", manager->num_tasks);
        scanf("%d", &index);
        if (index >= 1 && index <= manager->num_tasks) {
            for (int i = index - 1; i < manager->num_tasks - 1; ++i) {
                manager->tasks[i] = manager->tasks[i + 1];
            }
            manager->num_tasks--;
            printf("Task deleted successfully!\n");
        }
        else {
            printf("Invalid task index.\n");
        }
    }
    else {
        printf("No tasks to delete.\n");
    }
}

//updating the task using the task id -By Daniel
void update_task(TaskManager* manager) {
    if (manager->num_tasks > 0) {
        int index;
        printf("Enter the index of the task to update (1-%d): ", manager->num_tasks);
        scanf("%d", &index);
        if (index >= 1 && index <= manager->num_tasks) {
            Task* task = &manager->tasks[index - 1];
            printf("Enter new title: ");
            getchar(); 
            fgets(task->title, MAX_TITLE_LENGTH, stdin);
            printf("Enter new description: ");
            fgets(task->description, MAX_DESCRIPTION_LENGTH, stdin);
            printf("Task updated successfully!\n");
        }
        else {
            printf("Invalid task index.\n");
        }
    }
    else {
        printf("No tasks to update.\n");
    }
}

// Displaying single task by task id -By Kirston 
void display_single_task(TaskManager* manager) {
    if (manager->num_tasks > 0) {
        int index;
        printf("Enter the index of the task to display (1-%d): ", manager->num_tasks);
        scanf("%d", &index);
        if (index >= 1 && index <= manager->num_tasks) {
            printf("Task %d:\n", index);
            printf("Title: %s", manager->tasks[index - 1].title);
            printf("Description: %s", manager->tasks[index - 1].description);
        }
        else {
            printf("Invalid task index.\n");
        }
    }
    else {
        printf("No tasks to display.\n");
    }
}

// Getting tasks from a lower range to a higher range - By Alaba and Daniel
void display_range_tasks(TaskManager* manager) {
    if (manager->num_tasks > 0) {
        int start, end;
        printf("Enter Range Starting point between (1-%d): ", manager->num_tasks);
        scanf("%d", &start);
        printf("Enter Range ending point between (%d-%d): ", start, manager->num_tasks);
        scanf("%d", &end);
        if (start >= 1 && start <= end && end <= manager->num_tasks) {
            printf("Tasks in the range %d-%d:\n", start, end);
            for (int i = start - 1; i < end; ++i) {
                printf("Task %d:\n", i + 1);
                printf("Title: %s", manager->tasks[i].title);
                printf("Description: %s", manager->tasks[i].description);
                printf("\n");
            }
        }
        else {
            printf("Invalid range.\n");
        }
    }
    else {
        printf("No tasks to display.\n");
    }
}

// displaying all tasks to user -By Kirston
void display_all_tasks(TaskManager* manager) {
    if (manager->num_tasks > 0) {
        printf("All Tasks:\n");
        for (int i = 0; i < manager->num_tasks; ++i) {
            printf("Task %d:\n", i + 1);
            printf("Title: %s", manager->tasks[i].title);
            printf("Description: %s", manager->tasks[i].description);
            printf("\n");
        }
    }
    else {
        printf("No tasks to display.\n");
    }
}


//search for a task from the list -By Alaba Ibukunoluwa
bool search_task(TaskManager* manager) {
    char keyword[MAX_DESCRIPTION_LENGTH + 1];
    printf("Enter keyword to search: ");
    // I also tried to Implement that case sensitivity here, it didn't work (Please don't touch)
    getchar(); 
    fgets(keyword, sizeof(keyword), stdin);
    // Remove newline character
    keyword[strcspn(keyword, "\n")] = '\0';

    printf("Searching for tasks containing '%s':\n", keyword);
    bool found = false;
    for (int i = 0; i < manager->num_tasks; i++) {
        if (strstr(manager->tasks[i].title, keyword) != NULL || strstr(manager->tasks[i].description, keyword) != NULL) {
            printf("Task %d:\n", i + 1);
            printf("Title: %s", manager->tasks[i].title);
            printf("Description: %s", manager->tasks[i].description);
            printf("\n");
            found = true;
        }
    }
    return found;
}

// Re_order Fuction to take Two Task Id's And Switch their Places -BY Alaba Ibukunoluwa
void reorder_tasks(TaskManager* manager) {
    if (manager->num_tasks <= 1) {
        printf("Not enough tasks to reorder.\n");
        return;
    }

    int index1, index2;
    printf("Enter the indices of the tasks to swap (1-%d): ", manager->num_tasks);
    scanf("%d %d", &index1, &index2);
    if (index1 >= 1 && index1 <= manager->num_tasks &&
        index2 >= 1 && index2 <= manager->num_tasks) {
        swap_tasks(manager, index1 - 1, index2 - 1);
    }
    else {
        printf("Invalid task indices.\n");
    }
}

The swap function called in the main file, It Makes Use of the reorder function -BY Alaba Ibukunoluwa
void swap_tasks(TaskManager* manager, int index1, int index2) {
    if (index1 >= 0 && index1 < manager->num_tasks &&
        index2 >= 0 && index2 < manager->num_tasks) {
        Task temp = manager->tasks[index1];
        manager->tasks[index1] = manager->tasks[index2];
        manager->tasks[index2] = temp;
        printf("Tasks swapped successfully!\n");
    }
    else {
        printf("Invalid task indices.\n");
    }
}

//saves the list do the text file -By Alaba Ibukunoluwa
void save_tasks(TaskManager* manager) {
    FILE* file = fopen(FILENAME, "w");
    if (file != NULL) {
        fwrite(manager, sizeof(TaskManager), ONE, file);
        fclose(file);
    }
    else {
        printf("Error: Unable to save tasks to file.\n");
    }
}


// loads the list from the text file -By Alaba Ibukunoluwa
void load_tasks(TaskManager* manager) {
    FILE* file = fopen(FILENAME, "r");
    if (file != NULL) {
        fread(manager, sizeof(TaskManager), ONE, file);
        fclose(file);
    }
    else {
        printf("No saved tasks found.....\n");
        printf("creating new file");
    }
}

