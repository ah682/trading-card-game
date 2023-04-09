// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include "CCard.h"
#include <crtdbg.h>
#include <fstream>

/*
 * The CCounter class is used to keep track of various counters and values in the game.
 * It has several public member functions for generating random numbers, counting cards in a file,
 * creating cards in a vector, initializing the player's hand, and managing the seed value for random number generation.
 * The class also has several public data members for storing counter values and other information,
 * as well as private data members for managing the seed value and file input.
 */
class CCounter
{
public:
	int mLoopCounter = 0; // Counter for loops
	int mDeckCounter = 1; // Counter for decks
	int mCardCounter = 0; // Counter for cards
	int mRandomCard = 0; // Random card value
	int mResilienceIncrease = 0; // Resillience increase value

	string mLine = ""; // Line read from file
	unique_ptr<ifstream> mFileReader; // Pointer to ifle reader
	time_t mSeeder = 0; // Seed value for random number generation

	// Function overloading
	int Random(int max); // Returns random value
	int Random(int min, int max); // Returns random value within a range

	// Count number of lines
	void countCardsInFile(unique_ptr<CCounter>& pCounter); // Counts cards in file

	// Push into vector
	void createCardsInVector(unique_ptr<CCounter>& pCounter, vector<shared_ptr<CCard>>& pCards); // Creates cards in vector

	// Initialize check used card array
	void initializeCheckUsedCard(vector<shared_ptr<bool>>& pCheckUsedCardPlagiarist); // Intitializes check used card array

	void initializeHand(vector<shared_ptr<CCard>>& pHand, int size); // Initializes player's hand

	time_t getSeed(); // Gets seed value to pass to setSeed
	void setSeed(time_t seed); // Sets seed value for random number generation

	ifstream& getFile(); // Gets filename from setFile
	void setFile(const string& filename); // Sets filename for file input

	// Close player files once game is complete
	~CCounter() {
		if (mFile.is_open()) {
			mFile.close();
		}
	}

private:
	time_t mSeed = 0; // Seed value for random number generation
	ifstream mFile; // File input object
};

