//Samuel Tusick
//Task.cpp
//This file defines all functions

#include "../include/Task.h"
#include <iostream>

void addTask(std::vector<Task>& tasks)
{
    int tasktype = 0;
    Task newTask;

    std::cout << "What is the type of your task?\n" << "1. Homework\n" <<
        "2. Quiz\n" << "3. Exam\n" << "4. Other\n" << std::endl;
    std::cin >> tasktype;

    switch (tasktype)
    {
        case 1:
            newTask.type = "Homework";
            break;

        case 2:
            newTask.type = "Quiz";
            break;

        case 3:
            newTask.type = "Exam";
            break;

        case 4:
            newTask.type = "Other";
            break;

    default:
            std:: cout << "Invalid Task Type!" << std::endl;
            break;


    }


}

/*
void deleteTask(std::vector<Task>& tasks)
{

}

void updateTask(std::vector<Task>& tasks)
{

}

void changeStatus(std::vector<Task>& tasks)
{

}

void viewTasks(std::vector<Task>& tasks)
{

}
*/


