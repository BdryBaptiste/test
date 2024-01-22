#include "CheckInputFactory.h"

CheckInputFactory::CheckInputFactory() {}

static CheckInput* createCheckInput(InputType type) {
    switch (type) {
    case InputType::GUI:
        return new GUICheckInputs(&display);
    case InputType::Console:
        return new ConsoleCheckInputs(&display);
    default:
        return nullptr;
    }
}
