#ifndef DECISIONS_HPP
#define DECISIONS_HPP

#include <iostream>
#include <string>
#include "satchel.hpp"

using namespace std;

// This function gets a valid number choice from the player.
// It also lets the player type "Check satchel".
int getChoice(int minimum, int maximum, Satchel& satchel);

#endif