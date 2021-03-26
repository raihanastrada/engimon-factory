#include <iostream>
#include "Battle.h"
#include "Cell.h"
#include "Elements.hpp"
#include "Engimon.hpp"
#include "Inventory.hpp"
#include "Peta.h"
#include "Player.h"
#include "Point.h"
#include "Skill.h"
#include "GameInit.hpp"

using namespace std;

int main() {
    string playerName;
    int engCount;
    int minLVL;
    string command;
    bool running;
    GameInitiator G;
    pair<Engidex, CatalogSkill> GP = G.init();

    cout << "Selamat datang di dunia Engimon!" << endl;
    cout << "Sebelum memulai permainan, siapakah namamu? ";
    cin >> playerName;
    cout << "Oke "+playerName+", sebelum memulai petualanganmu isi settings berikut dan pilih engimonmu pertamamu terlebih dahulu" << endl;
    cout << "___________________________________________________________________________________________________________________" << endl;
    cout << "SETTINGS" << endl;
    cout << "Jumlah maksimum Engimon yang terdapat dalam satu peta (angka tidak dapat diubah selama permainan): ";
    cin >> engCount;
    cout << "Level minimum agar Engimon ditampilkan dalam huruf besar pada peta (angka tidak dapat diubah selama permainan): ";
    cin >> minLVL;
    cout << "___________________________________________________________________________________________________________________" << endl;
    // Ini pilih engimon atau random sabeb

    Player P(playerName);
    Peta Map("./peta.txt", engCount, P, minLVL);
    Map.viewmap();
    cout << "Selamat datang di dunia engimon gambar di atas merupakan peta dari dunia Engimon" << endl;
    cout << "Tuliskan command '-help' untuk mengetahui list command yang dapat digunakan, selamat berpetualang "+playerName+"!" << endl;
    Map.getPlayer()->InsertEngimon(Engimon(*(Map.getEngidex()), 3001)); // Insert first engimon
    Map.getPlayer()->SwitchActive(0); // Inisialisasi ActiveEngimon
    running = true;
    while (running)
    {
        cout << ">> ";
        cin >> command;
        if (command.length() == 1 && (command[0] == 'W' || command[0] == 'A' || command[0] == 'S' || command[0] == 'D' || command[0] == 'w' || command[0] == 'a' || command[0] == 's' || command[0] == 'd')) {
            Map.getPlayer()->Move(command[0]);
            Map.viewmap();
            // Map.increaseTurn();
            // Map.spawnEnemy();
        }
        if (command == "inventory") {
            string cmd;
            cout << "Pilih Inventory untuk dilihat: " << endl;
            cout << "> engimon" << endl;
            cout << "> skillitem" << endl;
            cin >> cmd;
            if (cmd == "engimon") {
                Map.getPlayer()->PrintListEngimon();
            }
            else if (cmd == ("skillitem")) {
                Map.getPlayer()->PrintListSkillItem();
            }
            else { cout << "Input tidak valid" << endl; }
        }
        if (command == "interact") {
            Map.getPlayer()->Interact();
        }
        if (command == "exit")
        {
            running = false;
        }
    }
    int out;
    cout << "Terimakasih telah bermain di dunia Engimon!" << endl;
    cin >> out;
    return 0;
}