/**********************************************
Name: Dustin Sherer
Coding 07
Purpose: Assignment designed to better understand the
    hash-table data structure through building one.
**********************************************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <array>
#include <string>

#include "linkedlist.h"

#define HASHTABLESIZE 15

class HashTable {

public:

    HashTable();
    ~HashTable();

    bool insertEntry(int, std::string*);
    std::string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();


private:

    int hash(int);

    std::array<LinkedList, HASHTABLESIZE> table;
    int entryCount;
};

#endif //HASHTABLE_H