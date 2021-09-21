//
// Created by Sakura on 5/23/2021.
//

#include "Repository.h"

Repository::Repository() {

}

void Repository::addTaskRepo(const Task &task) {
    this->tasks.push_back(task);
}

Repository::~Repository() {

}

std::vector<Task> Repository::getTasksRepo() {
    return this->tasks;
}
