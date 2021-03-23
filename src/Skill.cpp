// skill body
#include "Skill.h"
using namespace std;

Skill::Skill() : base_power(0), mastery_level(0) {}

Skill::Skill(int _base_power, int _mastery_level, vector<Element> _compatible_Element){
	this->base_power = _base_power;
	this->mastery_level = _mastery_level;
	this->compatible_Element = _compatible_Element; // vector punya assignment op
}

int Skill::getBasePower() const{
	return base_power;
}

int Skill::getMasteryLevel() const{
	return mastery_level;
}

vector<Element> getCompatibleElement() const{
	return compatible_Element;
}

void Skill::setBasePower(int _base_power){
	base_power = _base_power;
}

void Skill::setMasteryLevel(int _mastery_level){
	mastery_level = _mastery_level;
}

void setCompatibleElement(vector<Element> _compatible_Element){
	this->compatible_Element = _compatible_Element;
}