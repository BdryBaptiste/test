#include "GUIObserver.h"

GUIObserver::GUIObserver(){
    mainWindow = new QWidget;
    layout = new QVBoxLayout;
    mainWindow->setLayout(layout);
}

void GUIObserver::updateStart(){
    mainWindow->show();
}

void GUIObserver::updateMenu(const std::string& menuItem){
    QPushButton *button = new QPushButton(QString::fromStdString(menuItem));
    QObject::connect(button, &QPushButton::clicked, [menuItem] {
        // Handle button click, potentially notifying GameManager about the selection
    });
    layout->addWidget(button);
}
