#ifndef CONSOLECHECKINPUTS_H
#define CONSOLECHECKINPUTS_H

#include "CheckInputs.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <string>


class ConsoleCheckInputs : public CheckInputs {
private:


public:
    ConsoleCheckInputs(Display& display);
    int getIntegerInput() override;
    char getCharInput() override;
    // std::string getStringInput() override;
    std::pair<int, int> getTwoIntsInput() override;
};

#endif // CONSOLECHECKINPUTS_H
