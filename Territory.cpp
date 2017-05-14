//
// Created by acasali on 11/03/17.
//

#include "Territory.h"

Territory::Territory() : earth(true) {}

Territory::Territory(bool e) : earth(e) {}

Territory::Territory(Army *a) : earth(true), army(a) {}
