//
// Created by giulia on 06/12/16.
//

#include "Baratheon.h"
#include "RedWizard.h"
#include "Knight.h"

Strategy Baratheon::strategy = Strategy::onlySimple;

Baratheon::Baratheon() : Army(8, 7) {
    simpleTroop = new Knight();
    magicTroop = new RedWizard();
}

Baratheon::Baratheon(int nrw, int nk) : Army(nrw, nk) {
    simpleTroop = new Knight();
    magicTroop = new RedWizard();
}

string Baratheon::getName() {
    return "Baratheon";
}

Strategy Baratheon::getStrategy()
{
    return Baratheon::strategy;
}
