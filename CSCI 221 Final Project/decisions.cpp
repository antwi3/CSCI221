#include "decisions.hpp"

// This gets a valid choice from the player.
// The player can also type "Check satchel" to view the satchel.
int getChoice(int minimum, int maximum, Satchel& satchel) {
    string answer;
    string secondWord;
    int choice = 0;

    cout << "Enter your choice, or type 'Check satchel': ";
    cin >> answer;

    while (true) {
        // This checks if the player typed "Check satchel"
        if (answer == "Check" || answer == "check") {
            cin >> secondWord;

            if (secondWord == "satchel" || secondWord == "Satchel") {
                satchel.displayItemsFromFile();
            } else {
                cout << "Invalid prompt.\n";
            }

            cout << "\nEnter your choice, or type 'Check satchel': ";
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

        // Return the choice only if it is inside the correct range
        if (choice >= minimum && choice <= maximum) {
            return choice;
        }

        cout << "Invalid prompt. Enter a valid number, or type 'Check satchel': ";
        cin >> answer;
    }
}