//
// Created by giulia on 06/12/16.
//

#include "Greyjoy.h"
#include "Archer.h"
#include "Wizard.h"

Strategy Greyjoy::strategy = Strategy::onlySimple;
Greyjoy::Greyjoy() : Army(3, 32) {
    simpleTroop = new Archer();
    magicTroop = new Wizard();
}

Greyjoy::Greyjoy(int nw, int na) : Army(nw, na) {
    simpleTroop = new Archer();
    magicTroop = new Wizard();
}


string Greyjoy::getName() {
    return "Greyjoy";
}

Strategy Greyjoy::getStrategy()
{
    return Greyjoy::strategy;
}
