// skill header

#ifndef __SKILL_H
#define __SKILL_H

#include <stdio.h>
#include <vector>
#include <iostream>
#include "Elements.hpp"
using namespace std;

class Skill{
private:
	int base_power;
	int mastery_level;
	vector<Element> compatible_Element; // diasumsikan boleh pake STL di class skill
public:
	// default ctor, rasanya nggak bakal dipakai
	Skill();
	// custom ctor
	Skill(int _base_power, int _mastery_level, vector<Element> _compatible_Element);

	// getter
	int getBasePower() const;
	int getMasteryLevel() const;
	vector<Element> getCompatibleElement() const;

	// setter
	void setBasePower(int _base_power);
	void setMasteryLevel(int _mastery_level);
	void setCompatibleElement(vector<Element> _compatible_Element);
};

#endif