#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <stdio.h>
#include <map>

#define CAPACITY 10 //capacitynya berapa?

using namespace std;

template<typename T>
class Inventory
{
private:
    map <T, int> itemInventory;
    static int totalItem;
public:
    Inventory();
    void insertItem(T item);
    T getItem(T item);
    int numOfItem();
    ~Inventory();
};
#endif