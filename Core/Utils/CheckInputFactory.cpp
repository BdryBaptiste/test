#include "CheckInputFactory.h"

CheckInputFactory::CheckInputFactory() {}

static std::unique_ptr<CheckInputs> CheckInputFactory::createCheckInput(InputType type, Display& display) {
    if (type == InputType::GUI) {
        return std::make_unique<GUICheckInput>(display);
    } else if (type == InputType::Console) {
        return std::make_unique<ConsoleCheckInput>(display);
    } else {
        throw std::invalid_argument("Invalid InputType");
    }
}
