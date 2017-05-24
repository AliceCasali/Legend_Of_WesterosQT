//
// Created by acasali on 27/11/16.
//

#include "Map.h"
#include "Stark.h"
#include "Lannister.h"
#include "Greyjoy.h"
#include "Baratheon.h"
#include "WhiteWalkers.h"
#include "Targaryen.h"
#include "ConcreteArmyFactory.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Map::Map() : rows(numRows), columns(numCols) {
    //costruttore di default, la mappa all'inizio è sempre uguale
    matrix[rows][columns];

    int tempMat[rows][columns] = {{0, 6, 3, 5, 0, 0},
                                  {0, 0, 0, 3, 4, 0},
                                  {0, 6, 5, 1, 2, 0},
                                  {0, 4, 2, 1, 0, 0},
                                  {0, 0, 3, 0, 1, 0},
                                  {0, 0, 5, 4, 2, 0},
                                  {0, 1, 6, 4, 0, 0},
                                  {0, 6, 4, 3, 2, 0},
                                  {0, 1, 5, 6, 0, 0},
                                  {0, 0, 2, 3, 5, 0}
    };

    // TODO: usare factory per creare gli elementi della mappa?
    int i;
    for (i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            switch (tempMat[i][j]) {
                case 0:
                    matrix[i][j] = Territory(false);
                    break;
                case 1:
                    matrix[i][j] = Territory(new Stark(10, 25, 4, 1.5));
                    break;
                case 2:
                    matrix[i][j] = Territory(new Lannister(4, 35, 9, 1.5));
                    break;
                case 3:
                    matrix[i][j] = Territory(new Greyjoy(3, 32, 4, 1.5));
                    break;
                case 4:
                    matrix[i][j] = Territory(new Baratheon(8, 7, 5.5, 3.5));
                    break;
                case 5:
                    matrix[i][j] = Territory(new WhiteWalkers(20, 5, 3.5, 3.5));
                    break;
                case 6:
                    matrix[i][j] = Territory(new Targaryen(5, 30, 9, 1.5));
                    break;
            }

        }
    }
}

Territory Map::readTerritory(int r, int c) {
    //try{
    if (r >= 0 && r < rows && c >= 0 && c < columns)
        return matrix[r][c];
    else
        throw "Indici errati.";
    //}catch

}

void Map::writeTerritory(int r, int c, Territory val) {
    //try  {
    if (r >= 0 && r < rows && c >= 0 && c < columns)
        matrix[r][c] = val;
    else
        throw "Indici errati.";
    //}

}

void Map::show() {
    string s0;
    for (int i = 0; i < rows; i++) {
        s0 = "";            //riga separatore
        string s1 = "";     //riga lettere casate
        string s2 = "";     //riga numero truppe semplici
        string s3 = "";     //riga numero truppe magiche
        for (int j = 0; j < columns; j++) {
            s0 += "----";
            if (matrix[i][j].isEarth())    //terra
            {
                s1 += "| " + matrix[i][j].getArmy()->getName().substr(0,1) + " ";
                char sTmp[4];
                sprintf(sTmp, "%03d", matrix[i][j].getArmy()->getNumSimpleTroops());
                s2 += "|" + string(sTmp);
                sprintf(sTmp, "%03d", matrix[i][j].getArmy()->getNumMagicTroops());
                s3 += "|" + string(sTmp);
            }
            else  //acqua
            {
                s1 += "|xxx";
                s2 += "|xxx";
                s3 += "|xxx";
            }

        }
        //stampo riga i
        cout << s0 << "-" << endl << s1 << "|" << endl << s2 << "|"  << endl << s3 << "|"  << endl;
    }
    //stampo separatore per chiudere la matrice
    cout << s0 << "-" << endl;

}

