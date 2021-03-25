#ifndef _PETA__H_
#define _PETA__H_

#include "Cell.h"
#include "Player.h"
#include "Engimon.hpp"
#include "Elements.hpp"
#include "Battle.h"
#include <string>
#include <experimental/random>

using namespace std;

class Peta
{
    private:
        Cell cell[10][12];          // Matriks cell
        const int minLvl;           // Level minimum engimon agar ditampilkan huruf kecil
        int engimonCount;           // Batas engimon yang dapat di spawn
        Player player;              // Player, buat ngambil lokasi player
        CatalogSkill catalogSkill;  // catalog skill [NOTE belum diconstruct]
        static int turn;            // Turn
        
    public:
        /* Ctor */
        Peta(string filename, int engimonCount, Player player, int _minLvl);
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
        void setCell(Cell c, int i, int j);
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
        /* Move engimon dari cell c1 ke cell c2 */
        void moveEngimon(Cell c1, Cell c2);
        /* Mengecek apakah engimon valid bergerak ke cell */
        bool isValidMove(Engimon* engimon, Cell c);
        /* Mengecek apakah ada player / engimon */
        bool isPlayers(int i, int j);
        /* Mengecek apakah index valid */
        bool isValidIdx(int i, int j);
        int random(int min, int max);
        void battle();
};  

#endif  