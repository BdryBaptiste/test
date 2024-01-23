#include "UIGameManager.h"


UIGameManager::UIGameManager(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    display.reset(new GUIDisplay());
    checkInput.reset(new GUICheckInputs(*display));

    ui->setupUi(this);
}

void UIGameManager::startGameLoop(){
    this->show();
    QMetaObject::connectSlotsByName(this);
}

void configurePlayers(int modeChoice, std::shared_ptr<Player>& player1, std::shared_ptr<Player>& player2){

}


UIGameManager::~UIGameManager()
{
    delete ui;
}

void UIGameManager::on_TicTacToeButton_clicked()
{
    hideGameButtons();

    currentGame.reset(new TicTacToe(*display, player1.get(), player2.get()));

    ui->StartButton->setEnabled(true);
}

void UIGameManager::on_OthelloButton_clicked()
{
    hideGameButtons();

    currentGame.reset(new Othello(*display, player1.get(), player2.get()));

    ui->StartButton->setEnabled(true);
}

void UIGameManager::on_ConnectFourButton_clicked()
{
    hideGameButtons();

    currentGame.reset(new ConnectFour(*display, player1.get(), player2.get()));

    ui->StartButton->setEnabled(true);
}

void UIGameManager::on_DraugthsButton_clicked()
{
    hideGameButtons();

    // currentGame.reset(new Draughts(*display, player1.get(), player2.get()));

    ui->StartButton->setEnabled(true);
}

void UIGameManager::on_PlayerVsComputerButton_clicked()
{
    player1.reset(new HumanPlayer(*display, *checkInput));
    player2.reset(new AIPlayer());

    hideGameModeButtons();
    showGameButtons();
}

void UIGameManager::on_TwoPlayersButton_clicked()
{
    player1.reset(new HumanPlayer(*display, *checkInput));
    player2.reset(new HumanPlayer(*display, *checkInput));

    hideGameModeButtons();
    showGameButtons();
}

void UIGameManager::on_ComputerVsComputerButton_clicked()
{
    player1.reset(new AIPlayer());
    player2.reset(new AIPlayer());

    hideGameModeButtons();
    showGameButtons();
}

void UIGameManager::on_StartButton_clicked()
{
    ui->TicTacToeButton->hide();
    ui->ConnectFourButton->hide();
    ui->OthelloButton->hide();
    ui->DraughtsButton->hide();
    ui->StartButton->hide();

    currentGame->playGame();
}

void UIGameManager::hideGameModeButtons()
{
    ui->PlayerVsComputerButton->hide();
    ui->TwoPlayersButton->hide();
    ui->ComputerVsComputerButton->hide();

}

void UIGameManager::showGameButtons()
{
    ui->TicTacToeButton->show();
    ui->ConnectFourButton->show();
    ui->OthelloButton->show();
    ui->DraughtsButton->show();
    ui->StartButton->show();
}

void UIGameManager::hideGameButtons(){
    ui->TicTacToeButton->hide();
    ui->ConnectFourButton->hide();
    ui->OthelloButton->hide();
    ui->DraughtsButton->hide();
}

