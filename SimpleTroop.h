//
// Created by acasali on 27/11/16.
//

#ifndef LEGENDS_OF_WESTEROS_SIMPLETROOP_H
#define LEGENDS_OF_WESTEROS_SIMPLETROOP_H


class SimpleTroop{
public:
    SimpleTroop(float defense, float attack) : defense(defense), attack(attack) { }

    virtual ~SimpleTroop() {}

    virtual float getStrenght();

protected:
    float defense;
    float attack;
    float strenght;
};


#endif //LEGENDS_OF_WESTEROS_SIMPLETROOP_H
