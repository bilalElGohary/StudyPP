#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Menu;

class Todo{
private:
    Menu* menu;
    int choice {};
    vector<string> tasks;
    string task {};
    int index {};
    int taskNum {};

    void Clear(){
        cout << "\033[2J\033[1;1H";
    }

    void RemoveTask(){
        cout << "-----------------------------------------------\n";
        cout << "> Enter task ID: ";
        cin >> taskNum;
        
        index = taskNum - 1;

        if (index >= 0 && index < static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + index);
            std::cout << "Task deleted successfully!\n";
            Clear();
        } else {
            std::cout << "Invalid task number!\n";
            Clear();
        }
        cout << "-----------------------------------------------\n";
        Clear();
    }

    void AddTask(){
        cout << "-----------------------------------------------\n";
        cout << "> Enter task: ";
        cin.ignore();
        getline(cin, task);
        tasks.push_back(task);
        cout << "-----------------------------------------------\n";
    }

    void MainBody(){
        cout << " _____ ___  ____   ___" << endl << "|_   _/ _ \\|  _ \\ / _ \\" << endl << "  | || | | | | | | | | |" << endl << "  | || |_| | |_| | |_| |" << endl << "  |_| \\___/|____/ \\___/" << endl;
        cout << "-----------------------------------------------\n";
        cout << "0.] Exit. \n1.] Menu. \n2.] Add. \n3.] Remove.\n";
        cout << "-----------------------------------------------\n[]List: {\n";
        for (size_t i = 0; i < tasks.size(); ++i) {

            std::cout << "\t[] " << tasks[i] << "\n";

        }
        cout << "}\n-----------------------------------------------\n";
        cout << "> Choose[0-3]: ";
        cin >> choice;
    }

public:    
    explicit Todo(Menu* menu) : menu(menu) {}
    virtual void RunMain();

    ~Todo() = default;
};

class Menu{
private:
    string version = "v0.1.0";
    int choice {};
    Todo todo;

    void Clear(){
        cout << "\033[2J\033[1;1H";
    }

    void MainRun(){
        cout << " Welcome to,\t\t" << version << endl << "\t ____  ____  ____" << endl << "\t/ ___||  _ \\|  _ \\"<< endl << "\t\\___ \\| |_) | |_) |\n" << " \t ___) |  __/|  __/\n" << "\t|____/|_|   |_|" << endl << "\n study better by bringing everything\n you need into one place." << endl;
        cout << "-----------------------------------------------\n";
        cout << "0.] Exit. \n1.] TODO. \n2.] Pomodoro. \n";
        cout << "-----------------------------------------------\n";
        cout << "> Choose[0-3]: ";
        cin >> choice;
    }
    
public:
    Menu() : todo(this) {}

    virtual void RunMenu(){
    while (true){        
        MainRun();
        if(choice == 0){
            Clear();
            break;
        }else if(choice == 1){
            Clear();
            todo.RunMain();
            break;
        }else{
            cerr << "Invalid Input: Try agin.\n";
            Clear();
        }
    }
    }

    void setVersion(string version){
        version = version;
    }

    string getVersion(){
        return version;
    }
    
    ~Menu() = default;
};

void Todo::RunMain(){
    while (true){
        MainBody();

        if(choice == 0){
            Clear();
            break;
        }else if(choice == 1){
            menu->RunMenu();
            Clear();
        }else if(choice == 2){
            AddTask();
            Clear();
        }else if(choice == 3){
            RemoveTask();
            Clear();
        }else{
            cerr << "Invalid Input: Try agin.\n";
            Clear();
        }
    }
}
