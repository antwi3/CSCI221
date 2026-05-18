#include "satchel.hpp"
#include "bronze_dagger.hpp"
#include "kente_cloak.hpp"
#include "healing_calabash.hpp"
#include "golden_stool_key.hpp"
#include "spider_silk.hpp"
#include "royal_drum.hpp"

// Constructor starts the satchel as empty
Satchel::Satchel() {
    head = nullptr;
    count = 0;
}

// This loads saved items from satchel.txt
void Satchel::loadFromFile() {
    ifstream file("satchel.txt");

    string name;

    // Read each item name from the file
    while (getline(file, name)) {
        Item* item = nullptr;

        // Create the correct item object based on its name
        if (name == "Bronze Dagger") {
            item = new BronzeDagger();
        } else if (name == "Kente Cloak") {
            item = new KenteCloak();
        } else if (name == "Healing Calabash") {
            item = new HealingCalabash();
        } else if (name == "Golden Stool Key") {
            item = new GoldenStoolKey();
        } else if (name == "Spider Silk") {
            item = new SpiderSilk();
        } else if (name == "Royal Drum") {
            item = new RoyalDrum();
        }

        // Add the item to the linked list if it is valid
        if (item != nullptr && !hasItem(name)) {
            if (head == nullptr) {
                head = item;
            } else {
                Item* current = head;

                while (current->getNext() != nullptr) {
                    current = current->getNext();
                }

                current->setNext(item);
            }

            count++;
        }
    }

    file.close();
}

// This saves the current linked list items into satchel.txt
void Satchel::saveToFile() {
    ofstream file("satchel.txt");

    Item* current = head;

    // Write each item name to the file
    while (current != nullptr) {
        file << current->getName() << endl;
        current = current->getNext();
    }

    file.close();
}

// This adds a new item to the satchel
void Satchel::addItem(Item* item) {
    if (item == nullptr) {
        cout << "\nInvalid item.\n";
        return;
    }

    // The satchel can only hold 10 items
    if (count >= 10) {
        cout << "\nYour satchel is full. You cannot carry any more items.\n";
        delete item;
        return;
    }

    // Do not add duplicate items
    if (hasItem(item->getName())) {
        cout << "\nYou already have " << item->getName() << " in your satchel.\n";
        delete item;
        return;
    }

    // If the satchel is empty, the new item becomes the first item
    if (head == nullptr) {
        head = item;
    } else {
        Item* current = head;

        // Move to the end of the linked list
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }

        // Add the item at the end
        current->setNext(item);
    }

    count++;
    saveToFile();

    cout << "\nYou added " << item->getName() << " to your satchel.\n";
}

// This removes an item from the satchel
void Satchel::removeItem(string name) {
    if (head == nullptr) {
        cout << "\nYour satchel is empty.\n";
        return;
    }

    // Check if the first item is the one to remove
    if (head->getName() == name) {
        Item* temp = head;
        head = head->getNext();
        delete temp;
        count--;
        saveToFile();
        cout << "\nYou used " << name << ". It is no longer in your satchel.\n";
        return;
    }

    Item* current = head;

    // Search for the item before the item we want to remove
    while (current->getNext() != nullptr && current->getNext()->getName() != name) {
        current = current->getNext();
    }

    // If the item was not found
    if (current->getNext() == nullptr) {
        cout << "\nInvalid item. That item is not in your satchel.\n";
    } else {
        // Remove the item from the linked list
        Item* temp = current->getNext();
        current->setNext(temp->getNext());
        delete temp;
        count--;
        saveToFile();
        cout << "\nYou used " << name << ". It is no longer in your satchel.\n";
    }
}

// This searches the linked list to see if an item is inside the satchel
bool Satchel::hasItem(string name) {
    Item* current = head;

    while (current != nullptr) {
        if (current->getName() == name) {
            return true;
        }

        current = current->getNext();
    }

    return false;
}

// This checks if the satchel is empty
bool Satchel::isEmpty() {
    return head == nullptr;
}

// This displays the satchel contents from the linked list
void Satchel::displayItems() {
    if (head == nullptr) {
        cout << "\nYour satchel is empty.\n";
        return;
    }

    cout << "\nSatchel Items:\n";

    Item* current = head;
    int number = 1;

    // Print each item in the linked list
    while (current != nullptr) {
        cout << number << ". " << current->getName() << endl;
        cout << "   Effect: " << current->getEffect() << endl;
        cout << "   Type: " << current->getType() << endl;
        cout << "   Power: " << current->getPower() << endl;

        current = current->getNext();
        number++;
    }
}

// This reads directly from satchel.txt and prints what is saved there
void Satchel::displayItemsFromFile() {
    ifstream file("satchel.txt");

    string name;
    int number = 1;

    cout << "\nCurrent Satchel Contents from your satchel:\n";

    if (!file) {
        cout << "satchel.txt could not be opened.\n";
        return;
    }

    // Check if the file is empty
    if (file.peek() == EOF) {
        cout << "Your satchel is empty.\n";
        file.close();
        return;
    }

    // Print every item name saved in the file
    while (getline(file, name)) {
        cout << number << ". " << name << endl;
        number++;
    }

    file.close();
}

// This lets the player choose an item from the satchel
string Satchel::chooseItem() {
    if (head == nullptr) {
        cout << "\nYour satchel is empty. You have no items to use.\n";
        return "none";
    }

    displayItems();

    string answer;
    string secondWord;
    int choice = 0;

    cout << "\nChoose an item number from your satchel, or type 'Check satchel': ";
    cin >> answer;

    while (true) {
        // Let the player check the satchel from the file
        if (answer == "Check" || answer == "check") {
            cin >> secondWord;

            if (secondWord == "satchel" || secondWord == "Satchel") {
                displayItemsFromFile();
            } else {
                cout << "Invalid prompt.\n";
            }

            cout << "\nChoose an item number from your satchel, or type 'Check satchel': ";
            cin >> answer;
        } else if (answer == "1") {
            choice = 1;
        } else if (answer == "2") {
            choice = 2;
        } else if (answer == "3") {
            choice = 3;
        } else if (answer == "4") {
            choice = 4;
        } else if (answer == "5") {
            choice = 5;
        } else if (answer == "6") {
            choice = 6;
        } else if (answer == "7") {
            choice = 7;
        } else if (answer == "8") {
            choice = 8;
        } else if (answer == "9") {
            choice = 9;
        } else if (answer == "10") {
            choice = 10;
        } else {
            choice = 0;
        }

        // Only accept item numbers that are actually in the satchel
        if (choice >= 1 && choice <= count) {
            break;
        }

        cout << "Invalid item choice. Try again, or type 'Check satchel': ";
        cin >> answer;
    }

    Item* current = head;
    int number = 1;

    // Find the item that matches the chosen number
    while (current != nullptr) {
        if (number == choice) {
            return current->getName();
        }

        current = current->getNext();
        number++;
    }

    return "none";
}

// Return the number of items in the satchel
int Satchel::getCount() {
    return count;
}