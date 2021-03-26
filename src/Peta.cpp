#include "Cell.h"
#include "Player.h"
#include "Engimon.hpp"
#include "Elements.hpp"
#include "Battle.h"
#include "GameInit.hpp"
#include "Peta.h"
#include <iostream>
#include <fstream>
#include <string>
#include <experimental/random>
#include <math.h>

using namespace std;

int Peta::turn = 0;

#define line(n) cout << "------" << n << "------" << endl;

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
            for (j = 0; j < 12; j++)
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
    try
    {
        this->isValidIdx(i,j);
        return cell[i][j];
    }
    catch(string e)
    {
        cout << "error: " << e << endl;
    }
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
Player* Peta::getPlayer() {
    return &(this->player);
}

void Peta::setCell(Cell c, int i, int j) {
    Cell cell = getCell(i,j);
    cell = c;
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
            }
            if (j == 11)
            {
                cout << endl;
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
                    try
                    {
                        do
                        {
                            rngI = random(-1,1);
                            rngJ = random(-1,1);
                            isValidIdx(i+rngI,j+rngJ);
                        } while (sqrt(pow(i-(i+rngI),2) + pow(j-(j+rngJ),2)) > 1 && !isValidMove(cell[j][i].getEngimon(),cell[i+rngI][j+rngJ]) && isPlayers(i+rngI,j+rngJ) && cell[i+rngI][j+rngJ].getEngimon() != NULL);
                        Cell c = getCell(i+rngI,j+rngJ);
                        moveEngimon(cell[i][j],c);
                    }
                    catch(string e)
                    {
                        cout << "terjadi error: " << e << "saat " << cell[i][j].getEngimon()->getName() << "di ("<<j<<","<<i<<") ingin bergerak" << endl;
                    }
                }
            }
        }
    }
}
void Peta::spawnEnemy(Engidex e) {
    if (this->engimonCount != 0 && turn%4 == 0)
    {
        /* Cuma bisa spawn kalo masih ada jatah buat engimon */
        Element fire("Fire");
        Element water("Water");
        Element electric("Electric");
        Element ground("Ground");
        Element ice("Ice");
        int possibleId[72] = 
        {1001,1002,1003,1004,1005,1006,1007,1008,1009,
        2001,2002,2003,2004,2005,2006,2007,2008,2009,
        3001,3002,3003,3004,3005,3006,3007,3008,3009,
        4001,4002,4003,4004,4005,4006,4007,4008,4009,
        5001,5002,5003,5004,5005,5006,5007,5008,5009,
        1201,1202,1203,1204,1205,1206,1207,1208,1209,
        5301,5302,5303,5304,5305,5306,5307,5308,5309,
        5401,5402,5403,5404,5405,5406,5407,5408,5409};
        Engimon *engiEnemy = new Engimon(e, possibleId[rand() % 72]);
        int maxLvl = 100;
        if (this->player.getActiveEngimon()->getLevel() < 90) {maxLvl = this->player.getActiveEngimon()->getLevel()+10;}
        engiEnemy->setLevel(random(this->player.getActiveEngimon()->getLevel(),maxLvl));
        int i,j;
        if (engiEnemy->getElements().at(0) == water || engiEnemy->getElements().at(0) == ice)
        {
            do
            {
                j = random(SEA_MIN_X, SEA_MAX_X);
                i = random(SEA_MIN_Y, SEA_MAX_Y);
            } while (isPlayers(i,j) && cell[i][j].getEngimon() != NULL);
        }
        else 
        {
            do
            {
                j = random(GRS_MIN_X, GRS_MAX_X);
                i = random(GRS_MIN_Y, GRS_MAX_Y);
            } while (isPlayers(i,j) && cell[i][j].getEngimon() != NULL && (j >= SEA_MIN_X && j <= SEA_MAX_X && i >= SEA_MIN_Y && i <= SEA_MAX_Y));
        }
        cell[i][j].setEngimon(engiEnemy);
        this->engimonCount -= 1;
        cout << "Telah muncul sebuah "<< engiEnemy->getName() << " LV " << engiEnemy->getLevel() << " di titik ("<<j<<","<<i<<")" << endl;
    }
}
// Engimon Peta::generateEngimon(Engidex* e) {
//     int possibleId[72] = 
// 	{1001,1002,1003,1004,1005,1006,1007,1008,1009,
// 	 2001,2002,2003,2004,2005,2006,2007,2008,2009,
// 	 3001,3002,3003,3004,3005,3006,3007,3008,3009,
// 	 4001,4002,4003,4004,4005,4006,4007,4008,4009,
// 	 5001,5002,5003,5004,5005,5006,5007,5008,5009,
// 	 1201,1202,1203,1204,1205,1206,1207,1208,1209,
// 	 5301,5302,5303,5304,5305,5306,5307,5308,5309,
// 	 5401,5402,5403,5404,5405,5406,5407,5408,5409};
//     return Engimon(*e, possibleId[rand() % 72]);
//     // int firstElmt = this->random(1,5);
//     // int secondElmt = 0;
//     // if (firstElmt == 5) // Kalo water bisa W,G / W,I / W
//     // {
//     //     secondElmt = this->random(0,1); // Water
//     //     if (secondElmt) {secondElmt = this->random(3,4);} // W,G atau W,I
//     // }
//     // else if (firstElmt == 1)
//     // {
//     //     secondElmt = this->random(0,1); // E
//     //     if (secondElmt) {secondElmt = 2;} // E,F
//     // }
//     // int idx = this->random(1,10);
//     // int id = firstElmt*1000 + secondElmt*100 + idx;
//     // // pair<Engidex, CatalogSkill> e = this->GI;
//     // Engimon engiEnemy(e, id);
//     // // line(77777)
//     // // engiEnemy.PrintDetail();
//     // return engiEnemy;
// }

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
    if (engimon->getElements().at(0) == water || engimon->getElements().at(0) == ice)
    {
        // Jika ada elemen es atau water, bisa berjalan di air
        if (engimon->getElements().at(1) == ground) 
        {return (c.getType() == "sea" || c.getType() == "grassland");}
        return c.getType() == "sea";
    }
    else{return c.getType() == "grassland";}
}
bool Peta::isPlayers(int i, int j) {
    return j == getPlayerX() || i == getPlayerY() || j == getEngimonX() && i == getEngimonY();
}
bool Peta::isValidIdx(int i, int j) {
    if (i < 0 || i > 9 || j < 0 || j > 11)
    {
        throw "invalid idx";
    }
    return true;
}
int Peta::random(int min, int max) {
    mt19937 rng((unsigned long long)new char); // pseudo-random generator
    return rng()%(max-min+1)+min;
}
bool Peta::battle(CatalogSkill &catalog_skill){
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
        if (x >= 0 && y >= 0 && x <= 11 && y <= 9 && cell[y][x].getEngimon()){
            // ada engimon di (x, y)
            wild_engimon_cell_coordinate = coord;
        }
    }

    // cout << "player di: " << getPlayerY() << " " << getPlayerX() << "\n";
    // cout << "engimon lawan di " << wild_engimon_cell_coordinate.second << " " << wild_engimon_cell_coordinate.first << "\n";
    if (wild_engimon_cell_coordinate == make_pair(-1, -1)){
        // tidak ada adjacent wild engimon, throw error code 1
        throw 1;
    }

    Cell &tmp = cell[wild_engimon_cell_coordinate.second][wild_engimon_cell_coordinate.first];
    Engimon *enemy = tmp.getEngimon();
    // nampilin info wild engimon
    enemy->PrintInfo();
    cout << "\n";

    // ngitung sama nampilin power
    Battle::printPower(player.getActiveEngimon(), enemy);
    bool playerWins = Battle::comparePower(player.getActiveEngimon(), enemy);
    bool ret = true; // return value battle, defaultnya true karena nggak game over

    if (playerWins){
        // player menang, dapet wild engimon dan random skill item
        // wild engimon dihapus dari map
        cout << "Engimonmu menang!\n";
        if (!player.IsInventoryFull()){
            player.InsertEngimon(*enemy);
            vector<Element> enemy_elements = enemy->getElements();
            int gacha = rng()%(int)enemy_elements.size();
            Skill randomSkill = catalog_skill.getRandomSkillByElement(enemy_elements[gacha]);
            player.InsertSkillItem(randomSkill);
            cout << "Kamu mendapatkan engimon ";
            enemy->PrintInfo();
            cout << "\nKamu mendapatkan skill ";
            randomSkill.PrintInfo();
            tmp.setEngimon(nullptr);
            delete enemy;
        }
        int gacha_exp = rng()%99 + 1;
        player.getActiveEngimon()->addExp(gacha_exp);
        if (!player.getActiveEngimon()->getAlive()){
            ret = player.KillActive();
        }
        // gatau perlu setCell apa enggak
    }
    else{
        // player mati, active engimon ilang
        cout << "Engimonmu kalah!\n";
        ret = player.KillActive();
    }
    return ret;
}