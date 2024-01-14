#include "ConsoleObserver.h"

ConsoleObserver::ConsoleObserver(){
}

void ConsoleObserver::updateStart(){
    std::cout<<"Initialisation de la séquence de jeux"<<std::endl;
}

void ConsoleObserver::updateBoard(Board& board){
    int rows = board.getRows();
    int cols = board.getCols();

    std::cout << " ";
    for (int j = 0; j < cols; ++j) {
        std::cout << "   " << j + 1;
    }
    std::cout << std::endl;

    for (int i = 0; i < rows; ++i) {
        std::cout << "  ";  
        for (int j = 0; j < cols; ++j) {
            std::cout << "----";
        }
        std::cout << "-" << std::endl;

        std::cout << i + 1 << " ";
        for (int j = 0; j < cols; ++j) {
            Symbol cellSymbol = board.getCell(i, j);
            std::string cellChar = symbolToString(cellSymbol);
            std::cout << "| " << cellChar << " ";
        }
        std::cout << "|" << std::endl;
    }

    std::cout << "  ";
    for (int j = 0; j < cols; ++j) {
        std::cout << "----";
    }
    std::cout << "-" << std::endl;
}

void ConsoleObserver::updatePositionChoice(const Board& board, const std::vector<std::pair<int, int>>& validMoves) {
    std::map<std::pair<int, int>, int> moveNumbers;
    for (size_t i = 0; i < validMoves.size(); ++i) {
        moveNumbers[validMoves[i]] = i + 1;
    }

    int rows = board.getRows();
    int cols = board.getCols();

    std::cout << " ";
    for (int j = 0; j < cols; ++j) {
        std::cout << "   " << j + 1;
    }
    std::cout << std::endl;

    for (int i = 0; i < rows; ++i) {
        std::cout << "  ";
        for (int j = 0; j < cols; ++j) {
            std::cout << "----";
        }
        std::cout << "-" << std::endl;

        std::cout << i + 1 << " ";
        for (int j = 0; j < cols; ++j) {
            Symbol cellSymbol = board.getCell(i, j);
            std::string cellChar = symbolToString(cellSymbol);
            if (cellSymbol == Symbol::EMPTY && moveNumbers.find({i, j}) != moveNumbers.end()) {
                std::cout << "| " << moveNumbers[{i, j}] << " ";
            } else {
                std::cout << "| " << cellChar << " ";
            }
        }
        std::cout << "|" << std::endl;
    }

    std::cout << "  ";
    for (int j = 0; j < cols; ++j) {
        std::cout << "----";
    }
    std::cout << "-" << std::endl;
}

//Can change style to make them different in the console
void ConsoleObserver::updateInstructions(const std::string &instruction){
    std::cout << instruction << std::endl;
}
void ConsoleObserver::updateMessage(const std::string &message){
    std::cout << message << std::endl;
}
void ConsoleObserver::updateWarning(const std::string &warning){
    std::cout << warning << std::endl;
}
void ConsoleObserver::updateMenu(const std::string &menu){
    std::cout << menu << std::endl;
}
