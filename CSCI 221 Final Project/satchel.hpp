#ifndef SATCHEL_HPP
#define SATCHEL_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "item.hpp"

using namespace std;

// The Satchel class stores the player's items.
// It uses a linked list made of Item objects.
class Satchel {
private:
    Item* head;
    int count;

public:
    // Constructor
    Satchel();

    // File functions
    void loadFromFile();
    void saveToFile();

    // Satchel item functions
    void addItem(Item* item);
    void removeItem(string name);

    // Search functions
    bool hasItem(string name);
    bool isEmpty();

    // Display and choice functions
    void displayItems();
    void displayItemsFromFile();
    string chooseItem();

    // Getter for number of items
    int getCount();
};

#endif