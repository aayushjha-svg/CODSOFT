#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

struct Task
{
    string title;
    bool completed;
    int priority; // 3 = High, 2 = Medium, 1 = Low
};

// ---------------- COMPARATOR ----------------
bool compare(Task a, Task b)
{
    return a.priority > b.priority;
}

// ---------------- ADD TASK ----------------
void addTask(vector<Task>& tasks)
{
    Task newTask;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Task: ";
    getline(cin, newTask.title);

    string input;

    while (true)
    {
        cout << "Enter priority (High/Medium/Low): ";
        getline(cin, input);

        if (input == "High")
        {
            newTask.priority = 3;
            break;
        }
        else if (input == "Medium")
        {
            newTask.priority = 2;
            break;
        }
        else if (input == "Low")
        {
            newTask.priority = 1;
            break;
        }
        else
        {
            cout << "Invalid input! Try again.\n";
        }
    }

    newTask.completed = false;
    tasks.push_back(newTask);

    cout << "Task Added!\n";
}

// ---------------- VIEW TASKS ----------------
void viewTasks(vector<Task>& tasks)
{
    if (tasks.empty())
    {
        cout << "\nNo tasks available!\n";
        return;
    }

    sort(tasks.begin(), tasks.end(), compare);

    cout << "\n----- TASK LIST -----\n";

    for (int i = 0; i < tasks.size(); i++)
    {
        string p;

        if (tasks[i].priority == 3)
            p = "High";
        else if (tasks[i].priority == 2)
            p = "Medium";
        else
            p = "Low";

        cout << i + 1 << ". "
             << tasks[i].title
             << "\n   Priority : " << p
             << "\n   Status   : "
             << (tasks[i].completed ? "Completed" : "Pending")
             << "\n\n";
    }
}

// ---------------- MARK COMPLETED ----------------
void markCompleted(vector<Task>& tasks)
{
    if (tasks.empty())
    {
        cout << "\nNo tasks available!\n";
        return;
    }

    viewTasks(tasks);

    int taskNumber;

    cout << "\nEnter task number to mark completed: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= tasks.size())
    {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed!\n";
    }
    else
    {
        cout << "Invalid task number!\n";
    }
}

// ---------------- DELETE TASK ----------------
void deleteTask(vector<Task>& tasks)
{
    if (tasks.empty())
    {
        cout << "\nNo tasks available!\n";
        return;
    }

    viewTasks(tasks);

    int taskNumber;

    cout << "\nEnter task number to delete: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= tasks.size())
    {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task deleted successfully!\n";
    }
    else
    {
        cout << "Invalid task number!\n";
    }
}

// ---------------- SAVE TASKS ----------------
void saveTasks(vector<Task>& tasks)
{
    ofstream file("tasks.txt");

    for (int i = 0; i < tasks.size(); i++)
    {
        file << tasks[i].title << "|"
             << tasks[i].priority << "|"
             << tasks[i].completed << endl;
    }

    file.close();

    cout << "\nTasks saved successfully!\n";
}

// ---------------- LOAD TASKS ----------------
void loadTasks(vector<Task>& tasks)
{
    ifstream file("tasks.txt");

    string line;

    while (getline(file, line))
    {
        string title, priority, completedStr;
        stringstream ss(line);

        getline(ss, title, '|');
        getline(ss, priority, '|');
        getline(ss, completedStr);

        Task task;

        task.title = title;
        task.priority = stoi(priority);
        task.completed = stoi(completedStr);

        tasks.push_back(task);
    }

    file.close();
}
    //Search task------
void searchTask(vector<Task>& tasks)
{
    if (tasks.empty())
    {
        cout << "\nNo tasks available!\n";
        return;
    }

    string keyword;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter keyword: ";
    getline(cin, keyword);

    bool found = false;

    cout << "\n----- SEARCH RESULTS -----\n";

    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].title.find(keyword) != string::npos)
        {
            found = true;

            string p = (tasks[i].priority == 3) ? "High"
                     : (tasks[i].priority == 2) ? "Medium"
                     : "Low";

            cout << i + 1 << ". "
                 << tasks[i].title
                 << "\n   Priority : " << p
                 << "\n   Status   : "
                 << (tasks[i].completed ? "Completed" : "Pending")
                 << "\n\n";
        }
    }

    if (!found)
    {
        cout << "No matching tasks found!\n";
    }
}
void showPending(vector<Task>& tasks)
{
    cout << "\n----- PENDING TASKS -----\n";

    bool found = false;

    for (int i = 0; i < tasks.size(); i++)
    {
        if (!tasks[i].completed)
        {
            found = true;

            string p = (tasks[i].priority == 3) ? "High"
                     : (tasks[i].priority == 2) ? "Medium"
                     : "Low";

            cout << tasks[i].title
                 << " [" << p << "]\n";
        }
    }

    if (!found)
        cout << "No pending tasks!\n";
}
void showCompleted(vector<Task>& tasks)
{
    cout << "\n----- COMPLETED TASKS -----\n";

    bool found = false;

    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].completed)
        {
            found = true;

            cout << tasks[i].title << "\n";
        }
    }

    if (!found)
        cout << "No completed tasks!\n";
}
void showHighPriority(vector<Task>& tasks)
{
    cout << "\n----- HIGH PRIORITY TASKS -----\n";

    bool found = false;

    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].priority == 3)
        {
            found = true;

            cout << tasks[i].title
                 << (tasks[i].completed ? " (Done)" : " (Pending)")
                 << "\n";
        }
    }

    if (!found)
        cout << "No high priority tasks!\n";
}
// ---------------- MAIN ----------------
int main()
{
    vector<Task> tasks;
    loadTasks(tasks);

    while (true)
    {
        cout << "\n===== TASK MANAGER =====";
        cout << "\n1. Add Task";
        cout << "\n2. View Tasks";
        cout << "\n3. Mark Completed";
        cout << "\n4. Delete Task";
        cout << "\n5. Save & Exit";
        cout << "\n6. Search Task";
        cout << "\n7. Show Pending Tasks";
        cout << "\n8. Show Completed Tasks";
        cout << "\n9. Show High Priority Tasks";

        cout << "\nLoaded " << tasks.size() << " tasks.\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTask(tasks);
            break;

        case 2:
            viewTasks(tasks);
            break;

        case 3:
            markCompleted(tasks);
            break;

        case 4:
            deleteTask(tasks);
            break;

        case 5:
            saveTasks(tasks);
            cout << "Exiting...\n";
            return 0;
        case 6:
              searchTask(tasks);
              break;
        case 7:
              showPending(tasks);
              break;

        case 8:      
              showCompleted(tasks);
              break;

        case 9:
              showHighPriority(tasks);
              break;
        default:
            cout << "Invalid choice!\n";
        }
    }
}