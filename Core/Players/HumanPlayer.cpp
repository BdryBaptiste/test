#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(Display& display, CheckInputs& checkInput) : display(display), checkInput(checkInput){

}

std::pair<int, int> HumanPlayer::getDoubleInput(const Board& board) {
    int row, col;
    //display.showMessage("Entrez vos coordonnées de mouvement (ligne colonne): ");
    std::tie(row, col) = checkInput.getTwoIntsInput();

    // Valider l'entrée ou la demander à nouveau si nécessaire
    while (!board.isValidPosition(row - 1, col - 1) || !board.isCellEmpty(row - 1, col - 1)) {
        display.showMessage("Mouvement invalide. Veuillez réessayer.");
        std::tie(row, col) = checkInput.getTwoIntsInput();
    }

    return std::make_pair(row - 1, col - 1);
}

int HumanPlayer::getSingleInput(const Board& board, int max) {
    return checkInput.getIntegerInput();
}
