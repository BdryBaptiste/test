#include "Othello.h"
#include <iostream>
#include <sstream>
#include <time.h>

Othello::Othello(Display& display, Player* player1, Player* player2)
    : Game(BOARD_SIZE, BOARD_SIZE, display) {
    srand(static_cast<unsigned int>(time(NULL)));
    currentPlayer = Symbol::PLAYER_BLACK;
    this->player1.reset(player1);
    this->player2.reset(player2);
    setStartingPoint();
}

void Othello::switchPlayer() {
    currentPlayer = (currentPlayer == Symbol::PLAYER_BLACK) ? Symbol::PLAYER_WHITE : Symbol::PLAYER_BLACK;
}

bool Othello::hasValidMoves(Symbol player) const {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (isValidMoveForPlayer(row, col, player)) {
                return true;
            }
        }
    }
    return false;
}

bool Othello::isValidMoveForPlayer(int row, int col, Symbol player) const {
    if (gameBoard.getCell(row, col) != Symbol::EMPTY || row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return false;
    }

    Symbol opponent = (player == Symbol::PLAYER_BLACK) ? Symbol::PLAYER_WHITE : Symbol::PLAYER_BLACK;
    const int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    
    for (auto &dir : directions) {
        int dRow = dir[0], dCol = dir[1];
        int i = row + dRow, j = col + dCol;
        bool foundOpponent = false;

        while (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE && gameBoard.getCell(i, j) == opponent) {
            i += dRow;
            j += dCol;
            foundOpponent = true;
        }

        if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE && gameBoard.getCell(i, j) == player && foundOpponent) {
            return true;
        }
    }

    return false;
}

void Othello::setStartingPoint(){
    gameBoard.setCell(HALF_BOARD_SIZE_MINUS_ONE, HALF_BOARD_SIZE_MINUS_ONE, Symbol::PLAYER_WHITE);
    gameBoard.setCell(HALF_BOARD_SIZE_MINUS_ONE, HALF_BOARD_SIZE, Symbol::PLAYER_BLACK);
    gameBoard.setCell(HALF_BOARD_SIZE, HALF_BOARD_SIZE_MINUS_ONE, Symbol::PLAYER_BLACK);
    gameBoard.setCell(HALF_BOARD_SIZE, HALF_BOARD_SIZE, Symbol::PLAYER_WHITE);
}

std::map<int, std::pair<int, int>> Othello::getNumberedValidMoves() {
    std::map<int, std::pair<int, int>> numberedMoves;
    int moveNumber = 1;
    for (auto& move : validMoves) {
        numberedMoves[moveNumber++] = move;
    }
    return numberedMoves;
}


void Othello::playTurn() {
    int countBlack, countWhite;
    //CheckInputs* checkInputs = CheckInputs::getInstance(display);
    countPieces(countBlack, countWhite);
    display.notifyMessageUpdate("Nombre de B : " + std::to_string(countBlack) + ", Nombre de W : " + std::to_string(countWhite));
      display.notifyMessageUpdate("Nombre de mouvements valides: " + std::to_string(validMoves.size()));
    calculateValidMoves();
    if (validMoves.empty()) {
        display.notifyWarningUpdate("Aucun mouvement valide pour le joueur " + symbolToString(currentPlayer) + ". Passage au joueur suivant.");
        return;
    }

    auto numberedMoves = getNumberedValidMoves();
    display.notifyPositionChoiceUpdate(gameBoard, validMoves);

    bool validMove = false;
    while (!validMove) {
        display.notifyMessageUpdate("Joueur " + symbolToString(currentPlayer) + ", choisissez un mouvement: ");
        Player* currentPlayerPointer = (currentPlayer == Symbol::PLAYER_BLACK) ? this->player1.get() : this->player2.get();
        int moveNumber = currentPlayerPointer->getSingleInput(gameBoard, validMoves.size());

        if (numberedMoves.find(moveNumber) != numberedMoves.end()) {
            auto chosenMove = numberedMoves[moveNumber];
            if (gameBoard.isCellEmpty(chosenMove.first, chosenMove.second)) {
                gameBoard.setCell(chosenMove.first, chosenMove.second, currentPlayer);
                flipPieces(chosenMove.first, chosenMove.second);
                validMove = true;
            } else {
                display.notifyWarningUpdate("Mouvement invalide. Veuillez réessayer.");
            }
        } else {
            display.notifyWarningUpdate("Mouvement invalide. Veuillez réessayer.");
        }
    }
}


