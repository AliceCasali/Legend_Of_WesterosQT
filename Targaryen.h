//
// Created by acasali on 27/11/16.
//

#ifndef LEGENDS_OF_WESTEROS_TARGARYEN_H
#define LEGENDS_OF_WESTEROS_TARGARYEN_H

#include "Army.h"
#include "Soldier.h"
#include "Dragon.h"
#include "SimpleTroop.h"
#include "MagicTroop.h"

class Targaryen : public Army {
public:
    Targaryen();
    Targaryen(int nd,int ns);
    string getName() override;
    Strategy getStrategy() override;

    static Strategy strategy;


};


#endif //LEGENDS_OF_WESTEROS_TARGARYEN_H
