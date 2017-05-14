//
// Created by giulia on 16/12/16.
//

#ifndef LEGENDS_OF_WESTEROS_CONCRETEARMYFACTORY_H
#define LEGENDS_OF_WESTEROS_CONCRETEARMYFACTORY_H

#include <string>

#include "AbstractArmyFactory.h"
#include "Lannister.h"



class ConcreteArmyFactory : public AbstractArmyFactory {
public:
    ConcreteArmyFactory(house namehouse) : namehouse(namehouse){}
    ConcreteArmyFactory(std::string name);
    Army* createArmy(int typeSimple, int typeMagic) override ;
    Army* createArmy() override ;

private:
    house namehouse;
};


#endif //LEGENDS_OF_WESTEROS_CONCRETEARMYFACTORY_H
