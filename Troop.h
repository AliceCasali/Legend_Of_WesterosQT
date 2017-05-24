//
// Created by acasali on 27/11/16.
//

#ifndef LEGENDS_OF_WESTEROS_SIMPLETROOP_H
#define LEGENDS_OF_WESTEROS_SIMPLETROOP_H


class Troop{
public:
    Troop(float strenght) : strenght(strenght){ }

    virtual ~Troop() {}

    virtual float getStrenght();

protected:
    float strenght;
};


#endif //LEGENDS_OF_WESTEROS_SIMPLETROOP_H
