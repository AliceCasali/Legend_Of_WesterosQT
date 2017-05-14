//
// Created by giulia on 06/12/16.
//

#include "Zombie.h"

Zombie::Zombie() : MagicTroop(1, 6) {
    magic = ((attack + defense)/2);
}
