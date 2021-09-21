//
// Created by Sakura on 5/23/2021.
//

#ifndef TASKMANAGER_TASK_H
#define TASKMANAGER_TASK_H

#include <string>

class Task {
private:
    std::string description;
    std::string duration;
    std::string priority;
public:
    Task(const std::string& description, const std::string& duration, const std::string& priority);
    Task();
    ~Task();

    bool operator<(const Task&) const;
    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    const std::string &getDuration() const;

    void setDuration(const std::string &duration);

    const std::string &getPriority() const;

    void setPriority(const std::string &priority);
};


#endif //TASKMANAGER_TASK_H
