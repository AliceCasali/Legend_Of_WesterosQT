//
// Created by acasali on 03/12/16.
//

#ifndef LEGENDS_OF_WESTEROS_STARK_H
#define LEGENDS_OF_WESTEROS_STARK_H

#include "Troop.h"
#include "Army.h"

class Stark : public Army {
public:
    Stark(int numMagic,int numSimple, float magicStrength, float simpleStrength);
    string getName() override;
    Strategy getStrategy() override;

    static Strategy strategy;

};

#endif //LEGENDS_OF_WESTEROS_STARK_H
