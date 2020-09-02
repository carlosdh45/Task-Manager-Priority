#include <iostream>
#include "Process.h"

using namespace std;

int cpu = 0;
Node *head = nullptr;
void menu();
void processMenu();
void ask(const string& x);
Process add();
//void mmuMenu();

int main() {
    int option;
    do {
        menu();
        cin >> option;
        cout << endl;
        switch (option) {
            case 1:
                processMenu();
                break;
            case 2:
                cout << "Beta phase" << endl;
                break;
            case 3:
                sort(head);
                simulate(head, cpu);
                break;
            default:
                cout << option << ": is not a valid option" << endl << endl;
        }
    }while (option < 4);
    cout << "Exiting program" << endl;
    return 0;
}

void menu(){
    cout << "1. Process settings \n2. MMU settings \n3. Simulate \n4. Exit \nSelect:" ;
}

void processMenu(){
    int option;
    cout << "1. Add a new process  \n2. Show all process \n3. Go back \nSelect:";
    cin  >> option;
    cout << endl;
    switch (option) {
        case 1: {
            Process newProcess = add();
            cpu += newProcess.cpu;
            push(head,newProcess);
            break;
        }
        case 2: {
            show(head);
            break;
        }
        case 3: {
            cout << endl;
            break;
        }
        default:
            cout << option << ": in not a valid option" << endl;
    }
}

void ask(const string& x) {
    cout << "Type the " + x;
}

Process add() {
    Process newProcess{};
    cin.ignore();
    ask("name:");
    cin.getline(newProcess.name,30);
    ask("priority:");
    cin >> newProcess.priority;
    ask("cpu:");
    cin >> newProcess.cpu;
    ask("time_arrived:");
    cin >> newProcess.time_arrived;
    cout << endl;
    newProcess.status = "ready";
    newProcess.waiting_time = 0;
    newProcess.success_time = 0;
    return newProcess;
}