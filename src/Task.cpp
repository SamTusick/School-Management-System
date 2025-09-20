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
        std::cin.ignore();
        std::getline(std::cin, taskDueDate);

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


void deleteTask(std::vector<Task>& tasks)
{
    if (tasks.size() == 0)
        {
            std::cout << "There is no task to delete!\n";
            return;
        }

    std::cout << "What task would you like to delete?\n";
    for (int i = 0; i < tasks.size(); i++)
    {
        std::cout << i + 1 << ". " << tasks[i].title << std::endl;
    }

    int deleteChoice = 0;
    std::cin >> deleteChoice;

    if (deleteChoice < 1 || deleteChoice > tasks.size())
    {
        std::cout << "Invalid Choice\n";
        return;
    }

    std::cout << "Deleting: " << tasks[deleteChoice - 1].title << std::endl;
    tasks.erase(tasks.begin() + deleteChoice - 1);
}

void updateTask(std::vector<Task>& tasks)
{
    if (tasks.size() == 0)
    {
        std::cout << "There is no task to update!\n";
        return;
    }

    std::cout << "What task would you like to update?\n";
    for (int i = 0; i < tasks.size(); i++)
    {
        std::cout << i + 1 << ". " << tasks[i].title << std::endl;
    }

    int updateChoiceTask = 0;
    std::cin >> updateChoiceTask;

    if (updateChoiceTask < 1 || updateChoiceTask > tasks.size())
    {
        std::cout << "Invalid Choice\n";
        return;
    }

    int updateChoicePart = 0;
    std::cout << "What would you like to update?\n1. Type\n2. Title\n3. Due Date\n";
    std::cin >> updateChoicePart;

    if (updateChoicePart < 1 || updateChoicePart > 3)
    {
        std::cout << "Invalid Choice\n";
        return;
    }

    switch (updateChoicePart)
    {
    case 1:
        {
            int newType = 0;

            std::cout << "What is the new type of your task?\n" << "1. Homework\n" <<
                "2. Quiz\n" << "3. Exam\n" << "4. Other\n" << std::endl;
            std::cin >> newType;


            switch (newType)
            {
            case 1:
                tasks[updateChoiceTask - 1].type = "Homework";
                break;

            case 2:
                tasks[updateChoiceTask - 1].type = "Quiz";
                break;

            case 3:
                tasks[updateChoiceTask - 1].type = "Exam";
                break;

            case 4:
                tasks[updateChoiceTask - 1].type = "Other";
                break;

            default:
                std:: cout << "Invalid Task Type!\n" << std::endl;
                break;
            }
            break;
        }
        case 2:
        {
            std::string newTitle;
            std::cout << "What is the new type for the task?\n";
            std::cin.ignore();
            std::getline(std::cin, newTitle);
            tasks[updateChoiceTask - 1].title = newTitle;
            break;
        }
        case 3:
        {
            std::string newDate;
            std::cout << "What is the new Due Date for the task?\n";
            std::cin.ignore();
            std::getline(std::cin, newDate);
            tasks[updateChoiceTask - 1].dueDate = newDate;
            break;
        }
        default:
        {
            std::cout << "Invalid Choice\n";
            break;
        }
    }




}
/*
void changeStatus(std::vector<Task>& tasks)
{

}
*/
void viewTasks(std::vector<Task>& tasks)
{

    if(tasks.empty())
    {
        std::cout << "There is no tasks!\n" << std::endl;
    }
    else
    {
        std::cout << "\n--------------------------------------Task List--------------------------------------\n";

        for(int i = 0; i < tasks.size(); i++)
            {
                std::cout << i + 1 << ". " << tasks[i].type << " | "
                << tasks[i].title << " | Due: " << tasks[i].dueDate << " | Status: "
                << (tasks[i].status ? "Complete" : "Incomplete") << std::endl;
            }

        std::cout << "-------------------------------------------------------------------------------------\n";
    }
}

