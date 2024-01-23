#include "UIGameManager.h"


UIGameManager::UIGameManager(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    display.reset(new GUIDisplay());
    checkInput.reset(new GUICheckInputs(*display));

    ui->setupUi(this);

    connect(ui->TicTacToeButton, SIGNAL(clicked()), this, SLOT(onTicTacToeButtonClicked()));
    connect(ui->OthelloButton, SIGNAL(clicked()), this, SLOT(onOthelloButtonClicked()));
    connect(ui->ConnectFourButton, SIGNAL(clicked()), this, SLOT(onConnectFourButtonClicked()));
    connect(ui->DraughtsButton, SIGNAL(clicked()), this, SLOT(onDraugthsButtonClicked()));

    connect(ui->PlayerVsComputerButton, SIGNAL(clicked()), this, SLOT(onPlayerVsComputerButtonClicked()));
    connect(ui->TwoPlayersButton, SIGNAL(clicked()), this, SLOT(onTwoPlayersButtonClicked()));
    connect(ui->ComputerVsComputerButton, SIGNAL(clicked()), this, SLOT(onComputerVsComputerButtonClicked()));

    connect(ui->StartButton, SIGNAL(clicked()), this, SLOT(onStartButtonClicked()));
}

UIGameManager::~UIGameManager()
{
    delete ui;
}

void UIGameManager::onTicTacToeButtonClicked(){
    currentGame.reset(new TicTacToe(*display, player1.get(), player2.get()));

    ui->StartButton->setEnabled(true);
}

void UIGameManager::onOthelloButtonClicked()
{
    currentGame.reset(new Othello(*display, player1.get(), player2.get()));

    ui->StartButton->setEnabled(true);
}

void UIGameManager::onConnectFourButtonClicked()
{
    currentGame.reset(new ConnectFour(*display, player1.get(), player2.get()));

    ui->StartButton->setEnabled(true);
}

void UIGameManager::onDraugthsButtonClicked()
{
    // currentGame.reset(new Draughts(*display, player1.get(), player2.get()));
    //
    // hideGameButtons();
    // showGameModeButtons();
}

void UIGameManager::onPlayerVsComputerButtonClicked()
{
    player1.reset(new HumanPlayer(*display));
    player2.reset(new AIPlayer());

    hideGameModeButtons();
    showGameButtons();
}

void UIGameManager::onTwoPlayersButtonClicked()
{
    player1.reset(new HumanPlayer(*display));
    player2.reset(new HumanPlayer(*display));

    hideGameModeButtons();
    showGameButtons();
}

void UIGameManager::onComputerVsComputerButtonClicked()
{
    player1.reset(new AIPlayer());
    player2.reset(new AIPlayer());

    hideGameModeButtons();
    showGameButtons();
}

void UIGameManager::onStartButtonClicked()
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

