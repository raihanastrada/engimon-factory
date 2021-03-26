#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Inventory.hpp"

using namespace std;

#define CAPACITY 50 // Maks capacity inventory

int Player::maxCapacity = CAPACITY;
// yang TEST diapus/modify

// User-defined Constructor Player
Player::Player(string name) {
    this->PlayerName = name;
    this->Location = Point(5, 5);
    this->EngimonLocation = Point(5, 4); // Location engimon awal?
    this->ActiveEngimon = nullptr; // Awal nullptr
    // Awal langsung insert 1 Engimon ke inventory, set jadi Active Engimon
}

// Default Constructor Player
Player::Player() : Player("Player") { }

// Copy Constructor
Player::Player(const Player &player) {
    this->PlayerName = player.PlayerName;
    this->Location = player.Location;
    this->EngimonLocation = player.EngimonLocation;
    this->ActiveEngimon = player.ActiveEngimon;
    this->InvE = player.InvE;
    this->InvS = player.InvS;
}

// Operator Assignment
Player& Player::operator=(const Player& player) {
    this->PlayerName = player.PlayerName;
    this->Location = player.Location;
    this->EngimonLocation = player.EngimonLocation;
    this->InvE = player.InvE;
    this->InvS = player.InvS;
    this->ActiveEngimon = player.ActiveEngimon;
    return *this;
}

// Destructor Player
Player::~Player() { delete this->ActiveEngimon; }

// Menggerakkan Player (input W, A, S, D)
void Player::Move(char direction) {
    this->EngimonLocation = this->Location; // Active Engimon berpindah tempat ke lokasi Player
    if (direction == 'W' || direction == 'w') { this->Location.MoveUp(); }
    else if (direction == 'A' || direction == 'a') { this->Location.MoveLeft(); }
    else if (direction == 'S' || direction == 's') { this->Location.MoveDown(); }
    else if (direction == 'D' || direction == 'd') { this->Location.MoveRight(); }
}

// Getter Lokasi Player
Point Player::getLocation() { return this->Location; }

// Getter Lokasi Active Engimon
Point Player::getEngimonLocation() { return this->EngimonLocation; }

// Getter Active Engimon (Pointer ke Engimon) saat ini
Engimon* Player::getActiveEngimon() { return this->ActiveEngimon; }

// Meng-outputkan Detail Active Engimon (Mengecek Active Engimon) TEST
void Player::CheckActive() { ActiveEngimon->PrintInfo(); cout << endl; } // Prints ActiveEngimon Info // PrintDetail?

// Mengganti Active Engimon dengan Engimon yang berada pada Inventory (int index)
void Player::SwitchActive(int index) { ActiveEngimon = InvE.GetItemByIdx(index); } // Indeks Engimon harus diperlihatkan dahulu pada pilihan

// Menu mengganti active Engimon
void Player::SwitchActiveMenu() {
    int input;
    cout << "Inventory Engimon: " << endl;
    PrintListEngimon();
    cout << "Choose ActiveEngimon: ";
    cin >> input;
    if ((input - 1) < 0 || (input - 1) >= this->InvE.GetCount()) { cout << "Input not valid" << endl; return; }
    SwitchActive(input - 1);
}

// Memperlihatkan isi Inventory Engimon TEST
void Player::PrintListEngimon() {
    InvE.PrintAll(); // ganti format method printall, semua item harus punya printinfo
}

// Memperlihatkan isi Inventory Skill Item
void Player::PrintListSkillItem() {
    InvS.PrintAll(); // ganti format method printall, semua item harus punya printinfo
}

void Player::BreedingMenu(Engidex Engi) {
    if (IsInventoryFull()) { cout << "Inventory full" << endl; return; }
    int idx1, idx2;
    cout << "First Engimon" << endl;
    PrintListEngimon();
    cout << "Choose First Engimon: ";
    cin >> idx1;
    if ((idx1 - 1) < 0 || (idx1 - 1) >= InvE.GetCount()) { cout << "Input not valid" << endl; return; }
    cout << "Second Engimon" << endl;
    PrintListEngimon();
    cout << "Choose Second Engimon: ";
    cin >> idx2;
    if ((idx2 - 1) < 0 || (idx2 - 1) >= InvE.GetCount()) { cout << "Input not valid" << endl; return; }
    try {
        Engimon anak = breed(InvE.GetItemByIdx(idx1 - 1), InvE.GetItemByIdx(idx2 - 1), Engi);
        InsertEngimon(anak);
    }
    catch (bool e) {
        cout << "You cannot breed with yourself" << endl;
    }
    catch (int i) {
        cout << "Your Engimon's too weak to breed" << endl;
    }
}

