#include "Cell.h"

Cell::Cell(Symbol c) : content(c) {}

Symbol Cell::getContent() const {
    return content;
}

bool Cell::setContent(Symbol c, bool allowOverwrite) {
    if (allowOverwrite || isEmpty()) {
        content = c;
        return true;
    }
    return false;
}

bool Cell::isEmpty() const {
    return content == Symbol::EMPTY;
}
