#include "item.hpp"

// Default constructor
Item::Item() {
    name = "none";
    effect = "none";
    type = "none";
    power = 0;
    next = nullptr;
}

// Constructor that sets the item information
Item::Item(string itemName, string itemEffect, string itemType, int itemPower) {
    name = itemName;
    effect = itemEffect;
    type = itemType;
    power = itemPower;
    next = nullptr;
}

// Return the item name
string Item::getName() {
    return name;
}

// Return the item effect
string Item::getEffect() {
    return effect;
}

// Return the item type
string Item::getType() {
    return type;
}

// Return the item power
int Item::getPower() {
    return power;
}

// Return the next item in the linked list
Item* Item::getNext() {
    return next;
}

// Set the next item in the linked list
void Item::setNext(Item* nextItem) {
    next = nextItem;
}