//ritorna true se il combattimento è stato effettuato
bool Map::conquer(int invaderRow, int invaderColumn, int defenderRow, int defenderColumn) {

    // controlli su indici
    if (!(invaderColumn < columns && invaderColumn >= 0 && invaderRow < rows && invaderRow >= 0))
        return false;
    if (!(invaderColumn < columns && invaderColumn >= 0 && defenderRow < rows && defenderRow >= 0))
        return false;

    // assegno variabili
    Army *invader, *defender;
    invader = matrix[invaderRow][invaderColumn].getArmy();
    defender = matrix[defenderRow][defenderColumn].getArmy();

    // TODO: controlli su variabili (casate differenti, acqua ecc.)
    // ...

    // calcolo le forze tenendo conto delle varie strategy
    int invaderStrength, defenderStrength;
    // calcolo forza invader
    invaderStrength = calculateStrength(invaderRow, invaderColumn, true);

    // calcolo forza defender
    defenderStrength = calculateStrength(defenderRow, defenderColumn, false);

    // decido il vincitore
    int result = rand() % (invaderStrength + defenderStrength);
    int numSimTroops;
    int numMagTroops;
    if (result < invaderStrength) {
        //vince invader
        cout << "ha vinto l'invasore: " << matrix[invaderRow][invaderColumn].getArmy()->getName() << endl;
        numSimTroops = defender->getNumSimpleTroops() * 70 / 100;
        numMagTroops = defender->getNumMagicTroops() * 70 / 100;

        if ((numMagTroops + numSimTroops) <= 2) {
            //è sconfitto, si riassegna il territorio
            cout << "lìinvasore che ha conquistato il territorio è: " << matrix[invaderRow][invaderColumn].getArmy()->getName() << endl;

            ConcreteArmyFactory f(invader->getName());
            matrix[defenderRow][defenderColumn] = Territory(f.createArmy());
        }
        else
        {
            //colpito ma non affondato
            defender->setNumSimpleTroops(numSimTroops);
            defender->setNumMagTroops(numMagTroops);
        }
    }
    else {
        //vince defender
        cout << "ha vinto il difensore: " << matrix[defenderRow][defenderColumn].getArmy()->getName() << endl;
        numSimTroops = invader->getNumSimpleTroops() * 70 / 100;
        numMagTroops = invader->getNumMagicTroops() * 70 / 100;

        if ((numMagTroops + numSimTroops) <= 2) {
            //è sconfitto, si riassegna il territorio
            cout << "il difensore che ha conquistato il territorio è: " << matrix[defenderRow][defenderColumn].getArmy()->getName() << endl;
            ConcreteArmyFactory f(defender->getName());
            matrix[invaderRow][invaderColumn] = Territory(f.createArmy());
        }
        else
        {
            //colpito ma non affondato
            invader->setNumSimpleTroops(numSimTroops);
            invader->setNumMagTroops(numMagTroops);
        }

    }

    cout << "truppe semplici modificate perdente:" << numSimTroops << endl;
    cout << "truppe magiche modificate perdente:" << numMagTroops << endl;

    return true;
}

float Map::calculateStrength(int initialRow, int initialColumn, bool isInvader) {
    // crea e inizializza una matrice temporanea per vedere se ho già contato un territorio
    //bool calculatedMat[rows][columns];
    vector<vector<bool>> calculatedMat;
    for (int i = 0; i < rows; i++)
    {
        vector<bool> v;
        for (int j = 0; j < columns; j++) {
            v.push_back(false);
        }
        calculatedMat.push_back(v);
    }

    return calculateStrengthRecursive(initialRow, initialColumn, isInvader, calculatedMat);
}


float Map::calculateStrengthRecursive(int row, int col, bool isInvader, vector<vector<bool>> &calculatedMat) {
    if (!(col < columns && col >= 0 && row < rows && row >= 0))
        return 0;
    if (calculatedMat[row][col] == 1)
        return 0;
    //voleva un puntatore a matrice ma errore quindi vettore di vettori di bool
    Army *army = matrix[row][col].getArmy();

    // tra qui e...
    float power;
    calculatedMat[row][col] = 1;
    Strategy whichStrategy = army->getStrategy();
    switch(whichStrategy){
        case Strategy::onlyMagic:
            if(isInvader)
                power = army->getMagicPower();
            else
                power = army->getPower();
            break;
        case Strategy::onlySimple:
            if(isInvader)
                power = army->getSimplePower();
            else
                power = army->getPower();
            break;
        case Strategy::lessDefense:
            if(isInvader)
                power = army->getPower();
            else
                power = army->getPower() * 60/100;
            break;
        default:
            cerr << "error missing strategy" << endl;
    }
    // ... qui, differenzio la strategy


    power += controlledCall(row+1, col, isInvader, army->getName(), calculatedMat);
    power += controlledCall(row+1, col-1, isInvader, army->getName(), calculatedMat);
    power += controlledCall(row, col-1, isInvader, army->getName(), calculatedMat);
    power += controlledCall(row-1, col-1, isInvader, army->getName(), calculatedMat);
    power += controlledCall(row-1, col, isInvader, army->getName(), calculatedMat);
    power += controlledCall(row-1, col+1, isInvader, army->getName(), calculatedMat);
    power += controlledCall(row, col+1, isInvader, army->getName(), calculatedMat);
    power += controlledCall(row+1, col+1, isInvader, army->getName(), calculatedMat);

    return power;

}

int Map::controlledCall(int row, int col, bool isInvader, string armyName, vector<vector<bool>> &calculatedMat)
{
    if (!(col < columns && col >= 0 && row < rows && row >= 0)) //controllo confini
        return 0;
    if (!matrix[row][col].isEarth()) //controllo acqua
        return 0;
    if (matrix[row][col].getArmy()->getName() == armyName) //controllo armata
        return calculateStrengthRecursive(row, col, isInvader, calculatedMat);
}

void Map::countTroops(string nomeCasata, int &numMagic, int &numSimple){
    numMagic = 0;
    numSimple = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if(matrix[i][j].isEarth() && matrix[i][j].getArmy()->getName() == nomeCasata){
                numMagic += matrix[i][j].getArmy()->getNumMagicTroops();
                numSimple += matrix[i][j].getArmy()->getNumSimpleTroops();
            }
        }
    }
}
