#ifndef _GAMEINIT_HPP_
#define _GAMEINIT_HPP_

#include "Engimon.hpp"

class GameInitiator {
    private:
        Engidex e;
        vector<Element> el;
    public:
        Engidex init();
    private:
        void addNewEntry(int id, string name, string skillname, Element a);
        void addNewEntry(int id, string name, string skillname, Element a, Element b);
        void addNewEntry(int id, string name, string skillname);

        void setEngidex(Engidex en) { e = en; };
        void setElements(vector<Element> en) { el = en; };

        void generatePokemon();     
};

#endif