// Interaksi dengan Active Engimon
void Player::Interact() {
    string name = ActiveEngimon->getName();
    string slogan = "";
    for (int i=0; i<min(4, (int)name.length()); i++) slogan.push_back(name[i]);
    slogan += slogan;
    
    cout << '[' << name << "]: " << slogan << "\n";
}

// Print detail suatu Engimon (menampilkan nama parent beserta spesies mereka) serta seluruh atribut kelas
void Player::PrintEngimonMenu() {
    int index;
    cout << "Inventory Engimon: " << endl;
    PrintListEngimon();
    cout << "Choose Engimon to show: ";
    cin >> index;
    if ((index - 1) < 0 || (index - 1) >= InvE.GetCount()) { cout << "Input not valid" << endl; return; }
    cout << "Engimon Detail: " << endl;
    InvE.GetItemByIdx(index - 1)->PrintDetail();
}

// Menggunakan skill item pada InvS[indexS] ke Engimon pada InvE[indexE]
void Player::UseSkillItem(int indexS, int indexE) {
    if (!(InvE.GetItemByIdx(indexE))->addSkill(*(InvS.GetItemByIdx(indexS)))) return;
    InvS.DetractItemByIdx(indexS);
}

// Menu menggunakan skill item
void Player::UseSkillItemMenu() {
    if (InvS.GetCount() == 0) { cout << "Inventory SkillItem empty" << endl; return; }
    int indexS, indexE;
    cout << "Inventory SkillItem: " << endl;
    PrintListSkillItem();
    cout << "Choose SkillItem to use: ";
    cin >> indexS;
    if ((indexS - 1) < 0 || (indexS - 1) >= InvS.GetCount()) { cout << "Input Item not valid" << endl; return; }
    cout << "Inventory Engimon: " << endl;
    PrintListEngimon();
    cout << "Choose Engimon to use SkillItem on: ";
    cin >> indexE;
    if ((indexE - 1) < 0 || (indexE - 1) >= InvE.GetCount()) { cout << "Input Engimon not valid" << endl; return; }
    UseSkillItem(indexS - 1, indexE - 1);
}

// Mengembalikan true jika Inventory full, false jika tidak TEST
bool Player::IsInventoryFull() {
    return (InvE.GetCount() + InvS.GetCount() >= maxCapacity);
}

// Memasukkan Engimon ke Inventory TEST
void Player::InsertEngimon(Engimon E) {
    if (IsInventoryFull()) { cout << "Inventory full" << endl; return; }
    InvE.InsertItem(E);
}

// Memasukkan Skill Item ke inventory TEST
void Player::InsertSkillItem(Skill S) {
    if (IsInventoryFull()) { cout << "Inventory full" << endl; return; }
    InvS.InsertItem(S);
}

// Menghilangkan ActiveEngimon dari inventory, mengembalikan false jika game over, true jika masih terdapat engimon di inventory
bool Player::KillActive() {
    InvE.DetractItem(*ActiveEngimon);
    if (InvE.GetCount() > 0) SwitchActive(0);
    return (InvE.GetCount() > 0);
}

// Meng-outputkan info player (untuk mengecek atribut Player)
void Player::PrintInfo() {
    cout << "Nama: " << this->PlayerName << endl;
    cout << "PLoc: " << "(" << this->Location.GetX() << "," << this->Location.GetY() << ")" << endl;
    cout << "Eloc: " << "(" << this->Location.GetX() << "," << this->Location.GetY() << ")" << endl;
    cout << "InvE: " << this->InvE.GetCount() << endl; // TEST
    cout << "InvS: " << this->InvS.GetCount() << endl; // TEST
    cout << "MaxC: " << maxCapacity << endl;
    cout << "ActE: ";
    if (this->ActiveEngimon == nullptr) { cout << "nullptr" << endl; }
}