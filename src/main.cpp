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

using namespace std;

int main() {
    string playerName;
    int engCount;
    int minLVL;
    string command;
    bool running;

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
    running = true;
    while (running)
    {
        cout << ">> ";
        cin >> command;
        if (command == "exit")
        {
            running = false;
        }       
    }
    cout << "Terimakasih telah bermain di dunia Engimon!" << endl;
    return 0;
}