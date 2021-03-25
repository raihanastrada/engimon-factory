#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Inventory.hpp"

using namespace std;
#define Print(n) cout << n << endl
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

// Interaksi dengan Active Engimon
void Player::Interact() {

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
    InvE.GetItemByIdx(index)->PrintInfo(); // TEST harusnya PrintDetail
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