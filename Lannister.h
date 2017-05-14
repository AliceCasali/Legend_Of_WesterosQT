//
// Created by giulia on 06/12/16.
//

#ifndef LEGENDS_OF_WESTEROS_LANNISTER_H
#define LEGENDS_OF_WESTEROS_LANNISTER_H

#include "SimpleTroop.h"
#include "MagicTroop.h"
#include "Army.h"


class Lannister : public Army{
public:
    Lannister();
    Lannister(int nd,int na);
    string getName() override;
    Strategy getStrategy() override;

    static Strategy strategy;

};


#endif //LEGENDS_OF_WESTEROS_LANNISTER_H
