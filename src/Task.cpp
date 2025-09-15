//Samuel Tusick
//Task.cpp
//This file defines all functions

#include "../include/Task.h"
#include <iostream>

void addTask(std::vector<Task>& tasks)
{
    char repeat = 'Y';

    while(repeat == 'Y' || repeat == 'y')
    {
        Task newTask;

        // Get Task type
        int tasktype = 0;

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
            std:: cout << "Invalid Task Type!\n" << std::endl;
            break;
        }

        // Get Task tile
        std::string taskTitle;

        std::cout << "What is the task title?\n" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, taskTitle);

        newTask.title = taskTitle;

        // Get Due Date
        std::string taskDueDate;

        std::cout << "When is this task due? (xx/xx/xxxx)" << std::endl;
        std::getline(std::cin, newTask.dueDate);

        newTask.dueDate = taskDueDate;

        // Set completion
        newTask.status = false;

        // Save task
        tasks.push_back(newTask);
        std::cout << "You successfully added " << newTask.title << std::endl;

        // Ask for repeat
        std::cout << "Would you like to add another task? (Y/N)" << std::endl;
        std::cin >> repeat;
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


