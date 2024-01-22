#include "InputManager.h"

InputManager::InputManager() {}

void InputManager::setCheckInput(std::unique_ptr<CheckInputs> input) {
    checkInput = std::move(input);
}

CheckInputs* InputManager::getCheckInput() {
    return checkInput.get();
}
