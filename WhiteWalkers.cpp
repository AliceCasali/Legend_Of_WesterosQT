//
// Created by giulia on 06/12/16.
//

#include "WhiteWalkers.h"

Strategy WhiteWalkers::strategy = Strategy::onlySimple;

WhiteWalkers::WhiteWalkers(int numMagic,int numSimple, float magicStrength, float simpleStrength) : Army(numMagic, numSimple, magicStrength, simpleStrength) {
}

string WhiteWalkers::getName() {
    return "WhiteWalkers";
}

Strategy WhiteWalkers::getStrategy()
{
    return WhiteWalkers::strategy;
}
