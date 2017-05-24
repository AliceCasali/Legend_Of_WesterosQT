//
// Created by giulia on 16/12/16.
//

#include "ConcreteArmyFactory.h"
#include "Stark.h"
#include "Greyjoy.h"
#include "Targaryen.h"
#include "WhiteWalkers.h"
#include "Baratheon.h"


Army *ConcreteArmyFactory::createArmy(int strength, int magic) {
    switch(namehouse) {
        case house::Lannister:
            return new Lannister(4, 35, 9, 1.5);
        case house::Stark:
            return new Stark(10, 25, 4, 1.5);
        case house::Greyjoy:
            return new Greyjoy(3, 32, 4, 1.5);
        case house::Targaryen:
            return new Targaryen(5, 30, 9, 1.5);
        case house::WhiteWalkers:
            return new WhiteWalkers(20, 5, 3.5, 3.5);
        case house::Baratheon:
            return new Baratheon(8, 7, 5.5, 3.5);
    }
    return nullptr;
}

Army *ConcreteArmyFactory::createArmy() {
    switch(namehouse) {
        case house::Lannister:
            return new Lannister(4, 35, 9, 1.5);
        case house::Stark:
            return new Stark(10, 25, 4, 1.5);
        case house::Greyjoy:
            return new Greyjoy(3, 32, 4, 1.5);
        case house::Targaryen:
            return new Targaryen(5, 30, 9, 1.5);
        case house::WhiteWalkers:
            return new WhiteWalkers(20, 5, 3.5, 3.5);
        case house::Baratheon:
            return new Baratheon(8, 7, 5.5, 3.5);
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
