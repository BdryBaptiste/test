#ifndef CHECKINPUTS_H
#define CHECKINPUTS_H

#include <utility> // std::pair
#include <memory> // std::unique_ptr
#include <stdexcept>
#include "../Display/Display.h"
#include <unordered_set>

class CheckInputs {
protected:
    CheckInputs(Display& display);
    Display& display;
    static std::unordered_set<CheckInputs*> instances;

public:
    virtual ~CheckInputs(){
        instances.erase(this);
    }

    static CheckInputs* getInstance(Display& display);
    virtual int getIntegerInput() = 0;
    virtual char getCharInput() = 0;
    virtual std::string getStringInput() = 0;
    virtual std::pair<int, int> getTwoIntsInput() = 0;

    // Other existing methods
};

#endif // CHECKINPUTS_H
