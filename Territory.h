//
// Created by acasali on 11/03/17.
//

#ifndef LEGENDS_OF_WESTEROS_TERRITORY_H
#define LEGENDS_OF_WESTEROS_TERRITORY_H

#include "Army.h"

class Territory {
public:
    Territory();
    Territory(bool e);
    Territory(Army* army);



    Army *getArmy() const {
        return army;
    }

    void setArmy(Army *army) {
        Territory::army = army;
    }


    bool isEarth() const {
        return earth;
    }

private:
    bool earth;
    Army* army;


};

#endif //LEGENDS_OF_WESTEROS_TERRITORY_H
