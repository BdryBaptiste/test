#ifndef IPLAYERINTERACTOR_H
#define IPLAYERINTERACTOR_H

#include "../../Common/Board.h"
#include <utility>

class IPlayerInteractor {
public:
    virtual ~IPlayerInteractor() = default;
    virtual std::pair<int, int> getMove(const Board& board) = 0;
};

#endif // IPLAYERINTERACTOR_H
