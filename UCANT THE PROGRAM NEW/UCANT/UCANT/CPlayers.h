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
	int mProfPrestige = 30; // Stores the prestige of the professor
	string mProfName; // Stores the name of the professor
	string setProfessorName(string name); // Sets the name of the professor
	void ProfessorSacked(shared_ptr<CPlayers> plagiarist, shared_ptr<CPlayers> piffle, shared_ptr<CPlayers> pointless, shared_ptr<CPlayers> perdition); // Determines if a professor has been sacked
	string mProfNamer; // Gets Name of professor to set
private:

};

