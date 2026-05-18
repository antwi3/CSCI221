#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

// This is the base Item class.
// All other items will inherit from this class.
class Item {
private:
    string name;
    string effect;
    string type;
    int power;
    Item* next;

public:
    // Default constructor
    Item();

    // Constructor that sets all the item information
    Item(string itemName, string itemEffect, string itemType, int itemPower);

    // Getter functions
    string getName();
    string getEffect();
    string getType();
    int getPower();

    // Functions for the linked list
    Item* getNext();
    void setNext(Item* nextItem);
};

#endif