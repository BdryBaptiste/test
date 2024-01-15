#ifndef INTERFACEOBSERVER_H
#define INTERFACEOBSERVER_H

#include <string>
#include "../../Common/Board.h"

class InterfaceObserver {
public:
    virtual ~InterfaceObserver() = default;
    virtual void updateStatus() = 0;
    virtual void updateBoard(Board& board) = 0;
    virtual void updateInstructions(const std::string &status) = 0;
    virtual void updateMessage(const std::string &status) = 0;
    virtual void updateWarning(const std::string &status) = 0;
    virtual void updateGameChoiceMenu() = 0;
    virtual void updateModeChoiceMenu() = 0;

    virtual void updatePositionChoice(const Board& board, const std::vector<std::pair<int, int>>& validMoves) = 0;
};
#endif // INTERFACEOBSERVER_H
