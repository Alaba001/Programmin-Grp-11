#pragma once
#define TASK_MANAGER_H
#define MAX_TITLE_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_TASKS 100
#define ONE         1
#define FILENAME        "todoManager.txt"
#include<stdbool.h>

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int num_tasks;
} TaskManager;

void init_task_manager(TaskManager* manager);
void add_task(TaskManager* manager);
void delete_task(TaskManager* manager);
void update_task(TaskManager* manager);
void display_single_task(TaskManager* manager);
void display_range_tasks(TaskManager* manager);
void display_all_tasks(TaskManager* manager);
bool search_task(TaskManager* manager);
void save_tasks(TaskManager* manager);
void load_tasks(TaskManager* manager);
 