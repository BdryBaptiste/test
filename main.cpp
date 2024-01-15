#include <QApplication>
#include "Core/ConsoleGameManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ConsoleGameManager gameManager;
    gameManager.startGameLoop();

    return a.exec();
}
