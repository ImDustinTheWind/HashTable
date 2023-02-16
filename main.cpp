/**********************************************
Name: Dustin Sherer
Coding 07
Purpose: Assignment designed to better understand the
    hash-table data structure through building one.
**********************************************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    HashTable myTable;
    
    // show it is empty by calling getCount and printTable
    cout << "HASH-TABLE STATUS:\n";
    cout << "Current entry count for hash-table: " << myTable.getCount() << std::endl;
    myTable.printTable();
    
    // try and put ALL the test data into the table and show what happens
    cout << "\nAdding test data to hash-table....\n";
    cout << "=====================================\n\n";
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << " ...";
        if (myTable.insertEntry(ids[i], &(strs[i]))) {
            cout << "SUCCESS\n";
        }
        else { cout << "FAILURE\n"; }
    }

    // check hash-table status
    cout << "\nHASH-TABLE STATUS:\n";
    cout << "Current entry count for hash-table: " << myTable.getCount() << std::endl;
    myTable.printTable();

    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    // test getData with negative and positive id numbers
    cout << "\nTESTING getData(id)...\n";
    for (int i = -10; i < 110; i++) {
        cout << "getData(" << i << ") = " << myTable.getData(i) << std::endl;
    }

    // attempt to remove all entries, including outside range
    cout << "\nTESTING removeEntry(id)...\n";
    for (int i = -10; i < 110; i++) {
        cout << "removeEntry(" << i << ") : ";
        if (myTable.removeEntry(i)) {
            cout << "SUCCESS\n";
        }
        else { cout << "FAIL\n"; }
    }

    // check hash-table status
    cout << "\nHASH-TABLE STATUS:\n";
    cout << "Current entry count for hash-table: " << myTable.getCount() << std::endl;
    myTable.printTable();

    // adding parallel arrays of 500 more entries - including IDs out of normal ID range
    cout << "\nGenerating 1000 more entries... \n";
    srand(time(NULL));
    const int round2 = 1000;
    int ids2[round2];
    string strs2[round2];
    char buffer2[BUFFERSIZE];
    for (int i = 0; i < round2; i++) {
        ids2[i] = rand() % (MAXID*5+20) - 19;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer2[j] = rand() % 2 ? (rand() % (26)) + 'A' : (rand() % (26)) + 'a';
        }
        buffer2[BUFFERSIZE - 1] = '\0';
        strs2[i] = buffer2;
    }
    //show new test data
    cout << "\nShowing NEW Test Data (" << round2 << " entries)..." << endl;
    for (int i = 0; i < round2; i++) {
        cout << ids2[i] << " : " << strs2[i] << endl;
    }
    cout << endl;

    // add new test data to hash-table
    int addSuccess = 0;
    int addFailure = 0;
    cout << "\nAttempting to add 1000 new entries to hash-table....\n";
    cout << "=====================================\n\n";
    for (int i = 0; i < round2; i++) {
        cout << ids2[i] << " : " << strs2[i] << " ...";
        if (myTable.insertEntry(ids2[i], &(strs2[i]))) {
            cout << "SUCCESS\n";
            addSuccess++;
        }
        else { 
            cout << "FAIL\n";
            addFailure++;
        }
    }
    cout << "\nTotal SUCCESS: " << addSuccess << std::endl;
    cout << "Total FAIL: " << addFailure << std::endl;
    
    // check hash-table status
    cout << "\nHASH-TABLE STATUS:\n";
    cout << "Current entry count for hash-table: " << myTable.getCount() << std::endl;
    myTable.printTable();
    
    // use getData() to print data of all possible ids
    cout << "\nPrinting data for all possible IDs...\n";
    for (int i = -20; i < (MAXID*5+20); i++) {
        cout << "getData(" << i << ") = " << myTable.getData(i) << std::endl;
    }
    
    // 
    int insertCount = 0;
    int removeCount = 0;
    int getDataCount = 0;
    cout << "\n\nTest (" << (MAXID*50) <<  ") Random Operations\n";
    cout << "=====================================\n\n";

    for (int k = 0; k < MAXID*50; k++) {
        int whichMethod = rand();
        int tempPop, tempPeek = 0;
        //decide which method to apply
        if (whichMethod % 3 == 0) {
            int num = rand() % (MAXID * 10) + 1;
            cout << "remove |id: " << std::setw(3) << num << std::setw(12) << " | (remove_success  : " 
                << std::setw(5) << std::boolalpha << myTable.removeEntry(num) << ")" << std::endl;
            removeCount++;
        }
        else if (whichMethod % 2 == 0) {
            int num = rand() % (MAXID * 10) + 1;
            cout << "getData|id: " << std::setw(3) << num << std::setw(12) << " | -getData_data    : " << myTable.getData(num) << std::endl;
            getDataCount++;
        }
        else {
            int num = rand() % (MAXID*10) + 1;
            string randStr;
            char buffer3[BUFFERSIZE];
            for (int k = 0; k < BUFFERSIZE - 1; k++) {
                buffer3[k] =(rand() % (26)) + 'A';
            }
            buffer3[BUFFERSIZE - 1] = '\0';
            randStr = buffer3;
            cout << "insert |id: " << std::setw(3) << num << std::setw(12) << " | (insert_success  : " 
                << std::setw(5) << std::boolalpha << myTable.insertEntry(num, &randStr) << ") | data: " << std::setw(12) << randStr << std::endl;
            insertCount++;
        }

    }
    cout << "\nMethod count | insertEntry : " << insertCount << " | removeEntry : "
        << removeCount << " | getData : " << getDataCount << "\n\n\n";

    // check hash-table status
    cout << "\nHASH-TABLE STATUS:\n";
    cout << "Current entry count for hash-table: " << myTable.getCount() << std::endl;
    myTable.printTable();

    // use getData() to print data of all possible ids
    cout << "\nPrinting data for all possible IDs...\n";
    for (int i = -10; i < (MAXID*10+1); i++) {
        cout << "getData(" << i << ") = " << myTable.getData(i) << std::endl;
    }

    return 0;
}
