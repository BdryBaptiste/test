#include <QApplication>
#include "Core/ConsoleGameManager.h"
#include "Core/UIGameManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ConsoleGameManager gameManager;
    gameManager.startGameLoop();

    // UIGameManager gameManager;
    // gameManager.show();

    return a.exec();
}
