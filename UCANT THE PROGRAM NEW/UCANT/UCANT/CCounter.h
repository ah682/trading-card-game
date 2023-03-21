// Adam James Anthony Hall
#pragma once

#include "CCard.h"
#include <crtdbg.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

class CCounter
{
public:
	int i = 0;
	int mDeckCounter = 2;
	int mNum_cardsPlagiarist = 0;
	int mNum_cardsPiffle = 0;
	int mRandomCardPiffle = 0;
	int mRandomCardPlagiarist = 0;
	int mSeed = 0;
	int mResilienceIncreasePiffle = 0;
	int mResilienceIncreasePlagiarist = 0;
	string mLinePiffle = "";
	string mLinePlagiarist = "";
	ifstream mFilePlagiarist;
	ifstream mFilePiffle;
	ifstream mFile;
	int Random(int max);
	int randomRange(int min, int max);

	~CCounter() {
		if (mFile.is_open()) {
			mFile.close();
			cout << "File closed" << endl;
		}
	}
};

