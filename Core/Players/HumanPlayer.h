#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "../Interactors/IPlayerInteractor.h"
#include "../Utils/InputManager.h"
#include "../Utils/CheckInputs.h"
#include "../Display/Display.h"
#include "../../Common/Board.h"
#include "Player.h"

class HumanPlayer : public Player {
private:
    Display& display;
    CheckInputs& checkInput;

public:
    HumanPlayer(Display& display, CheckInputs& checkInput);
    std::pair<int, int> getDoubleInput(const Board& board) override;
    int getSingleInput(const Board& board, int max) override;
};

#endif // HUMANPLAYER_H
