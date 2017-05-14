//
// Created by giulia on 06/12/16.
//

#include "WhiteWalkers.h"
#include "Knight.h"
#include "Zombie.h"

Strategy WhiteWalkers::strategy = Strategy::onlySimple;

WhiteWalkers::WhiteWalkers() : Army(20, 5){
    simpleTroop = new Knight();
    magicTroop = new Zombie();
}

WhiteWalkers::WhiteWalkers(int nz, int nk) : Army(nz, nk) {
    simpleTroop = new Knight();
    magicTroop = new Zombie();
}

string WhiteWalkers::getName() {
    return "WhiteWalkers";
}

Strategy WhiteWalkers::getStrategy()
{
    return WhiteWalkers::strategy;
}
