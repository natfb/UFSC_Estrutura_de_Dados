#include "scheduler.hpp"
#include "policyUm.hpp"
#include "policyDois.hpp"

int main(){
    size_t id;
    int choice, task;
    Scheduler tasks;
    Scheduler *p1 = new policy1();
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
            task = p1->getTask();
            //task = tasks.getTask();
            cout << "Task to perform: " << task << endl;
            break;
        case 3:
            //task = p2.getTask();
            p2.printInfo();
            cout << "task to perform " << task << endl;
            break;
        case 4:
            tasks.printInfo();
            break;
        default:
            break;
        }
    }
}