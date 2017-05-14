//
// Created by giulia on 16/12/16.
//

#include "ConcreteArmyFactory.h"
#include "Stark.h"
#include "Greyjoy.h"
#include "Targaryen.h"
#include "WhiteWalkers.h"
#include "Baratheon.h"


Army *ConcreteArmyFactory::createArmy(int typeSimple, int typeMagic) {
    switch(namehouse) {
        case house::Lannister:
            return new Lannister();
        case house::Stark:
            return new Stark();
        case house::Greyjoy:
            return new Greyjoy();
        case house::Targaryen:
            return new Targaryen();
        case house::WhiteWalkers:
            return new WhiteWalkers();
        case house::Baratheon:
            return new Baratheon();
    }
    return nullptr;
}

Army *ConcreteArmyFactory::createArmy() {
    switch(namehouse) {
        case house::Lannister:
            return new Lannister();
        case house::Stark:
            return new Stark();
        case house::Greyjoy:
            return new Greyjoy();
        case house::Targaryen:
            return new Targaryen();
        case house::WhiteWalkers:
            return new WhiteWalkers();
        case house::Baratheon:
            return new Baratheon();
    }
    return nullptr;
}

ConcreteArmyFactory::ConcreteArmyFactory(string name)
{
    switch(name[0]) {
        case 'L':
            namehouse = house::Lannister;
            break;
        case 'S':
            namehouse = house::Stark;
            break;
        case 'G':
            namehouse = house::Greyjoy;
            break;
        case 'T':
            namehouse = house::Targaryen;
            break;
        case 'W':
            namehouse = house::WhiteWalkers;
            break;
        case 'B':
            namehouse = house::Baratheon;
            break;
    }
}
