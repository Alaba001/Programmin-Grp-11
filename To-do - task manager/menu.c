#include "menu.h"

//Group Project- Todo list  // Activity Manager
//Prog71985
// Author Names : Daniel Byamungu, Kirston Rozairo, Alaba Ibukunoluwa Adedoyin 
//Todolist interface

// Principal Editor: Daniel Byamungu
// Reviewd By: Alaba Ibukunoluwa

void print_menu() {
    printf("\nTODO LIST MANAGER\n");
    printf("1. Add task\n");
    printf("2. Delete task\n");
    printf("3. Update task\n");
    printf("4. Display single task\n");
    printf("5. Display range of tasks\n");
    printf("6. Display all tasks\n");
    printf("7. Search for a task\n");
    printf("8. Reorder tasks\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
}

void process_choice(TaskManager* manager, int choice) {
    switch (choice) {
    case 1:
        add_task(manager);
        break;
    case 2:
        delete_task(manager);
        break;
    case 3:
        update_task(manager);
        break;
    case 4:
        display_single_task(manager);
        break;
    case 5:
        display_range_tasks(manager);
        break;
    case 6:
        display_all_tasks(manager);
        break;
    case 7:
        if (!search_task(manager)) {
            printf("No tasks found matching the keyword.\n");
        }
        break;
    case 8:
        reorder_tasks(manager);
        break;
    case 9:
        printf("Exiting...\n");
        save_tasks(manager); // Save before exit (I really had a lot of Problem Implementiong this
        // Please no one should move it from here) 
        exit(0);
        break;
    default:
        printf("Invalid choice. Please try again.\n");
    }
}

