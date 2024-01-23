#include "HumanPlayer.h"
#include <QDebug>

HumanPlayer::HumanPlayer(Display& display, CheckInputs& checkInput) : display(display), checkInput(checkInput){

}

std::pair<int, int> HumanPlayer::getDoubleInput(const Board& board) {
    qDebug() << "Debug test";
    int row, col;
    display.showMessage("Entrez vos coordonnées de mouvement (ligne colonne): ");
    std::tie(row, col) = checkInput.getTwoIntsInput();

    // Valider l'entrée ou la demander à nouveau si nécessaire
    while (!board.isValidPosition(row, col) || !board.isCellEmpty(row, col)) {
        display.showMessage("Mouvement invalide. Veuillez réessayer.");
        std::tie(row, col) = checkInput.getTwoIntsInput();
    }

    return std::make_pair(row, col);
}

int HumanPlayer::getSingleInput(const Board& board, int max) {
    return checkInput.getIntegerInput();
}
