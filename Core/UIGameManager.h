#ifndef UIGAMEMANAGER_H
#define UIGAMEMANAGER_H

#include <QtWidgets>
#include "ui_MainWindow.h"
#include "Display/GUIDisplay.h"
#include "GameManager.h"
#include "Utils/GUICheckInput.h"
#include "../Games/TicTacToe/TicTacToe.h"
#include "../Games/ConnectFour/ConnectFour.h"
#include "../Games/Othello/Othello.h"
#include <iostream>

class UIGameManager : public QMainWindow, public GameManager
{
    Q_OBJECT
public:
    explicit UIGameManager(QWidget *parent = nullptr);
    ~UIGameManager();
    void startGameLoop() override;
    std::shared_ptr<GUIDisplay> display;
    std::shared_ptr<GUICheckInputs> checkInput;

private:
    Ui::MainWindow *ui;

private slots:
    void on_TicTacToeButton_clicked();
    void on_OthelloButton_clicked();
    void on_ConnectFourButton_clicked();
    void on_DraugthsButton_clicked();

    void on_PlayerVsComputerButton_clicked();
    void on_TwoPlayersButton_clicked();
    void on_ComputerVsComputerButton_clicked();

    void on_StartButton_clicked();

    void hideGameModeButtons();
    void showGameButtons();
};

#endif // UIGAMEMANAGER_H
