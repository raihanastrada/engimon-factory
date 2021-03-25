#ifndef _INVENTORY_HPP_
#define _INVENTORY_HPP_

#include <iostream>
#include <vector>
#include <utility>
#include <iterator>

using namespace std;

template <class T>
class Inventory {
    private:
        /* Max Capacity Inventory pada kelas Player */
        int Count; // Jumlah item pada inventory
        vector<pair<T, int>> Inv; // Vektor mengisi item dalam pair (objek, jumlah)
    public:
        Inventory() { // Default Constructor
            this->Inv = vector<pair<T, int>>();
            this->Count = 0;
        }
        Inventory& operator=(const Inventory& other) {
            this->Count = other.Count;
            this->Inv = other.Inv;
            return *this;
        }
        ~Inventory() { // Destructor
            vector<pair<T, int>>().swap(this->Inv); // Menukar vector dengan vector kosong (membebaskan memory)
        }
        void InsertItem(T item) { // Memasukkan Item ke inventory
            // Jika item tidak ditemukan (ditambahkan elemen baru dalam vector dengan count 1)
            if (FindItem(item) == nullptr) { this->Inv.push_back(make_pair(item, 1)); this->Count++; return; }
            this->Inv[ContainsID(item)].second++; // Menambah Count dari item inventory jika ditemukan
            this->Count++; // Menambah jumlah item pada inventory
        }
        void DetractItem(T item) {
            int index = ContainsID(item); // Index item input
            if (index == -1) return; // Tidak ditemukan item
            DetractItemByIdx(index); // Mengurangkan count item jika ditemukan
        }
        void DetractItemByIdx(int index) {
            if (index >= Inv.size() || index < 0) return; // Guard jika input index tidak valid
            // Menghapus dari inventory jika count item tersebut = 1
            if (Inv[index].second == 1) Inv.erase(Inv.begin() + index);
            else Inv[index].second--; // Mengurangkan count item tersebut jika > 1
            this->Count--;
        }
        T* FindItem(T item) { // Mengembalikan pointer ke Item yang dicari jika ditemukan, nullptr jika tidak
            for (typename vector<pair<T, int>>::iterator i = Inv.begin(); i != Inv.end(); i++) {
                if ((*i).first == item) {
                    return &((*i).first);
                }
            }
            return nullptr;
        }
        T* GetItemByIdx(int index) { // Mengembalikan pointer ke Item sesuai index input
            if (index >= Inv.size() || index < 0) return nullptr; // Guard jika input tidak valid
            return &((this->Inv[index]).first);
        }
        int ContainsID(T item) { // Memeriksa jika item berada pada inventory, jika ada dikembalikan indexnya, jika tidak dikembalikan -1
            for (typename vector<pair<T, int>>::iterator i = Inv.begin(); i != Inv.end(); i++) {
                if ((*i).first == item) {
                    return distance(Inv.begin(), i);
                }
            }
            return -1;  
        }
        int GetCount() { // Getter Count (jumlah item pada inventory)
            return this->Count;
        }
        void PrintAll() { // Print seluruh info inventory
            int i = 0;
            for (typename vector<pair<T, int>>::iterator i = Inv.begin(); i != Inv.end(); i++) {
                // cout << "Index: " << (distance(Inv.begin(), i)) << endl; // TEST
                cout << (distance(Inv.begin(), i) + 1) << ". ";
                (*i).first.PrintInfo(); // Setiap PrintInfo() harus ada << endl;
                cout << "\t" << "Count: " << (*i).second << endl;
            }
        }
};

#endif