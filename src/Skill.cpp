// skill body
#include "Skill.h"
using namespace std;

Skill::Skill() : base_power(0), mastery_level(0) {}

Skill::Skill(int _base_power, int _mastery_level) : base_power(_base_power), mastery_level(_mastery_level) {}

int Skill::getBasePower() const{
	return base_power;
}

int Skill::getMasteryLevel() const{
	return mastery_level;
}

void Skill::setBasePower(int _base_power){
	base_power = _base_power;
}

void Skill::setMasteryLevel(int _mastery_level){
	mastery_level = _mastery_level;
}