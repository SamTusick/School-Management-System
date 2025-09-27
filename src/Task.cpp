//Samuel Tusick
//Task.cpp
//This file defines all functions

#include "../include/Task.h"
#include <iostream>
#include <sqlite3.h>

void addTask(sqlite3* db, std::vector<Task>& tasks)
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

        // Save to DB
        std::string sql = "INSERT INTO tasks (title, type, dueDate, status) VALUES ('" +
       newTask.title + "', '" +
       newTask.type + "', '" +
       newTask.dueDate + "', " +
       (newTask.status ? "1" : "0") + ");";

        char* errMsg = nullptr;
        if (sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg) != SQLITE_OK) {
            std::cerr << "Error inserting task: " << errMsg << std::endl;
            sqlite3_free(errMsg);
            return;
        }

        // Grab the auto-generated ID
        newTask.id = sqlite3_last_insert_rowid(db);

        // Ask for repeat
        std::cout << "Would you like to add another task? (Y/N)" << std::endl;
        std::cin >> repeat;
    }
}

void deleteTask(sqlite3* db, std::vector<Task>& tasks)
{
    // Check for empty vector
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

    int taskId = tasks[deleteChoice - 1].id;
    std::string sql = "DELETE FROM tasks WHERE id = " + std::to_string(taskId) + ";";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg) != SQLITE_OK) {
        std::cerr << "Error deleting task: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return;
    }

    std::cout << "Deleting: " << tasks[deleteChoice - 1].title << std::endl;
    tasks.erase(tasks.begin() + deleteChoice - 1);
}

void updateTask(sqlite3* db, std::vector<Task>& tasks)
{
    // Check for empty vector
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

    int taskId = tasks[updateChoiceTask - 1].id;
    std::string sql = "UPDATE tasks SET "
        "type='" + tasks[updateChoiceTask - 1].type +
        "', title='" + tasks[updateChoiceTask - 1].title +
        "', dueDate='" + tasks[updateChoiceTask - 1].dueDate +
        "' WHERE id=" + std::to_string(taskId) + ";";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg) != SQLITE_OK) {
        std::cerr << "Error updating task: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

}

void changeStatus(sqlite3* db, std::vector<Task>& tasks)
{
    int changeTaskChoice = 0;

    std::cout << "Which task's status would you like to change?\n";
    for (int i = 0; i < tasks.size(); i++)
    {
        std::cout << i + 1 << ". " << tasks[i].title << std::endl;
    }

    std::cin >> changeTaskChoice;
    if (changeTaskChoice < 1 || changeTaskChoice > tasks.size())
    {
        std::cout << "Invalid Choice\n";
        return;
    }

    int newStatus = 0;
    std::cout << "Is this task:\n1. Complete\n2. Incomplete\n";
    std::cin >> newStatus;

    if (newStatus == 1)
    {
        tasks[changeTaskChoice - 1].status = true;
    }
    else if (newStatus == 2)
    {
        tasks[changeTaskChoice - 1].status = false;
    }
    else
    {
        std::cout << "Invalid Task Status!\n";
    }

    int taskId = tasks[changeTaskChoice - 1].id;
    std::string sql = "UPDATE tasks SET status=" +
        std::to_string(tasks[changeTaskChoice - 1].status ? 1 : 0) +
        " WHERE id=" + std::to_string(taskId) + ";";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg) != SQLITE_OK) {
        std::cerr << "Error updating status: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void viewTasks(sqlite3* db, std::vector<Task>& tasks)
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

int callback(void* data, int argc, char** argv, char** azColName) {
    auto* tasks = static_cast<std::vector<Task>*>(data);
    Task t;
    t.id = argv[0] ? std::stoi(argv[0]) : 0;
    t.type = argv[1] ? argv[1] : "";
    t.title = argv[2] ? argv[2] : "";
    t.dueDate = argv[3] ? argv[3] : "";
    t.status = (argv[4] && std::string(argv[4]) == "1");
    tasks->push_back(t);   // <-- THIS WAS MISSING
    return 0;
}

void loadTasks(sqlite3* db, std::vector<Task>& tasks)
{
    tasks.clear();
    const char* sql = "SELECT id, type, title, dueDate, status FROM tasks;";
    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql, callback, &tasks, &errMsg) != SQLITE_OK) {
        std::cerr << "Error loading tasks: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

