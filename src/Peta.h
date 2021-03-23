#ifndef _PETA__H_
#define _PETA__H_

#include "Cell.h"
#include "Player.h"
#include "Engimon.hpp"
#include <string>

using namespace std;

class Peta
{
    private:
        Cell cell[10][12];          // Matriks cell
        const int minLvl;           // Level minimum engimon agar ditampilkan huruf kecil
        int engimonCount;           // Batas engimon yang dapat di spawn
        Player player;              // Player, buat ngambil lokasi player
        static int turn;            // Turn
        
    public:
        /* Ctor */
        Peta(string filename, int engimonCount, Player player);
        /* Dtor */
        ~Peta();
        
        // Getter
        Cell getCell(int i, int j);
        const int getMinLvl();
        int getEngimonCount();
        int getPlayerX();
        int getPlayerY();
        int getEngimonX();
        int getEngimonY();

        // Setter
        /* Set cell pada Cell[i][j] */
        void setCell(Cell cells, int i, int j);
        void setEngimonCount(int count);
        void increaseTurn();

        // Method
        /* Menampilkan tampilan peta */
        void viewmap();
        /* Menampilkan keterangan map */
        void information();
        /* Engimon pada map bergerak random */
        void randomMove();
        /* Spawn engimon */
        void spawnEnemy();
};  

#endif  