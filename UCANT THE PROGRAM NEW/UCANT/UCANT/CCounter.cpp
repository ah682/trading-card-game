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

// Count number of cards in file
void CCounter::countCardsInFile(unique_ptr<CCounter>& pCounter)
{
    // Count the number of cards in the file
    while (getline(pCounter->mFile, pCounter->mLine))
    {
        pCounter->mCardCounter++ + G_DECK_SIZE;
    }
}

void CCounter::createCardsInVector(unique_ptr<CCounter>& pCounter, vector<shared_ptr<CCard>>& pCards)
{
	// Iterate over each element in the vector using a for loop
	for (int i = 0; i < pCounter->mCardCounter; i++)
	{
		// Use make_shared to create a new shared_ptr to a CCard object and assign it to the current element in the vector
		pCards[i] = make_shared<CCard>();
	}
}


void CCounter::initializeCheckUsedCard(vector<shared_ptr<bool>>& pCheckUsedCardPlagiarist) {
	for (int i = 0; i < pCheckUsedCardPlagiarist.size(); i++) {
		pCheckUsedCardPlagiarist[i] = make_shared<bool>(false);
	}
}

void CCounter::initializeHand(vector<shared_ptr<CCard>>& pHand, int size) {
	for (int i = 0; i < size; i++) {
		pHand[i] = make_shared<CCard>();
	}
}

time_t CCounter::getSeed() { // Gets seed value to pass to setSeed
	return mSeed;
}

void CCounter::setSeed(time_t seed) {
	mSeed = seed;
}

ifstream& CCounter::getFile() { // Gets filename from setFile
	return mFile;
}

void CCounter::setFile(const string& filename) {
	mFile.open(filename);
}


