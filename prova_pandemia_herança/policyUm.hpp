#include "scheduler.hpp"

class policy1 : public Scheduler{

    public:
        int getTask(){
            int id = taskId.at(0);
            taskId.erase(taskId.begin() + 0);

            return id;
    }
};