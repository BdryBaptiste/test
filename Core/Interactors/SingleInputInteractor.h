#ifndef SINGLEINPUTINTERACTOR_H
#define SINGLEINPUTINTERACTOR_H

#include "../../Common/Board.h"

class SingleInputInteractor {
public:
    virtual ~SingleInputInteractor() = default;
    virtual int getSingleInput(const Board& board) = 0;
};

#endif // SINGLEINPUTINTERACTOR_H