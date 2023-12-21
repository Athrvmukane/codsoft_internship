#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class ToDoList {
private:
    struct Task {
        string description;
        bool completed;

        Task(const string& desc) : description(desc), completed(false) {}
    };

    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.emplace_back(description);
        cout << "Task added: " << description << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
        } else {
            cout << "----- To-Do List -----" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                if (!tasks[i].completed) {
                    cout << "[" << setw(2) << i + 1 << "] ";
                    cout << (tasks[i].completed ? "[X] " : "[ ] ");
                    cout << tasks[i].description << endl;
                }
            }
            cout << "-----------------------" << endl;
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size() && !tasks[index - 1].completed) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description << endl;
        } else {
            cout << "Invalid task index or task already completed." << endl;
        }
    }
};

int main() {
    ToDoList toDoList;

    int choice;
    do {
        cout << "\n--- To-Do List Menu ---" << endl;
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore();  // Ignore newline character in the buffer
                getline(cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                size_t taskIndex;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> taskIndex;
                toDoList.markTaskAsCompleted(taskIndex);
                break;
            }
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
