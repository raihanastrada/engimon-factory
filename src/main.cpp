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
#define LINEE(n) cout << "--------" << n << "--------" << endl;
int main() {
    string playerName;
    int engCount;
    int minLVL;
    string command;
    bool running;
    GameInitiator GI;
    pair<Engidex, CatalogSkill> G = GI.init();

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
    Map.getPlayer()->InsertEngimon(Engimon(G.first, 3001)); // Insert first engimon
    //
    Engimon a(G.first, 2008);
    Engimon b(G.first, 3009);
    Engimon c(G.first, 4001);
    a.setLevel(77);
    b.setLevel(77);
    c.setLevel(77);
    Map.getPlayer()->InsertEngimon(a);
    Map.getPlayer()->InsertEngimon(b);
    Map.getPlayer()->InsertEngimon(c);
    //
    Map.getPlayer()->SwitchActive(0); // Inisialisasi ActiveEngimon
    running = true;

    while (running)
    {
        cout << ">> ";
        cin >> command;
        if (command.length() == 1 && (command[0] == 'W' || command[0] == 'A' || command[0] == 'S' || command[0] == 'D' || command[0] == 'w' || command[0] == 'a' || command[0] == 's' || command[0] == 'd')) {
            try {
                Point AEtemp = Map.getPlayer()->getEngimonLocation();
                // int AEx = Map.getEngimonX(), AEy = Map.getEngimonY();
                Map.getPlayer()->Move(command[0]);
                int x = Map.getPlayerX();
                int y = Map.getPlayerY();
                if (Map.getCellP(y, x)->getEngimon()) {
                    // Engimon temp(*((Map.getCellP(y, x))->getEngimon()));
                    // Map.getCellP(AEtemp.GetY(), AEtemp.GetX())->setEngimon(&temp);
                    Map.setEngimonAt(AEtemp.GetY(), AEtemp.GetX(), Map.getCellP(y, x)->getEngimon());
                    Map.setEngimonAt(y, x, NULL);
                    throw (0);
                }
            }
            catch (int) {
                cout << "Engimon dipindahkan" << endl;
            }
            Map.viewmap();
            Map.increaseTurn();
            Map.spawnEnemy(G.first);
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
        // switch active engimon
        if (command == "switch") {
            Map.getPlayer()->SwitchActiveMenu();
        }
        if (command == "interact") {
            Map.getPlayer()->Interact();
        }
        if (command == "use") {
            Map.getPlayer()->UseSkillItemMenu();
        }
        if (command == "breed") {
            Map.getPlayer()->BreedingMenu(G.first);
        }
        if (command == "detail") {
            Map.getPlayer()->PrintEngimonMenu();
        }
        if (command == "-help") {
            cout << "List of commands untuk bermain:" << endl;
            cout << "inventory untuk melihat inventory" << endl;
            cout << "switch untuk mengganti active Engimon" << endl;
            cout << "w,a,s,d untuk berjalan pada map" << endl;
            cout << "interact untuk interaksi dengan active Engimon" << endl;
            cout << "exit untuk keluar dari game" << endl; 
            cout << "battle untuk battle dengan Engimon" << endl;
            cout << "use untuk menggunakan skill item pada Engimon yang berada di inventory" << endl;
            cout << "detail untuk melihat detail dari Engimon yang dimiliki" << endl;
            cout << "breed untuk melakukan breeding antar Engimon pada Inventory" << endl;
        }
        if (command == "kill") {
            Map.getPlayer()->KillActive();
        }
        if (command == "battle") {
            try {
                if (Map.battle(G.second) == false) {
                    cout << "GAME OVER" << endl;
                    running = false;
                }
            }
            catch (int) {
                cout << "Tidak terdapat Engimon di sekitar Anda" << endl;
            }
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