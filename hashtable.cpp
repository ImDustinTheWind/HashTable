/**********************************************
Name: Dustin Sherer
Coding 07
Purpose: Assignment designed to better understand the
    hash-table data structure through building one.
**********************************************/

#include "hashtable.h"


HashTable::HashTable() {
    entryCount = 0;
}

HashTable::~HashTable() {

}

bool HashTable::insertEntry(int iId, std::string* iData) {
    bool isInserted = false;
    int chainlink = hash(iId);
    if ((table[chainlink].addNode(iId, iData))) {
        isInserted = true;
        entryCount++;
    }
    return isInserted;
}

std::string HashTable::getData(int gId) {
    Data passData;
    std::string gData;
    int chainlink = hash(gId);
    if ((gId > 0) && (table[chainlink].getNode(gId, &passData))) {
        gData = passData.data;
    }
    else { gData = ""; }
    return gData;
}

bool HashTable::removeEntry(int rId) {
    bool isRemoved = false;
    int chainlink = hash(rId);
    if (table[chainlink].deleteNode(rId)) {
        isRemoved = true;
        entryCount--;
    }
    return isRemoved;
}

int HashTable::getCount() {
    return entryCount;
}

void HashTable::printTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        std::cout << "-------\n";
        if (table[i].getCount() > 0) {
            std::cout << "Link " << i << ": ";
            table[i].printList(false);
            std::cout << std::endl;
        }
        else { std::cout << "Link " << i << ": EMPTY" << std::endl; }
    }
}

int HashTable::hash(int id) {
    return (id%HASHTABLESIZE);
}
