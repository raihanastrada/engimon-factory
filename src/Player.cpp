#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Inventory.hpp"

using namespace std;
#define Print(n) cout << n << endl
#define CAPACITY 20 // Maks capacity inventory

int Player::maxCapacity = CAPACITY;

// User-defined Constructor Player
Player::Player(string name) {
    this->PlayerName = name;
    this->Location = Point(5, 5);
    this->EngimonLocation = Point(5, 4); // Location engimon awal?
}

// Default Constructor Player
Player::Player() : Player("Player") { }

// Operator Assignment
Player& Player::operator=(const Player& player) {
    this->PlayerName = player.PlayerName;
    this->Location = player.Location;
    this->EngimonLocation = player.EngimonLocation;
    this->InvE = player.InvE;
    // this->InvS = player.InvS;
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

// Meng-outputkan Detail Active Engimon (Mengecek Active Engimon)
void Player::CheckActive() { ActiveEngimon->PrintInfo(); } // Prints ActiveEngimon Info // PrintDetail?

// Mengganti Active Engimon dengan Engimon yang berada pada Inventory (int index)
void Player::SwitchActive(int index) { ActiveEngimon = InvE.GetItemByIdx(index); } // Indeks Engimon harus diperlihatkan dahulu pada pilihan

// Menu mengganti active Engimon
void Player::SwitchActiveMenu() {
    // Print list engimon (beserta index + 1)
    // cin >> (input pengguna)
    // cek validasi input
    // switch active engimon
}

// Memperlihatkan isi Inventory Engimon
void Player::PrintListEngimon() {
    InvE.PrintAll(); // ganti format method printall, semua item harus punya printinfo
}

// Memperlihatkan isi Inventory Skill Item
void Player::PrintListSkillItem() {
    //InvS.PrintAll(); // ganti format method printall, semua item harus punya printinfo
}

// Interaksi dengan Active Engimon
void Player::Interact() {

}

// Print detail suatu Engimon (menampilkan nama parent beserta spesies mereka) serta seluruh atribut kelas
void Player::PrintEngimonMenu() {
    // PrintListEngimon
    // cin >> indexEngimon yang ingin dicek detailnya
    // getitembyid(indexEngimon)->printinfo / printdetail;
}

// Mengembalikan true jika Inventory full, false jika tidak
bool Player::IsInventoryFull() {
    return (InvE.GetCount() /*+ InvS.GetCount()*/ >= maxCapacity);
}

// Memasukkan Engimon ke Inventory
void Player::InsertEngimon(Engimon E) {

}

// Memasukkan Skill Item ke inventory
void Player::InsertSkillItem(Skill S) {

}