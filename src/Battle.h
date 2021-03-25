// battle header
// class battle ini kayak container fungsi-fungsi battle
// dicontain biar enggak global

#ifndef __BATTLE_H
#define __BATTLE_H

#include <bits/stdc++.h>
#include "Engimon.hpp"
#include "Elements.hpp"
#include "Skill.h"
using namespace std;

// contoh pemakaian:
// (a dan b bertipe Engimon)
// Battle::printPower(a, b);
// Battle::comparePower(a, b);

class Battle{
public:
	// menampilkan power level pada pertarungan antara active dengan wild
	static void printPower(Engimon active, Engimon wild);

	// komparator power dua engimon
	// mengembalikan true jika power engimon active tidak lebih kecil dari power engimon 
	static bool comparePower(Engimon active, Engimon wild);
};

#endif