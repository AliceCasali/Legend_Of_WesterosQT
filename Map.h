//
// Created by acasali on 27/11/16.
//

#ifndef LEGENDS_OF_WESTEROS_MAP_H
#define LEGENDS_OF_WESTEROS_MAP_H

#include <vector>

#include "Territory.h"
#define numRows 10
#define numCols 6

typedef double typeElem;

using namespace std;

class Map {

public:
    Map();

    //Map(int r, int c);

    void show();

    Territory readTerritory(int r, int c);

    void writeTerritory(int r, int c, Territory val);

    int getNumRows() const {
        return rows;
    }

    int getNumColumns() const {
        return columns;
    }

    bool conquer(int invaderRow, int invaderColumn, int defenderRow, int defenderColumn);

    //static int numRows, numCols;

private:
    int rows;
    int columns;
    Territory matrix[numRows][numCols];

    float calculateStrength(int initialRow, int initialColumn, bool isInvader);
    float calculateStrengthRecursive(int initialRow, int initialColumn, bool isInvader, vector<vector<bool>> &calculatedMat);
    int controlledCall(int row, int col, bool isInvader, string armyName, vector<vector<bool>> &calculatedMat);

};



#endif //LEGENDS_OF_WESTEROS_MAP_H
