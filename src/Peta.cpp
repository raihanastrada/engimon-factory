#include "Peta.h"
#include "Player.h"
#include "Engimon.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int Peta::turn = 0;

Peta::Peta(string filename, int _engimonCount, Player _player) : minLvl(int _minLvl) {
    // open file
    ifstream readfile(filename);
    if (readfile.fail())
    {
        // kondisi gagal
        cout << "error: file not found" << endl;
    }
    else
    {
        // open file aman
        string line;
        int i = 0;
        while (getline(readfile, line)) // keep reading file
        {
            int j;
            for (j = 0; j < 10; j++)
            {
                if (line[j] == '-')
                {
                    Cell cell Cell(line[j], "grassland", NULL);
                }
                else
                {
                    Cell cell Cell(line[j], "ocean", NULL);
                }
                setCell(cell,i,j);
            }
            i++;
        }
        // close file
        readfile.close();
        this->engimonCount = _engimonCount;
        this->player = _player;
    }
}

Peta::~Peta() {
    if(cell != NULL) {
        for(int i = 0; i < 10; ++i) {
            delete[] cell[i];   
        }
        delete[] cell;
    }
}
        
Cell Peta::getCell(int i, int j) {
    if (i < 0 || i > 9 || j < 0 || j > 11)
    {
        throw "invalid index";
    }
    return cell[i][j];
}
const int Peta::getMinLvl() {
    return this->minLvl;
}
int Peta::getEngimonCount() {
    return this->engimonCount;
}
int Peta::getPlayerX() {
    return this->player.getLocation().GetX();
}
int Peta::getPlayerY() {
    return this->player.getLocation().GetY();
}
int Peta::getEngimonX() {
    return this->player.getEngimonLocation().GetX();
}
int Peta::getEngimonY() {
    return this->player.getEngimonLocation().GetY();
}

void Peta::setCell(Cell _cell, int i, int j) {
    if (i < 0 || i > 9 || j < 0 || j > 11)
    {
        throw "invalid index";
    }
    cell[i][j] = _cell;
}
void Peta::setEngimonCount(int count) {
    this->engimonCount = count;
}
void Peta::increaseTurn() {
    turn += 1;
}

void Peta::viewmap() {
    int i,j;
    for(i = 0; i < 10; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (j == getPlayerX() && i == getPlayerY())
            {
                /* Jika lokasi player */
                cout << "P";
            }
            else if (j == getEngimonX() && i == getEngimonY())
            {
                /* Jika lokasi Active Engimon */
                cout << "X";
            }
            else
            {
                cell[i][j].show();
                if (j == 11)
                {
                    cout << endl;
                }
            }
        }
    }
}
void Peta::information() {
    cout << "Keterangan: " << endl;
    cout << endl;
    cout << "W/w: Water engimon" << endl;
    cout << "I/i: Ice engimon" << endl;    
    cout << "F/f: Fire engimon" << endl;
    cout << "G/g: Ground engimon" << endl;
    cout << "E/e: Electric engimon" << endl;
    cout << "L/l: Fore/Electric engimon" << endl;
    cout << "S/s: Water/Ice engimon" << endl;
    cout << "N/n: Water/Ground engimon" << endl;
    cout << endl;
    cout << "P: Player" << endl;
    cout << "X: Active Engimon" << endl;
    cout << endl;
    cout << "-: Grassland" << endl;
    cout << "o: Sea" << endl;
}
void Peta::randomMove() {
    if (turn%5 == 0)
    {
        /* Jika turn kelipatan 5 */
        cout << "randomMove" << endl;
    }
}
void Peta::spawnEnemy() {
    if (this->engimonCount != 0)
    {
        /* Cuma bisa spawn kalo masih ada jatah buat engimon */
        cout << "spawnEnemy" << endl;
    }
}