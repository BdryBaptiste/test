#ifndef CONSOLEOBSERVER_H
#define CONSOLEOBSERVER_H

#include <iostream>
#include <map>
#include "InterfaceObserver.h"

class ConsoleObserver : public InterfaceObserver{
public:
    ConsoleObserver();
    void updateStart() override;
    void updateBoard(Board& board) override;
    void updateInstructions(const std::string &instruction) override;
    void updateMessage(const std::string &message) override;
    void updateWarning(const std::string &warning) override;
    void updateMenu(const std::string &menu) override;

    void updatePositionChoice(const Board& board, const std::vector<std::pair<int, int>>& validMoves) override;

};

#endif // CONSOLEOBSERVER_H
