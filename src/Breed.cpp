#include <iostream>
#include "Engimon.hpp"
#include <string>

using namespace std;

Engimon Engimon::breed(Engimon dad, Engimon mom) {
	if (dad.id == mom.id) {
		throw false; // exception bikin anak ma diri sendiri
	}
	if (dad.exp<3100 || mom.exp<3100) { 
		throw 0; // exception level bapak ibu lower than 31
	}
	
	// level bapak ibu kurang 30
	dad.exp -= 3000;
	mom.exp -= 3000;
	
	// nama anak
	Engimon anak();
	cout<<"Namain anaknye bang"<<endl;
	cin>>anak.name;
	anak.alive = true;
	anak.exp = 0;
	
	// ortu anak
	anak.parents[0] = dad;
	anak.parents[1] = mom;
	
	string spesies_bapak = dad.getSpeciesName();
	string spesies_ibu = mom.getSpeciesName();
	int id_bapak = dad.getEngidexID();
	int id_ibu = mom.getEngidexID();
	
	// spesies anak
	if (spesies_bapak==spesies_ibu) {
		anak.species(spesies_bapak,id_bapak);
	}
	else {
		if (elemen bapak > elemen ibu) {
			anak.species(spesies_bapak,id_bapak);
		}
		else if (elemen ibu > elemen bapak) {
			anak.species(species_bapak,id_bapak);
		}
		else {
			anak.species(anak_beda_spesies,999);
		}
	}
	
	anak.skills[0] = anak.uniqueSkill; // slot pertama skill reserved for species unique skill
	// skill anak
		
	int slotted_skill = 1;
	int current_skill = 1;

	// set seluruh skill anak = skill bapak
	for (int i=1;i<4;i++) {
		if (elemen kompatibel && dad.skills[i]!=null) {
			anak.skills[current_skill] = dad.skills[i];
			current_skill ++;
			slotted_skill ++;
		}		
	}
	
	// Cek skill bapak = skill ibu
	current_skill = 1;
	while(current_skill<slotted_skill && anak.skills[current_skill]!=null) {
		for (int i=1;i<4;i++) {
			if (anak.skills[current_skill] == mom.skills[i] && 
						anak.skills[current_skill].getMasteryLevel < mom.skills[i].getMasteryLevel()) {
				anak.skills[current_skill].setMasteryLevel(mom.skills[i].getMasteryLevel());
			}
			else if (anak.skills[current_skill] == mom.skills[i] && 
						anak.skills[current_skill].getMasteryLevel == mom.skills[i].getMasteryLevel()) {
				anak.skills[current_skill].setMasteryLevel(mom.skills[i].getMasteryLevel()+1);
			}
		}
		current_skill++;
	}
	
	// Cek mastery level skill
	current_skill = 1;
	Skill* temp = new Skill();
	int temp_idx = 0;
	while(current_skill<slotted_skill && anak.skills[current_skill!=null]) {
		for (int i=1;i<4;i++) {
			if (elemen kompatibel && mom.skills[i]!=null) {
				if (anak.skills[current_skill].getMasteryLevel > mom.skills[i].getMasteryLevel()) {
					temp[temp_idx] = anak.skills[current_skill];
					temp_idx ++;
					anak.skills[current_skill] = mom.skills[i];
				}
			}
		}
		current_skill++;
	}
	
	// maksimalisasi jumlah skill
	temp.sort();
	temp_idx = 0;
	while(slotted_skill<4) {
		current_skill = slotted_skill;
		anak.skills[current_skill] = temp[temp_idx];
		slotted_skill ++;
	}
	
	return anak;
}
