//
// Created by giulia on 06/12/16.
//

#include "Lannister.h"
#include "Dragon.h"
#include "Archer.h"

Strategy Lannister::strategy = Strategy::onlySimple;

Lannister::Lannister() : Army(4, 35) {
    simpleTroop = new Archer();
    magicTroop = new Dragon();
}

Lannister::Lannister(int nd, int na) : Army(nd, na) {
    simpleTroop = new Archer();
    magicTroop = new Dragon();
}

string Lannister::getName() {
    return "Lannister";
}

Strategy Lannister::getStrategy()
{
    return Lannister::strategy;
}
