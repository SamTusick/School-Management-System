//Samuel Tusick
//Task.h
//This file contains declares all functions and defines struct
#ifndef TASK_H
#define TASK_H
#include <vector>
#include <string>


// Task definintion

struct Task
{
    int type;
    std::string title;
    std::string dueDate;
    bool status;
};


//Functions Declarations

void addTask(std::vector<Task>& tasks);
void deleteTask(std::vector<Task>& tasks);
void updateTask(std::vector<Task>& tasks);
void changeStatus(std::vector<Task>& tasks);
void viewTasks(std::vector<Task>& tasks);

#endif //TASK_H