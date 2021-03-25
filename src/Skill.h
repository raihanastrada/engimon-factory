// skill header

#ifndef __SKILL_H
#define __SKILL_H

#include <stdio.h>
#include <vector>
#include <iostream>
#include <random>
#include "Elements.hpp"
using namespace std;


class Skill{
private:
	int id;
	int base_power;
	int mastery_level;
	string name;
	vector<Element> compatible_Element; // diasumsikan boleh pake STL di class skill
	static int curr_id; // id skill mulai dari nol
public:
	// default ctor, id skill hasil default ctor -1
	Skill();
	// custom ctor
	Skill(string _name, int _base_power, vector<Element> _compatible_Element);
	Skill(string _name, int _base_power, int _mastery_level, vector<Element> _compatible_Element);
	// cctor
	Skill(const Skill &other);
	// assignment op
	Skill& operator=(const Skill &other);
	// desktruktor
	~Skill();

	// comparator equal
	friend bool operator==(Skill a, Skill b);
	// comparator less
	friend bool operator<(Skill a, Skill b);

	// getter
	int getBasePower() const;
	int getMasteryLevel() const;
	vector<Element> getCompatibleElement() const;

	// setter
	void setBasePower(int _base_power);
	void setMasteryLevel(int _mastery_level);
	void setCompatibleElement(vector<Element> _compatible_Element);

	// check compatibility
	bool isCompatible(vector<Element> _elements);

	// print info
	void PrintInfo();
};

class CatalogSkill{
private:
	map<Element, vector<Skill>> catalog; // catalog skill per element
public:
	// add skill ke catalog
	void addSkill(Skill s);
	// get random skill by element
	Skill getRandomSkillByElement(Element e);
};

#endif