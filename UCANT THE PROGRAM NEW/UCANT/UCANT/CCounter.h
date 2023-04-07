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
	int mResilienceIncrease = 0;

	string mLine = "";
	ifstream* mFileReader;
	time_t mSeeder = 0;
	
	// Function overloading
	int Random(int max);
	int Random(int min, int max);

	// Count number of lines
	void countCardsInFile(unique_ptr<CCounter>& pCounter);

	// Push into vector
	void createCardsInVector(unique_ptr<CCounter>& pCounter, vector<shared_ptr<CCard>>& pCards);

	// Initialize check used card array
	void initializeCheckUsedCard(vector<shared_ptr<bool>>& pCheckUsedCardPlagiarist);

	void initializeHand(vector<shared_ptr<CCard>>& pHand, int size);

	time_t getSeed();
	void setSeed(time_t seed);

	ifstream& getFile();
	void setFile(const string& filename);

	// Close player files once game is complete
	~CCounter() {
		if (mFile.is_open()) {
			mFile.close();
		}
	}

private:
	time_t mSeed = 0;
	ifstream mFile;
};

