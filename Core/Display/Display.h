#ifndef DISPLAY_H
#define DISPLAY_H

#include "../../Common/Board.h"
#include "../../Common/Cell.h"

#include <string>

class Display {
public:
    virtual void displayBoard(const Board& board) = 0;
    virtual void displayPositionChoice(const Board& board, const std::vector<std::pair<int, int>>& validMoves) = 0;
    virtual void showMessage(const std::string& message) = 0;
    virtual void displayInstructions() = 0;
    virtual ~Display() = default;
};

#endif // DISPLAY_H
