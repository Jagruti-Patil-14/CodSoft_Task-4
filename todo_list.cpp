#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;
struct Task 
{
    string task_name;
    bool completed;
    Task(string name) : task_name(name), completed(false) {}
};
class TodoList 
{
private:
    vector<Task> tasks;
public:
    void addTask(const string& task_name)
    {
        tasks.push_back(Task(task_name));
        cout << "Task added successfully.\n";
    }
    void viewTasks() 
    {
        if (tasks.empty()) 
        {
            cout << "No tasks in the list.\n";
        }
        else 
        {
            cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) 
            {
                cout << i + 1 << ". " << tasks[i].task_name << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl;
            }
        }
    }
    void markTaskCompleted(size_t index) 
    {
        if (index >= 1 && index <= tasks.size()) 
        {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed.\n";
        } 
        else 
        {
            cout << "Invalid task index.\n";
        }
    }
    void removeTask(size_t index) 
    {
        if (index >= 1 && index <= tasks.size()) 
        {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed successfully.\n";
        }
        else
        {
            cout << "Invalid task index.\n";
        }
    }
};
int main() 
{
    TodoList todoList;
    int choice;
    string taskDescription;
    size_t index;

    while (true) 
    {
        cout << "\nWELCOME TO TODO LIST MANAGER\n";
        cout << "****** MENU ******\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) 
        {
            case 1:
                cout << "Enter task : ";
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todoList.markTaskCompleted(index);
                break;
            case 4:
                cout << "Enter task index to remove: ";
                cin >> index;
                todoList.removeTask(index);
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
                break;
        }
    }
    return 0;
}
