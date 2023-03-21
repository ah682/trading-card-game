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

const time_t readSeedFile(string filename);


int main()
{
	typedef shared_ptr<CCounter> CCounterPtr;
	auto Counter = make_unique<CCounter>();

	// Genereates seed from read file
	Counter->seed = readSeedFile("seed.txt");
	srand(Counter->seed);
	cout << "Seed Number: " << Counter->seed << endl;

	// Initialize data before commencing U-Can't

	CManager message;
	message.gameStart();

	const int deckSize = 48;

	Counter->filePlagiarist.open("plagiarist.txt");
	Counter->filePiffle.open("piffle-paper.txt");
	//Counter->filePlagiarist.open("pointless.txt");
   // Counter->filePiffle.open("perdition.txt");

	auto pPlagiarist = make_shared<CPlayers::SProfessor>();
	auto pPiffle = make_shared<CPlayers::SProfessor>();
	auto pPerdition = make_shared<CPlayers::SProfessor>();
	auto pPointless = make_shared<CPlayers::SProfessor>();

	// Count the number of cards in the plagiarist file
	while (getline(Counter->filePlagiarist, Counter->linePlagiarist))
	{
		Counter->num_cardsPlagiarist++ + deckSize;
	}

	// Count the number of cards in the piffle file
	while (getline(Counter->filePiffle, Counter->linePiffle))
	{
		Counter->num_cardsPiffle++ + deckSize;
	}


	// Allocate memory for the cards
	auto pCardsPiffle = vector<shared_ptr<CCard>>(Counter->num_cardsPiffle);

	for (int i = 0; i < Counter->num_cardsPiffle; i++)
	{
		pCardsPiffle[i] = make_shared<CCard>(); // Assign the shared_ptr to the vector element
	}

	// Allocate memory for the cards
	auto pCardsPlagiarist = vector<shared_ptr<CCard>>(Counter->num_cardsPlagiarist);

	for (int i = 0; i < Counter->num_cardsPlagiarist; i++)
	{
		pCardsPlagiarist[i] = make_shared<CCard>(); // Assign the shared_ptr to the vector element
	}

	// Allocate memory for the cards
	auto pCardsPlagiaristStudents = vector<shared_ptr<CStudent>>(Counter->num_cardsPlagiarist);

	for (int i = 0; i < Counter->num_cardsPlagiarist; i++)
	{
		pCardsPlagiaristStudents[i] = make_shared<CStudent>(); // Assign the shared_ptr to the vector element
	}

	// Allocate memory for the cards
	auto pCardsPiffleStudents = vector<shared_ptr<CStudent>>(Counter->num_cardsPiffle);

	for (int i = 0; i < Counter->num_cardsPiffle; i++)
	{
		pCardsPiffleStudents[i] = make_shared<CStudent>(); // Assign the shared_ptr to the vector element
	}

	// Allocate memory for the cards
	typedef vector <shared_ptr<CCard>> cardsDrawn;
	auto cardsPlagiaristDrawn = cardsDrawn{};
	auto cardsPiffleDrawn = cardsDrawn{};

	typedef vector <shared_ptr<CStudent>> cardsStudentDrawn;
	auto cardsPlagiaristStudentsDrawn = cardsStudentDrawn{};
	auto cardsPiffleStudentsDrawn = cardsStudentDrawn{};

	typedef vector <shared_ptr<CTable>> Table;
	auto tablePlagiarist = Table{};
	auto tablePiffle = Table{};

	typedef vector <shared_ptr<CPlagiarismHearing>> plagiarismHearingCards;
	auto plagiarismHearingPlagiarist = plagiarismHearingCards{};
	auto plagiarismHearingPiffle = plagiarismHearingCards{};

	typedef vector <shared_ptr<CCourseAccreditation>> courseAccreditationCards;
	auto courseAccreditationPlagiarist = courseAccreditationCards{};
	auto courseAccreditationPiffle = courseAccreditationCards{};

	typedef vector <shared_ptr<CFeedbackForum>> feedbackForumCards;
	auto feedbackForumPlagiarist = feedbackForumCards{};
	auto feedbackForumPiffle = feedbackForumCards{};

	message.fillDeck(Counter->filePlagiarist, cardsPlagiarist, cardsPlagiaristStudents);
	message.fillDeck(Counter->filePiffle, pcardsPiffle, cardsPiffleStudents);


	// Allocate
	typedef vector<shared_ptr<bool>> checkUsedCard;

	auto checkUsedCardPlagiarist = checkUsedCard(deckSize);

	for (int i = 0; i < deckSize; i++)
	{
		checkUsedCardPlagiarist[i] = make_unique<bool>(false);
	}

	auto checkUsedCardPiffle = checkUsedCard(deckSize);

	for (int i = 0; i < deckSize; i++)
	{
		checkUsedCardPiffle[i] = make_unique<bool>(false);
	}

	// MAKE LOOP UNTIL PRESTIGE HITS 0
	do
	{
		// Allocate memory for the cards

		// Draws random card for plagiarist and checks if works with cout
		if (Counter->i < deckSize)
		{
			cout << "Drawn Cards from Plagiarist:" << endl;
			message.drawCard(cardsPlagiarist, cardsPlagiaristDrawn, Counter->deckCounter, Counter->i, *pPlagiarist, checkUsedCardPlagiarist);

			cout << "Drawn Cards from Piffle-Paper:" << endl;
			message.drawCard(pcardsPiffle, cardsPiffleDrawn, Counter->deckCounter, Counter->i, *pPiffle, checkUsedCardPiffle);


			// Piffle Chooses a card card THIS IS SUPPOSE TO BE RANDOM
			Counter->randomCardPiffle = Counter->randomRange(cardsPiffleDrawn.size() - 2, cardsPiffleDrawn.size() - 1);

			cout << "Piffle-Papaer chooses card: " << cardsPiffleDrawn[Counter->randomCardPiffle]->type << " " << cardsPiffleDrawn[Counter->randomCardPiffle]->firstname << " " << cardsPiffleDrawn[Counter->randomCardPiffle]->lastname << " " << cardsPiffleDrawn[Counter->randomCardPiffle]->power << " " << cardsPiffleDrawn[Counter->randomCardPiffle]->resilience << " " << cardsPiffleDrawn[Counter->randomCardPiffle]->boost << endl;
			// Plagiarist Chooses a card card THIS IS SUPPOSE TO BE RANDOM
			Counter->randomCardPlagiarist = Counter->randomRange(cardsPlagiaristDrawn.size() - 2, cardsPlagiaristDrawn.size() - 1);
			cout << "Plagiarist chooses: " << cardsPlagiaristDrawn[Counter->randomCardPlagiarist]->type << " " << cardsPlagiaristDrawn[Counter->randomCardPlagiarist]->firstname << " " << cardsPlagiaristDrawn[Counter->randomCardPlagiarist]->lastname << " " << cardsPlagiaristDrawn[Counter->randomCardPlagiarist]->power << " " << cardsPlagiaristDrawn[Counter->randomCardPlagiarist]->resilience << " " << cardsPlagiaristDrawn[Counter->randomCardPlagiarist]->boost << endl;
		}

		//Prints table on cards for specific player
		message.tableCard(tablePiffle, cardsPiffleDrawn, *pPiffle, "Piffle-Paper", Counter->randomCardPiffle);
		message.tableCard(tablePlagiarist, cardsPlagiaristDrawn, *pPlagiarist, "Plagiarist", Counter->randomCardPlagiarist);

		// Make cards duel
		// Create Piffle Player piffle gets attacked
		message.cardsDuel(tablePiffle, tablePlagiarist, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist", cardsPlagiaristDrawn, Counter->randomCardPlagiarist, Counter->resilienceIncreasePlagiarist);


		int randomRangeOneorTwo = Counter->randomRange(1, 2);
		//Piffle Gets Attacked
		message.plagiarismHearing(cardsPlagiaristDrawn, plagiarismHearingPlagiarist, tablePiffle, Counter->randomCardPlagiarist, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist", randomRangeOneorTwo);
		message.courseAccreditation(cardsPlagiaristDrawn, courseAccreditationPlagiarist, tablePiffle, Counter->randomCardPlagiarist, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist");
		message.feedbackForum(cardsPlagiaristDrawn, feedbackForumPlagiarist, tablePiffle, Counter->randomCardPlagiarist, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist", randomRangeOneorTwo, tablePlagiarist);


		if (pPlagiarist->profPrestige <= 0 || pPiffle->profPrestige <= 0)
		{
			// Exit the loop when one of the players loses all their prestige
			break;
		}

		// Make cards duel
		// Create Plagiarist Player plagiarist gets attacked
		message.cardsDuel(tablePlagiarist, tablePiffle, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", cardsPiffleDrawn, Counter->randomCardPiffle, Counter->resilienceIncreasePiffle);

		randomRangeOneorTwo = Counter->randomRange(1, 2);
		//Plagiarist Gets Attacked
		message.plagiarismHearing(cardsPiffleDrawn, plagiarismHearingPiffle, tablePlagiarist, Counter->randomCardPiffle, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", randomRangeOneorTwo);
		message.courseAccreditation(cardsPiffleDrawn, courseAccreditationPiffle, tablePlagiarist, Counter->randomCardPiffle, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper");
		message.feedbackForum(cardsPiffleDrawn, feedbackForumPiffle, tablePlagiarist, Counter->randomCardPiffle, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", randomRangeOneorTwo, tablePiffle);

		if (pPlagiarist->profPrestige <= 0 || pPiffle->profPrestige <= 0)
		{
			// Exit the loop when one of the players loses all their prestige
			break;
		}

	} while (pPlagiarist->profPrestige > 0 && pPiffle->profPrestige > 0);

	// Checks who is winner
	message.gameOver(*pPiffle, *pPlagiarist);

	// Close files
	Counter->filePlagiarist.close();
	Counter->filePiffle.close();

	// De-allocate memory

	// Memory Leak Detection
	_CrtDumpMemoryLeaks();

	return 0;
}

const time_t readSeedFile(string filename)
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
