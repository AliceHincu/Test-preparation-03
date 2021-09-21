//
// Created by Sakura on 5/23/2021.
//

#include "Task.h"

Task::Task(const std::string &description, const std::string &duration, const std::string &priority):
description(description), duration(duration), priority(priority){}

Task::Task(): description{""}, duration{""}, priority{""} {}

const std::string &Task::getDescription() const {
    return description;
}

void Task::setDescription(const std::string &description) {
    Task::description = description;
}

const std::string &Task::getDuration() const {
    return duration;
}

void Task::setDuration(const std::string &duration) {
    Task::duration = duration;
}

const std::string &Task::getPriority() const {
    return priority;
}

void Task::setPriority(const std::string &priority) {
    Task::priority = priority;
}

bool Task::operator<(const Task &other) const {
    return this->getPriority()<other.getPriority();
}


Task::~Task() = default;
