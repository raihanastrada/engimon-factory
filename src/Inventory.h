#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <stdio.h>
#include <vector>
#include <map>
#include "Skill.h"
#include "Engimon.hpp"

#define CAPACITY 10 //capacitynya berapa?

using namespace std;

class Inventory
{
private:
    map <Skill, int> skillInventory;
    map <Engimon, int> engimonInventory;
    static int totalObject;
public:
    Inventory();
    void addSkill(Skill S);
    void addEngimon(Engimon E);
    int numOfObject();
    ~Inventory();
};
#endif