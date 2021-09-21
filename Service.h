//
// Created by Sakura on 5/23/2021.
//

#ifndef TASKMANAGER_SERVICE_H
#define TASKMANAGER_SERVICE_H


#include "Repository.h"

class Service {
public:
    Service(Repository &repo);
    void addTask(const std::string&, const std::string&, const std::string&);
    void readFile();
    std::vector<std::string> tokenize(const std::string& str, char delimiter);
    std::vector<Task> sortTasks();
    int getDuration(const std::string& p);
    ~Service();

private:
    Repository repo;
    std::string fileName = "tasks.txt";
    char delimitator = '|';


};


#endif //TASKMANAGER_SERVICE_H
