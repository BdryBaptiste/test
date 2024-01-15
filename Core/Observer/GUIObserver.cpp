#include "GUIObserver.h"

GUIObserver::GUIObserver(){
    mainWindow = new QWidget;
    layout = new QVBoxLayout;
    mainWindow->setLayout(layout);
}

void GUIObserver::updateStatus(){
    mainWindow->show();
}

void GUIObserver::updateGameChoiceMenu(){
    QPushButton *ticTacToeButton = new QPushButton("Tic Tac Toe");
    QPushButton *connectFourButton = new QPushButton("Connect Four");
    QPushButton *othelloButton = new QPushButton("Othello");
    QPushButton *draughtsButton = new QPushButton("Draughts");

    layout->addWidget(ticTacToeButton);
    layout->addWidget(connectFourButton);
    layout->addWidget(othelloButton);
    layout->addWidget(draughtsButton);

    // Connect button clicks to slots
    QObject::connect(ticTacToeButton, &QPushButton::clicked, [] {
        // Launch Tic Tac Toe game or perform an action
    });

    QObject::connect(connectFourButton, &QPushButton::clicked, [] {
        // Launch Connect Four game or perform an action
    });

    QObject::connect(othelloButton, &QPushButton::clicked, [] {
        // Launch Othello game or perform an action
    });

    QObject::connect(draughtsButton, &QPushButton::clicked, [] {
        // Launch draught game or perform an action
    });
}

void GUIObserver::updateBoard(Board& board){

}

void GUIObserver::updateInstructions(const std::string &status){

}
void GUIObserver::updateMessage(const std::string &status){

}
void GUIObserver::updateWarning(const std::string &status){

}
void GUIObserver::updatePositionChoice(const Board& board, const std::vector<std::pair<int, int>>& validMoves){

}


