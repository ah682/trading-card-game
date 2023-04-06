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

class CPlayers
{
public:
	struct SProfessor
	{
		string mProfName;
		int mProfPrestige = 30;
	};

	void ProfessorSacked(CPlayers::SProfessor& plagiarist, CPlayers::SProfessor& piffle, CPlayers::SProfessor& pointless, CPlayers::SProfessor& perdition);
	

};

