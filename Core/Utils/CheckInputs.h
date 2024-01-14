#ifndef CHECKINPUTS_H
#define CHECKINPUTS_H

#include <utility> // std::pair
#include <memory> // std::unique_ptr
#include "../Display/Display.h"

class CheckInputs {
private:
    Display& display;
    static CheckInputs* instance;
    CheckInputs(Display& display);

public:
    static CheckInputs* getInstance(Display& display);
    int getIntegerInput();
    char getCharInput();
    std::string getStringInput();
    std::pair<int, int> getTwoIntsInput();
};

#endif // CHECKINPUTS_H
