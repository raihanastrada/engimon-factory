#include "Cell.h"
#include "Engimon.hpp"
#include "Elements.hpp"
#include <string>
#include <vector>

using namespace std;

Cell::Cell() {
    this->view = '-';
    this->type = "grassland";
    engimon = NULL;
}

Cell::Cell(char view, string type, Engimon* _engimon) {
    this->view = view;
    this->type = type;
    engimon = _engimon;
}
Cell::~Cell() {
    delete engimon;
}
Cell& Cell::operator=(const Cell& c) {
    this->view = c.view;
    this->type = c.type;
    engimon = c.engimon;
    return *this;
}
char Cell::getView() {
    return this->view;
}
string Cell::getType() {
    return this->type;
}
Engimon* Cell::getEngimon() {
    return engimon;
}
void Cell::setView(char view) {
    this->view = view;
}
void Cell::setType(string type) {
    this->type = type;
}
void Cell::setEngimon(Engimon* _engimon) {
    engimon = _engimon;
}
void Cell::show(int minLvl) {
    if (engimon == NULL) 
    {
        // Jika tidak terdapat engimon
        cout << view;
    }
    else 
    {
        // Tampilkan berdasarkan engimon
        char c = this->engimonView();
        if (engimon->getLevel() > minLvl)
        {
            c = toupper(c);
        }
        cout << c;
    }
}
char Cell::engimonView() {
    Element fire("Fire");
    Element water("Water");
    Element electric("Electric");
    Element ground("Ground");
    Element ice("Ice");
    // engimon->PrintDetail();
    // LINEx(101010101)
    if (engimon->getElements().size() == 1) {
        if (engimon->getElements().at(0) == fire) return 'f';
        if (engimon->getElements().at(0) == ground) return 'g';
        if (engimon->getElements().at(0) == electric) return 'e';
        if (engimon->getElements().at(0) == water) return 'w';
        if (engimon->getElements().at(0) == ice) return 's';
    }
    else {
        if (engimon->getElements().at(0) == electric) return 'l';
        if (engimon->getElements().at(1) == ice) return 's';
        if (engimon->getElements().at(1) == ground) return 'n';
    }
    // if (engimon->getElements().at(0) == electric)
    // {
    //     if (engimon->getElements().at(1) == fire){return 'l';}
    //     else{return 'e';}
    // }
    // else if (engimon->getElements().at(0) == water)
    // {
    //     if (engimon->getElements().at(1) == ice){return 's';}
    //     else if (engimon->getElements().at(1) == ground){return 'n';}
    //     else{return 'w';}
    // }
    // else if (engimon->getElements().at(0) == fire) {return'f';}
    // else if (engimon->getElements().at(0) == ground) {return 'g';}
    // else{return 'i';}
    return 'i';
}