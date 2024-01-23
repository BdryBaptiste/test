#include <QApplication>
#include "Core/ConsoleGameManager.h"
#include "Core/UIGameManager.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //ConsoleGameManager gameManager;
    //gameManager.startGameLoop();

    UIGameManager gameManager;
    gameManager.startGameLoop();

    return a.exec();
}
