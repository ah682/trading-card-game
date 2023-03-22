// Adam James Anthony Hall

// Memory Leak Detection
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <memory>

#include "CManager.h"
#include "CCard.h"
#include "CStudent.h"
#include "CTable.h"
#include "CCourseAccreditation.h"
#include "CPlagiarismHearing.h"
#include "CCounter.h"
#include "CFeedbackForum.h"

using namespace std;

const time_t ReadSeedFile(string filename);


int main()
{
	typedef unique_ptr<CCounter> pCCounterPtr;

	auto pCounterPiffle = make_unique<CCounter>();
	auto pCounterPlagiarist = make_unique<CCounter>();

	// Genereates seed from read file
	pCounterPiffle->mSeed = ReadSeedFile("seed.txt");
	srand(pCounterPiffle->mSeed);
	cout << "Seed Number: " << pCounterPiffle->mSeed << endl;

	// Initialize data before commencing U-Can't

	auto pGameState = make_unique<CManager>();
	pGameState->GameStart();

	const int DECK_SIZE = 48;

	pCounterPlagiarist->mFile.open("plagiarist.txt");
	pCounterPiffle->mFile.open("piffle-paper.txt");
	//Counter->filePlagiarist.open("pointless.txt");
   // Counter->filePiffle.open("perdition.txt");

	auto pPlagiarist = make_shared<CPlayers::SProfessor>();
	auto pPiffle = make_shared<CPlayers::SProfessor>();
	auto pPerdition = make_shared<CPlayers::SProfessor>();
	auto pPointless = make_shared<CPlayers::SProfessor>();

	// Count the number of cards in the plagiarist file
	while (getline(pCounterPlagiarist->mFile, pCounterPiffle->mLine))
	{
		pCounterPlagiarist->mCardCounter++ + DECK_SIZE;
	}

	// Count the number of cards in the piffle file
	while (getline(pCounterPiffle->mFile, pCounterPlagiarist->mLine))
	{
		pCounterPiffle->mCardCounter++ + DECK_SIZE;
	}


	// Allocate memory for the cards
	auto pCardsPiffle = vector<shared_ptr<CCard>>(pCounterPiffle->mCardCounter);

	for (int i = 0; i < pCounterPiffle->mCardCounter; i++)
	{
		pCardsPiffle[i] = make_shared<CCard>(); // Assign the shared_ptr to the vector element
	}

	// Allocate memory for the cards
	auto pCardsPlagiarist = vector<shared_ptr<CCard>>(pCounterPlagiarist->mCardCounter);

	for (int i = 0; i < pCounterPlagiarist->mCardCounter; i++)
	{
		pCardsPlagiarist[i] = make_shared<CCard>(); // Assign the shared_ptr to the vector element
	}

	// Allocate memory for the cards
	auto pCardsPlagiaristStudents = vector<shared_ptr<CStudent>>(pCounterPlagiarist->mCardCounter);

	for (int i = 0; i < pCounterPlagiarist->mCardCounter; i++)
	{
		pCardsPlagiaristStudents[i] = make_shared<CStudent>(); // Assign the shared_ptr to the vector element
	}

	// Allocate memory for the cards
	auto pCardsPiffleStudents = vector<shared_ptr<CStudent>>(pCounterPiffle->mCardCounter);

	for (int i = 0; i < pCounterPiffle->mCardCounter; i++)
	{
		pCardsPiffleStudents[i] = make_shared<CStudent>(); // Assign the shared_ptr to the vector element
	}

	// Allocate memory for the cards
	typedef vector <shared_ptr<CCard>> cardsDrawn;
	auto pCardsPlagiaristDrawn = cardsDrawn{};
	auto pCardsPiffleDrawn = cardsDrawn{};

	typedef vector <shared_ptr<CStudent>> cardsStudentDrawn;
	auto pCardsPlagiaristStudentsDrawn = cardsStudentDrawn{};
	auto pCardsPiffleStudentsDrawn = cardsStudentDrawn{};

	typedef vector <shared_ptr<CTable>> Table;
	auto pTablePlagiarist = Table{};
	auto pTablePiffle = Table{};

	typedef vector <shared_ptr<CPlagiarismHearing>> plagiarismHearingCards;
	auto pPlagiarismHearingPlagiarist = plagiarismHearingCards{};
	auto pPlagiarismHearingPiffle = plagiarismHearingCards{};

	typedef vector <shared_ptr<CCourseAccreditation>> courseAccreditationCards;
	auto pCourseAccreditationPlagiarist = courseAccreditationCards{};
	auto pCourseAccreditationPiffle = courseAccreditationCards{};

	typedef vector <shared_ptr<CFeedbackForum>> feedbackForumCards;
	auto pFeedbackForumPlagiarist = feedbackForumCards{};
	auto pFeedbackForumPiffle = feedbackForumCards{};

	pGameState->FillDeck(pCounterPlagiarist->mFile, pCardsPlagiarist, pCardsPlagiaristStudents);
	pGameState->FillDeck(pCounterPiffle->mFile, pCardsPiffle, pCardsPiffleStudents);


	// Allocate
	typedef vector<shared_ptr<bool>> checkUsedCard;

	auto pCheckUsedCardPlagiarist = checkUsedCard(DECK_SIZE);

	for (int i = 0; i < DECK_SIZE; i++)
	{
		pCheckUsedCardPlagiarist[i] = make_unique<bool>(false);
	}

	auto pCheckUsedCardPiffle = checkUsedCard(DECK_SIZE);

	for (int i = 0; i < DECK_SIZE; i++)
	{
		pCheckUsedCardPiffle[i] = make_unique<bool>(false);
	}

	// MAKE LOOP UNTIL PRESTIGE HITS 0
	do
	{
		// Allocate memory for the cards

		// Draws random card for plagiarist and checks if works with cout
		if (pCounterPlagiarist->i < DECK_SIZE)
		{
			cout << "Drawn Cards from Plagiarist:" << endl;
			pGameState->DrawCard(pCardsPlagiarist, pCardsPlagiaristDrawn, pCounterPlagiarist->mDeckCounter, pCounterPlagiarist->i, *pPlagiarist, pCheckUsedCardPlagiarist);

			cout << "Drawn Cards from Piffle-Paper:" << endl;
			pGameState->DrawCard(pCardsPiffle, pCardsPiffleDrawn, pCounterPiffle->mDeckCounter, pCounterPiffle->i, *pPiffle, pCheckUsedCardPiffle);


			// Piffle Chooses a card card THIS IS SUPPOSE TO BE RANDOM
			pCounterPiffle->mRandomCard = pCounterPiffle->RandomRange(pCardsPiffleDrawn.size() - 2, pCardsPiffleDrawn.size() - 1);

			cout << "Piffle-Papaer chooses card: " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mType << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mFirstname << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mLastname << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mPower << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mResilience << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mBoost << endl;
			// Plagiarist Chooses a card card THIS IS SUPPOSE TO BE RANDOM
			pCounterPlagiarist->mRandomCard = pCounterPlagiarist->RandomRange(pCardsPlagiaristDrawn.size() - 2, pCardsPlagiaristDrawn.size() - 1);
			cout << "Plagiarist chooses: " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mType << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mFirstname << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mLastname << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mPower << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mResilience << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mBoost << endl;
		}

		//Prints table on cards for specific player
		pGameState->TableCard(pTablePiffle, pCardsPiffleDrawn, *pPiffle, "Piffle-Paper", pCounterPiffle->mRandomCard);
		pGameState->TableCard(pTablePlagiarist, pCardsPlagiaristDrawn, *pPlagiarist, "Plagiarist", pCounterPlagiarist->mRandomCard);

		// Make cards duel
		// Create Piffle Player piffle gets attacked
		pGameState->CardsDuel(pTablePiffle, pTablePlagiarist, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist", pCardsPlagiaristDrawn, pCounterPlagiarist->mRandomCard, pCounterPlagiarist->mResilienceIncrease);


		int randomRangeOneorTwo = pCounterPlagiarist->RandomRange(1, 2); //?????????????????????????????????????????????????????????
		//Piffle Gets Attacked
		pGameState->PlagiarismHearing(pCardsPlagiaristDrawn, pPlagiarismHearingPlagiarist, pTablePiffle, pCounterPlagiarist->mRandomCard, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist", randomRangeOneorTwo);
		pGameState->CourseAccreditation(pCardsPlagiaristDrawn, pCourseAccreditationPlagiarist, pTablePiffle, pCounterPlagiarist->mRandomCard, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist");
		pGameState->FeedbackForum(pCardsPlagiaristDrawn, pFeedbackForumPlagiarist, pTablePiffle, pCounterPlagiarist->mRandomCard, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist", randomRangeOneorTwo, pTablePlagiarist);


		if (pPlagiarist->profPrestige <= 0 || pPiffle->profPrestige <= 0)
		{
			// Exit the loop when one of the players loses all their prestige
			break;
		}

		// Make cards duel
		// Create Plagiarist Player plagiarist gets attacked
		pGameState->CardsDuel(pTablePlagiarist, pTablePiffle, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", pCardsPiffleDrawn, pCounterPiffle->mRandomCard, pCounterPiffle->mResilienceIncrease);

		randomRangeOneorTwo = pCounterPiffle->RandomRange(1, 2); //?????????????????????????????????????????????????????????
		//Plagiarist Gets Attacked
		pGameState->PlagiarismHearing(pCardsPiffleDrawn, pPlagiarismHearingPiffle, pTablePlagiarist, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", randomRangeOneorTwo);
		pGameState->CourseAccreditation(pCardsPiffleDrawn, pCourseAccreditationPiffle, pTablePlagiarist, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper");
		pGameState->FeedbackForum(pCardsPiffleDrawn, pFeedbackForumPiffle, pTablePlagiarist, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", randomRangeOneorTwo, pTablePiffle);

		if (pPlagiarist->profPrestige <= 0 || pPiffle->profPrestige <= 0)
		{
			// Exit the loop when one of the players loses all their prestige
			break;
		}

	} while (pPlagiarist->profPrestige > 0 && pPiffle->profPrestige > 0);

	// Checks who is winner
	pGameState->GameOver(*pPiffle, *pPlagiarist);

	// Close files
	pCounterPlagiarist->mFile.close();
	pCounterPiffle->mFile.close();

	// Memory Leak Detection
	_CrtDumpMemoryLeaks();

	return 0;
}

const time_t ReadSeedFile(string filename)
{
	time_t seed_value = 0;

	// Read from the file
	ifstream file_stream(filename);
	if (file_stream.is_open())
	{
		string line;
		if (getline(file_stream, line))
		{
			seed_value = stoi(line);
		}
		file_stream.close();
	}
	else
	{
		cout << "Unable to open file " << filename << '\n';
	}

	return seed_value;
}
