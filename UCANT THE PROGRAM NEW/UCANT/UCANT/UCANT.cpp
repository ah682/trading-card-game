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
	auto pCounter = make_unique<CCounter>();

	// Genereates seed from read file
	pCounter->mSeed = ReadSeedFile("seed.txt");
	srand(pCounter->mSeed);
	cout << "Seed Number: " << pCounter->mSeed << endl;

	// Initialize data before commencing U-Can't

	CManager message;
	message.gameStart();

	const int DECK_SIZE = 48;

	pCounter->mFilePlagiarist.open("plagiarist.txt");
	pCounter->mFilePiffle.open("piffle-paper.txt");
	//Counter->filePlagiarist.open("pointless.txt");
   // Counter->filePiffle.open("perdition.txt");

	auto pPlagiarist = make_shared<CPlayers::SProfessor>();
	auto pPiffle = make_shared<CPlayers::SProfessor>();
	auto pPerdition = make_shared<CPlayers::SProfessor>();
	auto pPointless = make_shared<CPlayers::SProfessor>();

	// Count the number of cards in the plagiarist file
	while (getline(pCounter->mFilePlagiarist, pCounter->mLinePlagiarist))
	{
		pCounter->mNum_cardsPlagiarist++ + DECK_SIZE;
	}

	// Count the number of cards in the piffle file
	while (getline(pCounter->mFilePiffle, pCounter->mLinePiffle))
	{
		pCounter->mNum_cardsPiffle++ + DECK_SIZE;
	}


	// Allocate memory for the cards
	auto pCardsPiffle = vector<shared_ptr<CCard>>(pCounter->mNum_cardsPiffle);

	for (int i = 0; i < pCounter->mNum_cardsPiffle; i++)
	{
		pCardsPiffle[i] = make_shared<CCard>(); // Assign the shared_ptr to the vector element
	}

	// Allocate memory for the cards
	auto pCardsPlagiarist = vector<shared_ptr<CCard>>(pCounter->mNum_cardsPlagiarist);

	for (int i = 0; i < pCounter->mNum_cardsPlagiarist; i++)
	{
		pCardsPlagiarist[i] = make_shared<CCard>(); // Assign the shared_ptr to the vector element
	}

	// Allocate memory for the cards
	auto pCardsPlagiaristStudents = vector<shared_ptr<CStudent>>(pCounter->mNum_cardsPlagiarist);

	for (int i = 0; i < pCounter->mNum_cardsPlagiarist; i++)
	{
		pCardsPlagiaristStudents[i] = make_shared<CStudent>(); // Assign the shared_ptr to the vector element
	}

	// Allocate memory for the cards
	auto pCardsPiffleStudents = vector<shared_ptr<CStudent>>(pCounter->mNum_cardsPiffle);

	for (int i = 0; i < pCounter->mNum_cardsPiffle; i++)
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

	message.fillDeck(pCounter->mFilePlagiarist, pCardsPlagiarist, pCardsPlagiaristStudents);
	message.fillDeck(pCounter->mFilePiffle, pCardsPiffle, pCardsPiffleStudents);


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
		if (pCounter->i < DECK_SIZE)
		{
			cout << "Drawn Cards from Plagiarist:" << endl;
			message.drawCard(pCardsPlagiarist, pCardsPlagiaristDrawn, pCounter->mDeckCounter, pCounter->i, *pPlagiarist, pCheckUsedCardPlagiarist);

			cout << "Drawn Cards from Piffle-Paper:" << endl;
			message.drawCard(pCardsPiffle, pCardsPiffleDrawn, pCounter->mDeckCounter, pCounter->i, *pPiffle, pCheckUsedCardPiffle);


			// Piffle Chooses a card card THIS IS SUPPOSE TO BE RANDOM
			pCounter->mRandomCardPiffle = pCounter->randomRange(pCardsPiffleDrawn.size() - 2, pCardsPiffleDrawn.size() - 1);

			cout << "Piffle-Papaer chooses card: " << pCardsPiffleDrawn[pCounter->mRandomCardPiffle]->mType << " " << pCardsPiffleDrawn[pCounter->mRandomCardPiffle]->mFirstname << " " << pCardsPiffleDrawn[pCounter->mRandomCardPiffle]->mLastname << " " << pCardsPiffleDrawn[pCounter->mRandomCardPiffle]->mPower << " " << pCardsPiffleDrawn[pCounter->mRandomCardPiffle]->mResilience << " " << pCardsPiffleDrawn[pCounter->mRandomCardPiffle]->mBoost << endl;
			// Plagiarist Chooses a card card THIS IS SUPPOSE TO BE RANDOM
			pCounter->mRandomCardPlagiarist = pCounter->randomRange(pCardsPlagiaristDrawn.size() - 2, pCardsPlagiaristDrawn.size() - 1);
			cout << "Plagiarist chooses: " << pCardsPlagiaristDrawn[pCounter->mRandomCardPlagiarist]->mType << " " << pCardsPlagiaristDrawn[pCounter->mRandomCardPlagiarist]->mFirstname << " " << pCardsPlagiaristDrawn[pCounter->mRandomCardPlagiarist]->mLastname << " " << pCardsPlagiaristDrawn[pCounter->mRandomCardPlagiarist]->mPower << " " << pCardsPlagiaristDrawn[pCounter->mRandomCardPlagiarist]->mResilience << " " << pCardsPlagiaristDrawn[pCounter->mRandomCardPlagiarist]->mBoost << endl;
		}

		//Prints table on cards for specific player
		message.tableCard(pTablePiffle, pCardsPiffleDrawn, *pPiffle, "Piffle-Paper", pCounter->mRandomCardPiffle);
		message.tableCard(pTablePlagiarist, pCardsPlagiaristDrawn, *pPlagiarist, "Plagiarist", pCounter->mRandomCardPlagiarist);

		// Make cards duel
		// Create Piffle Player piffle gets attacked
		message.cardsDuel(pTablePiffle, pTablePlagiarist, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist", pCardsPlagiaristDrawn, pCounter->mRandomCardPlagiarist, pCounter->mResilienceIncreasePlagiarist);


		int randomRangeOneorTwo = pCounter->randomRange(1, 2);
		//Piffle Gets Attacked
		message.plagiarismHearing(pCardsPlagiaristDrawn, pPlagiarismHearingPlagiarist, pTablePiffle, pCounter->mRandomCardPlagiarist, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist", randomRangeOneorTwo);
		message.courseAccreditation(pCardsPlagiaristDrawn, pCourseAccreditationPlagiarist, pTablePiffle, pCounter->mRandomCardPlagiarist, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist");
		message.feedbackForum(pCardsPlagiaristDrawn, pFeedbackForumPlagiarist, pTablePiffle, pCounter->mRandomCardPlagiarist, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist", randomRangeOneorTwo, pTablePlagiarist);


		if (pPlagiarist->profPrestige <= 0 || pPiffle->profPrestige <= 0)
		{
			// Exit the loop when one of the players loses all their prestige
			break;
		}

		// Make cards duel
		// Create Plagiarist Player plagiarist gets attacked
		message.cardsDuel(pTablePlagiarist, pTablePiffle, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", pCardsPiffleDrawn, pCounter->mRandomCardPiffle, pCounter->mResilienceIncreasePiffle);

		randomRangeOneorTwo = pCounter->randomRange(1, 2);
		//Plagiarist Gets Attacked
		message.plagiarismHearing(pCardsPiffleDrawn, pPlagiarismHearingPiffle, pTablePlagiarist, pCounter->mRandomCardPiffle, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", randomRangeOneorTwo);
		message.courseAccreditation(pCardsPiffleDrawn, pCourseAccreditationPiffle, pTablePlagiarist, pCounter->mRandomCardPiffle, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper");
		message.feedbackForum(pCardsPiffleDrawn, pFeedbackForumPiffle, pTablePlagiarist, pCounter->mRandomCardPiffle, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", randomRangeOneorTwo, pTablePiffle);

		if (pPlagiarist->profPrestige <= 0 || pPiffle->profPrestige <= 0)
		{
			// Exit the loop when one of the players loses all their prestige
			break;
		}

	} while (pPlagiarist->profPrestige > 0 && pPiffle->profPrestige > 0);

	// Checks who is winner
	message.gameOver(*pPiffle, *pPlagiarist);

	// Close files
	pCounter->mFilePlagiarist.close();
	pCounter->mFilePiffle.close();

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
