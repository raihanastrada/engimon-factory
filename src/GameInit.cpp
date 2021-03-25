#include "Engimon.hpp"
#include "Skill.h"
#include "Elements.hpp"

map<pair<Element, Element>, float> Element::advantageIndex;
long long int Engimon::engimon_count = 0;

#define LINE cout << "-----------------------------" << endl;

Engidex init()
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

    Element::setAdvantage(fire, water, 0.0);
    Element::setAdvantage(fire, ground, 0.5);
    Element::setAdvantage(fire, ice, 2.0);
    
    Element::setAdvantage(water, fire, 2.0);
    Element::setAdvantage(water, electric, 0.0);

    Element::setAdvantage(electric, water, 2.0);
    Element::setAdvantage(electric, ground, 1.5);
    Element::setAdvantage(electric, ice, 1.5);

    Element::setAdvantage(ground, fire, 1.5);
    Element::setAdvantage(ground, electric, 2.0);
    Element::setAdvantage(ground, ice, 0.0);

    Element::setAdvantage(ice, fire, 0);
    Element::setAdvantage(ice, electric, 0.5);
    Element::setAdvantage(ice, ground, 2);

    // Initialize Pokemon Species
    /*
    FORMAT:
        Skill skill(basepower, masterlevel, vector<Element> compatibleElement);
        Engidex::addSpecies(name, id, skill, elementName) (you can use string for el name)
    */

    Engidex engidex;

    Skill shock(1, 1, vector<Element>() = { electric });
    engidex.addSpecies("Pikamee", 3001, shock, electric);
    
    return engidex;
}


