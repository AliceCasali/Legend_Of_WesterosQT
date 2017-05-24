//
// Created by acasali on 27/11/16.
//
#include <iostream>

using namespace std;

#include "Targaryen.h"

Strategy Targaryen::strategy = Strategy::onlySimple;


Targaryen::Targaryen(int numMagic,int numSimple, float magicStrength, float simpleStrength) : Army(numMagic, numSimple, magicStrength, simpleStrength) {
}

string Targaryen::getName() {
    return "Targaryen";
}

Strategy Targaryen::getStrategy()
{
    return Targaryen::strategy;
}
