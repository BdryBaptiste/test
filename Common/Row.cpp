#include "Row.h"
#include <iostream>

Row::Row(){}

void Row::setValue(int r) const{
    if(r <= 0){
        std::cout << "Erreur nbrow <= 0";
    } else {
        nbrow = r;
    }
}

int Row::getValue() const {
    return nbrow;
}

bool Row::isEmpty() const {
    for(int i=0;i<nbrow;i++){

    }
}
