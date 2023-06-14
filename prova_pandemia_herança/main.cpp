#include "policyUm.hpp"
#include "policyDois.hpp"

int main(){

    int choice, id, task;
    Scheduler tasks;
    policy1 p1;
    policy2 p2;
    while(choice != 5){
        cout << "1 schedude task" << endl; 
        cout << "2 policy 1" << endl;
        cout << "3 policy 2" << endl;
        cout << "4 print" << endl;
        cout << "5 exit" << endl; 
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "tark id: ";
            cin >> id;
            tasks.addInfo(id);
            break;
        case 2:
            task = p1.getTask();
            cout << "task to perform: " << task << endl;
            break;
        case 3:
            task = p2.getTask();
            cout << "task to perform: " << task << endl;
            break;
        case 4:
            tasks.printInfo();
            break;
        default:
            break;
        }
    }
}