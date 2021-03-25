#include <iostream>
#include "Engimon.hpp"
#include <string>

using namespace std;

Engimon breed(Engimon dad, Engimon mom, Engidex e) {
	if (dad == mom) {
		throw false; // exception bikin anak ma diri sendiri
	}
	if (dad.getLevel()<31 || mom.getLevel()<31) { 
		throw 0; // exception level bapak ibu lower than 31
	}
	
	// level bapak ibu kurang 30
	dad.level(dad.getLevel-30);
	mom.level(mom.getLevel-30);
	
	// construct default engimon
	Engimon* anak = new Engimon();
	
	// set elemen dan spesies anak
	int id_bapak = dad.getEngidexID();
	int id_ibu = mom.getEngidexID();
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
				id_anak = rand() % 9000 + 1000;
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
				id_anak = rand() % 9000 + 1000;
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
				id_anak = rand() % 9000 + 1000;
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
				id_anak = rand() % 9000 + 1000;
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
	anak->parents[0] = &dad;
	anak->parents[1] = &mom;
	
	// set skill anak selain unique skill
	int slotted_skill = 1;
	int current_skill = 1;
	
	// set skill anak = skill bapak selama constraint memenuhi
	for (int i=1;i<4;i++) {
		if ()
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
