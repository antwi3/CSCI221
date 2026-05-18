# CSCI221 Final Project: Text-Based Adventure Game

## Author
Joshua Antwi

## Project Description
This project is a text-based adventure game I wrote in C++, based on my favorite character from Ghanaian folklore (Kwaku Anansi). The player makes choices that affect the story, collect items and stores them in a satchel (inventory system).
Thew choices you make along the way can either benefit you or injure and kill you.

I'm pretty proud of this current version, but I intend to improve upon it, to extend the story, add more complicated game mechanics, as well as to possibly add graphics and other features in the future.

The game uses multiple C++ files, including '.cpp' and '.hpp' files to organise the code into separate parts. It also uses a text file to save and read the player's collected items.


## Main Features
- Branching story paths based on the player's decisions
- A satchel system for storing collected items
- Item files using seperate '.hpp' and '.cpp' files
- A maximum item limit
- Special items that can help the player later in the game
- Colored terminal text for important items and dialogue

## Files Included
- 'main.cpp' - Runs the main game
- 'satchel.hpp' - contains the Satchel class declarations
- 'satchel.cpp' - contains the class function definitions
- 'satchel.txt' - stores collected items
- 'Makefile' - compiles the project
- Multiple items '.hpp' and '.cpp' files that define different game items

## How to Compile:
In your terminal, type in:
- cd **[copied file path]**
- make
- ./game
