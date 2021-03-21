#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <stdio.h>
#include <string>
#include "Point.h"

using namespace std;

class Player {
    private:
        Point Location;
        // Inventory<Engimon> InvEngimon (Kelas Engimon)
        // Inventory<SkillItem> InvSkillItem (Kelas Skill Item)
        // Engimon* ActiveEngimon;
        static int maxCapacity;
    public:
        void Move(char direction);
        void SwitchActive(string EngimonName);
        void PrintListEngimon();
        void PrintListSkill();
        void UseSkill();
        void Breeding();
        void Battle();
        void Interact();
        bool IsInventoryFull();
};

#endif