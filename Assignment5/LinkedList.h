// ASU CSE310 Assignment #5
// Name of Author: Richard Marquez Cortes
// ASU ID: 1214775731
// Description: A simple linked list that implements a list of Food objects. A user can
//              perform searching, insertion or deletion on the linked list.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Food
{
    string foodID, name, supplierID;
    double price;
    struct Food* next;
};

class LinkedList
{
private:
    struct Food* head;
    int size;
public:
    LinkedList();
    ~LinkedList();
    Food* getHead();
    int getSize();
    bool insertFood(string foodID, string name, string supplierID, double price);
    bool deleteFood(string foodID);
    bool searchFood(string foodID);
    void displayList();
};

//Constructor
LinkedList::LinkedList()
{
    head = NULL;
    size = 0;
}

//Destructor
LinkedList::~LinkedList()
{
    //----
    struct Food* curr, * temp; //variables
    curr = head;
    temp = head;
    while (curr != NULL) //traverses linked list until null
    {
        curr = curr->next; //sets curr to the next food
        delete temp; //deletes temp
        temp = curr; //temp is set to curr to be repeated
    }
}

//Accessor for the head
Food* LinkedList::getHead()
{
    return head;
}

//Return number of foods inside the Linked list
int LinkedList::getSize()
{
    return size;
}

//Insert the parameter food at the head of the linked list.
//return true if it is inserted successfully and false otherwise
bool LinkedList::insertFood(string foodID, string name, string supplierID, double price)
{
    //----
    struct Food* newFood = new Food(); //create new food
    //sets new food's info
    newFood->foodID = foodID;
    newFood->name = name;
    newFood->supplierID = supplierID;
    newFood->price = price;

    if (head == NULL) //checks for empty list
    {
        head = newFood; //sets head to the new food
        size = size + 1; //increments size
        return true;
    }
    else //list not empty
    {
        newFood->next = head; //sets new food's next pointer to the head
        head = newFood; //sets head to new food
        size = size + 1; //increments size
        return true;
    }
}

//Delete the food with the given foodID from the linked list.
//Return true if it is deleted successfully and false otherwise
bool LinkedList::deleteFood(string foodID)
{
    //----
    struct Food* temp = head;
    struct Food* prev = head;
    if (head == NULL) //checks for empty list
    {
        return false;
    }
    //traverses linked list until foodID matches
    while (temp->next != NULL && temp->foodID.compare(foodID) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    //end of linked list, food was not found
    if (temp->foodID.compare(foodID) != 0)
    {
        return false;
    }
    else
    {
        if (temp != NULL)
        {
            head = temp->next; //sets head to temp's next
            free(temp); //frees temp
            size = size - 1; //decrements size
            return true;
        }
        else
        {
            if (temp->next != NULL)
            {
                head = temp->next; //sets head to temp's next
                free(temp); //frees temp
                size = size - 1; //decrements size
                return true;
            }
            else
            {
                free(temp); //frees temp
                head = NULL; //sets head to null since its only food in list
                size = size - 1; //decrements size
                return true;
            }
        }
    }
}

//This function searches the food list with the given foodID
//returns true if it is found, otherwise return false.
bool LinkedList::searchFood(string foodID)
{
    //----
    struct Food* curr = head;
    if(head == NULL) //checks for empty list
    {
        return false;
    }
    //traverses linked list until foodID matches or end of list
    while (curr->next != NULL && curr->foodID.compare(foodID) != 0)
    {
        curr = curr->next; //moves pointer to next node
    }
    if (curr->foodID.compare(foodID) == 0)
    {
        return true; //food was found
    }
    return false; //food not found
}

//This function displays the content of the linked list.
void LinkedList::displayList()
{
    struct Food* temp = head;
    if (head == NULL) //checks for empty list
    {
        return;
    }
    while (temp != NULL) //not empty, so it prints list
    {
        cout << left;
        cout << setw(4) << temp->foodID
             << setw(30) << temp->name
             << setw(12) << temp->supplierID
             << setw(8) << temp->price << endl;
        temp = temp->next;
    }
}
