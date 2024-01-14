#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <memory>
#include "Display/Display.h"
#include "Game.h"
#include "Players/AIPlayer.h"
#include "Players/HumanPlayer.h"
#include "../Games/TicTacToe/TicTacToe.h"
#include "../Games/ConnectFour/ConnectFour.h"
#include "../Games/Othello/Othello.h"
#include "Observer/InterfaceObserver.h"
#include "Observer/ConsoleObserver.h"
#include "Observer/GUIObserver.h"

#include <iostream>
#include <cctype> // Pour tolower
//#include "../Games/Draughts/Draughts.h"

class GameManager {
public:
    GameManager();
    void startGameLoop();

private:
    CheckInputs* checkInputs;
    std::shared_ptr<Display> display;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::shared_ptr<Game> currentGame;
    int getGameChoice();
    char getReplayChoice();
    int getModeChoice();
    void configurePlayers(int modeChoice, std::shared_ptr<Player>& player1, std::shared_ptr<Player>& player2);
};

#endif // GAMEMANAGER_H
