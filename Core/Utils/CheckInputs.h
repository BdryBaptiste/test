#ifndef CHECKINPUTS_H
#define CHECKINPUTS_H

#include <utility> // std::pair
#include <memory> // std::unique_ptr
#include <stdexcept>
#include "../Display/Display.h"
#include <unordered_set>

class CheckInputs {
protected:
    CheckInputs(Display& display) : display(display){}
    Display& display;

public:
    virtual ~CheckInputs() = default;
    virtual int getIntegerInput() = 0;
    virtual char getCharInput() = 0;
    virtual std::string getStringInput() = 0;
    virtual std::pair<int, int> getTwoIntsInput() = 0;

    // Other existing methods
};

#endif // CHECKINPUTS_H
