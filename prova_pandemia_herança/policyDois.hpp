#include "scheduler.hpp"

class policy2 : public Scheduler{
    
    public:
    int getTask(){
        int sizee = taskId.size();
        int id = taskId.at(sizee);
        taskId.erase(taskId.begin() + sizee);
        return id;
    }
};