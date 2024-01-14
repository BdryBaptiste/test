#include <QApplication>
#include "Core/GameManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameManager gameManager;
    gameManager.startGameLoop();

    return a.exec();
}
