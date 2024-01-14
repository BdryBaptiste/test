#ifndef IAIINTERFACE_H
#define IAIINTERFACE_H

#include "../../Common/Board.h"
#include <utility>

class IAInterface {
public:
    virtual ~IAInterface() = default;
    virtual std::pair<int, int> getMove(const Board& board) = 0;
};

#endif // IAIINTERFACE_H
