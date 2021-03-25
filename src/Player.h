#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <string>
#include "Inventory.hpp"
#include "Point.h"
#include "Engimon.hpp"
#include "Skill.h"

using namespace std;

class Player {
    private:
        string PlayerName;
        Point EngimonLocation; // Previous Location (Engimon mengikuti gerakan Player)
        Point Location; // Lokasi Player
        Inventory<Engimon> InvE; // Inventory Engimon (Kelas Engimon)
        Inventory<Skill> InvS; // Inventory SkillItem (Kelas Skill Item)
        Engimon* ActiveEngimon; // Pointer ke Active Engimon
        static int maxCapacity; // Kapasitas maksimum inventory
    public:
        Player(); // Default constructor
        Player(string name); // User-defined constructor
        Player& operator=(const Player&); // Operator Assignment
        ~Player(); // Destructor TEST
        Point getLocation(); // Getter Location Player
        Point getEngimonLocation(); // Getter Location Active Engimon
        void Move(char direction); // Bergerak ke kiri, kanan, atas, atau bawah
        void CheckActive(); // Mengecek active engimon
        void SwitchActive(int index); // Mengganti active engimon // Mencari Engimon pada Inv dengan index
        void SwitchActiveMenu(); // Menu untuk memilih mengganti Engimon Active
        void PrintListEngimon(); // Menampilkan list engimon yang dimiliki
        // Menampilkan data lengkap suatu engimon (setiap atribut kelas)
        // Juga harus menampilkan nama parent beserta spesies mereka
        void PrintListSkillItem(); // Menampilkan list skill item yang dimiliki
        void PrintEngimonMenu(); // Print detail suatu Engimon (menampilkan nama parent beserta spesies mereka) serta seluruh atribut kelas
        void UseSkillItem(/*apaan*/); // Menggunakan skill item pada suatu engimon
        void Breeding(); // Melaksanakan breeding antara 2 engimon
        void Battle(); // Melakukan battle dengan suatu engimon yang berada di dekatnya (adjacent tiles)
        // Petak kiri, kanan, atas, dan bawah (tampilkan detail engimon lawan ke layar)
        void Interact(); // Mengecek Active Engimon
        bool IsInventoryFull(); // Mengecek jika inventory full
        void InsertEngimon(Engimon E); // Insert Engimon ke inventory TEST
        void InsertSkillItem(Skill S); // Insert SkillItem ke inventory
        void PrintInfo(); // Meng-outputkan info player
};

#endif