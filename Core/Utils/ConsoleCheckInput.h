#ifndef CONSOLECHECKINPUTS_H
#define CONSOLECHECKINPUTS_H

#include <utility>
#include <memory>
#include "../Display/Display.h"
#include "CheckInputs.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ConsoleCheckInputs : public CheckInput {
public:
    static CheckInputs* getInstance(Display& display) override;
    int getIntegerInput() override;
    char getCharInput() override;
    std::string getStringInput() override;
    std::pair<int, int> getTwoIntsInput() override;
};

#endif // CONSOLECHECKINPUTS_H
