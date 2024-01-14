#ifndef SYMBOLS_H
#define SYMBOLS_H

#include <string>

enum class Symbol : char {
    EMPTY = ' ',
    PLAYER_X = 'X',
    PLAYER_O = 'O',
    PLAYER_BLACK = 'B',
    PLAYER_WHITE = 'W'
};

std::string symbolToString(Symbol symbol);

#endif // SYMBOLS_H
