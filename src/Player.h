#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <string>
#include "Point.h"
#include "Engimon.hpp"

using namespace std;

class Player {
    private:
        string PlayerName;
        Point EngimonLocation; // Previous Location (Engimon mengikuti gerakan Player)
        Point Location; // Lokasi Player
        // Inventory<Engimon> InvEngimon // (Kelas Engimon)
        // Inventory<SkillItem> InvSkillItem // (Kelas Skill Item)
        // Engimon* ActiveEngimon;
        static int maxCapacity; // Kapasitas maksimum inventory
    public:
        Player(); // Default constructor
        Player(string name); // User-defined constructor
        ~Player(); // Destructor
        Point getLocation();
        Point getEngimonLocation();
        void Move(char direction); // Bergerak ke kiri, kanan, atas, atau bawah
        void CheckActive(); // Mengecek active engimon
        void SwitchActive(string EngimonName); // Mengganti active engimon
        void PrintListEngimon(); // Menampilkan list engimon yang dimiliki
        // Menampilkan data lengkap suatu engimon (setiap atribut kelas)
        // Juga harus menampilkan nama parent beserta spesies mereka
        void PrintListSkillItem(); // Menampilkan list skill item yang dimiliki
        void UseSkillItem(/*apaan*/); // Menggunakan skill item pada suatu engimon
        void Breeding(); // Melaksanakan breeding antara 2 engimon
        void Battle(); // Melakukan battle dengna suatu engimon yang berada di dekatnya (adjacent tiles)
        // Petak kiri, kanan, atas, dan bawah (tampilkan detail engimon lawan ke layar)
        void Interact();
        bool IsInventoryFull();
};

#endif