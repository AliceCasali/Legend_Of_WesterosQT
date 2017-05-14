//
// Created by acasali on 27/11/16.
//

#ifndef LEGENDS_OF_WESTEROS_MAGICTROOP_H
#define LEGENDS_OF_WESTEROS_MAGICTROOP_H


class MagicTroop {
public:

    MagicTroop(float attack, float defense) : attack(attack), defense(defense) { }

    virtual float getMagic();

protected:
    float attack;
    float defense;
    float magic;


};


#endif //LEGENDS_OF_WESTEROS_MAGICTROOP_H
