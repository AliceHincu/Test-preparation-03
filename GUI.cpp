//
// Created by Sakura on 5/23/2021.
//

#include "GUI.h"

GUI::GUI(Service &service, QWidget *parent): QWidget{parent}, service{service} {
    this->initGUI();
}

GUI::~GUI() {}

void GUI::initGUI() {
    this->service.readFile();

    auto* mainLayout = new QVBoxLayout{this};
    // list
    this->tasksListWidget = new QListWidget{};
    this->tasksListWidget->setMinimumWidth(300);
    this->tasksListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    mainLayout->addWidget(this->tasksListWidget);

    // label + textedit
    auto* priorityWidget = new QWidget{};
    auto* priorityLayout = new QFormLayout{ priorityWidget };
    auto* priorityLabel = new QLabel{"&Priority: "};
    this->priorityLineEdit = new QLineEdit{};
    priorityLabel->setBuddy(this->priorityLineEdit);
    priorityLayout->addRow(priorityLabel, this->priorityLineEdit);
    mainLayout->addWidget(priorityWidget);

    // button
    auto* buttonsWidget = new QWidget{};
    auto* buttonsLayout = new QHBoxLayout{buttonsWidget};
    this->priorityButton = new QPushButton("Show duration");
    buttonsLayout->addWidget(this->priorityButton);
    mainLayout->addWidget(buttonsWidget);
    QObject::connect(this->priorityButton, &QPushButton::clicked, this, &GUI::getDuration);

    // labels
    auto* durationWidget = new QWidget{};
    auto* durationLayout = new QFormLayout{ durationWidget };
    auto* durationLabel = new QLabel{"Number of cars: "};
    this->durationLineEdit = new QLineEdit{};
    durationLabel->setBuddy(this->durationLineEdit);
    durationLayout->addRow(durationLabel, this->durationLineEdit);
    mainLayout->addWidget(durationWidget);

    this->populateTaskList();
}

void GUI::populateTaskList() {
    if(this->tasksListWidget->count() > 0)
        this->tasksListWidget->clear();
    auto tasks = this->service.sortTasks();

    for (auto &t: tasks){
        // fromStdString() -> Returns a copy of the str string
        QString itemInList = QString::fromStdString(t.getDescription()+" "+t.getPriority());
        QFont font{"Verdana", 10};
        if (t.getPriority() == "1")
            font.setBold(true);

        auto* item = new QListWidgetItem{itemInList};
        item->setFont(font);

        //auto colorString = QString::fromStdString(t.getColor());
        //item->setForeground(QColor(colorString));
        this->tasksListWidget->addItem(item);
    }

    // set the selection on the first item in the list if it's not empty
    if (!tasks.empty())
        this->tasksListWidget->setCurrentRow(0);
}

void GUI::getDuration() {
    std::string priority = this->priorityLineEdit->text().toStdString();
    int nr = this->service.getDuration(priority);
    this->durationLineEdit->setText(QString::fromStdString(std::to_string(nr)));
}
