#include "Inventory.h"

using namespace std;

//Ctor
template<typename T>
Inventory<T>::Inventory(){
    totalObject = 0;
}

//Insert item ke inventory
template<typename T>
void Inventory<T>::insertItem(T item){
    if (totalObject < CAPACITY)
    {
        itemInventory[item]++;
        totalItem++;
    }
    else
    {
        cout << "Imventory Penuh" << endl;
    }    
}

//Get item from inventory
template<typename T>
T Inventory<T>::getItem(T item){
    if (itemInventory.count(item))
    {
        itemInventory[item]--;
        totalItem--;
        if (itemInventory.at(item) == 0) //jika value / jumlah di key == item adalah 0, hapus item dari inventory
        {
            itemInventory.erase(item);
        }            
        return item;
    }
    else //item not found
    {
        return NULL;
    }  
}

//Get jumlah item dalam inventory
template<typename T>
int Inventory<T>::numOfItem(){
    return totalItem;
}

//Dtor
template<typename T>
Inventory<T>::~Inventory(){}