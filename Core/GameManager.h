#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <memory>
#include "Display/DisplayConsole.h"
#include "Game.h"
#include "Players/AIPlayer.h"
#include "Players/HumanPlayer.h"
#include "../Games/TicTacToe/TicTacToe.h"
#include "../Games/ConnectFour/ConnectFour.h"
#include "../Games/Othello/Othello.h"
#include "Utils/CheckInputFactory.h"
#include "Utils/CheckInputs.h"
#include "Utils/InputManager.h"
#include "Utils/InputType.h"
//#include "../Games/Draughts/Draughts.h"

class GameManager {
public:
    virtual ~GameManager() = default;
    virtual void startGameLoop() = 0;

protected:
    std::shared_ptr<DisplayConsole> display;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::shared_ptr<Game> currentGame;
    virtual int getGameChoice() = 0;
    virtual char getReplayChoice() = 0;
    virtual int getModeChoice() = 0;
    virtual void configurePlayers(int modeChoice, std::shared_ptr<Player>& player1, std::shared_ptr<Player>& player2) = 0;
};

#endif // GAMEMANAGER_H
