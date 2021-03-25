#include "Peta.h"
#include "Player.h"
#include "Engimon.hpp"
#include "Elements.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <experimental/random>
#include <math.h>

using namespace std;

int Peta::turn = 0;

Peta::Peta(string filename, int _engimonCount, Player _player, int _minLvl) : minLvl(_minLvl) {
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
                Cell c;
                if (line[j] == 'o')
                {
                    c.setView(line[j]);
                }
                cell[i][j] = c;
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
    // if(cell != NULL) {
    //     for(int i = 0; i < 10; ++i) {
    //         delete[] cell[i];   
    //     }
    //     delete[] cell;
    // }
}
        
Cell Peta::getCell(int i, int j) {
    if (isValidIdx(i,j))
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

void Peta::setCell(Cell c, int i, int j) {
    try
    {
        Cell cell = getCell(i,j);
        cell = c;
    }
    catch(string e)
    {
        cout << "error: " << e << endl;
    }
}
void Peta::setEngimonCount(int count) {
    this->engimonCount = count;
}
void Peta::increaseTurn() {
    turn += 1;
}

void Peta::viewmap() {
    int i,j;
    char c;
    for(i = 0; i < 10; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (j == getPlayerX() && i == getPlayerY())
            {
                /* Jika lokasi player */
                cout << 'P';
            }
            else if (j == getEngimonX() && i == getEngimonY())
            {
                /* Jika lokasi Active Engimon */
                cout << 'X';
            }
            else
            {
                cell[i][j].show(this->minLvl);
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
    cout << "L/l: Fire/Electric engimon" << endl;
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
        int i,j;
        for(i = 0; i < 10; i++)
        {
            for (j = 0; j < 12; j++)
            {
                if (cell[i][j].getEngimon() != NULL)
                {
                    int rngI, rngJ;
                    do
                    {
                        rngI = random(-1,1);
                        rngJ = random(-1,1);
                    } while (!isValidIdx(i+rngI,j+rngJ) && sqrt(pow(i-(i+rngI),2) + pow(j-(j+rngJ),2)) > 1 && !isValidMove(cell[i][j].getEngimon(),cell[i+rngI][j+rngJ]) && !isPlayers(i+rngI,j+rngJ));
                    Cell c = getCell(rngI,rngJ);
                    moveEngimon(cell[i][j],c);
                }
            }
        }
    }
}
void Peta::spawnEnemy() {
    if (this->engimonCount != 0)
    {
        /* Cuma bisa spawn kalo masih ada jatah buat engimon */
        cout << "spawnEnemy" << endl;
        this->engimonCount -= 1;
    }
}
void Peta::moveEngimon(Cell c1, Cell c2) {
    c2.setEngimon(c1.getEngimon());
    c1.setEngimon(NULL);
}
bool Peta::isValidMove(Engimon* engimon, Cell c) {
    Element fire("Fire");
    Element water("Water");
    Element electric("Electric");
    Element ground("Ground");
    Element ice("Ice");
    if (engimon->getElements().at(0) == water || engimon->getElements().at(1) == water || engimon->getElements().at(0) == ice || engimon->getElements().at(1) == ice)
    {
        if ( (engimon->getElements().at(0) == water && engimon->getElements().at(1) == ground) || (engimon->getElements().at(0) == ground && engimon->getElements().at(1) == water) )
        {
            return (c.getType() == "sea" || c.getType() == "grassland");
        }
        // Jika ada elemen es atau water, bisa berjalan di air
        return c.getType() == "sea";
    }
    else
    {
        return c.getType() == "grassland";
    }
}
bool Peta::isPlayers(int i, int j) {
    return j != getPlayerX() && i != getPlayerY() && j != getEngimonX() && i != getEngimonY();
}
bool Peta::isValidIdx(int i, int j) {
    return !(i < 0 || i > 9 || j < 0 || j > 11);
}
int Peta::random(int min, int max) {
    experimental::randint(min, max);
}
void Peta::battle(){
    // cari adjacent wild engimon
    // prioritas adjacent engimon yang dipilih random
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    mt19937 rng((unsigned long long)new char); // pseudo-random generator
    vector<pair<int, int>> adjacent_cell_coordinates;
    for (int i=0; i<(int)dx.size(); i++) adjacent_cell_coordinates.emplace_back(getPlayerX()+dx[i], getPlayerY()+dy[i]);
    shuffle(adjacent_cell_coordinates.begin(), adjacent_cell_coordinates.end(), rng);

    pair<int, int> wild_engimon_cell_coordinate = make_pair(-1, -1);
    for (auto &coord : adjacent_cell_coordinates){
        int x = coord.first, y = coord.second;
        if (cell[x][y].getEngimon()){
            // ada engimon di (x, y)
            wild_engimon_cell_coordinate = coord;
        }
    }

    if (wild_engimon_cell_coordinate == make_pair(-1, -1)){
        // tidak ada adjacent wild engimon, throw error code 1
        throw 1;
    }

    Cell &tmp = cell[wild_engimon_cell_coordinate.first][wild_engimon_cell_coordinate.second];
    Engimon *enemy = tmp.getEngimon();
    // nampilin info wild engimon
    enemy->PrintInfo();

    // ngitung sama nampilin power
    Battle::printPower(*player.getActiveEngimon(), *enemy);
    bool playerWins = Battle::comparePower(*player.getActiveEngimon(), *enemy);

    if (playerWins){
        // player menang, dapet wild engimon dan random skill item
        // wild engimon dihapus dari map
        player.InsertEngimon(*enemy);
        vector<Element> enemy_elements = enemy->getElements();
        int gacha = rng()%(int)enemy_elements.size();
        player.InsertSkillItem(catalogSkill.getRandomSkillByElement(enemy_elements[gacha]));
        delete enemy;
        // gatau perlu setCell apa enggak
    }
    else{
        // player mati, active engimon ilang
        player.KillActive();
    }

}