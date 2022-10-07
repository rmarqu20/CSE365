// ASU CSE310 Assignment #5
// Name of Author: Richard Marquez Cortes
// ASU ID: 1214775731
// Description: this is the main program that reads input from keyboard,
// it then call hash functions to execute hash commands given in the input.

/**************************************************************************
//(1)Describe here what is your hash function?
//My hash function sums up each of the characters in the key and the sum is multiplied by pi.
//The sum is then modulo'd with the number of slots.
//(2)What is the number of collisions you expected?
//It depends on the number of foods and slots, but I was expecting anywhere from 1-3 collisions.
//(3)Did your hash function work well? Using the test cases, what's your hash
//   table's load factor?
//Yes my hash function worked well. For test case 4, my largest slot contained 14 foods. The
//expected load factor for test case 4 was 9.90909.
//(4)If you had to change your hash function to reduce the number of collisions,
//   how will you change it?
//Instead of multiplying by pi, I think multiplying by a prime number would improve the efficiency
//of my hash function.
***************************************************************************/

#include "Hash.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

//This function extracts tokens from oneLine and get all info. of a Food
void getFoodInfo(string oneLine, string& FoodID, string& name, string& supplierID, double& price);

//This function extracts tokens from oneLine and get a Food key which is
//the combination of FoodID, name and supplierID
void getKey(string oneLine, string& command, string& FoodID, string& name, string& supplierID);

int main()
{
    //a variable represents the number of hash table slots
    int size;

    //a variable represents the number of commands
    int numOfCommand;

    //a variable represents the actual command name
    string command;

    string FoodID, name, supplierID;
    double price;
    string delimiter = ",";

    //declare any other necessary variables here
    //----
    string oneLine, commandLine;

    cout << "Enter the size of the hash table: ";
    cin >> size;
    cin.ignore(20, '\n');

    //create the hash table with the relevant number of slots
    //----
    Hash* hashT = NULL;
    hashT = new Hash(size);
    do {
        cout << "\nEnter food info.(enter InsertionEnd to terminate): " << endl;
        getline(cin, oneLine);
        if (oneLine.compare("InsertionEnd") == 0)
        {
            break;
        }

        //if command is not InsertionEnd
        //Get one line, call getFoodInfo(), then
        //insert the new Food inside the hash table
        //----
        getFoodInfo(oneLine, FoodID, name, supplierID, price); //gets new food info
        hashT->hashInsert(FoodID, name, supplierID, price); //inserts new food into hash

    } while (true);

    cout << "\nEnter number of commands: ";
    cin >> numOfCommand;
    cin.ignore(20, '\n');

    for (int i = 0; i < numOfCommand; i++)
    {
        //get one line from the input file and extract the first token,
        //if the token is hashDisplay, call the relevant function in Hash.h
        //-----
        cout << "\nEnter Command: ";
        getline(cin, oneLine);
        getKey(oneLine, command, FoodID, name, supplierID); //gets key
        if (command.compare("hashDisplay") == 0)
        {
            hashT->hashDisplay(); //displays the hash table
        }
            //if the token is hashSearch, call the relevant function in Hash.h
            //----
        else if (command.compare("hashSearch") == 0)
        {
            hashT->hashSearch(FoodID, name, supplierID); //searches for a food in the hash table
        }
            //if the token is hashDelete, call the relevant function in Hash.h
            //----
        else if (command.compare("hashDelete") == 0)
        {
            hashT->hashDelete(FoodID, name, supplierID); //deletes a food from the hash table
        }
            //for all other cases, show the following message
            //cout << "Invalid command" << endl;
        else
        {
            cout << "Invalid command" << endl; //invalid command entered
        }
    } //end for loop
    return 0;
} //end main
//function that takes the oneLine input into its parts and returns a vector
vector<string> split(const string& s, char delim)
{
    vector<string> result;
    stringstream ss(s);
    string str;

    while (getline(ss, str, delim))
    {
        result.push_back(str);
    }
    return result;
}

//*******************************************************************
//This function extract the tokens from one line and
//get all Food info.
//*******************************************************************
void getFoodInfo(string oneLine, string& FoodID, string& name, string& supplierID, double& price)
{
    string delimiter = ",";

    //finish the remaining codes below
    //----
    vector<string> v = split(oneLine, ','); //vector is created with food info
    FoodID = v[0]; //saves foodID
    name = v[1]; //saves name
    supplierID = v[2]; //saves supplierID
    string strPrice = v[3]; //saves price as a string
    //price = atof(strPrice.c_str());
    price = stod(strPrice); //converts price from string to double

    //Note: you can use stod to convert a string into double
    //but you will need c++11 compiler to achieve this
    //for example: price = stod(token);
}

//********************************************************************
//This function extracts the FoodID, name, supplierID from a given line
//These info. forms the key of a Food.
//This function is given to you. Study it.
//********************************************************************
void getKey(string oneLine, string& command, string& FoodID, string& name, string& supplierID)
{
    string delimiter = ",";
    int pos = oneLine.find(delimiter);
    string token = oneLine.substr(0, pos);
    command = token;
    string foodID;
    oneLine.erase(0, pos + delimiter.length());

    pos = oneLine.find(delimiter);
    token = oneLine.substr(0, pos);
    foodID = token;
    oneLine.erase(0, pos + delimiter.length());

    pos = oneLine.find(delimiter);
    token = oneLine.substr(0, pos);
    name = token;
    oneLine.erase(0, pos + delimiter.length());

    pos = oneLine.find(delimiter);
    token = oneLine.substr(0, pos);
    supplierID = token;
    oneLine.erase(0, pos + delimiter.length());
}