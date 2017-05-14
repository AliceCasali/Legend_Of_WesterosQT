//
// Created by acasali on 27/11/16.
//
#include <iostream>

using namespace std;

#include "Targaryen.h"
#include "Soldier.h"
#include "Dragon.h"

Strategy Targaryen::strategy = Strategy::onlySimple;

Targaryen::Targaryen() : Army(5, 30) {
    simpleTroop = new Soldier();
    magicTroop = new Dragon();
}

Targaryen::Targaryen(int nd, int ns) : Army(nd, ns) {
    simpleTroop = new Soldier();
    magicTroop = new Dragon();
}

string Targaryen::getName() {
    return "Targaryen";
}

Strategy Targaryen::getStrategy()
{
    return Targaryen::strategy;
}
