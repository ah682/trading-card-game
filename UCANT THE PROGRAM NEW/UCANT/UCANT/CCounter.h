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
	int mDeckCounter = 2;
	int mCardCounter = 0;
	int mRandomCard = 0;
	int mSeed = 0;
	int mResilienceIncrease = 0;

	string mLine = "";
	ifstream mFile;
	int Random(int max);
	int RandomRange(int min, int max);

	// Close player files
	~CCounter() {
		if (mFile.is_open()) {
			mFile.close();
			cout << "File closed" << endl;
		}
	}
};

