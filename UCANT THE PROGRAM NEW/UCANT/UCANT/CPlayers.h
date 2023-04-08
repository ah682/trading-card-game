// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include "CCard.h"
#include <crtdbg.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

/*
 * The CPlayers class has a public struct called SProfessor.
 * The SProfessor struct has two data members:
 * - mProfName: which stores the name of the professor as a string.
 * - mProfPrestige: which stores the prestige of the professor as an int and is initialized to 30.
 *
 * The CPlayers class also has a public member function called ProfessorSacked,
 * which takes several SProfessor objects as arguments and determines if a professor has been sacked.
 */
class CPlayers
{
public:
	struct SProfessor // Stores the name and prestige of a professor
	{
		string mProfName; // Stores the name of the professor
		int mProfPrestige = 30; // Stores the prestige of the professor
	};
	
	string setProfessorName(string name); // Sets the name of the professor
	void ProfessorSacked(shared_ptr<CPlayers::SProfessor> plagiarist, shared_ptr<CPlayers::SProfessor> piffle, shared_ptr<CPlayers::SProfessor> pointless, shared_ptr<CPlayers::SProfessor> perdition); // Determines if a professor has been sacked
	

};

