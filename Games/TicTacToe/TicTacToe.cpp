#include "TicTacToe.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <QDebug>

const int BOARD_SIZE = 3;
const int FIRST_CELL = 0;
const int LAST_CELL = BOARD_SIZE - 1;
const int WIN_CONDITION = 3;

TicTacToe::TicTacToe(Display& display, Player* player1, Player* player2)
    : Game(BOARD_SIZE, BOARD_SIZE, display) {
    srand(static_cast<unsigned int>(time(NULL)));
    currentPlayer = Symbol::PLAYER_X;
    this->player1.reset(player1);
    this->player2.reset(player2);
}

void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == Symbol::PLAYER_X) ? Symbol::PLAYER_O : Symbol::PLAYER_X;
}

void TicTacToe::playTurn() {
    int row, col;
    std::pair<int, int> move;
    Symbol playerSymbol = currentPlayer;

    do {
        Player* currentPlayerPointer = (currentPlayer == Symbol::PLAYER_X) ? this->player1.get() : this->player2.get();
        move = currentPlayerPointer->getDoubleInput(gameBoard);
        row = move.first;
        col = move.second;
    } while (!gameBoard.setCell(row, col, playerSymbol));
}

Symbol TicTacToe::checkWinner() {
    // Vérification pour chaque direction
    for (int i = 0; i < BOARD_SIZE; i++) {
        bool horizontalWin = true, verticalWin = true;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (gameBoard.getCell(i, j) != currentPlayer) horizontalWin = false;
            if (gameBoard.getCell(j, i) != currentPlayer) verticalWin = false;
        }
        if (horizontalWin || verticalWin) return currentPlayer;
    }

    // Vérification des diagonales
    bool diag1Win = true, diag2Win = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (gameBoard.getCell(i, i) != currentPlayer) diag1Win = false;
        if (gameBoard.getCell(i, BOARD_SIZE - 1 - i) != currentPlayer) diag2Win = false;
    }
    if (diag1Win || diag2Win) return currentPlayer;

    // Aucun gagnant
    return Symbol::EMPTY;
}

void TicTacToe::displayInstructions() {
    display.showMessage("Chaque joueur choisit une cellule vide où placer son pion. Le but est d'aligner 3 pions horizontalement, verticalement ou en diagonale.");
}

std::string TicTacToe::getVictoryMessage(Symbol winner) const {
    if (winner != Symbol::EMPTY) {
        return "Joueur " + symbolToString(winner) + " est gagnant";
    }
    return "Match nul";
}
