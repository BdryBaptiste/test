#include "UIGameManager.h"


UIGameManager::UIGameManager(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->TicTacToeButton, SIGNAL(clicked()), this, SLOT(onTicTacToeButtonClicked()));
}

UIGameManager::~UIGameManager()
{
    delete ui;
}

void UIGameManager::onTicTacToeButtonClicked(){

}

