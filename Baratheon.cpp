//
// Created by giulia on 06/12/16.
//

#include "Baratheon.h"

Strategy Baratheon::strategy = Strategy::onlySimple;

Baratheon::Baratheon(int numMagic,int numSimple, float magicStrength, float simpleStrength) : Army(numMagic, numSimple, magicStrength, simpleStrength) {
}

string Baratheon::getName() {
    return "Baratheon";
}

Strategy Baratheon::getStrategy()
{
    return Baratheon::strategy;
}
