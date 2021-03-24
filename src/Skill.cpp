// skill body
#include "Skill.h"
using namespace std;

Skill::Skill() : id(-1), base_power(0), mastery_level(0) {}

Skill::Skill(int _base_power, int _mastery_level, vector<Element> _compatible_Element){
	this->base_power = _base_power;
	this->mastery_level = _mastery_level;
	this->compatible_Element = _compatible_Element; // vector punya assignment op
	this->id = _id;
	curr_id++;
}

Skill::Skill(Skill &other){
	this->base_power = other.base_power;
	this->mastery_level = other.mastery_level;
	this->compatible_Element = other.compatible_Element;
	this->id = other.id;
}

Skill& Skill::operator=(Skill &other){
	this->base_power = other.base_power;
	this->mastery_level = other.mastery_level;
	this->compatible_Element = other.compatible_Element;
	this->id = other.id;
	return this;
}

bool Skill::operator==(Skill &other){
	return this->id == other.id;
}

bool Skill::operator<(Skill &other){
	return this->mastery_level < other.mastery_level;
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

void printInfo(){
	cout << "base power: " << this->base_power << "\n";
	cout << "mastery level: " << this->mastery_level << "\n";
	cout << "compatible element: {";
	bool first = 1;
	for (Element &e : compatible_Element){
		if (first) first = 0;
		else cout << ",";
		cout << e.getElementName();
	}
	cout << "\n";
}