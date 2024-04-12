#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include"task_manager.h"

void print_menu();
void process_choice(TaskManager* manager, int choice);