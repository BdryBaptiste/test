#include "UIGameManager.h"


UIGameManager::UIGameManager(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // GUIObserver guiObserver;
    // display->addObserver(&guiObserver);

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

    hideGameButtons();
    showGameModeButtons();
}

void UIGameManager::onOthelloButtonClicked()
{
    currentGame.reset(new Othello(*display, player1.get(), player2.get()));

    hideGameButtons();
    showGameModeButtons();
}

void UIGameManager::onConnectFourButtonClicked()
{
    currentGame.reset(new ConnectFour(*display, player1.get(), player2.get()));

    hideGameButtons();
    showGameModeButtons();
}

void UIGameManager::onDraugthsButtonClicked()
{
    std::cout<<"test";
    // currentGame.reset(new Draughts(*display, player1.get(), player2.get()));
    //
    // hideGameButtons();
    // showGameModeButtons();
}

void UIGameManager::onPlayerVsComputerButtonClicked()
{
    ui->StartButton->setEnabled(true);

    player1.reset(new HumanPlayer(*display));
    player2.reset(new AIPlayer());
}

void UIGameManager::onTwoPlayersButtonClicked()
{
    ui->StartButton->setEnabled(true);

    player1.reset(new HumanPlayer(*display));
    player2.reset(new HumanPlayer(*display));
}

void UIGameManager::onComputerVsComputerButtonClicked()
{
    ui->StartButton->setEnabled(true);

    player1.reset(new AIPlayer());
    player2.reset(new AIPlayer());
}

void UIGameManager::onStartButtonClicked()
{
    // currentGame->playGame();
}

void UIGameManager::hideGameButtons()
{
    ui->TicTacToeButton->hide();
    ui->ConnectFourButton->hide();
    ui->OthelloButton->hide();
    ui->DraughtsButton->hide();
}

void UIGameManager::showGameModeButtons()
{
    ui->PlayerVsComputerButton->show();
    ui->TwoPlayersButton->show();
    ui->ComputerVsComputerButton->show();
    ui->StartButton->show();
}

