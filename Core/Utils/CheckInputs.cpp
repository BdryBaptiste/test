#include "CheckInputs.h"

CheckInputs::CheckInputs(Display& display) : display(display) {
    instances.insert(this);
}

CheckInputs* CheckInputs::getInstance(Display& display) {
    if (!instances.empty()) {
        return *instances.begin();
    }
    return nullptr;
}
