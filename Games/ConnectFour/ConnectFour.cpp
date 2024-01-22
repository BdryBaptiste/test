#include "ConnectFour.h"
#include <iostream>
#include <time.h>
#include <sstream>

const int NUM_COLS = 7;
const int NUM_ROWS = 4;
const int MIN_COLUMN = 1;
const int MAX_COLUMN = 7;
const int WIN_CONDITION = 4;

ConnectFour::ConnectFour(Display& display, Player* player1, Player* player2)
    : Game(NUM_ROWS, NUM_COLS, display) {
    srand(static_cast<unsigned int>(time(NULL)));
    currentPlayer = Symbol::PLAYER_X;
    this->player1.reset(player1);
    this->player2.reset(player2);
}

void ConnectFour::switchPlayer() {
    currentPlayer = (currentPlayer == Symbol::PLAYER_X) ? Symbol::PLAYER_O : Symbol::PLAYER_X;
}

void ConnectFour::playTurn() {
    int col;
    Symbol playerSymbol = currentPlayer;

    do {
        Player* currentPlayerPointer = (currentPlayer == Symbol::PLAYER_X) ? this->player1.get() : this->player2.get();
        display.showMessage("On demande au joueur de pick un nombre");
        col = currentPlayerPointer->getSingleInput(gameBoard, NUM_COLS);
        display.showMessage("Le joueur a pick un nombre, c'est " + col);
        
        // La colonne doit être ajustée pour l'indexation du tableau (0 à 6)
        int adjustedCol = col - 1;

        // Vérifiez si le choix de la colonne est valide et si la colonne n'est pas pleine
        if (col >= MIN_COLUMN && col <= MAX_COLUMN && !gameBoard.isColumnFull(adjustedCol)) {
            // Trouver la première cellule vide dans la colonne et placer le symbole
            for (int row = gameBoard.getRows() - 1; row >= 0; row--) {
                if (gameBoard.isCellEmpty(row, adjustedCol)) {
                    gameBoard.setCell(row, adjustedCol, playerSymbol);
                    break;
                }
            }
            break; // Sortie de la boucle après un mouvement valide
        } else {
            std::ostringstream messageStream;
            if (col < MIN_COLUMN || col > MAX_COLUMN) {
                messageStream << "Entrée invalide. La colonne doit être entre " << MIN_COLUMN << " et " << MAX_COLUMN;
            } else {
                messageStream << "La colonne " << col << " est pleine. Veuillez choisir une autre colonne.";
            }
            display.showMessage(messageStream.str());
        }
    } while (true);
}


Symbol ConnectFour::checkWinner() {
    Symbol playerSymbol = (currentPlayer == Symbol::PLAYER_X) ? Symbol::PLAYER_X : Symbol::PLAYER_O;

    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (gameBoard.getCell(i, j) == playerSymbol) {
                if (gameBoard.checkLine(i, j, 0, 1, playerSymbol, WIN_CONDITION) ||   // Horizontale
                    gameBoard.checkLine(i, j, 1, 0, playerSymbol, WIN_CONDITION) ||   // Verticale
                    gameBoard.checkLine(i, j, 1, 1, playerSymbol, WIN_CONDITION) ||   // Diagonale bas droite
                    gameBoard.checkLine(i, j, 1, -1, playerSymbol, WIN_CONDITION)) {  // Diagonale bas gauche
                    return playerSymbol;
                }
            }
        }
    }
    return Symbol::EMPTY; // Aucun gagnant trouvé
}



void ConnectFour::displayInstructions() {
    display.showMessage("Chaque joueur choisit une colonne pour déposer son jeton. Le but est d'aligner 4 jetons horizontalement, verticalement ou en diagonale.");
}

std::string ConnectFour::getVictoryMessage(Symbol winner) const {
    if (winner == Symbol::PLAYER_X || winner == Symbol::PLAYER_O) {
        return "Joueur " + symbolToString(winner) + " est gagnant";
    }
    return "Match nul";
}
