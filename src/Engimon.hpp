#ifndef _ENGIMON_HPP_
#define _ENGIMON_HPP_

#include <string>
#include <vector>
#include <iostream>

#include "Point.h"
#include "Skill.h"
#include "Elements.hpp"

using namespace std;

// ENGIMON DIES AT LEVEL 100.
#define MAX_EXP 100 * 100 
#define Print(n) cout << n << endl

/*
ENGIDEX code format
<first-element 1..5> <second-element 0..5> <index 0..10>

example:
Third engimon type with elements Electric and Fire has ENGIDEX code:
    1203

First engimon type with elements Ground
    3001
*/

class Engidex {
    private:
        vector<Species> codex;
    public:
        class Species {
            private:
                string species_name;
                int species_id;
                Skill uniqueSkill;
            public:
                Species();
                Species(string nm, int id);

                string getSpeciesName();
                int getEngidexID();
        }

        Engidex();
        
        static void addSpecies(string name, Element a1, Element b2);
        static void addSpecies(string name, Element a1);
        static void addSpecies(string name, int firstElement, int secondElement);
        static void addSpecies(string name, int firstElement);
        static void getSpecies(int code);
}


class Engimon : public Engidex::Species {
    private:
        int             id;
        string          name;
        Engimon[2]      parents;
        Skill[4]        skills;
        int             exp;
        bool            alive;

        static long long int engimon_count;
    public:
        Engimon()
        {
            engimon_count++;
        };

        ~Engimon()
        {
            delete[] parents;
            delete[] skills;
        };

        /* SETTERS */
        void setName(string new_name)
        {   
            name = new_name;
        };

        /* GETTERS */
        bool    getAlive();             { return alive; };
        string  getName();              { return name; };
        int     getLevel()              { return exp / 100; };
        int     getExp();               { return exp % 100; };
        int     getCumulativeExp();     { return exp; };

        /* BASIC FUNCTIONS */
        void addExp(int new_exp)
        {
            if (exp + new_exp > MAX_EXP)
            {
                exp = MAX_EXP;
                alive = false;
            } else {
                exp += new_exp;
            }
        };

        void PrintInfo()
        {
            Print(name);
        };

        addSkill(Skill newSkill);      

        /* FRIEND FUNCTIONS */
        friend Engimon breed(Engimon dad, Engimon mom); // for breeding
};

#endif