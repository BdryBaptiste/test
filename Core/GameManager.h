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
#include "Utils/CheckInputs.h"
//#include "../Games/Draughts/Draughts.h"

class GameManager {
public:
    virtual ~GameManager() = default;
    virtual void startGameLoop() = 0;

protected:
    std::shared_ptr<Display> display;
    std::shared_ptr<CheckInputs> checkInput;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::shared_ptr<Game> currentGame;
};

#endif // GAMEMANAGER_H
