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
    virtual ~GameManager() = default;
    virtual void startGameLoop() = 0;

protected:
    CheckInputs* checkInputs;
    std::shared_ptr<Display> display;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::shared_ptr<Game> currentGame;
    virtual int getGameChoice() = 0;
    virtual char getReplayChoice() = 0;
    virtual int getModeChoice() = 0;
    virtual void configurePlayers(int modeChoice, std::shared_ptr<Player>& player1, std::shared_ptr<Player>& player2) = 0;
};

#endif // GAMEMANAGER_H
