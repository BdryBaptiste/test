#include "Game.h"
#include <sstream>

Game::Game(int rows, int cols, Display& display)
    : gameBoard(rows, cols), currentPlayer(Symbol::PLAYER_X), display(display) {
}

GameOutcome Game::determineOutcome(){
    if (gameBoard.isBoardFull()){
        return GameOutcome::DRAW;
    }
    return GameOutcome::ONGOING;
}


void Game::endGame(GameOutcome outcome) {
    display.displayBoard(gameBoard);
    Symbol winner = checkWinner();

    if (winner != Symbol::EMPTY) {
        std::string winnerMessage = getVictoryMessage(winner);
        display.showMessage(winnerMessage);
    } else if (gameBoard.isBoardFull()) {
        display.showMessage("Match nul !");
    }
}


void Game::playGame() {
    Symbol winner;

    displayInstructions();

    while (true) {
        display.displayBoard(gameBoard);
        playTurn();
        winner = checkWinner();
        if (winner != Symbol::EMPTY || gameBoard.isBoardFull()) {
            break;
        }
        display.showMessage("Changement de joueur");
        switchPlayer();
    }
    endGame(determineOutcome());
}
