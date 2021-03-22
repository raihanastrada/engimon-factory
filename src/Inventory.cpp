#include "Inventory.h"

using namespace std;

//Ctor
Inventory::Inventory(){
    totalObject = 0;
}

//Add Skill ke inventory
void Inventory::addSkill(Skill S){
    if (totalObject < CAPACITY)
    {
        skillInventory[S]++;
        totalObject++;
    }
    else
    {
        cout << "Inventory Penuh, tidak bisa menambah Skill" << endl;
    }
}

//Add Engimon ke inventory
void Inventory::addEngimon(Engimon E){
    if (totalObject < CAPACITY)
    {
        engimonInventory[E]++;
        totalObject++;
    }
    else
    {
        cout << "Inventory Penuh, tidak bisa menambah Engimon" << endl;
    }
}

//Get jumlah objek dalam inventory
int Inventory::numOfObject(){
    return totalObject;
}

//Dtor
Inventory::~Inventory(){}