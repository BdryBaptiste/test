#ifndef PLAYER_H
#define PLAYER_H

#include "../../Common/Board.h"
#include "../Interactors/SingleInputInteractor.h"
#include "../Interactors/DoubleInputInterator.h"
#include "../Display/Display.h"

class Player {
public:
    virtual std::pair<int, int> getDoubleInput(const Board& board) = 0;
    virtual int getSingleInput(const Board& board, int max) = 0;
    virtual ~Player() {}
};

#endif // PLAYER_H
