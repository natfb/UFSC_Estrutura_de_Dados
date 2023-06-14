#include "scheduler.hpp"

class policy2 : public Scheduler{
    
    public:
    int getTask(){
        int sizee = taskId.size();
        int id = taskId.at(sizee - 1);
        taskId.erase(taskId.begin() + sizee - 1);
        return id;
    }
};