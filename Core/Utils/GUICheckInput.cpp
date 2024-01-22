#include "GUICheckInput.h"

GUICheckInputs* GUICheckInputs::instance = nullptr;

GUICheckInputs::GUICheckInputs(Display& display) : CheckInputs(display) {}

int GUICheckInputs::getIntegerInput() {
    // GUI-specific implementation
}

char GUICheckInputs::getCharInput() {
    // GUI-specific implementation
}

std::string GUICheckInputs::getStringInput() {
    // GUI-specific implementation
}

std::pair<int, int> GUICheckInputs::getTwoIntsInput() {
    // GUI-specific implementation
}

// ... (other methods if necessary)
