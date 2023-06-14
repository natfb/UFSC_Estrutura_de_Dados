#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <iostream>
#include <vector>
using namespace std;

class Scheduler
{

    public:
        static vector <size_t> taskId;
    
    virtual void addInfo(size_t a){
        taskId.push_back(a);
    }
    virtual void printInfo(){
        for(int i = 0; i < taskId.size(); i++){
            cout << "Vectr position " << i << " - Job " << taskId.at(i) << endl;
        }
    }
    virtual int getTask(int i){
            int id = taskId.at(i);
            taskId.erase(taskId.begin() + i);

            return id;
    }     
    
};

#endif