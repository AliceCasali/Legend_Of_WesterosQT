//
// Created by acasali on 27/11/16.
//

#ifndef LEGENDS_OF_WESTEROS_TARGARYEN_H
#define LEGENDS_OF_WESTEROS_TARGARYEN_H

#include "Army.h"
#include "Troop.h"

class Targaryen : public Army {
public:
    Targaryen(int numMagic,int numSimple, float magicStrength, float simpleStrength);
    string getName() override;
    Strategy getStrategy() override;

    static Strategy strategy;


};


#endif //LEGENDS_OF_WESTEROS_TARGARYEN_H
