//
// Created by giulia on 06/12/16.
//

#ifndef LEGENDS_OF_WESTEROS_WHITEWALKERS_H
#define LEGENDS_OF_WESTEROS_WHITEWALKERS_H


#include "Army.h"
#include "SimpleTroop.h"
#include "MagicTroop.h"

class WhiteWalkers : public Army{
public:
    WhiteWalkers();
    WhiteWalkers(int nz,int nk);
    string getName() override;
    Strategy getStrategy() override;

    static Strategy strategy;

};


#endif //LEGENDS_OF_WESTEROS_WHITEWALKERS_H
