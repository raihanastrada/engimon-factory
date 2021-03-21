#ifndef _ELEMENTS_HPP_
#define _ELEMENTS_HPP_

#include <vector>
#include <string>

using namespace std;

/*
CONTOH PEMAKAIAN (INISIALISASI SEMUA ELEMEN DI ELEMENTS.CPP)

Mendapatkan elemen
Element.getElement("Fire");

Mendapatkan 
*/

class Element {
    private:
        static vector<Element> elementDex;
        static vector<vector<int>> advantageIndex;
        static int elementCount;
        int id;
        string elementName;

    public:
        Element();
        ~Element();

        friend bool operator==(Element a, Element b);

        friend void setAdvantage(Element a, Element b);
        friend void setAdvantage(int idA, int idB);
        
        friend int getAdvantage(Element a, Element b);

        static void addElementToGlobal(Element newElement);
        static Element getElement(string elementName);
};

#endif