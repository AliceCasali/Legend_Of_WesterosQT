//
// Created by acasali on 27/11/16.
//

#ifndef LEGENDS_OF_WESTEROS_ARMYFACTORY_H
#define LEGENDS_OF_WESTEROS_ARMYFACTORY_H

#include <string>
#include "SimpleTroop.h"
#include "MagicTroop.h"
//#include "AbstractArmyFactory.h"

using namespace std;


enum class Strategy {onlyMagic, onlySimple, lessDefense};

class Army {
public:
    Army(int m, int s) : numMagic(m), numSimple(s){}
    virtual ~Army();

    virtual string getName() = 0;

    virtual float getPower();
    virtual float getSimplePower();
    virtual float getMagicPower();
    virtual int getNumSimpleTroops();
    virtual int getNumMagicTroops();
    virtual void setNumSimpleTroops(int);
    virtual void setNumMagTroops(int);

    virtual Strategy getStrategy() = 0; //non serve una classe astratta strategy, basta sfruttare questa classe

    static Strategy randomStrategy();

protected:
    int numMagic;
    int numSimple;
    MagicTroop* magicTroop;
    SimpleTroop* simpleTroop;

};



#endif //LEGENDS_OF_WESTEROS_ARMYFACTORY_H
