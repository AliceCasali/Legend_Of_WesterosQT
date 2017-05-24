//
// Created by giulia on 06/12/16.
//

#include "Lannister.h"

Strategy Lannister::strategy = Strategy::onlySimple;

Lannister::Lannister(int numMagic,int numSimple, float magicStrength, float simpleStrength) : Army(numMagic, numSimple, magicStrength, simpleStrength) {
}

string Lannister::getName() {
    return "Lannister";
}

Strategy Lannister::getStrategy()
{
    return Lannister::strategy;
}
