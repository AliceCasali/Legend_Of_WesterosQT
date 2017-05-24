//
// Created by giulia on 06/12/16.
//

#include "Greyjoy.h"

Strategy Greyjoy::strategy = Strategy::onlySimple;


Greyjoy::Greyjoy(int numMagic,int numSimple, float magicStrength, float simpleStrength) : Army(numMagic, numSimple, magicStrength, simpleStrength) {
}

string Greyjoy::getName() {
    return "Greyjoy";
}

Strategy Greyjoy::getStrategy()
{
    return Greyjoy::strategy;
}
