#include "Symbols.h"

std::string symbolToString(Symbol symbol) {
    switch (symbol) {
        case Symbol::EMPTY: return " ";
        case Symbol::PLAYER_X: return "X";
        case Symbol::PLAYER_O: return "O";
        case Symbol::PLAYER_BLACK: return "B";
        case Symbol::PLAYER_WHITE: return "W";
        default: return "?"; // Placeholder
    }
}
