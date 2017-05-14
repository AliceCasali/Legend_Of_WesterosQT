//
// Created by acasali on 27/11/16.
//

#include "Soldier.h"

Soldier::Soldier() : SimpleTroop(1, 2) {
    strenght = ((attack + defense)/2);
}
