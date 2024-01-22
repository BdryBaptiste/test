#ifndef CHECKINPUTFACTORY_H
#define CHECKINPUTFACTORY_H

#include "InputType.h"
#include "ConsoleCheckInput.h"
#include "GUICheckInput.h"

class CheckInputFactory
{
public:
    Display& display;
    CheckInputFactory();
    static CheckInput* createCheckInput(InputType type);
};

#endif // CHECKINPUTFACTORY_H
