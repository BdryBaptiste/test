#ifndef OTHELLO_H
#define OTHELLO_H

#include "../../Core/Game.h"
#include "../../Core/Players/AIPlayer.h"
#include "../../Core/Players/HumanPlayer.h"
#include "../../Core/Players/Player.h"
#include <map>

class Othello : public Game {
public:
    static const int BOARD_SIZE = 8;
    static const int HALF_BOARD_SIZE = BOARD_SIZE / 2;
    static const int HALF_BOARD_SIZE_MINUS_ONE = HALF_BOARD_SIZE - 1;
    Othello(Display& display, Player* player1, Player* player2);
    void switchPlayer() override;
    void playTurn() override;
    Symbol checkWinner() override;
    void displayInstructions() override;
    std::string getVictoryMessage(Symbol winner) const;

private:
    HumanPlayer* humanPlayer;
    AIPlayer* aiPlayer;
    void setStartingPoint();
    void flipPieces(int row, int col);
    bool isValidMove(int row, int col) const;
    bool isValidMoveForPlayer(int row, int col, Symbol player) const;
    bool hasValidMoves(Symbol player) const;
    void calculateValidMoves();
    void countPieces(int& countX, int& countO) const;
    std::vector<std::pair<int, int>> validMoves;
    std::map<int, std::pair<int, int>> getNumberedValidMoves();
};

#endif // OTHELLO_H
