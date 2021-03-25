#include "Engimon.hpp"
#include "Skill.h"
#include "Elements.hpp"

map<pair<Element, Element>, float> Element::advantageIndex;
Engidex Engidex::Species::defaultEngidex;

void init()
{
    // Initialize Elements
    /*
        Element element("elementName");
        Element element2("element2Name");
        setAdvantage(element, element2);
    */

    Element fire("Fire");
    Element water("Water");
    Element electric("Electric");
    Element ground("Ground");
    Element ice("Ice");

    setAdvantage(fire, water, 0);
    setAdvantage(fire, ground, 0.5);
    setAdvantage(fire, ice, 2);
    
    setAdvantage(water, fire, 2);

    // WIP

    // Initialize Pokemon Species
    /*
    FORMAT:
        Skill skill(basepower, masterlevel, vector<Element> compatibleElement);
        Engidex::addSpecies(name, id, skill, elementName) (you can use string for el name)
    */
    Engidex engidex;
    Engidex::Species::setDefaultEngidex(engidex);

    Skill shock(1, 1, vector<Element>() = { electric });
    engidex.addSpecies("Pikamee", 3001, shock, electric);
}


