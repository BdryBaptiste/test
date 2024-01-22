#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Cell.h"

class Board {
public:
    Board(int r, int c);
    Symbol getCell(int row, int col) const;
    bool setCell(int row, int col, Symbol value, bool allowOverwrite = false);
    int getCols() const;
    int getRows() const;
    bool isCellEmpty(int row, int col) const;
    bool isColumnFull(int col) const;
    bool isValidPosition(int row, int col) const;
    bool isBoardFull() const;
    bool checkLine(int startRow, int startCol, int deltaRow, int deltaCol, Symbol player, int winCondition) const;

private:
    std::vector<std::vector<Cell>> grid;
    int rows;
    int cols;
    int filledCells = 0;
};

#endif // BOARD_H
