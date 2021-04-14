// battle body

#include "Battle.h"

void Battle::printPower(Engimon *active, Engimon *wild){
	float power_active, power_wild;
	power_active = active->getLevel()*getAdvantage(active->getElements(), wild->getElements());
	for (Skill s : active->getSkills()) power_active += s.getBasePower()*s.getMasteryLevel();
	power_wild = wild->getLevel()*getAdvantage(wild->getElements(), active->getElements());
	for (Skill s : wild->getSkills()) power_wild += s.getBasePower()*s.getMasteryLevel();
	cout << "active engimon total power = " << power_active << "\n";
	cout << "wild engimon total power = " << power_wild << "\n";
}

bool Battle::comparePower(Engimon *active, Engimon *wild){
	float power_active, power_wild;
	power_active = active->getLevel()*getAdvantage(active->getElements(), wild->getElements());
	for (Skill s : active->getSkills()) power_active += s.getBasePower()*s.getMasteryLevel();
	power_wild = wild->getLevel()*getAdvantage(wild->getElements(), active->getElements());
	for (Skill s : wild->getSkills()) power_wild += s.getBasePower()*s.getMasteryLevel();
	return power_active >= power_wild;
}
