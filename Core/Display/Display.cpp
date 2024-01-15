#include "Display.h"

Display::Display(){
}

void Display::notifyStart(){
    for (auto& observer : observers) {
        observer->updateStatus();
    }
}

void Display::addObserver(InterfaceObserver* observer) {
    observers.push_back(observer);
}

void Display::notifyBoardUpdate(Board& board) {
    for (auto& observer : observers) {
        observer->updateBoard(board);
    }
}

void Display::notifyInstructionsUpdate(const std::string &instruction) {
    for (auto& observer : observers) {
        observer->updateInstructions(instruction);
    }
}

void Display::notifyMessageUpdate(const std::string &message) {
    for (auto& observer : observers) {
        observer->updateMessage(message);
    }
}

void Display::notifyWarningUpdate(const std::string &warning) {
    for (auto& observer : observers) {
        observer->updateWarning(warning);
    }
}

void Display::notifyGameChoiceMenuUpdate() {
    for (auto& observer : observers) {
        observer->updateGameChoiceMenu();
    }
}

void Display::notifyPositionChoiceUpdate(const Board& board, const std::vector<std::pair<int, int>>& validMoves){
    for (auto& observer : observers) {
        observer->updatePositionChoice(board, validMoves);
    }
}
