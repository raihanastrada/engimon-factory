#ifndef _ELEMENTS_HPP_
#define _ELEMENTS_HPP_

#include <vector>
#include <string>
#include <map>

using namespace std;

/*
CONTOH PEMAKAIAN (INISIALISASI SEMUA ELEMEN DI ELEMENTS.CPP)

Mendapatkan elemen
Element.getElement("Fire");

Mendapatkan 
*/

class Element {
    private:
        static map<pair<Element, Element>, float> advantageIndex;
        string elementName;

    public:
        Element()
        {
            elementName = "UNKNOWN";
        }

        Element(string elementname)
        {
            elementName = elementname;
        };

        ~Element();

        friend bool operator==(Element a, Element b)
        {
            return a.elementName == b.elementName;
        };

        friend void setAdvantage(Element a, Element b, float mult)
        {
            advantageIndex[pair<Element, Element>(a, b)] = mult;
        };
        
        friend int getAdvantage(Element a, Element b)
        {
            pair<Element, Element> e (a,b);
            if (advantageIndex.count(e) == 0)
            {
                return 1;
            } else {
                return advantageIndex[e];
            }
        };
};

#endif