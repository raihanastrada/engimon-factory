#include <iostream>
#include "Cell.h"
#include "Elements.hpp"
#include "Engimon.hpp"
#include "Inventory.hpp"
#include "Peta.h"
#include "Player.h"
#include "Point.h"
// #include "Skill.h"

// g++ -o main main.cpp Cell.cpp Elements.cpp Engimon.cpp Peta.cpp Player.cpp Point.cpp Skill.cpp

using namespace std;

int main() {
    string playerName;
    int engCount;
    int minLVL;
    cout << "Masukan nama Player: ";
    cin >> playerName;
    cout << "Masukan jumlah maksimum Engimon: ";
    cin >> engCount;
    cout << "Masukan level minimum Engimon: ";
    cin >> minLVL;

    Player P = Player(playerName);
    Peta Map = Peta("./peta.txt", engCount, P, minLVL);
    Map.viewmap();
    
    // Player P = Player("default");
    // Peta Map = Peta("./peta.txt", 10, P, 5);


    return 0;
}