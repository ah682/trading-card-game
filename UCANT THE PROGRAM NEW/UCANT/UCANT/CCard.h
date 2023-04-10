// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include <crtdbg.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

// Initilalise size of decks as 48 integers
const int G_DECK_SIZE = 48;

// Initialise Card Type's Integer ID
const string G_STUDENT = "1";
const string G_PLAGIARISM_HEARING = "2";
const string G_COURSE_ACCREDITATION = "3";
const string G_FEEDBACK_FORUM = "4";
const string G_INDUSTRIAL_PLACEMENT = "5";
const string G_PASS_LEADER = "6";
const string G_RESEARCH_FUNDING = "7";
const string G_MITIGATING_CIRCUMSTANCES = "8";
const string G_EASY_TARGET = "9";
const string G_SERIAL_OFFENDER = "10";
const string G_GRADUATE_STUDENT = "11";

/*
 * The CCard class represents a card in the game.
 * It has several public member functions for using the card and its abilities,
 * as well as virtual functions that can be overridden in derived classes.
 * The class also has several public data members for storing information about the card,
 * such as its type, name, power, resilience, and boost.
 */
class CCard
{
public:

	void useCard(); // Function overloading
	int useCardSpecialAbility(); // Gets returned value such as damage to pass to professor or entities
	virtual void printCardUse(); // Virtual Function
	void activateCardDeath(); // Function overloading
	void attackProfessor(); // Function which attacks CPlayers class
	void attackEntity(); // Function which attacks

	string mType; // Stores card type for use in source files
	string mFirstName; // Stores card's first name for use in source files
	string mLastName; // Stores card's last name for use in source files
	string mPower; // Stores cards power for use in source files
	string mResilience; // Store cards resilience for use in source files
	string mBoost; // Stores cards boost for use in source files
};

