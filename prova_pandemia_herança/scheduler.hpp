#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <iostream>
#include <vector>
using namespace std;

class Scheduler
{

    //protected:
    public:
        vector <size_t> taskId;

    
    void addInfo(size_t a){
        taskId.push_back(a);
    }
    void printInfo(){
        for(int i = 0; i < taskId.size(); i++){
            cout << "Vector Position " << i << " - Job " << taskId.at(i) << endl;
        }
    }
    virtual size_t getTask(){
            return 0;
    }    
};

class policy1 : public Scheduler{

    public:
        size_t task = 88;

        size_t getTask() override {
        //size_t task;
        if (!taskId.empty()) {
            task = taskId.front();  // Get the first element
            taskId.erase(taskId.begin());  // Remove the first element
            return task;
        }
        return task;  // Return a default value if the vector is empty
    }
};

class policy2 : public Scheduler{
    
    public:
    size_t getTask(){
            //size_t id = Scheduler::getTaskId(Scheduler::getSize());
            //taskId.erase(taskId.begin() + 0);

            return 0;
        }
};

#endif