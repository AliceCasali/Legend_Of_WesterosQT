//
// Created by acasali on 03/12/16.
//

#include "Stark.h"

Strategy Stark::strategy = Strategy::onlySimple;

Stark::Stark(int numMagic,int numSimple, float magicStrength, float simpleStrength) : Army(numMagic, numSimple, magicStrength, simpleStrength) {
}

string Stark::getName() {
    return "Stark";
}

Strategy Stark::getStrategy()
{
    return Stark::strategy;
}
