#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task_manager.h"
#include "menu.h"

//Group Project- Todo list  // Activity Manager
//Prog71985
// Author Names : Daniel Byamungu, Kirston Rozairo, Alaba Ibukunoluwa Adedoyin 
//Todolist interface

// Principal Editor: Daniel Byamungu
// Reviewed by: Alaba Ibukunoluwa 

int main() {
    TaskManager manager;
    init_task_manager(&manager);
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);
        process_choice(&manager, choice);
    } while (choice != 9);

    return 0;
}