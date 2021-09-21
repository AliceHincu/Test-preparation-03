//
// Created by Sakura on 5/23/2021.
//

#ifndef TASKMANAGER_REPOSITORY_H
#define TASKMANAGER_REPOSITORY_H


#include <vector>
#include "Task.h"

class Repository {
public:
    Repository();
    void addTaskRepo(const Task&);
    std::vector<Task> getTasksRepo();
    ~Repository();

private:
    std::vector<Task> tasks;
};


#endif //TASKMANAGER_REPOSITORY_H
