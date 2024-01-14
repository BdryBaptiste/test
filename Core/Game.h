#ifndef GAME_H
#define GAME_H

#include <memory>
#include "../Common/Board.h"
#include "Players/Player.h"
#include "Interactors/IPlayerInteractor.h"
#include "utils/CheckInputs.h"
#include "Display/Display.h"

enum class GameOutcome {
    BLACK_WINS,
    WHITE_WINS,
    DRAW,
    ONGOING
};


class Game {
    protected:
        Board gameBoard;
        Symbol currentPlayer;
        Display& display;
        std::unique_ptr<Player> player1;
        std::unique_ptr<Player> player2;

    public:
        Game(int rows, int cols, Display& display);

        void playGame();
        GameOutcome determineOutcome();
        void endGame(GameOutcome outcome);

        // Méthodes virtuelles pures
        virtual void switchPlayer() = 0;
        virtual void playTurn() = 0;
        virtual Symbol checkWinner() = 0;
        virtual std::string getVictoryMessage(Symbol winner) const = 0;
        virtual void displayInstructions() = 0;
};

#endif // GAME_H
