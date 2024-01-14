#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "../../Core/Game.h"
#include "../../Core/Players/AIPlayer.h"
#include "../../Core/Players/HumanPlayer.h"
#include "../../Core/Players/Player.h"

class TicTacToe : public Game {
private:
    HumanPlayer* humanPlayer;
    AIPlayer* aiPlayer;

public:
    TicTacToe(Display& display, Player* player1, Player* player2);

    void switchPlayer() override;
    void playTurn() override;
    Symbol checkWinner() override;
    void displayInstructions() override;
    std::string getVictoryMessage(Symbol winner) const;
};

#endif // TICTACTOE_H
