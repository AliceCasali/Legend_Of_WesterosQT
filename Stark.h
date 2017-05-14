//
// Created by acasali on 03/12/16.
//

#ifndef LEGENDS_OF_WESTEROS_STARK_H
#define LEGENDS_OF_WESTEROS_STARK_H

#include "SimpleTroop.h"
#include "MagicTroop.h"
#include "Army.h"

class Stark : public Army {
public:
    Stark();
    Stark(int nw,int ns);
    string getName() override;
    Strategy getStrategy() override;

    static Strategy strategy;

};


#endif //LEGENDS_OF_WESTEROS_STARK_H
