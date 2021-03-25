#ifndef _ENGIMON_HPP_
#define _ENGIMON_HPP_

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

#include "Point.h"
#include "Skill.h"
#include "Elements.hpp"

using namespace std;

// ENGIMON DIES AT LEVEL 100.
#define MAX_EXP 100 * 100 

/*
ENGIDEX code format
<first-element 1..5> <second-element 0..5> <index 0..10>

example:
Third engimon type with elements Electric and Fire has ENGIDEX code:
    1203

First engimon type with elements Ground
    3001
*/

// ASUMSI HANYA ADA SATU ENGIDEX UNTUK SATU GAME.
class Engidex {
    public:
        Engidex()
        {
            codex = map<int, Species>();
        }

        Engidex(const Engidex &eng) 
        {
            codex = eng.codex;
        }

        Engidex& operator=(const Engidex &e)
        {
            Engidex *res = new Engidex(e);
            return *res;
        }

        class Species {
            private:
                int species_id;
                string species_name;
            protected:
                vector<Skill> skills;
                vector<Element> elements;
            public:
                Species()
                {
                    species_name = "Unknown";
                    species_id = 0;
                }

                Species(Engidex e, int id)
                {
                    Species spec = e.getSpecies(id);
                    species_name = spec.species_name;
                    species_id = spec.species_id;
                    skills = spec.skills;
                    elements = spec.elements;
                };

                /* Constructors for creating new species and entering into codex */
                Species(string nm, int id, Skill u, Element e1) 
                {
                    species_name = nm;
                    species_id = id;
                    skills.push_back(u);
                    elements.push_back(e1);
                };

                Species(string nm, int id, Skill u, Element e1, Element e2)
                {
                    species_name = nm;
                    species_id = id;
                    skills.push_back(u);
                    elements.push_back(e1);
                    elements.push_back(e2);
                };

                // Copy constructor
                Species(const Species &spec)
                {
                    species_name = spec.species_name;
                    species_id = spec.species_id;
                    skills = spec.skills;
                    elements = spec.elements;
                }

                void species_info_print() 
                {
                    cout << species_name << endl;
                }

                string getSpeciesName() { return species_name; };
                int getEngidexID() { return species_id; };
                Skill getUniqueSkill() { return skills[0]; };

                vector<Element> getElements() { return elements; };

                Species& operator=(const Species& sp)
                {
                    Species *res = new Species(sp);
                    return *res;
                };

                bool operator==( Species sp2 ) { return species_id == sp2.species_id; };
                bool operator==( int id ) { return species_id == id; };
                bool operator==( string name ) { return species_name == name; };
        };
        
        void addSpecies(string name, int id, Skill u, Element a1, Element a2)
        {
            Species s(name, id, u, a1, a2);
            codex[id] = s;
        };

        void addSpecies(string name, int id, Skill u, string a1, string a2)
        {
            Species s(name, id, u, Element(a1), Element(a2));
            codex[id] = s;
        };

        void addSpecies(string name, int id, Skill u, Element a1)
        {
            Species s(name, id, u, a1);
            codex.insert(make_pair(id, s));
        };

        void addSpecies(string name, int id, Skill u, string a1)
        {
            Species s(name, id, u, Element(a1));
            codex[id] = s;
        };

        Species getSpecies(int code) {
            return codex[code];
        }

    private:
        map<int, Species> codex;
};

/*
Relasi inheritance IS A,
Engimon bernama "PikaPika" dengan spesies "Pikachu" maka, PikaPika(child, engimon) IS A Pikachu(parent, species)
*/

class Engimon : public Engidex::Species {
    private:
        int                 id;
        string              name;
        vector<Engimon*>    parents;
        int                 exp;
        bool                alive;

        static long long int engimon_count;
    public:
        Engimon()
        {
            name = "UNKNOWN";
            exp = 0;
            alive = false;
        }

        Engimon(Engidex e, int species_id) : Species(e, species_id)
        {
            id = engimon_count;
            engimon_count++;
            name = getSpeciesName();
            skills.push_back(getUniqueSkill());
            exp = 0;
            alive = true;
        };

        Engimon(const Engimon &e) : Species(e)
        {
            id = e.id;
            name = e.name;
            parents = e.parents;
            skills = e.skills;
            exp = e.exp;
            alive = e.alive;
        }

        Engimon& operator=(const Engimon &e)
        {
            Engimon *res = new Engimon(e);
            return *res;
        }

        ~Engimon()
        {
            vector<Engimon*>().swap(parents);
            vector<Skill>().swap(skills);
        };

        /* SETTERS */
        void setName(string new_name)
        {   
            name = new_name;
        };

        /* GETTERS */
        bool    getAlive()              { return alive; };
        string  getName()               { return name; };
        int     getLevel()              { return exp / 100; };
        int     getExp()                { return exp % 100; };
        int     getCumulativeExp()      { return exp; };

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
             cout << getEngidexID() << "#" << getSpeciesName() << "\t" << " \"" << name << "\"";
        };

        void addSkill(Skill newSkill)
        {
            if (skills.size() < 4 && (find(skills.begin(), skills.end(), newSkill) == skills.end()))
            {
                skills.push_back(newSkill);
            } else {
                cout << "Engimon sudah memiliki 4 skill" << endl;
            }
        };   

        vector<Skill> getSkills(){
            return skills;
        }

        /* OPERATORS */
        bool operator==(Engimon comp) { return id == comp.id; };

        /* FRIEND FUNCTIONS */
        friend Engimon breed(Engimon dad, Engimon mom); // for breeding
};

#endif