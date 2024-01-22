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
    virtual  CheckInputs* getInstance(Display& display);
    virtual int getIntegerInput() = 0;
    virtual char getCharInput() = 0;
    virtual std::string getStringInput() = 0;
    virtual std::pair<int, int> getTwoIntsInput();
};

#endif // CHECKINPUTS_H
