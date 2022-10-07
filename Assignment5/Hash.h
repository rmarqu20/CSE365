// ASU CSE310 Assignment #5
// Name of Author: Richard Marquez Cortes
// ASU ID: 1214775731
// Description: this is where you need to design functions on Hash hashTable,
// such as hashInsert, hashDelete, hashSearch and hashDisplay

#include "LinkedList.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

class Hash
{
private:
    LinkedList* hashTable;     //hashTable is a one-dimensional array of LinkedList
    int m;                     //slots number of the hash table
public:
    Hash(int size);
    ~Hash();
    bool hashInsert(string foodID, string name, string supplierID, double price);
    bool hashDelete(string foodID, string name, string supplierID);
    bool hashSearch(string foodID, string name, string supplierID);
    void hashDisplay();
    int hashFunction(string key);

    //add any other auxiliary functions here
    //----
};

//constructor
Hash::Hash(int size)
{
    hashTable = new LinkedList[size];
    m = size;
}

//Destructor
Hash::~Hash()
{
    //----
    struct Food* temp, * tempNext;
    for (int i = 0; i < m; i++) //traverses through hash table
    {
        temp = hashTable[i].getHead(); //sets temp to head
        if (temp != NULL) //checks for non empty list
        {
            while (temp != NULL) //traverses through list
            {
                tempNext = temp->next; //sets tempNext to temp's next food
                delete temp; //deletes temp
                temp = tempNext; //sets temp to tempNext
            }
        }
    }
}

//hashInsert inserts a Food with the relevant info. into the hashTable.
//it returns true if the data is inserted successfully and false otherwise
bool Hash::hashInsert(string foodID, string name, string supplierID, double price)
{
    //----
    string key = foodID + name + supplierID; //creates hash key
    int index = hashFunction(key); //finds index of food
    bool in = hashTable[index].insertFood(foodID, name, supplierID, price);
    if (in == true) //food was inserted successfully
    {
        cout << "slot index = " << index << endl; //prints slot index
        return true;
    }
    else
    {
        return false; //food was not inserted
    }
}

//hashDelete deletes a Food with the relevant key from the hashTable.
//it returns true if it is deleted successfully and false otherwise
//Note: key is the combination of foodID, name and supplierID
bool Hash::hashDelete(string foodID, string name, string supplierID)
{
    //----
    string key = foodID + name + supplierID; //creates hash key
    int index = hashFunction(key); //finds index of food
    bool found = hashSearch(foodID,name,supplierID);
    if (found == true) //looks for food at slot
    {
        hashTable[index].deleteFood(foodID); //deletes food
        //prints deleted food's info
        cout << "\n";
        cout << setw(4) << foodID
             << setw(30) << name
             << setw(12) << supplierID
             << " is deleted from hash table." << endl;
        return true;
    }
    else
    {
        //prints food's info but was not deleted
        cout << "\n";
        cout << setw(4) << foodID
             << setw(30) << name
             << setw(12) << supplierID
             << " is NOT deleted from hash table." << endl;
        return false;
    }
}

//This function searches for a key inside the hash table and
//return true if it is found and false otherwise
//Note: key is the combination of foodID, name and supplierID
bool Hash::hashSearch(string foodID, string name, string supplierID)
{
    //----
    string key = foodID + name + supplierID; //creates hash key
    int index = hashFunction(key); //finds index of food
    bool search = hashTable[index].searchFood(foodID);
    if (search == false) //food was found
    {
        //prints food's info
        cout << "\n" << left
             << setw(4) << foodID
             << setw(30) << name
             << setw(12) << supplierID
             << " is found inside the hash table." << endl;
        return true;
    }
    else if (search == true)
    {
        //prints food's info but was not found
        cout << "\n" << left
             << setw(4) << foodID
             << setw(30) << name
             << setw(12) << supplierID
             << " is NOT found inside the hash table." << endl;
        return false;
    }
}

//This function prints all the elements from the hash hashTable.
void Hash::hashDisplay()
{
    //----
    for (int i = 0; i < m; i++) //traverses hash table
    {
        if (hashTable[i].getSize() != 0) //checks for empty list
        {
            cout << endl;
            cout << "hashTable[" << i << "], size = " << hashTable[i].getSize(); //slot not empty
        }
        else
        {
            cout << endl;
            cout << "hashTable[" << i << "] is empty, size = 0"; //slot empty
        }
        cout << endl;
        hashTable[i].displayList(); //prints list
    }
}

//This is the hash function you will need to design, test and refine
//Given a Food key, the function should return the slot index where it
//will be hashed to
int Hash::hashFunction(string key)
{
    //----
    int sum = 0;
    for (int i = 0; i < key.length()-1; i++) //traverses key
    {
        sum = sum + key[i]; //adds sum of all characters
    }
    sum = sum * 3.14159; //multiplies sum by pi
    sum = sum % m; //modulo sum by number of slots
    return sum;
}
