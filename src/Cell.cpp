#include "Cell.h"
#include "Engimon.hpp"
#include <string>

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
void Cell::show() {
    if (engimon == NULL) 
    {
        // Jika tidak terdapat engimon
        cout << view;
    }
    else 
    {
        // Tampilkan berdasarkan engimon
        cout << "E"; // Temporary
    }
}