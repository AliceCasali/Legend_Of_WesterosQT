//
// Created by acasali on 03/12/16.
//

#include "Stark.h"
#include "Soldier.h"
#include "Wizard.h"

Strategy Stark::strategy = Strategy::onlySimple;

Stark::Stark() : Army(10, 25){
    simpleTroop = new Soldier();
    magicTroop = new Wizard();
}

Stark::Stark(int nw, int ns) : Army(nw, ns) {
    simpleTroop = new Soldier();
    magicTroop = new Wizard();
    }

string Stark::getName() {
    return "Stark";
}

Strategy Stark::getStrategy()
{
    return Stark::strategy;
}
