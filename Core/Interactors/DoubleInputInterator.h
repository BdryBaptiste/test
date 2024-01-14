#ifndef DOUBLEINPUTINTERACTOR_H
#define DOUBLEINPUTINTERACTOR_H

#include "../../Common/Board.h"

class DoubleInputInteractor {
public:
    virtual ~DoubleInputInteractor() = default;
    virtual std::pair<int, int> getDoubleInput(const Board& board) = 0;
};


#endif // DOUBLEINPUTINTERACTOR_H