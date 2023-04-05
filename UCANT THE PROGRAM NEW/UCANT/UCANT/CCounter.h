// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include "CCard.h"
#include <crtdbg.h>
#include <fstream>


class CCounter
{
public:
	int mI = 0;
	int mDeckCounter = 1;
	int mCardCounter = 0;
	int mRandomCard = 0;
	time_t mSeed = 0;
	int mResilienceIncrease = 0;

	string mLine = "";
	ifstream mFile;
	
	// Function overloading
	int Random(int max);
	int Random(int min, int max);

	// Close player files once game is complete
	~CCounter() {
		if (mFile.is_open()) {
			mFile.close();
		}
	}
};

