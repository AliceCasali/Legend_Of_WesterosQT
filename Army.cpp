//
// Created by acasali on 27/11/16.
//

#include "Map.h"
#include "Army.h"


Army::~Army()
{
    delete simpleTroop;
    delete magicTroop;
}

float Army::getPower() {
    return getSimplePower()+getMagicPower();
}
float Army::getSimplePower() {
    return simpleTroop->getStrenght() * numSimple;
}

float Army::getMagicPower() {
    return magicTroop->getMagic() * numMagic;
}

int Army::getNumSimpleTroops() {
    return numSimple;
}

int Army::getNumMagicTroops() {
    return numMagic;
}

void Army::setNumSimpleTroops(int numSimTroops) {
    numSimple = numSimTroops;
}

void Army::setNumMagTroops(int numMagTroops) {
    numMagic = numMagTroops;
}

Strategy Army::randomStrategy() {

    int randomStrategy;

    randomStrategy = rand() % 3;

    switch (randomStrategy)
    {
        case 0:
            return Strategy::onlySimple;
        case 1:
            return Strategy::lessDefense;
        case 2:
            return Strategy::onlyMagic;
    }
}
