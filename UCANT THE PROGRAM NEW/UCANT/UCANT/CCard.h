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

class CCard
{
public:
	string mType;
	string mFirstname;
	string mLastname;
	string mPower;
	string mResilience;
	string mBoost;

	//virtual int useCardAbility(int ability = 0) = 0; // Virtual Function
};

