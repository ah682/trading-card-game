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
	
	// Function overloading
	int Random(int max);
	int Random(int min, int max);

	// Close player files
	~CCounter() {
		if (mFile.is_open()) {
			mFile.close();
			cout << "File closed" << endl;
		}
	}

	//Constructor open player files
	//CCounter() {
	//	mFile.open("Player1.txt");
	//	if (mFile.is_open()) {
	//		cout << "File opened" << endl;
	//	}
	//	else {
	//		cout << "File not opened" << endl;
	//	}
	//}
};

