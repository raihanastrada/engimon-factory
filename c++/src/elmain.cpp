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
    setAdvantage(fire, water, 0.0);
    setAdvantage(fire, ground, 0.5);
    setAdvantage(fire, ice, 2.0);
    
    setAdvantage(water, fire, 2.0);
    setAdvantage(water, electric, 0.0);

    setAdvantage(electric, water, 2.0);
    setAdvantage(electric, ground, 1.5);
    setAdvantage(electric, ice, 1.5);

    setAdvantage(ground, fire, 1.5);
    setAdvantage(ground, electric, 2.0);
    setAdvantage(ground, ice, 0.0);

    setAdvantage(ice, fire, 0);
    setAdvantage(ice, electric, 0.5);
    setAdvantage(ice, ground, 2);
    
    cout << "-----" << 3 << "-----" << endl;

    cout << "Fire vs Ice:\t\t " << getAdvantage(fire, ice) << endl;
    cout << "Fire/Water vs Water/Electric\t " << getAdvantage(vector<Element>() = {fire, water}, vector<Element>() = {water, electric}) << endl;
    cout << "Water/Electric vs Fire/Water\t " << getAdvantage(vector<Element>() = {water, electric}, vector<Element>() = {fire, water}) << endl;
}