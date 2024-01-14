#ifndef CELL_H
#define CELL_H

#include "Symbols.h"

class Cell {
private:
    Symbol content;
public:
    Cell(Symbol c = Symbol::EMPTY);
    Symbol getContent() const;
    bool setContent(Symbol c, bool allowOverwrite);
    bool isEmpty() const;
    
};

#endif // CELL_H