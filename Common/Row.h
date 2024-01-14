#ifndef ROW_H
#define ROW_H

#include "Cell.h"

class Row {
private:
public:
    int nbrow; // interdire <= 0
    Row();
    void setValue(int r) const;
    int getValue() const;
    bool isEmpty() const;
    
};

#endif // ROW_H