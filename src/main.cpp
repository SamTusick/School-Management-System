//Samuel Tusick
//main.cpp
//This program will allow me to input assignments and other important tasks.
//Will be able to view, add, delete, edit, and mark complete tasks
//This file will run the menu and program loop

#include <iostream>
#include <vector>
#include "../include/Task.h"
#include "sqlite3.h"

int main()
{
    sqlite3* db;
    int rc = sqlite3_open("tasks.db", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    } else {
        std::cout << "Opened database successfully!\n" << std::endl;
    }

    // create table if not exists
    const char* sql = "CREATE TABLE IF NOT EXISTS tasks ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "type TEXT NOT NULL,"
                      "title TEXT NOT NULL,"
                      "due_date TEXT,"
                      "status INTEGER NOT NULL);";
    sqlite3_exec(db, sql, 0, 0, 0);

    std::vector<Task> tasks;
    int taskChoice = 0;

    do
    {
        std::cout << "What would you like to do?\n" << "1. Add Task\n"
        << "2. Remove Task\n" << "3. Update Task\n" << "4. Change Status\n"
        << "5. View Task\n" << "6. Exit\n" << std::endl;

        std::cin >> taskChoice;

        switch (taskChoice)
        {
        case 1:
            //Call Add Task Function
                addTask(tasks);
                break;
        case 2:
            //Call Remove Task Function
                deleteTask(tasks);
                break;
        case 3:
            //Call Update Task Function
                updateTask(tasks);
                break;
        case 4:
            //Call Change Status Function
                changeStatus(tasks);
                break;
        case 5:
            //Call View Tasks Function
                viewTasks(tasks);
                break;
        case 6:
            std::cout << "Exiting Program..." << std::endl;
            break;

        default:
            std::cout << "Invalid Choice! Try Again\n" << std::endl;
            break;
        }

    }while(taskChoice!=6);

    std::cout << "Closing database..." << std::endl;
    sqlite3_close(db);
    return 0;

}



