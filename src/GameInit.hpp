#ifndef _GAMEINIT_HPP_
#define _GAMEINIT_HPP_

#include "Engimon.hpp"
#include "Skill.h"
#include <random>

class GameInitiator {
    private:
        Engidex e;
        CatalogSkill c;
        vector<Element> el;
    public:
        pair<Engidex, CatalogSkill> init();
    private:
        void addNewEntry(int id, string name, string skillname, Element a);
        void addNewEntry(int id, string name, string skillname, Element a, Element b);
        void addNewEntry(int id, string name, string skillname);

        void setEngidex(Engidex en) { e = en; };
        void setElements(vector<Element> en) { el = en; };

        void generatePokemon();
};

#endif