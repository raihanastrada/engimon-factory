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
	int id;
	int base_power;
	int mastery_level;
	vector<Element> compatible_Element; // diasumsikan boleh pake STL di class skill
	static int curr_id; // id skill mulai dari nol
public:
	// default ctor, id skill hasil default ctor -1
	Skill();
	// custom ctor
	Skill(int _base_power, int _mastery_level, vector<Element> _compatible_Element);
	// cctor
	Skill(const Skill &other);
	// assignment op
	Skill& operator=(const Skill &other);

	// comparator equal
	bool operator==(Skill &other);
	// comparator less
	bool operator<(Skill &other);

	// getter
	int getBasePower() const;
	int getMasteryLevel() const;
	vector<Element> getCompatibleElement() const;

	// setter
	void setBasePower(int _base_power);
	void setMasteryLevel(int _mastery_level);
	void setCompatibleElement(vector<Element> _compatible_Element);

	// print info
	void PrintInfo();
};

#endif