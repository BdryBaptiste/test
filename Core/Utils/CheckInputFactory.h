#ifndef CHECKINPUTFACTORY_H
#define CHECKINPUTFACTORY_H

#include <memory.h>
#include "InputType.h"
#include "ConsoleCheckInput.h"
#include "GUICheckInput.h"
#include "../Display/Display.h"

class CheckInputFactory
{
public:
    CheckInputFactory();
    static std::unique_ptr<CheckInputs> createCheckInput(InputType type, Display& display);
};

#endif // CHECKINPUTFACTORY_H
