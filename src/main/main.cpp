using namespace std;
#include <iostream>
// #include "todo.cpp"
#include <vector>
#include <list>
#include <string>

void clear(){
    cout << "\033[2J\033[1;1H";
}

void menu(){
    string version = "v0.1.0";
    int choice {};

    while (true){
        cout << " Welcome to,\t\t" << version << endl << "\t ____  ____  ____" << endl << "\t/ ___||  _ \\|  _ \\"<< endl << "\t\\___ \\| |_) | |_) |\n" << " \t ___) |  __/|  __/\n" << "\t|____/|_|   |_|" << endl << "\n study better by bringing everything\n you need into one place." << endl;
        cout << "-----------------------------------------------\n";
        cout << "0.] Exit. \n1.] TODO. \n2.] Pomodoro. \n";
        cout << "-----------------------------------------------\n";
        cout << "> Choose[0-3]: ";
        cin >> choice;
        
        if(choice == 0){
            clear();
            break;
        }else if(choice == 1){
            clear();
            // todo();
            break;
        }else{
            cerr << "Invalid Input: Try agin.\n";
            clear();
        }
    }
}

void todo(){
    int choice {};
    vector<string> tasks;
    string task {};
    int index {};


    while (true){
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


        if(choice == 0){
            clear();
            break;
        }else if(choice == 1){
            clear();
            // menu();
            break;
        }else if(choice == 2){
            cout << "-----------------------------------------------\n";
            cout << "> Enter task: ";
            cin.ignore();
            getline(cin, task);
            tasks.push_back(task);
            cout << "-----------------------------------------------\n";
            clear();
        }else if(choice == 3){
            cout << "-----------------------------------------------\n";
            cout << "> Enter task ID: ";
            int taskNum {};
            cin >> taskNum;

            index = taskNum - 1;

            if (index >= 0 && index < static_cast<int>(tasks.size())) {
                tasks.erase(tasks.begin() + index);
                std::cout << "Task deleted successfully!\n";
                clear();
            } else {
                std::cout << "Invalid task number!\n";
                clear();
            }
            cout << "-----------------------------------------------\n";
            clear();
        }
        else{
            cerr << "Invalid Input: Try agin.\n";
            clear();
        }
    }
}

void run(){

}


int main(){
    clear();
    todo();
}