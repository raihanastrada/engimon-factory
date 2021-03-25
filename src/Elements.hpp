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

        string getName(){
            return elementName;
        }

        friend bool operator==(Element a, Element b)
        {
            return a.elementName == b.elementName;
        };

        friend bool operator<(Element a, Element b)
        {
            return a < b;
        }

        friend bool operator<(pair<Element, Element> a, pair<Element, Element> b)
        {
            if (a.first < b.first)
            {
                return true;
            } else {
                return a.second < b.second;
            }
        }

        friend static void setAdvantage(Element a, Element b, float mult)
        {
            advantageIndex.insert(make_pair(make_pair(a, b), mult));
        };
        
        friend static float getAdvantage(Element a, Element b)
        {
            pair<Element, Element> e (a,b);
            if (advantageIndex.count(e) == 0)
            {
                return 1;
            } else {
                return advantageIndex[e];
            }
        };

        friend static float getAdvantage(vector<Element> a, vector<Element>b)
        {
            float max = -1;
            if (a.size() != 0 && b.size() != 0)
            {
                for (Element &i: a)
                {   
                    for (Element &j: b)
                    {
                        if (getAdvantage(i, j) > max)
                        {
                            max = getAdvantage(i, j);
                        }
                    }
                }
            }

            return max;
        }
};

#endif