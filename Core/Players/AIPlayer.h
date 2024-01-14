#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"

class AIPlayer : public Player {
public:
    AIPlayer();
    std::pair<int, int> getDoubleInput(const Board& board) override;
    int getSingleInput(const Board& board, int max) override;
};

#endif // AIPLAYER_H