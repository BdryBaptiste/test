#ifndef DISPLAY_H
#define DISPLAY_H

#include "../../Common/Board.h"
#include "../../Common/Cell.h"
#include "../Observer/InterfaceObserver.h"

#include <string>

class Display {
    public:
        std::vector<InterfaceObserver*> observers;
        void addObserver(InterfaceObserver* observer);
        void notifyBoardUpdate(Board& board);
        void notifyWarningUpdate(const std::string &warning);
        void notifyInstructionsUpdate(const std::string &instuctions);
        void notifyMessageUpdate(const std::string &message);
        void notifyGameChoiceMenuUpdate();
        void notifyModeChoiceMenuUpdate();
        void notifyPositionChoiceUpdate(const Board& board, const std::vector<std::pair<int, int>>& validMoves);
        void notifyStart();
        Display();
};

#endif // DISPLAY_H
