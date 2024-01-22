#include "ConsoleCheckInput.h"

ConsoleheckInputs::ConsoleCheckInputs(Display& display) : display(display) {}

ConsoleCheckInputs* ConsoleCheckInputs::instance = nullptr;

ConsoleCheckInputs* ConsoleCheckInputs::getInstance(Display& display) {
    if (instance == nullptr) {
        instance = new ConsoleCheckInputs(display);
    }
    return instance;
}

int ConsoleCheckInputs::getIntegerInput() {
    int input;
    while (true) {
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            display.showMessage("Entrée invalide. Veuillez entrer un entier : ");
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
        }
    }
}

char ConsoleCheckInputs::getCharInput() {
    char input;
    while (true) {
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            display.showMessage("Entrée invalide. Veuillez entrer un caractère : ");
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
        }
    }
}

std::string ConsoleCheckInputs::getStringInput() {
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            display.showMessage("Entrée invalide. Veuillez entrer une chaîne de caractères : ");
        } else {
            return input;
        }
    }
}

std::pair<int, int> ConsoleCheckInputs::getTwoIntsInput() {
    std::string line;
    int num1, num2;
    while (true) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        if (iss >> num1 && iss >> num2) {
            return std::make_pair(num1, num2);
        } else {
            display.showMessage("Entrée invalide. Veuillez entrer deux entiers séparés par un espace : ");
        }
    }
}
