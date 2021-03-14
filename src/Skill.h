// skill header

#ifndef __SKILL_H
#define __SKILL_H

#include <bits/stdc++.h>
using namespace std;

class Skill{
private:
	int base_power;
	int mastery_level;
public:
	// default ctor, rasanya nggak bakal dipakai
	Skill();
	// custom ctor
	Skill(int _base_power, int _mastery_level);

	// getter
	int getBasePower() const;
	int getMasteryLevel() const;

	// setter
	void setBasePower(int _base_power);
	void setMasteryLevel(int _mastery_level);
};

#endif