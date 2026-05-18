/*
    Author: Joshua Antwi
    Code: Text-based game "Web of The Ancient Kingdom"
    Purpose: Final Project for "Data Structures in C++" course
    Date: (April 29th, 2026) to (May 13th, 2026)

    Citations:
    -
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "satchel.hpp"
#include "bronze_dagger.hpp"
#include "kente_cloak.hpp"
#include "healing_calabash.hpp"
#include "golden_stool_key.hpp"
#include "spider_silk.hpp"
#include "royal_drum.hpp"
#include "glowing_red_mask.hpp"
#include "cursed_gourd.hpp"
#include "obsidian_ring.hpp"
#include "whispering_shell.hpp"
#include "ashanti_mirror.hpp"
#include "sunstone_bead.hpp"
#include "enchanted_ivory_tusk.hpp"

using namespace std;

const string YELLOW = "\033[33m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string RESET = "\033[0m";

const string BRONZE_DAGGER_TEXT = YELLOW + string("Bronze Dagger") + RESET;
const string KENTE_CLOAK_TEXT = YELLOW + string("Kente Cloak") + RESET;
const string HEALING_CALABASH_TEXT = YELLOW + string("Healing Calabash") + RESET;
const string GOLDEN_STOOL_KEY_TEXT = YELLOW + string("Golden Stool Key") + RESET;
const string SPIDER_SILK_TEXT = YELLOW + string("Spider Silk") + RESET;
const string ROYAL_DRUM_TEXT = YELLOW + string("Royal Drum") + RESET;
const string GLOWING_RED_MASK_TEXT = YELLOW + string("Glowing Red Mask") + RESET;
const string CURSED_GOURD_TEXT = YELLOW + string("Cursed Gourd") + RESET;
const string OBSIDIAN_RING_TEXT = YELLOW + string("Obsidian Ring") + RESET;
const string WHISPERING_SHELL_TEXT = YELLOW + string("Whispering Shell") + RESET;
const string ASHANTI_MIRROR_TEXT = YELLOW + string("Ashanti Mirror") + RESET;
const string SUNSTONE_BEAD_TEXT = YELLOW + string("Sunstone Bead") + RESET;
const string ENCHANTED_IVORY_TUSK_TEXT = YELLOW + string("Enchanted Ivory Tusk") + RESET;

void printDivider() {
    cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
}

void receiveInjury(bool& injured, bool& alive) {
    if (injured == false) {
        injured = true;

        cout << "\n" << RED << "You have been injured." << RESET << "\n";
        cout << "Your wound will make the rest of the journey more dangerous.\n";
        cout << "If you are injured again before healing, you will die.\n";
    } else {
        alive = false;

        cout << "\n" << RED << "You have been injured again." << RESET << "\n";
        cout << "Your old wound opens, and the new pain spreads through your body.\n";
        cout << "Because you were already injured, this second wound is too much to survive.\n";
        cout << "You collapse before the story can carry you any farther.\n";
    }
}

string makeLowercase(string text) {
    for (size_t i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i]);
    }

    return text;
}

void waitForEnter() {
    string enter;
    cout << "Press ENTER to continue...";
    getline(cin, enter);
}

int getValidChoice(int smallestChoice, int largestChoice, Satchel& satchel) {
    string input;

    while (true) {
        cout << "Enter your choice, or type 'Check satchel': ";
        getline(cin, input);

        string loweredInput = makeLowercase(input);

        if (loweredInput == "check satchel") {
            cout << "\n";
            satchel.displayItemsFromFile();
            cout << "\n";
            continue;
        }

        bool isNumber = true;

        if (input == "") {
            isNumber = false;
        }

        for (size_t i = 0; i < input.length(); i++) {
            if (!isdigit(input[i])) {
                isNumber = false;
            }
        }

        if (isNumber == true) {
            int numberChoice = stoi(input);

            if (numberChoice >= smallestChoice && numberChoice <= largestChoice) {
                return numberChoice;
            }
        }

        cout << "Invalid prompt. Enter a valid number, or type 'check satchel'.\n";
    }
}

int main() {
    Satchel satchel;

    ofstream clearFile("satchel.txt");
    clearFile.close();

    satchel.loadFromFile();

    bool alive = true;
    bool injured = false;
    bool rememberedName = false;
    bool rememberedEightLimbs = false;
    bool rememberedTrickster = false;

    string itemUsed;
    string user_name;

    cout << "Greetings, traveller.\n";
    cout << "My name is J.A.R.V.I.S.\n";
    cout << "Just A Rather Very Intelligent System.\n";
    cout << "What is your name?\n";
    getline(cin, user_name);

    cout << "\nNice to meet you, " << user_name << "!\n";

    cout << "\nDo you want to play the game?\n";
    cout << "1. Yes\n";
    cout << "2. No\n\n";

    int playChoice = getValidChoice(1, 2, satchel);

    if (playChoice == 1) {
        cout << "\nThat's great!\n";
        waitForEnter();
    } else {
        cout << "\nWell, you've already compiled me, so we're playing this game, " << user_name << "!!!\n";
        waitForEnter();
    }

    cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "                                                                                               WEB OF THE ANCIENT KINGDOM";
    cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    cout << RED << "\nIMPORTANT RULE:\n" << RESET;
    cout << "If you are injured once, you can still survive.\n";
    cout << "But if you are injured a second time before healing, you will die.\n";
    cout << "Also, some items are cursed; interacting with them can hurt you.\n\n";

    cout << GREEN << "At any point when the game asks for a choice, you can type 'Check satchel' to view your current satchel contents.\n\n" << RESET;

    waitForEnter();
    printDivider();

    cout << "You wake beneath a baobab tree at the edge of a silent plain.\n";
    cout << "The sky is the color of old brass, and the red earth is warm under your palms.\n";
    cout << "You do not remember laying down here.\n";
    cout << "You do not remember walking here.\n";
    cout << "You do not remember your name.\n\n";

    cout << "When you try to stand, your body moves in a way that does not feel entirely human.\n";
    cout << "You look down and count eight limbs.\n";
    cout << "Some look like arms, some like legs.\n";
    cout << "All of them seem to know something you do not.\n\n";

    cout << "A dry wind passes through the grass.\n";
    cout << "For a moment, it sounds almost like a voice.\n";
    cout << "'Find the palace. Find the thread. Remember what was taken.'\n\n";

    cout << "Before choosing a road, you notice a hollow in the baobab tree.\n";
    cout << "Inside the hollow is a " << GLOWING_RED_MASK_TEXT << ".\n";
    cout << "It glows like a coal that has learned how to breathe.\n\n";

    cout << "Do you touch the " << GLOWING_RED_MASK_TEXT << "?\n";
    cout << "1. Yes\n";
    cout << "2. No\n\n";

    int maskStartChoice = getValidChoice(1, 2, satchel);
    printDivider();

    if (maskStartChoice == 1) {
        cout << "You touch the " << GLOWING_RED_MASK_TEXT << ".\n";
        cout << "It burns your palm with a memory that is not yours.\n";
        cout << "You pull away, but the mask has already marked you.\n";
        satchel.addItem(new GlowingRedMask());
        receiveInjury(injured, alive);
    } else {
        cout << "You leave the " << GLOWING_RED_MASK_TEXT << " in the hollow.\n";
        cout << "For a moment, it seems to smile without having a mouth.\n";
    }

    if (alive == true) {
        cout << "\nA second object lies near the root of the tree: a " << SUNSTONE_BEAD_TEXT << ".\n";
        cout << "It is warm, small, and full of soft golden light.\n\n";

        cout << "Do you pick up the " << SUNSTONE_BEAD_TEXT << "?\n";
        cout << "1. Yes\n";
        cout << "2. No\n\n";

        int beadChoice = getValidChoice(1, 2, satchel);
        printDivider();

        if (beadChoice == 1) {
            cout << "You pick up the " << SUNSTONE_BEAD_TEXT << ".\n";
            cout << "Its warmth settles into your hand without hurting you.\n";
            satchel.addItem(new SunstoneBead());
        } else {
            cout << "You leave the " << SUNSTONE_BEAD_TEXT << " beside the root.\n";
        }
    }

    if (alive == true) {
        cout << "\nTwo roads wait in front of you.\n";
        cout << "The left road bends toward a market village, where smoke rises in thin black lines.\n";
        cout << "The right road crosses the savanna toward distant walls that shine faintly in the heat.\n\n";

        cout << "Which path do you choose?\n";
        cout << "1. Go toward the market village\n";
        cout << "2. Go toward the savanna road\n\n";

        int firstPath = getValidChoice(1, 2, satchel);
        printDivider();

        if (firstPath == 1) {
            cout << "You walk toward the market village.\n";
            cout << "No one stops you when you enter.\n";
            cout << "No one welcomes you either.\n";
            cout << "People glance at your eight limbs and then look away, as if pretending not to see rain falling indoors.\n\n";

            cout << "At the edge of the market, the path splits.\n";
            cout << "The left side goes through the busy center, where merchants sell salt, cloth, and dried fish.\n";
            cout << "The right side goes behind the storage huts, where the shadows lean strangely against the walls.\n\n";

            cout << "Which way do you go?\n";
            cout << "1. Left, through the busy market\n";
            cout << "2. Right, behind the storage huts\n\n";

            int villageSide = getValidChoice(1, 2, satchel);
            printDivider();

            if (villageSide == 1) {
                cout << "You walk through the busy market.\n";
                cout << "A woman selling kola nuts looks at you and stops counting coins.\n";
                cout << "Somewhere nearby, a drummer taps a pattern that feels too familiar.\n";
                cout << "You cannot remember the song, but your body remembers the rhythm.\n\n";
                rememberedName = true;
            } else {
                cout << "You move behind the storage huts.\n";
                cout << "The clay walls are marked with scratches that look random at first.\n";
                cout << "Then you realize they are not scratches at all.\n";
                cout << "They are fragments of webs.\n";
                cout << "Your fingers twitch, as if they once knew how to answer them.\n\n";
                rememberedEightLimbs = true;
            }

            cout << "Near an abandoned stall, you find a " << BRONZE_DAGGER_TEXT << " wrapped in faded cloth.\n";
            cout << "It is small, plain, and heavier than it looks.\n\n";

            cout << "Do you pick up the " << BRONZE_DAGGER_TEXT << "?\n";
            cout << "1. Yes\n";
            cout << "2. No\n\n";

            int daggerChoice = getValidChoice(1, 2, satchel);
            printDivider();

            if (daggerChoice == 1) {
                satchel.addItem(new BronzeDagger());
            } else {
                cout << "\nYou leave the " << BRONZE_DAGGER_TEXT << " behind.\n";
            }

            cout << "\nA clay merchant calls you over and shows you a " << CURSED_GOURD_TEXT << ".\n";
            cout << "He says it is filled with royal medicine, but he will not meet your eyes.\n\n";

            cout << "Do you drink from the " << CURSED_GOURD_TEXT << "?\n";
            cout << "1. Yes\n";
            cout << "2. No\n\n";

            int gourdChoice = getValidChoice(1, 2, satchel);
            printDivider();

            if (gourdChoice == 1) {
                cout << "You drink from the " << CURSED_GOURD_TEXT << ".\n";
                cout << "The liquid is sweet for one second, then bitter as betrayal.\n";
                cout << "Your stomach tightens, and the market tilts around you.\n";
                satchel.addItem(new CursedGourd());
                receiveInjury(injured, alive);
            } else {
                cout << "You refuse the " << CURSED_GOURD_TEXT << ".\n";
                cout << "The merchant smiles as if you passed a test.\n";
            }

            if (alive == true) {
                cout << "\nAs you pass between the market stalls, the air changes.\n";
                cout << "The noise of the village drops away, as if someone placed a bowl over the world.\n";
                cout << "A spotted hyena spirit steps from beneath a table of broken pots.\n";
                cout << "Its eyes are too calm.\n";
                cout << "Its smile is almost human.\n\n";

                cout << "'A body with eight limbs and no memory,' it says. 'That is a lonely thing.'\n";
                cout << "Then it leaps.\n\n";

                cout << "You must use an item from your satchel.\n";

                itemUsed = satchel.chooseItem();

                if (!satchel.isEmpty()) {
                    printDivider();
                }

                if (itemUsed == "Bronze Dagger") {
                    cout << "You draw the " << BRONZE_DAGGER_TEXT << ".\n";
                    cout << "You do not stab the spirit. Instead, you cut the empty air in front of it.\n";
                    cout << "The air opens like cloth.\n";
                    cout << "The hyena spirit falls through the cut and disappears.\n\n";

                    cout << "A memory rises: laughter in a room full of kings.\n";
                    cout << "The laughter is yours.\n";
                    rememberedName = true;
                } else if (itemUsed == "Glowing Red Mask") {
                    cout << "You raise the " << GLOWING_RED_MASK_TEXT << ".\n";
                    cout << "The mask screams without sound.\n";
                    cout << "The hyena spirit flees, but the scream cuts through your skull.\n";
                    receiveInjury(injured, alive);
                } else if (itemUsed == "none") {
                    cout << "You reach for nothing and find nothing.\n";
                    cout << "The hyena spirit bites your side before dissolving into smoke.\n";
                    cout << "You survive, but pain follows you like a second shadow.\n";
                    receiveInjury(injured, alive);
                } else {
                    cout << "That item does not answer the hyena spirit.\n";
                    cout << "The spirit moves faster than thought and wounds you before vanishing.\n";
                    cout << "You survive, but only barely.\n";
                    receiveInjury(injured, alive);
                }
            }

            if (alive == true) {
                cout << "\nPast the market, you find a " << KENTE_CLOAK_TEXT << " hanging from a wooden pole.\n";
                cout << "Its colors are bright, but not loud.\n";
                cout << "The patterns shift when you look away.\n\n";

                cout << "Do you pick up the " << KENTE_CLOAK_TEXT << "?\n";
                cout << "1. Yes\n";
                cout << "2. No\n\n";

                int cloakChoice = getValidChoice(1, 2, satchel);
                printDivider();

                if (cloakChoice == 1) {
                    satchel.addItem(new KenteCloak());
                } else {
                    cout << "\nYou leave the " << KENTE_CLOAK_TEXT << " behind.\n";
                }

                cout << "\nBeyond the village, you reach a sacred grove.\n";
                cout << "The trees stand very still.\n";
                cout << "White markings cover their bark, and mist gathers around their roots.\n";
                cout << "In the mist, a tall figure without a face waits beside a dry well.\n\n";

                cout << "'Only one wrapped in story-cloth may pass,' it says.\n\n";

                cout << "You must use an item from your satchel.\n";

                itemUsed = satchel.chooseItem();

                if (!satchel.isEmpty()) {
                    printDivider();
                }

                if (itemUsed == "Kente Cloak") {
                    cout << "You wrap yourself in the " << KENTE_CLOAK_TEXT << ".\n";
                    cout << "The cloth grows warm around your shoulders.\n";
                    cout << "The faceless figure steps aside and lowers its head.\n\n";

                    cout << "For a moment, you see your hands spinning thread in darkness.\n";
                    rememberedEightLimbs = true;
                } else if (itemUsed == "Bronze Dagger") {
                    cout << "You swing the " << BRONZE_DAGGER_TEXT << " at the figure.\n";
                    cout << "The blade passes through mist.\n";
                    cout << "The figure touches your forehead, and a door in your mind opens too quickly.\n";
                    cout << "You stagger forward, injured and shaken.\n";
                    receiveInjury(injured, alive);
                } else if (itemUsed == "none") {
                    cout << "You have no item to use.\n";
                    cout << "The mist enters your mouth, your eyes, and finally your memory.\n";
                    cout << "You die in the sacred grove without remembering your name.\n";
                    alive = false;
                } else {
                    cout << "That item does not protect you from the figure.\n";
                    cout << "The mist tightens around your thoughts.\n";
                    cout << "You survive, but your mind is wounded.\n";
                    receiveInjury(injured, alive);
                }
            }

        } else if (firstPath == 2) {
            cout << "You walk across the savanna road.\n";
            cout << "The grass is dry, and the sunlight makes the horizon tremble.\n";
            cout << "Far away, royal walls rise like something half-remembered from a dream.\n\n";

            cout << "The road splits around a field of tall grass.\n";
            cout << "The left path follows old footprints pressed deep into the dust.\n";
            cout << "The right path follows web-shaped marks that appear and vanish when the wind blows.\n\n";

            cout << "Which path do you follow?\n";
            cout << "1. Left, follow the old footprints\n";
            cout << "2. Right, follow the web-shaped marks\n\n";

            int savannaSide = getValidChoice(1, 2, satchel);
            printDivider();

            if (savannaSide == 1) {
                cout << "You follow the old footprints.\n";
                cout << "They lead you past broken spearheads and half-buried shields.\n";
                cout << "You feel that someone fought here long ago.\n";
                cout << "The strange part is that you feel you were watching from above.\n\n";
                rememberedName = true;
            } else {
                cout << "You follow the web-shaped marks.\n";
                cout << "They do not lead in a straight line, but you understand their turns.\n";
                cout << "Your eight limbs begin to move with a quiet confidence.\n";
                cout << "For the first time, your body feels less like a mistake.\n\n";
                rememberedEightLimbs = true;
            }

            cout << "Beside the road, you find a " << HEALING_CALABASH_TEXT << " resting near a flat stone.\n";
            cout << "It is filled with bitter medicine.\n\n";

            cout << "Do you pick up the " << HEALING_CALABASH_TEXT << "?\n";
            cout << "1. Yes\n";
            cout << "2. No\n\n";

            int calabashChoice = getValidChoice(1, 2, satchel);
            printDivider();

            if (calabashChoice == 1) {
                satchel.addItem(new HealingCalabash());
            } else {
                cout << "\nYou leave the " << HEALING_CALABASH_TEXT << " behind.\n";
            }

            cout << "\nFarther along the savanna, you hear branches breaking.\n";
            cout << "A massive elephant steps from the tall grass.\n";
            cout << "Its eyes are old and bright, and one tusk glows with pale gold light.\n";
            cout << "You realize this must be the " << ENCHANTED_IVORY_TUSK_TEXT << ".\n\n";

            cout << "Do you fight the elephant for the " << ENCHANTED_IVORY_TUSK_TEXT << ", or run away?\n";
            cout << "1. Fight the elephant\n";
            cout << "2. Run away\n\n";

            int elephantChoice = getValidChoice(1, 2, satchel);
            printDivider();

            if (elephantChoice == 1) {
                cout << "You rush toward the elephant.\n";
                cout << "The fight is brutal and foolish, but somehow you survive it.\n";
                cout << "The elephant strikes you with the force of a falling wall.\n";
                receiveInjury(injured, alive);

                if (alive == true) {
                    cout << "\nWhen the dust clears, the " << ENCHANTED_IVORY_TUSK_TEXT << " lies on the ground.\n";
                    cout << "You take it, though your body trembles from the cost.\n";
                    satchel.addItem(new EnchantedIvoryTusk());
                }
            } else {
                cout << "You run from the elephant.\n";
                cout << "The earth shakes behind you, but eventually the sound fades.\n";
                cout << "You survive, but the " << ENCHANTED_IVORY_TUSK_TEXT << " remains behind.\n";
            }

            if (alive == true) {
                cout << "\nYou approach a dry riverbed.\n";
                cout << "At first, there is nothing there but cracked mud and white stones.\n";
                cout << "Then the sand rises, grain by grain, into the shape of a giant serpent.\n\n";

                cout << "You must use an item from your satchel.\n";

                itemUsed = satchel.chooseItem();

                if (!satchel.isEmpty()) {
                    printDivider();
                }

                if (itemUsed == "Healing Calabash") {
                    cout << "You drink from the " << HEALING_CALABASH_TEXT << " before the serpent strikes.\n";
                    cout << "Strength moves through all eight limbs at once.\n";
                    cout << "You leap over the serpent and land on the far side of the riverbed.\n";
                    satchel.removeItem("Healing Calabash");
                    rememberedEightLimbs = true;
                } else if (itemUsed == "Enchanted Ivory Tusk") {
                    cout << "You raise the " << ENCHANTED_IVORY_TUSK_TEXT << ".\n";
                    cout << "The serpent recoils from the old elephant magic inside it.\n";
                    cout << "You cross the riverbed safely.\n";
                } else if (itemUsed == "none") {
                    cout << "You have nothing to help you survive the serpent's attack.\n";
                    cout << "The serpent knocks you into the dry riverbed.\n";
                    receiveInjury(injured, alive);
                } else {
                    cout << "That item does not answer the serpent.\n";
                    cout << "It strikes with the weight of a buried river.\n";
                    cout << "You survive, but you are wounded.\n";
                    receiveInjury(injured, alive);
                }
            }

            if (alive == true) {
                cout << "\nAfter escaping the riverbed, you reach an old royal gate.\n";
                cout << "A " << GOLDEN_STOOL_KEY_TEXT << " hangs from a chain beside it.\n\n";

                cout << "Do you pick up the " << GOLDEN_STOOL_KEY_TEXT << "?\n";
                cout << "1. Yes\n";
                cout << "2. No\n\n";

                int keyChoice = getValidChoice(1, 2, satchel);
                printDivider();

                if (keyChoice == 1) {
                    satchel.addItem(new GoldenStoolKey());
                } else {
                    cout << "\nYou leave the " << GOLDEN_STOOL_KEY_TEXT << " behind.\n";
                }

                cout << "\nA royal guardian made of gold dust forms in front of the gate.\n";
                cout << "'Only the one with the sacred key may enter,' it says.\n\n";

                cout << "You must use an item from your satchel.\n";

                itemUsed = satchel.chooseItem();

                if (!satchel.isEmpty()) {
                    printDivider();
                }

                if (itemUsed == "Golden Stool Key") {
                    cout << "You hold up the " << GOLDEN_STOOL_KEY_TEXT << ".\n";
                    cout << "The guardian kneels, and the royal gate opens.\n\n";
                    rememberedName = true;
                    satchel.removeItem("Golden Stool Key");
                } else if (itemUsed == "Enchanted Ivory Tusk") {
                    cout << "You hold up the " << ENCHANTED_IVORY_TUSK_TEXT << ".\n";
                    cout << "The guardian sees the elephant magic and steps aside.\n";
                    cout << "It is not the sacred key, but it is ancient enough to be respected.\n";
                } else if (itemUsed == "none") {
                    cout << "You have no item to show the guardian.\n";
                    cout << "The spear falls like a line being drawn through your life.\n";
                    cout << "You die at the royal gate.\n";
                    alive = false;
                } else {
                    cout << "That item does not prove you belong here.\n";
                    cout << "The guardian strikes you with the blunt end of its spear.\n";
                    receiveInjury(injured, alive);
                }
            }
        }
    }

    if (alive == true) {
        cout << "\nWhether by road, grove, gate, or hidden passage, you eventually reach the Valley of Remembered Stories.\n";
        cout << "The valley is quiet in a way that feels deliberate.\n\n";

        cout << "Three routes lead closer to the palace.\n";
        cout << "The left route passes through a field of broken masks.\n";
        cout << "The middle route descends into a tunnel marked with webs.\n";
        cout << "The right route leads to a black shrine beside a dead fire.\n\n";

        cout << "Which route do you take?\n";
        cout << "1. Left, through the field of broken masks\n";
        cout << "2. Middle, through the web-marked tunnel\n";
        cout << "3. Right, toward the black shrine\n\n";

        int memoryRoute = getValidChoice(1, 3, satchel);
        printDivider();

        if (memoryRoute == 1) {
            cout << "You enter the field of broken masks.\n";
            cout << "Each mask whispers a different name.\n\n";

            cout << "At the center of the field, you find a " << ROYAL_DRUM_TEXT << " resting on a stone.\n\n";

            cout << "Do you pick up the " << ROYAL_DRUM_TEXT << "?\n";
            cout << "1. Yes\n";
            cout << "2. No\n\n";

            int drumChoice = getValidChoice(1, 2, satchel);
            printDivider();

            if (drumChoice == 1) {
                satchel.addItem(new RoyalDrum());
            } else {
                cout << "\nYou leave the " << ROYAL_DRUM_TEXT << " behind.\n";
            }

            cout << "\nAs you leave the field, the broken masks rise into the air.\n";
            cout << "They circle you slowly and whisper false names.\n\n";

            cout << "What do you do?\n"; 
            cout << "1. Run straight through the masks\n";
            cout << "2. Walk slowly and listen carefully\n\n";

            int maskChoice = getValidChoice(1, 2, satchel);
            printDivider();

            if (maskChoice == 1) {
                cout << "You run straight through the masks.\n";
                cout << "The voices cut into your mind like cold water.\n";
                receiveInjury(injured, alive);
            } else {
                cout << "You walk slowly and listen carefully.\n";
                cout << "Most of the names are lies.\n";
                cout << "But beneath the lies, one name waits patiently: Anansi.\n";
                rememberedName = true;
            }

        } else if (memoryRoute == 2) {
            cout << "You enter the web-marked tunnel.\n";
            cout << "At the center of the tunnel, you find a glowing piece of " << SPIDER_SILK_TEXT << ".\n\n";

            cout << "Do you pick up the " << SPIDER_SILK_TEXT << "?\n";
            cout << "1. Yes\n";
            cout << "2. No\n\n";

            int silkChoice = getValidChoice(1, 2, satchel);
            printDivider();

            if (silkChoice == 1) {
                satchel.addItem(new SpiderSilk());
            } else {
                cout << "\nYou leave the " << SPIDER_SILK_TEXT << " behind.\n";
            }

            cout << "\nDeeper in the tunnel, the floor splits into two narrow ledges.\n";
            cout << "The left ledge is darker but steady.\n";
            cout << "The right ledge is brighter but covered in loose stones.\n\n";

            cout << "Which ledge do you take?\n";
            cout << "1. Left, the dark ledge\n";
            cout << "2. Right, the loose stone ledge\n\n";

            int ledgeChoice = getValidChoice(1, 2, satchel);
            printDivider();

            if (ledgeChoice == 1) {
                cout << "You move across the dark ledge carefully.\n";
                cout << "Your many limbs grip the stone with an ease that surprises you.\n";
                rememberedEightLimbs = true;
            } else {
                cout << "You step onto the loose stone ledge.\n";
                cout << "It breaks under your weight.\n";
                cout << "You fall against the tunnel wall and cut your side.\n";
                receiveInjury(injured, alive);
            }

        } else {
            cout << "You walk toward the black shrine.\n";
            cout << "A small " << OBSIDIAN_RING_TEXT << " sits in a bowl of ash.\n";
            cout << "Beside it is a polished " << ASHANTI_MIRROR_TEXT << ".\n\n";

            cout << "Which item do you interact with?\n";
            cout << "1. Put on the " << OBSIDIAN_RING_TEXT << "\n";
            cout << "2. Take the " << ASHANTI_MIRROR_TEXT << "\n";
            cout << "3. Leave both alone\n\n";

            int shrineChoice = getValidChoice(1, 3, satchel);
            printDivider();

            if (shrineChoice == 1) {
                cout << "You slide the " << OBSIDIAN_RING_TEXT << " onto one finger.\n";
                cout << "It tightens instantly, cold as a buried moon.\n";
                satchel.addItem(new ObsidianRing());
                receiveInjury(injured, alive);
            } else if (shrineChoice == 2) {
                cout << "You take the " << ASHANTI_MIRROR_TEXT << ".\n";
                cout << "For one second, you see your true shape reflected in it.\n";
                satchel.addItem(new AshantiMirror());
                rememberedEightLimbs = true;
            } else {
                cout << "You leave both shrine objects untouched.\n";
                cout << "The ash bowl cracks behind you as you walk away.\n";
            }
        }
    }

    if (alive == true) {
        cout << "\nBefore the palace, you reach a salt marsh where the ground shines white.\n";
        cout << "Something small rests beside a pool of dark water: a " << WHISPERING_SHELL_TEXT << ".\n";
        cout << "It whispers your name, even though you have not remembered it yet.\n\n";

        cout << "Do you listen to the " << WHISPERING_SHELL_TEXT << "?\n";
        cout << "1. Yes\n";
        cout << "2. No\n\n";

        int shellChoice = getValidChoice(1, 2, satchel);
        printDivider();

        if (shellChoice == 1) {
            cout << "You lift the " << WHISPERING_SHELL_TEXT << " to your ear.\n";
            cout << "The whisper becomes a scream.\n";
            cout << "It tells you one true thing and ten poisoned lies.\n";
            satchel.addItem(new WhisperingShell());
            rememberedName = true;
            receiveInjury(injured, alive);
        } else {
            cout << "You leave the " << WHISPERING_SHELL_TEXT << " beside the dark water.\n";
            cout << "It keeps whispering long after you walk away.\n";
        }
    }

    if (alive == true) {
        cout << "\nA bone leopard blocks the palace road.\n";
        cout << "Its ribs show through its golden fur, and its teeth are carved with old names.\n";
        cout << "It lowers itself to pounce.\n\n";

        cout << "You must use an item from your satchel.\n";

        itemUsed = satchel.chooseItem();

        if (!satchel.isEmpty()) {
            printDivider();
        }

        if (itemUsed == "Enchanted Ivory Tusk") {
            cout << "You raise the " << ENCHANTED_IVORY_TUSK_TEXT << ".\n";
            cout << "The bone leopard freezes.\n";
            cout << "The ancient elephant magic inside the tusk is stronger than the leopard's hunger.\n";
            cout << "It bows its head and lets you pass.\n";
        } else if (itemUsed == "Bronze Dagger") {
            cout << "You draw the " << BRONZE_DAGGER_TEXT << ".\n";
            cout << "You wound the bone leopard, but it claws your shoulder before fleeing.\n";
            receiveInjury(injured, alive);
        } else if (itemUsed == "Ashanti Mirror") {
            cout << "You hold up the " << ASHANTI_MIRROR_TEXT << ".\n";
            cout << "The bone leopard sees its own dead face and runs into the grass.\n";
        } else if (itemUsed == "none") {
            cout << "You have no item to use.\n";
            cout << "The bone leopard strikes before you can move.\n";
            cout << "You die on the palace road.\n";
            alive = false;
        } else {
            cout << "That item does not stop the bone leopard.\n";
            cout << "It slashes you across the side before vanishing.\n";
            receiveInjury(injured, alive);
        }
    }

    if (alive == true && injured == true) {
        cout << "\nBecause you are injured, the world begins to tilt slightly.\n";
        cout << "You find a quiet underground chamber where a thin stream runs through the stone floor.\n\n";

        cout << "Two tunnels lead out.\n";
        cout << "The left tunnel carries the sound of moving water.\n";
        cout << "The right tunnel carries the sound of whispering voices.\n\n";

        cout << "Which tunnel do you choose?\n";
        cout << "1. Left, toward the water\n";
        cout << "2. Right, toward the voices\n\n";

        int injuredPath = getValidChoice(1, 2, satchel);
        printDivider();

        if (injuredPath == 1) {
            cout << "You follow the sound of water.\n";
            cout << "The stream is cold and clear.\n";

            if (satchel.hasItem("Healing Calabash")) {
                cout << "\nYou still have the " << HEALING_CALABASH_TEXT << ".\n";
                cout << "Do you use it now?\n";
                cout << "1. Yes\n";
                cout << "2. No\n\n";

                int healChoice = getValidChoice(1, 2, satchel);
                printDivider();

                if (healChoice == 1) {
                    cout << "You drink from the " << HEALING_CALABASH_TEXT << ".\n";
                    cout << "The medicine tastes bitter and earthy.\n";
                    cout << "Slowly, the pain loosens its grip.\n";
                    satchel.removeItem("Healing Calabash");
                    injured = false;
                } else {
                    cout << "You save the " << HEALING_CALABASH_TEXT << " and continue while injured.\n";
                    cout << "The wound remains open. Another serious injury will kill you.\n";
                }
            } else if (satchel.hasItem("Sunstone Bead")) {
                cout << "\nThe " << SUNSTONE_BEAD_TEXT << " grows warm in your satchel.\n";
                cout << "Its light closes the edge of your wound.\n";
                cout << "You are no longer injured.\n";
                satchel.removeItem("Sunstone Bead");
                injured = false;
            } else {
                cout << "\nYou do not have a healing item, so you continue while injured.\n";
                cout << "The wound remains open. Another serious injury will kill you.\n";
            }

        } else {
            cout << "You follow the whispering voices.\n";
            cout << "They promise to return your memories all at once, without pain, without cost.\n";
            cout << "You know, somehow, that they are lying.\n\n";

            cout << "You must use an item from your satchel.\n";

            itemUsed = satchel.chooseItem();

            if (!satchel.isEmpty()) {
                printDivider();
            }

            if (itemUsed == "Kente Cloak") {
                cout << "You wrap yourself in the " << KENTE_CLOAK_TEXT << ".\n";
                cout << "The voices press against the cloth but cannot enter.\n";
            } else if (itemUsed == "Spider Silk") {
                cout << "You cast the " << SPIDER_SILK_TEXT << " into the dark.\n";
                cout << "It forms a net of thin light and catches the whispering spirits.\n";
            } else if (itemUsed == "Ashanti Mirror") {
                cout << "You hold up the " << ASHANTI_MIRROR_TEXT << ".\n";
                cout << "The voices see themselves and scatter.\n";
            } else if (itemUsed == "none") {
                cout << "You have no item to use.\n";
                cout << "The voices enter your mind and begin turning off the lights.\n";
                cout << "You die beneath the earth.\n";
                alive = false;
            } else {
                cout << "That item does not protect you from the voices.\n";
                cout << "They move through it like wind through grass.\n";
                cout << "You die beneath the earth.\n";
                alive = false;
            }
        }
    }

    if (alive == true) {
        cout << "\nAt last, you reach the royal palace.\n";
        cout << "It does not look as grand as you expected.\n";
        cout << "It looks quiet, abandoned, and patient.\n";
        cout << "The doors are covered in gold, but dust has settled into the web carvings.\n\n";

        cout << "Above the doors, words appear in pale light:\n";
        cout << "'Only the forgotten keeper of stories may reclaim what was stolen.'\n\n";

        cout << "Before entering, the path splits one final time.\n";
        cout << "The left stairway leads to the throne room.\n";
        cout << "The right stairway leads to the Hall of Old Stories.\n\n";

        cout << "Which stairway do you take?\n";
        cout << "1. Left, to the throne room\n";
        cout << "2. Right, to the Hall of Old Stories\n\n";

        int finalRoute = getValidChoice(1, 2, satchel);
        printDivider();

        if (finalRoute == 1) {
            cout << "You climb the left stairway and enter the throne room directly.\n";
            cout << "The room is bright with gold, but the brightness feels thin, like paint over old wood.\n";
        } else {
            cout << "You climb the right stairway and enter the Hall of Old Stories.\n";
            cout << "Every wall is carved with the same figure: a spider who tricks kings, spirits, and death itself.\n";
            cout << "The stories feel less like stories and more like belongings you misplaced.\n";
            rememberedName = true;
        }

        cout << "\nA false king sits on the throne.\n";
        cout << "He wears a crown made of stolen stories.\n";
        cout << "His face is almost familiar, but only because it is made from fractures of the faces of others.\n\n";

        cout << RED << "'You are no one,' he says calmly.\n" << RESET;
        cout << RED << "'A body without a name. A god without a memory. A spider without a web.'\n\n" << RESET;

        cout << "Then he opens his hand, and a storm of stolen memories moves toward you.\n";
        cout << "You must use an item from your satchel.\n";

        itemUsed = satchel.chooseItem();

        if (!satchel.isEmpty()) {
            printDivider();
        }

        if (itemUsed == "Spider Silk") {
            cout << "You hold up the " << SPIDER_SILK_TEXT << ".\n";
            cout << "It stretches from your fingers and crosses the throne room in silent lines.\n";
            cout << "The stolen memories strike the web and become visible.\n";
            rememberedTrickster = true;
        } else if (itemUsed == "Royal Drum") {
            cout << "You beat the " << ROYAL_DRUM_TEXT << " once.\n";
            cout << "The palace seems to remember its own foundation.\n";
            cout << "The stolen memories loosen and begin returning to their owners.\n";
            rememberedTrickster = true;
        } else if (itemUsed == "Enchanted Ivory Tusk") {
            cout << "You raise the " << ENCHANTED_IVORY_TUSK_TEXT << ".\n";
            cout << "The old elephant magic breaks the first wave of stolen memories.\n";
            cout << "But the tusk alone cannot fully defeat the false king.\n";
            cout << "The backlash wounds you.\n";
            receiveInjury(injured, alive);

            if (alive == true && satchel.hasItem("Spider Silk")) {
                cout << "\nYou still have the " << SPIDER_SILK_TEXT << ".\n";
                cout << "Do you use it now?\n";
                cout << "1. Yes\n";
                cout << "2. No\n\n";

                int tuskChance = getValidChoice(1, 2, satchel);
                printDivider();

                if (tuskChance == 1) {
                    cout << "You throw the " << SPIDER_SILK_TEXT << " into the air.\n";
                    cout << "The web catches the broken memories and pulls them apart thread by thread.\n";
                    rememberedTrickster = true;
                } else {
                    cout << "You refuse to use the " << SPIDER_SILK_TEXT << ".\n";
                    cout << "The false king takes what remains of your memory.\n";
                    alive = false;
                }
            } else if (alive == true) {
                cout << "\nYou have no second memory item to finish the fight.\n";
                cout << "The false king gathers himself and overpowers you.\n";
                alive = false;
            }
        } else if (itemUsed == "Kente Cloak") {
            cout << "You wrap yourself in the " << KENTE_CLOAK_TEXT << ".\n";
            cout << "It protects you from the first wave of stolen memories.\n";
            cout << "But protection is not the same as victory.\n";
            receiveInjury(injured, alive);

            if (alive == false) {
                cout << "\nThe false king watches you fall.\n";
                cout << RED << "'Even stories must end somewhere,' he says.\n" << RESET;
            } else if (satchel.hasItem("Spider Silk")) {
                cout << "\nYou still have " << SPIDER_SILK_TEXT << " in your satchel.\n";
                cout << "Do you use it now?\n";
                cout << "1. Yes\n";
                cout << "2. No\n\n";

                int secondChance = getValidChoice(1, 2, satchel);
                printDivider();

                if (secondChance == 1) {
                    cout << "You throw the " << SPIDER_SILK_TEXT << " into the air.\n";
                    cout << "It catches the false king's stolen memories and pulls them apart thread by thread.\n";
                    rememberedTrickster = true;
                } else {
                    cout << "You refuse to use the " << SPIDER_SILK_TEXT << ".\n";
                    cout << "The false king takes what remains of your memory.\n";
                    alive = false;
                }
            } else if (satchel.hasItem("Royal Drum")) {
                cout << "\nYou still have the " << ROYAL_DRUM_TEXT << " in your satchel.\n";
                cout << "Do you use it now?\n";
                cout << "1. Yes\n";
                cout << "2. No\n\n";

                int drumChance = getValidChoice(1, 2, satchel);
                printDivider();

                if (drumChance == 1) {
                    cout << "You beat the " << ROYAL_DRUM_TEXT << " with shaking hands.\n";
                    cout << "The sound breaks through the stolen memories.\n";
                    rememberedTrickster = true;
                } else {
                    cout << "You refuse to use the " << ROYAL_DRUM_TEXT << ".\n";
                    cout << "The false king takes the rest of your memories.\n";
                    alive = false;
                }
            } else {
                cout << "\nYou have no stronger memory item.\n";
                cout << "The false king takes the rest of your memories.\n";
                alive = false;
            }
        } else if (itemUsed == "Bronze Dagger") {
            cout << "You attack with the " << BRONZE_DAGGER_TEXT << ".\n";
            cout << "The blade passes through the storm, but memories cannot be cut by bronze.\n";
            cout << "The false king takes the last pieces of your mind.\n";
            alive = false;
        } else if (itemUsed == "Golden Stool Key") {
            cout << "You hold up the " << GOLDEN_STOOL_KEY_TEXT << ".\n";
            cout << "The key trembles, but there is no lock here for it to open.\n";
            alive = false;
        } else if (itemUsed == "Healing Calabash") {
            cout << "You reach for the " << HEALING_CALABASH_TEXT << ".\n";
            cout << "It can heal a wound, but not a stolen self.\n";
            alive = false;
        } else if (itemUsed == "Ashanti Mirror") {
            cout << "You hold up the " << ASHANTI_MIRROR_TEXT << ".\n";
            cout << "The false king sees every face he stole.\n";
            cout << "For one moment, he forgets which one is his.\n";

            if (satchel.hasItem("Royal Drum")) {
                cout << "\nYou still have the " << ROYAL_DRUM_TEXT << ".\n";
                cout << "Do you use it now?\n";
                cout << "1. Yes\n";
                cout << "2. No\n\n";

                int mirrorChance = getValidChoice(1, 2, satchel);
                printDivider();

                if (mirrorChance == 1) {
                    cout << "You beat the " << ROYAL_DRUM_TEXT << ".\n";
                    cout << "The false king breaks apart beneath the weight of the reflected stories.\n";
                    rememberedTrickster = true;
                } else {
                    cout << "You hesitate too long.\n";
                    cout << "The false king recovers and destroys the mirror.\n";
                    alive = false;
                }
            } else {
                cout << "But you have no second memory item to finish the fight.\n";
                cout << "The false king recovers and overpowers you.\n";
                alive = false;
            }
        } else if (itemUsed == "none") {
            cout << "You have no item to use.\n";
            cout << "The stolen memories pass through you like cold rain.\n";
            alive = false;
        } else {
            cout << "That item betrays you or fails you at the worst possible moment.\n";
            cout << "The false king attacks before you can choose again.\n";
            alive = false;
        }

        if (alive == true && rememberedTrickster == true) {
            cout << "\nThe palace becomes silent.\n";
            cout << "The false king looks down at his hands and sees that they are empty.\n";
            cout << "Without stolen stories, there is nothing left of him.\n";
            cout << "He turns to dust and falls lightly across the golden floor.\n\n";

            cout << "Then memory returns, not all at once, but carefully.\n";
            cout << "A laugh. A trick. A web in the corner of the world.\n";
            cout << "A throne you never wanted until someone tried to steal it.\n\n";

            if (rememberedName == true || rememberedEightLimbs == true) {
                cout << "The clues were always there: the eight limbs, the web marks, the old rhythm, the thread.\n";
            }

            cout << "You are not a lost stranger.\n";
            cout << "You are Kwaku Anansi, trickster, spider, keeper of stories.\n\n";

            cout << "You climb the golden throne and raise your eight limbs.\n";
            cout << "The stolen stories return to the people like birds finding their way home.\n";
            cout << "The ancient kingdom remembers its true storyteller.\n\n";

            cout << "You reclaim your throne.\n";
            cout << "CONGRATULATIONS, " << user_name << "!\n";
            cout << "YOU WIN THE GAME!!!\n";
        }
    }

    cout << "\nFinal Satchel Contents:\n";
    satchel.displayItemsFromFile();

    cout << "\nThank you for playing WEB OF THE ANCIENT KINGDOM.\n";
    cout << "Have a great day, " << user_name << "!\n";

    return 0;
}