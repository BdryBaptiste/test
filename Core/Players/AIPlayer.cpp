#include "AIPlayer.h"
#include <iostream>

AIPlayer::AIPlayer() {
}

std::pair<int, int> AIPlayer::getDoubleInput(const Board& board) {
    std::cout << "Robot pick a column";
    int row, col;
    do {
        row = rand() % board.getRows();
        col = rand() % board.getCols();
    } while (!board.isCellEmpty(row, col));
    return std::make_pair(row, col);
}

int AIPlayer::getSingleInput(const Board& board, int max) {
    int col;
    //sleep(1);
    col = rand() % max +1;
    std::cout << "Robot choisit la colonne : " << col << std::endl;
    return col;
}