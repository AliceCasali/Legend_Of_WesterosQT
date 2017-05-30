//
// Created by giulia on 06/12/16.
//

#ifndef LEGENDS_OF_WESTEROS_WHITEWALKERS_H
#define LEGENDS_OF_WESTEROS_WHITEWALKERS_H

#include "Army.h"
#include "Troop.h"

class WhiteWalkers : public Army{
public:
    WhiteWalkers(int numMagic,int numSimple, float magicStrength, float simpleStrength);
    string getName() override;
    Strategy getStrategy() override;

    static Strategy strategy;

};

#endif //LEGENDS_OF_WESTEROS_WHITEWALKERS_H
