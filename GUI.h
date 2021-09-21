//
// Created by Sakura on 5/23/2021.
//

#ifndef TASKMANAGER_GUI_H
#define TASKMANAGER_GUI_H

#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include "Service.h"

class GUI: public QWidget {
private:
    Service& service;
    QListWidget* tasksListWidget{};
    QLineEdit* priorityLineEdit{};
    QLineEdit* durationLineEdit{};
    QPushButton* priorityButton{};
public:
    GUI(Service& service, QWidget *parent = nullptr);
    ~GUI();
    void initGUI();
    void populateTaskList();

    void getDuration();
};


#endif //TASKMANAGER_GUI_H
