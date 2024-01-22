#include "CheckInputFactory.h"

CheckInputFactory::CheckInputFactory() {}

static std::unique_ptr<CheckInputs> CheckInputFactory::createCheckInput(InputType type) {
    if (type == InputType::GUI) {
        return std::make_unique<GUICheckInput>();
    } else if (type == InputType::Console) {
        return std::make_unique<ConsoleCheckInput>();
    } else {
        throw std::invalid_argument("Invalid InputType");
    }
}
