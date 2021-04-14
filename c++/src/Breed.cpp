#include <iostream>
#include "Engimon.hpp"
#include <string>

using namespace std;

Engimon breed(Engimon* dad, Engimon* mom, Engidex e) {
	if (*dad == *mom) {
		throw false; // exception bikin anak ma diri sendiri
	}
	if (dad->getLevel()<31 || mom->getLevel()<31) { 
		throw 0; // exception level bapak ibu lower than 31
	}
	
	// level bapak ibu kurang 30
	dad->setLevel(dad->getLevel()-30);
	mom->setLevel(mom->getLevel()-30);
	int possibleId[72] = 
	{1001,1002,1003,1004,1005,1006,1007,1008,1009,
	 2001,2002,2003,2004,2005,2006,2007,2008,2009,
	 3001,3002,3003,3004,3005,3006,3007,3008,3009,
	 4001,4002,4003,4004,4005,4006,4007,4008,4009,
	 5001,5002,5003,5004,5005,5006,5007,5008,5009,
	 1201,1202,1203,1204,1205,1206,1207,1208,1209,
	 5301,5302,5303,5304,5305,5306,5307,5308,5309,
	 5401,5402,5403,5404,5405,5406,5407,5408,5409};
	
	// construct default engimon
	Engimon* anak = new Engimon();
	
	// set elemen dan spesies anak
	int id_bapak = dad->getEngidexID();
	int id_ibu = mom->getEngidexID();
	int id_anak;
	if ((id_bapak/100)%10 == 0 && (id_ibu/100)%10 == 0) { // bapak dan ibu single elemen
	
		Element elemenBapak(id_bapak/1000);
		Element elemenIbu(id_ibu/1000);
		int element[2] = {id_bapak,id_ibu};
		int idx = rand() % 2;
		
		if (elemenBapak == elemenIbu) { // elemen sama
			id_anak = element[idx];
			Engimon* hold = new Engimon(e, id_anak);
			anak = hold;
		}
		else {
			float advBapak = getAdvantage(elemenBapak,elemenIbu);
			float advIbu = getAdvantage(elemenIbu,elemenBapak);
			if (advBapak > advIbu) {
				Engimon* hold = new Engimon(e, id_bapak);
				anak = hold;
			}
			else if (advIbu > advBapak) {
				Engimon* hold = new Engimon(e, id_ibu);
				anak = hold;
			}
			else {
				int idx_possibleId = rand() % 72;
				id_anak = possibleId[idx_possibleId];
				Engimon* hold = new Engimon(e, id_anak);
				anak = hold;
			}
		}
		
	}
	else if ((id_bapak/100)%10 != 0 && (id_ibu/100)%10 == 0) { // bapak 2 elemen, ibu 1 elemen
		
		int element[2] = {id_bapak/1000,(id_bapak/100)%10};
		int idx = rand() % 2;
		Element elemenBapak(element[idx]);
		Element elemenIbu(id_ibu/1000);
		int elementchosen[2] = {id_bapak,id_ibu};
		float advBapak = getAdvantage(elemenBapak,elemenIbu);
		float advIbu = getAdvantage(elemenIbu,elemenBapak);
		
		if (elemenBapak == elemenIbu) { // elemen sama
			id_anak = elementchosen[idx];
			Engimon* hold = new Engimon(e, id_anak);
			anak = hold;
		}
		else {
			if (advBapak > advIbu) {
				Engimon* hold = new Engimon(e, id_bapak);
				anak = hold;
			}
			else if (advIbu > advBapak) {
				Engimon* hold = new Engimon(e, id_ibu);
				anak = hold;
			}
			else {
				int idx_possibleId = rand() % 72;
				id_anak = possibleId[idx_possibleId];
				Engimon* hold = new Engimon(e, id_anak);
				anak = hold;
			}
		}
			
	}
	else if ((id_bapak/100)%10 == 0 && (id_ibu/100)%10 != 0) { // bapak 1 elemen, ibu 2 elemen
	
		int element[2] = {id_ibu/1000,(id_ibu/100)%10};
		int idx = rand() % 2;
		Element elemenBapak(id_bapak/1000);
		Element elemenIbu(element[idx]);
		int elementchosen[2] = {id_bapak,id_ibu};
		float advBapak = getAdvantage(elemenBapak,elemenIbu);
		float advIbu = getAdvantage(elemenIbu,elemenBapak);
		
		if (elemenBapak == elemenIbu) { // elemen sama
			id_anak = elementchosen[idx];
			Engimon* hold = new Engimon(e, id_anak);
			anak = hold;
		}
		else {
			if (advBapak > advIbu) {
				Engimon* hold = new Engimon(e, id_bapak);
				anak = hold;
			}
			else if (advIbu > advBapak) {
				Engimon* hold = new Engimon(e, id_ibu);
				anak = hold;
			}
			else {
				int idx_possibleId = rand() % 72;
				id_anak = possibleId[idx_possibleId];
				Engimon* hold = new Engimon(e, id_anak);
				anak = hold;
			}
		}	
		
	}
	else { // bapak dan ibu 2 elemen
		
		int elementbapak[2] = {id_bapak/1000,(id_ibu/100)%10};
		int elementibu[2] = {id_ibu/1000,(id_ibu/100)%10};
		int idx = rand() % 2;
		Element elemenBapak(elementbapak[idx]);
		Element elemenIbu(elementibu[idx]);
		int elementchosen[2] = {id_bapak,id_ibu};
		float advBapak = getAdvantage(elemenBapak,elemenIbu);
		float advIbu = getAdvantage(elemenIbu,elemenBapak);
		
		if (elemenBapak == elemenIbu) { // elemen sama
			id_anak = elementchosen[idx];
			Engimon* hold = new Engimon(e, id_anak);
			anak = hold;
		}
		else {
			if (advBapak > advIbu) {
				Engimon* hold = new Engimon(e, id_bapak);
				anak = hold;
			}
			else if (advIbu > advBapak) {
				Engimon* hold = new Engimon(e, id_ibu);
				anak = hold;
			}
			else {
				int idx_possibleId = rand() % 72;
				id_anak = possibleId[idx_possibleId];
				Engimon* hold = new Engimon(e, id_anak);
				anak = hold;
			}
		}	
		
	}
	
	// set nama dan ortu anak
	string name;
	cout<<"Namain anaknye bang"<<endl;
	cin>>name;
	anak->setName(name);
	anak->setParents(dad, mom);
	
	// set skill anak selain unique skill
	// set skill anak = skill bapak selama constraint memenuhi
	for (int i=0;i<dad->getSkills().size();i++) {
		anak->addSkillBreed(dad->getSkills().at(i));
	}
	
	//set skill anak = skill ibu selama constraint memenuhi
	for (int i=0;i<mom->getSkills().size();i++) {
		anak->addSkillBreed(mom->getSkills().at(i));
	}

//	anak.skills[0] = anak.uniqueSkill; // slot pertama skill reserved for species unique skill
//	// skill anak
//		
//	int slotted_skill = 1;
//	int current_skill = 1;
//
//	// set seluruh skill anak = skill bapak
//	for (int i=1;i<4;i++) {
//		if (elemen kompatibel && dad.skills[i].getId() != -1) {
//			anak.skills[current_skill] = dad.skills[i];
//			current_skill ++;
//			slotted_skill ++;
//		}		
//	}
//	
//	// Cek skill bapak = skill ibu
//	current_skill = 1;
//	while(current_skill<slotted_skill) {
//		for (int i=1;i<4;i++) {
//			if (anak.skills[current_skill].getId() == mom.skills[i].getId() && 
//						anak.skills[current_skill] < mom.skills[i]) {
//				anak.skills[current_skill].setMasteryLevel(mom.skills[i].getMasteryLevel());
//			}
//			else if (anak.skills[current_skill].getId() == mom.skills[i].getId() && 
//						anak.skills[current_skill].getMasteryLevel == mom.skills[i].getMasteryLevel()) {
//				anak.skills[current_skill].setMasteryLevel(mom.skills[i].getMasteryLevel()+1);
//			}
//		}
//		current_skill++;
//	}
//	
//	// Cek mastery level skill, ganti current skill dengan skill ibu kalau mastery current lebih kecil
//	vector<Skill> temp;
//	for (int i=1;i<4;i++) {
//		current_skill = 1;
//		while (current_skill<slotted_skill && mom.skills[i].getId() != -1) {
//			if (anak.skills[current_skill] < mom.skills[i]) {
//				temp.push_back(anak.skills[current_skill]);
//				anak.skills[current_skill] = mom.skills[i];
//				break;
//			}
//			current_skill++;
//		}
//	}
//	
//	// Cek mastery level skill, swap current skill dengan skill yang sudah terbuang kalau mastery current lebih kecil
//	for (int i=1;i<slotted_skill;i++) {
//		sort(temp.rbegin(),temp.rend());
//		if (anak.skills[i] < temp[0]) {
//			Skill swap();
//			swap = anak.skills[i];
//			anak.skills[i] = temp[0];
//			temp[0] = swap;
//		}
//	}
//	
//	// sort skill yang kebuang berdasarkan mastery level
//	sort(temp.rbegin(),temp.rend());
//	
//	// maxing skill amount	
//	int temp_idx = 0;
//	while(slotted_skill<4) {
//		current_skill = slotted_skill;
//		anak.skills[current_skill] = temp[temp_idx];
//		slotted_skill ++;
//	}
	
	return *anak;
}
