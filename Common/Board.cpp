#include "../Common/Board.h"
#include <iostream>

Board::Board(int r, int c) : rows(r), cols(c), filledCells(0) {
    grid = std::vector<std::vector<Cell>>(r, std::vector<Cell>(c));
}

int Board::getCols() const {
    return cols;
}

int Board::getRows() const {
    return rows;
}

bool Board::isValidPosition(int row, int col) const {
    return (row >= 0 && row < rows) && (col >= 0 && col < cols);
}

Symbol Board::getCell(int row, int col) const {
    if (isValidPosition(row, col)) {
        return grid[row][col].getContent();
    } else {
        return Symbol::EMPTY;
    }
}

bool Board::setCell(int row, int col, Symbol value, bool allowOverwrite) {
    if (isValidPosition(row, col) && (allowOverwrite || isCellEmpty(row, col))) {
        if (isCellEmpty(row, col)) {
            filledCells++;  // Incrémenter le compteur seulement si la cellule était vide
        }
        grid[row][col].setContent(value, allowOverwrite);
        return true;
    } else {
        return false;
    }
}

bool Board::isCellEmpty(int row, int col) const {
    return isValidPosition(row, col) && grid[row][col].isEmpty();
}

bool Board::isColumnFull(int col) const {
    //Si la première ligne est occupée, la colonne est pleine
    return !isCellEmpty(0, col);
}

bool Board::isBoardFull() const {
    return filledCells == rows * cols;
}

bool Board::checkLine(int startRow, int startCol, int deltaRow, int deltaCol, Symbol player, int winCondition) const {
    for (int k = 0; k < winCondition; ++k) {
        int row = startRow + k * deltaRow;
        int col = startCol + k * deltaCol;

        if (!isValidPosition(row, col) || getCell(row, col) != player) {
            return false;
        }
    }
    return true;
}