#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <iostream>
#include <vector>
using namespace std;

class Scheduler
{

    public:
        vector <size_t> taskId;
    
    void addInfo(size_t a){
        taskId.push_back(a);
    }
    void printInfo(){
        for(int i = 0; i < taskId.size(); i++){
            cout << "Vectr position " << i << " - Job " << taskId.at(i) << endl;
        }
    }
    int getTask(int i){
            int id = taskId.at(i);
            taskId.erase(taskId.begin() + i);

            return id;
    }     
    
};

#endif