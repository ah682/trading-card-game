// Adam James Anthony Hall

// Initialize necessary header files
#include "CCard.h"
#include "CCounter.h"

#include <crtdbg.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

// Function overloading
int CCounter::Random(int max) // Returns random value
{
	return int(float(rand()) / (RAND_MAX + 1) * float(max));
}

int CCounter::Random(int min, int max) // Returns random value within a range
{
	return min + int(float(rand()) / (RAND_MAX + 1) * float(max - min + 1));
}

void CCounter::countCardsInFile(unique_ptr<CCounter>& pCounter) // Count number of cards in file
{
    // Count the number of cards in the file
    while (getline(pCounter->mFile, pCounter->mLine))
    {
        pCounter->mCardCounter++ + G_DECK_SIZE;
    }
}

void CCounter::createCardsInVector(unique_ptr<CCounter>& pCounter, vector<shared_ptr<CCard>>& pCards) // Create cards in vector using a for loop
{
	// Iterate over each element in the vector using a for loop
	for (int i = 0; i < pCounter->mCardCounter; i++)
	{
		// Use make_shared to create a new shared_ptr to a CCard object and assign it to the current element in the vector
		pCards[i] = make_shared<CCard>();
	}
}


void CCounter::initializeCheckUsedCard(vector<shared_ptr<bool>>& pCheckUsedCardPlagiarist) // Initialize the vector of bools for checking used cards in Plagiarist's hand 
{ 
	for (int i = 0; i < pCheckUsedCardPlagiarist.size(); i++) {
		pCheckUsedCardPlagiarist[i] = make_shared<bool>(false);
	}
}

void CCounter::initializeHand(vector<shared_ptr<CCard>>& pHand, int size) // Initialize the vector of cards in the hand
{
	for (int i = 0; i < size; i++) {
		pHand[i] = make_shared<CCard>();
	}
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
}

time_t CCounter::getSeed() // Gets seed value to pass to setSeed
{ 
	return mSeed;
}

void CCounter::setSeed(time_t seed) // Sets seed value to pass to srand
{ 
	mSeed = seed;
}

ifstream& CCounter::getFile()   // Gets filename from setFile
{
	return mFile;
}

void CCounter::setFile(const string& filename) // Sets filename to pass to openFile
{
	mFile.open(filename);
}


