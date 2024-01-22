#ifndef GUICHECKINPUTS_H
#define GUICHECKINPUTS_H

#include "CheckInputs.h"

class GUICheckInputs : public CheckInputs {
private:
    GUICheckInputs(Display& display);

public:
    int getIntegerInput() override;
    char getCharInput() override;
    std::string getStringInput() override;
    std::pair<int, int> getTwoIntsInput() override;
};

#endif // GUICHECKINPUTS_H
