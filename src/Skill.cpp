// skill body
#include "Skill.h"
using namespace std;

int Skill::curr_id = 0;

Skill::Skill() : id(-1), base_power(0), mastery_level(0) {}

Skill::Skill(int _base_power, int _mastery_level, vector<Element> _compatible_Element){
	this->base_power = _base_power;
	this->mastery_level = _mastery_level;
	this->compatible_Element = _compatible_Element; // vector punya assignment op
	this->id = curr_id;
	curr_id++;
}

Skill::Skill(const Skill &other){
	this->base_power = other.base_power;
	this->mastery_level = other.mastery_level;
	this->compatible_Element = other.compatible_Element;
	this->id = other.id;
}

Skill& Skill::operator=(const Skill &other){
	this->base_power = other.base_power;
	this->mastery_level = other.mastery_level;
	this->compatible_Element = other.compatible_Element;
	this->id = other.id;
	return *this;
}

Skill::~Skill() {
	vector<Element>().swap(compatible_Element);
}

bool operator==(Skill a, Skill b){
	return a.id == b.id;
}

bool operator<(Skill a, Skill b){
	return a.mastery_level < b.mastery_level;
}

int Skill::getBasePower() const{
	return base_power;
}

int Skill::getMasteryLevel() const{
	return mastery_level;
}

vector<Element> Skill::getCompatibleElement() const{
	return compatible_Element;
}

void Skill::setBasePower(int _base_power){
	base_power = _base_power;
}

void Skill::setMasteryLevel(int _mastery_level){
	mastery_level = _mastery_level;
}

void Skill::setCompatibleElement(vector<Element> _compatible_Element){
	this->compatible_Element = _compatible_Element;
}

bool Skill::isCompatible(vector<Element> _elements){
	// bruteforce O(N^2)
	for (Element e1 : compatible_Element){
		for (Element e2 : _elements){
			if (e1 == e2) return true;
		}
	}
	return false;
}

/*void printInfo(){
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
}*/

void Skill::PrintInfo() {
	cout << "Base Power: " << this->base_power << endl; // TESTing
}