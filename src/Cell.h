#ifndef _CELL_H_
#define _CELL_H_
#include "Engimon.hpp"
#include <string>

using namespace std;

class Cell
{
    private:
        char view;          // tampilan cell
        string type;        // type cell; grassland/sea
        Engimon* engimon;   // engimon pada cell
    public:
        /* Ctor */
        Cell();
        /* Ctor user defined */
        Cell(char view, string type, Engimon* engimon);
        /* Dtor */
        ~Cell();

        /* Getter */
        char getView();
        string getType();
        Engimon* getEngimon();

        /* Setter */
        void setView(char view);
        void setType(string type);
        void setEngimon(Engimon* engimon);

        /* Method */
        /* Menampilkan tampilan cell pada terminal */
        void show();
};

#endif