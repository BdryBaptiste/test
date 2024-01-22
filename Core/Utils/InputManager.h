#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "CheckInputs.h"

class InputManager
{  
public:
    void setCheckInput(std::unique_ptr<CheckInputs> input);

    CheckInputs* getCheckInput();

private:
    std::unique_ptr<CheckInputs> checkInput;
};

#endif // INPUTMANAGER_H
