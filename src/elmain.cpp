#include "Elements.hpp"
#include <iostream>

map<pair<Element, Element>, float> Element::advantageIndex;

int main()
{
    cout << "-----" << 1 << "-----" << endl;
    Element fire("Fire");
    Element water("Water");
    Element electric("Electric");
    Element ground("Ground");
    Element ice("Ice");

    cout << "-----" << 2 << "-----" << endl;
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
    
    cout << "-----" << 3 << "-----" << endl;
}