Symbol Othello::checkWinner() {
    int countBlack = 0, countWhite = 0;

    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            Symbol cell = gameBoard.getCell(row, col);
            if (cell == Symbol::PLAYER_BLACK) {
                ++countBlack;
            } else if (cell == Symbol::PLAYER_WHITE) {
                ++countWhite;
            }
        }
    }

    bool movesLeftForBlack = hasValidMoves(Symbol::PLAYER_BLACK);
    bool movesLeftForWhite = hasValidMoves(Symbol::PLAYER_WHITE);

    if (countBlack + countWhite == BOARD_SIZE * BOARD_SIZE || (!movesLeftForBlack && !movesLeftForWhite)) {
        if (countBlack > countWhite) {
            return Symbol::PLAYER_BLACK;
        } else if (countWhite > countBlack) {
            return Symbol::PLAYER_WHITE;
        } else {
            return Symbol::EMPTY;
        }
    }

    return Symbol::EMPTY;
}


void Othello::countPieces(int& countBlack, int& countWhite) const {
    countBlack = 0;
    countWhite = 0;
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (gameBoard.getCell(row, col) == Symbol::PLAYER_BLACK) {
                ++countBlack;
            } else if (gameBoard.getCell(row, col) == Symbol::PLAYER_WHITE) {
                ++countWhite;
            }
        }
    }
}

void Othello::displayInstructions() {
    display.notifyInstructionsUpdate("Chacun son tour, les joueurs doivent poser un pion de sorte qu’il entoure les pions de la couleur adverse afin de pouvoir retourner les pions et les faire basculer dans sa couleur.\nLe terme « entourer » signifie apposer un pion de chaque côté d’une couleur adverse.\nLes pions deviennent alors de la couleur entourée.\nQuand le plateau est plein, le joueur avec le plus de pions remporte la partie.");
}

void Othello::flipPieces(int row, int col) {
    const int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    Symbol opponent = (currentPlayer == Symbol::PLAYER_BLACK) ? Symbol::PLAYER_WHITE : Symbol::PLAYER_BLACK;

    for (auto &dir : directions) {
        std::vector<std::pair<int, int>> toFlip;
        int dRow = dir[0], dCol = dir[1];
        int i = row + dRow, j = col + dCol;

        while (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE && gameBoard.getCell(i, j) == opponent) {
            toFlip.push_back({i, j});
            i += dRow;
            j += dCol;
        }

        if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE && gameBoard.getCell(i, j) == currentPlayer) {
            for (auto &pos : toFlip) {
                gameBoard.setCell(pos.first, pos.second, currentPlayer, true);
            }
        }
    }
}

bool Othello::isValidMove(int row, int col) const {
    if (gameBoard.getCell(row, col) != Symbol::EMPTY || row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return false;
    }

    Symbol opponent = (currentPlayer == Symbol::PLAYER_BLACK) ? Symbol::PLAYER_WHITE : Symbol::PLAYER_BLACK;

    const int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    for (auto &dir : directions) {
        int dRow = dir[0], dCol = dir[1];
        int i = row + dRow, j = col + dCol;
        bool foundOpponent = false;

        while (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE && gameBoard.getCell(i, j) == opponent) {
            i += dRow;
            j += dCol;
            foundOpponent = true;
        }

        if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE && gameBoard.getCell(i, j) == currentPlayer && foundOpponent) {
            return true;
        }
    }

    return false;
}

void Othello::calculateValidMoves() {
    validMoves.clear(); // Efface les mouvements précédents

    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (isValidMove(row, col)) {
                validMoves.push_back(std::make_pair(row, col));
            }
        }
    }
}

std::string Othello::getVictoryMessage(Symbol winner) const {
    if (winner == Symbol::PLAYER_BLACK) {
        return "Couleur noire est gagnante";
    } else if (winner == Symbol::PLAYER_WHITE) {
        return "Couleur blanche est gagnante";
    }
    return "Match nul";
}