//
// Created by Sakura on 5/23/2021.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Service.h"

Service::Service(Repository &repo) : repo(repo) {}

void Service::addTask(const std::string &description, const std::string &duration, const std::string &priority) {
    Task t{description, duration, priority};
    this->repo.addTaskRepo(t);
}

void Service::readFile() {
    // Read from the text file
    std::ifstream myFile(this->fileName);
    Task car;

    if(myFile.is_open()) {
        std::string line;

        while(std::getline(myFile, line)) {
            std::vector<std::string> attributes = this->tokenize(line, this->delimitator);
            this->addTask(attributes[0], attributes[1], attributes[2]);
        }
    }
    else std::cout << "Problem with opening file!";
    // Close the file
    myFile.close();
}

std::vector<std::string> Service::tokenize(const std::string &str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;

    while(std::getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::vector<Task> Service::sortTasks() {
    auto tasks = this->repo.getTasksRepo();

    std::sort(tasks.begin(), tasks.end());

    return tasks;
}

int Service::getDuration(const std::string& p){
    auto tasks = this->repo.getTasksRepo();
    int nr=0;

    for(const auto& t:this->repo.getTasksRepo()){
        if(t.getPriority() == p)
            nr+=std::stoi(t.getDuration());
    }

    return nr;
}

Service::~Service() {

}
