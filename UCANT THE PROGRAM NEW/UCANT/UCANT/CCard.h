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

// Initialise Card Types
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

class CCard
{
public:

	void useCard(); // function overloading
	int useCardSpecialAbility();
	virtual void printCardUse(); // Virtual Function
	void activateCardDeath(); //function overloading
	void attackProfessor();
	void attackEntity();

	string mType;
	string mFirstname;
	string mLastname;
	string mPower;
	string mResilience;
	string mBoost;
};

