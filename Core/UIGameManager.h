#ifndef UIGAMEMANAGER_H
#define UIGAMEMANAGER_H

#include <QtWidgets>
#include "ui_MainWindow.h"
#include "Display/Display.h"
#include "Display/GUIDisplay.h"
#include "GameManager.h"
#include "Utils/CheckInputs.h"
#include "Game.h"
#include "../Games/TicTacToe/TicTacToe.h"
#include "../Games/ConnectFour/ConnectFour.h"
#include "../Games/Othello/Othello.h"
#include <iostream>

class UIGameManager : public QMainWindow
{
    Q_OBJECT
public:
    explicit UIGameManager(QWidget *parent = nullptr);
    ~UIGameManager();

private:
    CheckInputs* checkInputs;
    Ui::MainWindow *ui;
    std::shared_ptr<Display> display;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::shared_ptr<Game> currentGame;

private slots:
    void onTicTacToeButtonClicked();
    void onOthelloButtonClicked();
    void onConnectFourButtonClicked();
    void onDraugthsButtonClicked();

    void onPlayerVsComputerButtonClicked();
    void onTwoPlayersButtonClicked();
    void onComputerVsComputerButtonClicked();

    void onStartButtonClicked();

    void hideGameButtons();
    void showGameModeButtons();

};

#endif // UIGAMEMANAGER_H
