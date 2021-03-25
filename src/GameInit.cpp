#include "Engimon.hpp"
#include "Skill.h"
#include "Elements.hpp"

map<pair<Element, Element>, float> Element::advantageIndex;
long long int Engimon::engimon_count = 0;

#define LINE cout << "-----------------------------" << endl;

void init()
{
    // Initialize Elements
    /*
        Element element("elementName");
        Element element2("element2Name");
        setAdvantage(element, element2);
    */
    LINE
    Element fire("Fire");
    Element water("Water");
    Element electric("Electric");
    Element ground("Ground");
    Element ice("Ice");
    LINE
    // setAdvantage(fire, water, 0.0);
    // setAdvantage(fire, ground, 0.5);
    // setAdvantage(fire, ice, 2.0);
    
    // setAdvantage(water, fire, 2.0);
    // setAdvantage(water, electric, 0.0);

    // setAdvantage(electric, water, 2.0);
    // setAdvantage(electric, ground, 1.5);
    // setAdvantage(electric, ice, 1.5);

    // setAdvantage(ground, fire, 1.5);
    // setAdvantage(ground, electric, 2.0);
    // setAdvantage(ground, ice, 0.0);

    // setAdvantage(ice, fire, 0);
    // setAdvantage(ice, electric, 0.5);
    // setAdvantage(ice, ground, 2);

    // Initialize Pokemon Species
    /*
    FORMAT:
        Skill skill(basepower, masterlevel, vector<Element> compatibleElement);
        Engidex::addSpecies(name, id, skill, elementName) (you can use string for el name)
    */
    LINE
    Engidex engidex;
    Engidex::Species::setDefaultEngidex(engidex);
    LINE
    Skill shock(1, 1, vector<Element>() = { electric });
    engidex.addSpecies("Pikamee", 3001, shock, electric);
    LINE
    

}


