//
// Created by acasali on 27/11/16.
//

#include "Dragon.h"

Dragon::Dragon() : MagicTroop(10, 8) {
    magic = ((attack + defense)/2);
}
