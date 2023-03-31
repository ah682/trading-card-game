// Adam James Anthony Hall

// Memory Leak Detection
#define _CRTDBG_MAP_ALLOC

// Initialize necessary header files
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
#include "CResearchFunding.h"
#include "CMitigatingCircumstances.h"
#include "CIndustrialPlacement.h"
#include "CEasyTarget.h"
#include "CSerialOffender.h"
#include "CGraduateStudent.h"

// Tells the compiler to use the standard namespace
using namespace std;

int main()
{
	// Function declaration to read seed file
	time_t ReadSeedFile(string filename);

	// Define a type alias for a unique pointer to a CCounter object
	typedef unique_ptr<CCounter> pCCounterPtr;

	// Create a unique pointer to a CCounter object for Piffle
	auto pCounterPiffle = make_unique<CCounter>();

	// Create a unique pointer to a CCounter object for Plagiarist
	auto pCounterPlagiarist = make_unique<CCounter>();

	// Create a unique pointer to a CCounter object for Pointless
	auto pCounter = make_unique<CCounter>();

	// Create a unique pointer to a CCounter object for Perdition
	auto pCounterPerdition = make_unique<CCounter>();

	// Create a unique pointer to a CCounter object for Pointless
	auto pCounterPointless = make_unique<CCounter>();

	// Genereate seed from read file
	pCounterPiffle->mSeed = ReadSeedFile("seed.txt");
	// Generate random number from seed
	srand(pCounterPiffle->mSeed);
	// Prints out seed number of U-Can't the widowing
	cout << "Seed Number: " << pCounterPiffle->mSeed << endl;

	// Initialize data before commencing U-Can't
	auto pGameState = make_unique<CManager>();
	pGameState->GameStart();

	// Open texts files and assign the contents to mFile
	pCounterPlagiarist->mFile.open("plagiarist.txt");
	pCounterPiffle->mFile.open("piffle-paper.txt");
	pCounterPointless->mFile.open("pointless.txt");
	pCounterPerdition->mFile.open("perdition.txt");

	// Create a shared pointer to new SProfessor objects
	auto pPlagiarist = make_shared<CPlayers::SProfessor>();
	pPlagiarist->mProfName = "Plagiarist";
	auto pPiffle = make_shared<CPlayers::SProfessor>();
	pPiffle->mProfName = "Piffle-Paper";
	auto pPerdition = make_shared<CPlayers::SProfessor>();
	pPerdition->mProfName = "Perdition";
	auto pPointless = make_shared<CPlayers::SProfessor>();
	pPointless->mProfName = "Pointless";

	// Count the number of cards in the plagiarist file
	while (getline(pCounterPlagiarist->mFile, pCounterPiffle->mLine))
	{
		pCounterPlagiarist->mCardCounter++ + G_DECK_SIZE;
	}

	// Count the number of cards in the piffle file
	while (getline(pCounterPiffle->mFile, pCounterPlagiarist->mLine))
	{
		pCounterPiffle->mCardCounter++ + G_DECK_SIZE;
	}

	// Count the number of cards in the pointless file
	while (getline(pCounter->mFile, pCounter->mLine))
	{
		pCounter->mCardCounter++ + G_DECK_SIZE;
	}

	// Count the number of cards in the perdition file
	while (getline(pCounter->mFile, pCounter->mLine))
	{
		pCounter->mCardCounter++ + G_DECK_SIZE;
	}


	// Create a vector of shared pointers to CCard objects from pCounterPiffle's mCardCounter
	auto pCardsPiffle = vector<shared_ptr<CCard>>(pCounterPiffle->mCardCounter);

	// Iterate over each element in the vector using a for loop
	for (int i = 0; i < pCounterPiffle->mCardCounter; i++)
	{	// Use make_shared to create a new shared_ptr to a CCard object and assign it to the current element in the vector
		pCardsPiffle[i] = make_shared<CCard>();
	}

	// Create a vector of shared pointers to CCard objects from pCounterPlagiarist's mCardCounter
	auto pCardsPlagiarist = vector<shared_ptr<CCard>>(pCounterPlagiarist->mCardCounter);

	// Iterate over each element in the vector using a for loop
	for (int i = 0; i < pCounterPlagiarist->mCardCounter; i++)
	{	// Use make_shared to create a new shared_ptr to a CCard object and assign it to the current element in the vector
		pCardsPlagiarist[i] = make_shared<CCard>(); // Assign the shared_ptr to the vector element
	}

	// Create a vector of shared pointers to CStudent objects from pCounterPlagiarist's mCardCounter
	auto pCardsPlagiaristStudents = vector<shared_ptr<CStudent>>(pCounterPlagiarist->mCardCounter);

	// Iterate over each element in the vector using a for loop
	for (int i = 0; i < pCounterPlagiarist->mCardCounter; i++)
	{
		// Use make_shared to create a new shared_ptr to a CStudent object and assign it to the current element in the vector
		pCardsPlagiaristStudents[i] = make_shared<CStudent>(); // Assign the shared_ptr to the vector element
	}

	// Create a vector of shared pointers to CStudent objects from pCounterPiffle's mCardCounter
	auto pCardsPiffleStudents = vector<shared_ptr<CStudent>>(pCounterPiffle->mCardCounter);

	// Iterate over each element in the vector using a for loop
	for (int i = 0; i < pCounterPiffle->mCardCounter; i++)
	{
		// Use make_shared to create a new shared_ptr to a CStudent object and assign it to the current element in the vector
		pCardsPiffleStudents[i] = make_shared<CStudent>(); // Assign the shared_ptr to the vector element
	}

	// Define a new type alias named cardsDrawn for a vector of shared pointers to CCard objects
	typedef vector <shared_ptr<CCard>> cardsDrawn;
	// Create two new variables of type cardsDrawn and initialize them with empty vectors
	auto pCardsPlagiaristDrawn = cardsDrawn{};
	auto pCardsPiffleDrawn = cardsDrawn{};

	// Define a new type alias named cardsStudentDrawn for a vector of shared pointers to CStudent objects
	typedef vector <shared_ptr<CStudent>> cardsStudentDrawn;
	// Create two new variables of type cardsStudentDrawn and initialize them with empty vectors
	auto pCardsPlagiaristStudentsDrawn = cardsStudentDrawn{};
	auto pCardsPiffleStudentsDrawn = cardsStudentDrawn{};

	// Define a new type alias named Table for a vector of shared pointers to CTable objects
	typedef vector <shared_ptr<CTable>> Table;
	// Create two new variables of type Table and initialize them with empty vectors
	auto pTablePlagiarist = Table{};
	auto pTablePiffle = Table{};

	// Define a type alias for a vector of shared pointers to CPlagiarismHearing objects
	typedef vector <shared_ptr<CPlagiarismHearing>> DrawPlagiarismHearingCards;
	// Create an instance of DrawPlagiarismHearingCards named pDrawPlagiarismHearingCardsPlagiarist
	auto pDrawPlagiarismHearingCardPlagiarist = DrawPlagiarismHearingCards{};
	// Create an instance of DrawPlagiarismHearingCardS named pDrawPlagiarismHearingCardsPiffle
	auto pDrawPlagiarismHearingCardPiffle = DrawPlagiarismHearingCards{};

	// Define a type alias for a vector of shared pointers to CCourseAccreditation objects
	typedef vector <shared_ptr<CCourseAccreditation>> DrawCourseAccreditationCards;
	// Create an instance of DrawCourseAccreditationCards named pDrawCourseAccreditationCardPlagiarist
	auto pDrawCourseAccreditationCardPlagiarist = DrawCourseAccreditationCards{};
	// Create an instance of DrawCourseAccreditationCards named pDrawCourseAccreditationCardPiffle
	auto pDrawCourseAccreditationCardPiffle = DrawCourseAccreditationCards{};

	// Define a type alias for a vector of shared pointers to CFeedbackForum objects
	typedef vector <shared_ptr<CFeedbackForum>> feedbackForumCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pFeedbackForumPlagiarist = feedbackForumCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pFeedbackForumPiffle = feedbackForumCards{};

	// Define a type alias for a vector of shared pointers to CFeedbackForum objects
	typedef vector <shared_ptr<CPassLeader>> passLeaderCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pPassLeaderPlagiarist = passLeaderCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pPassLeaderPiffle = passLeaderCards{};

	// Define a type alias for a vector of shared pointers to CResearchFunding objects
	typedef vector <shared_ptr<CResearchFunding>> researchFundingCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pResearchFundingPlagiarist = researchFundingCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pResearchFundingPiffle = researchFundingCards{};

	//	Define  a type alias for a vector of shared pointers to CMitigatingCircumstances objects
	typedef vector <shared_ptr<CMitigatingCircumstances>> mitigatingCircumstancesCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pMitigatingCircumstancesPlagiarist = mitigatingCircumstancesCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pMitigatingCircumstancesPiffle = mitigatingCircumstancesCards{};

	// Define a type for a shared pointer to a CStudent object
	typedef  shared_ptr<CMitigatingCircumstances> studentCard;
	// Create an instance of studentCard named pStudentPlagiaristTest
	auto pStudentPlagiaristTest = studentCard{};
	// Create an instance of studentCard named pStudentPiffleTest
	auto pStudentPiffleTest = studentCard{};

	//	Define  a type alias for a vector of shared pointers to CEasyTarget objects
	typedef vector <shared_ptr<CEasyTarget>> easyTargetCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pEasyTargetPlagiarist = easyTargetCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pEasyTargetPiffle = easyTargetCards{};

	//	Define  a type alias for a vector of shared pointers to CSerialOffender objects
	typedef vector <shared_ptr<CSerialOffender>> serialOffenderCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pSerialOffenderPlagiarist = serialOffenderCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pSerialOffenderPiffle = serialOffenderCards{};

	//	Define  a type alias for a vector of shared pointers to CGraduateStudent objects
	typedef vector <shared_ptr<CGraduateStudent>> graduateStudentCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pGraduateStudentPlagiarist = graduateStudentCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pGraduateStudentPiffle = graduateStudentCards{};

	//	Define  a type alias for a vector of shared pointers to CIndustrialPlacement objects
	typedef vector <shared_ptr<CIndustrialPlacement>> industrialPlacementCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pIndustrialPlacementPlagiarist = industrialPlacementCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pIndustrialPlacementPiffle = industrialPlacementCards{};

	// Call the FillDeck method of the pGameState object with arguments pCounterPlagiarist->mFile, pCardsPlagiarist and pCardsPlagiaristStudents
	pGameState->FillDeck(pCounterPlagiarist->mFile, pCardsPlagiarist, pCardsPlagiaristStudents);
	// Call the FillDeck method of the pGameState object with arguments pCounterPiffle->mFile, pCardsPlagiarist and pCardsPiffleStudents
	pGameState->FillDeck(pCounterPiffle->mFile, pCardsPiffle, pCardsPiffleStudents);


	// Define a type alias for a vector of shared pointers to bools
	typedef vector<shared_ptr<bool>> checkUsedCard;

	// Create a checkUsedCard object for Plagiarist with size DECK_SIZE
	auto pCheckUsedCardPlagiarist = checkUsedCard(G_DECK_SIZE);

	// Initialize all elements of pCheckUsedCardPlagiarist to unique pointers to false
	for (int i = 0; i < G_DECK_SIZE; i++)
	{
		pCheckUsedCardPlagiarist[i] = make_unique<bool>(false);
	}

	// Create a checkUsedCard object for Piffle with size DECK_SIZE
	auto pCheckUsedCardPiffle = checkUsedCard(G_DECK_SIZE);

	// Initialize all elements of pCheckUsedCardPiffle to unique pointers to false
	for (int i = 0; i < G_DECK_SIZE; i++)
	{
		pCheckUsedCardPiffle[i] = make_unique<bool>(false);
	}

	// Do while loop which continues until pPlagiarist->profPrestige > 0 and pPiffle->profPrestige > 0;
	do
	{
		pGameState->StartRound(pGameState->mRoundCounter);

		// Draws random card for plagiarist and prints cards if pCounterPlagiarist->i < DECK_SIZE
		if (pCounterPlagiarist->mI < G_DECK_SIZE)
		{
			// Draw card function draws two cards for Plagiarist
			pGameState->DrawCard(pCardsPlagiarist, pCardsPlagiaristDrawn, pCounterPlagiarist->mDeckCounter, pCounterPlagiarist->mI, *pPlagiarist, pCheckUsedCardPlagiarist);

			//	Draw card function draws two cards for Piffle
			pGameState->DrawCard(pCardsPiffle, pCardsPiffleDrawn, pCounterPiffle->mDeckCounter, pCounterPiffle->mI, *pPiffle, pCheckUsedCardPiffle);

			// Piffle Chooses a random card from the two cards DrawCard function have selected
			pCounterPiffle->mRandomCard = pCounterPiffle->Random(pCardsPiffleDrawn.size() - 2, pCardsPiffleDrawn.size() - 1);
			// Prints out chosen card for Piffle-Paper
			cout << "Piffle-Paper chooses card: " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mType << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mFirstname << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mLastname << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mPower << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mResilience << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mBoost << endl;

			// Plagiarist Chooses a random card from the two cards DrawCard function have selected
			pCounterPlagiarist->mRandomCard = pCounterPlagiarist->Random(pCardsPlagiaristDrawn.size() - 2, pCardsPlagiaristDrawn.size() - 1);
			// Prints out chosen card for Plagiarist
			cout << "Plagiarist chooses: " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mType << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mFirstname << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mLastname << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mPower << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mResilience << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mBoost << endl;
		}

		//PrintTable function prints current cards on table for each player
		pGameState->PrintTable(pTablePiffle, pCardsPiffleDrawn, *pPiffle, "Piffle-Paper", pCounterPiffle->mRandomCard);
		pGameState->PrintTable(pTablePlagiarist, pCardsPlagiaristDrawn, *pPlagiarist, "Plagiarist", pCounterPlagiarist->mRandomCard);

		// Use type 1 cards (Student Cards), Piffle gets attacked
		pGameState->UseStudentCard(pTablePiffle, pTablePlagiarist, *pPiffle, *pPlagiarist, "name?", "name?", pCardsPlagiaristDrawn, pCardsPlagiaristStudentsDrawn, pCounterPlagiarist->mRandomCard, pEasyTargetPiffle);

		// Initialize random range between one or two to choose truly random card
		int randomRangeOneorTwo = pCounterPlagiarist->Random(1, 2);

		// Use type x cards (Plagiarism Hearing Cards), Piffle gets attacked
		pGameState->UsePlagiarismHearingCard(pCardsPlagiaristDrawn, pDrawPlagiarismHearingCardPlagiarist, pTablePiffle, pCounterPlagiarist->mRandomCard, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist", randomRangeOneorTwo, pEasyTargetPiffle);
		// Use type x cards (Course Accreditation Cards), Piffle gets attacked
		pGameState->UseCourseAccreditationCard(pCardsPlagiaristDrawn, pDrawCourseAccreditationCardPlagiarist, pTablePiffle, pCounterPlagiarist->mRandomCard, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist", pEasyTargetPiffle);
		// Use type x cards (Feedback Forum Cards), Piffle gets attacked or Plagiarist gets healed
		pGameState->UseFeedbackForumCard(pCardsPlagiaristDrawn, pFeedbackForumPlagiarist, pTablePiffle, pCounterPlagiarist->mRandomCard, *pPiffle, *pPlagiarist, "Piffle-Paper", "Plagiarist", randomRangeOneorTwo, pTablePlagiarist, pEasyTargetPiffle);
		// Use type x cards (Industrial Placement Cards), Piffle gets attacked
		pGameState->UseIndustrialPlacementCard(pCardsPlagiaristDrawn, pIndustrialPlacementPlagiarist, pCounterPlagiarist->mRandomCard, *pPiffle, *pPlagiarist, "attackerName", pTablePlagiarist, pTablePiffle, pEasyTargetPiffle);
		// Use type x cards (Pass Leader Cards), Plagiarist type 6 deck gets increased attack power
		pGameState->UsePassLeaderCard(pCardsPlagiaristDrawn, pPassLeaderPlagiarist, pCounterPlagiarist->mRandomCard, *pPlagiarist, *pPlagiarist, "Plagiarist", pTablePlagiarist);
		// Use type x cards (ResearchFunding Cards), Piffle type 6 deck gets increased attack power
		pGameState->UseResearchFundingCard(pCardsPlagiaristDrawn, pResearchFundingPlagiarist, pCounterPlagiarist->mRandomCard, *pPlagiarist, "Plagiarist", pTablePlagiarist);
		// Use type x cards(MitigatingCircumstances Cards), Piffle type 6 deck gets increased attack power
		pGameState->UseMitigatingCircumstancesCard(pCardsPlagiarist, pStudentPlagiaristTest, pTablePlagiarist, pMitigatingCircumstancesPlagiarist, pCounterPlagiarist->mRandomCard);
		// Use type x cards(EasyTarget Cards), Piffle type 6 deck gets increased attack power
		pGameState->UseEasyTargetCard(pCardsPlagiarist, pEasyTargetPlagiarist, pCounterPlagiarist->mRandomCard, *pPlagiarist, "Plagiarist", pTablePlagiarist);
		// Use type x cards(Serial Offender Cards), Piffle type 6 deck gets increased attack power
		pGameState->UseSerialOffenderCard(pTablePiffle, pTablePlagiarist, *pPiffle, *pPlagiarist, "name?", "name?", pCardsPlagiaristDrawn, pSerialOffenderPlagiarist, pCounterPlagiarist->mRandomCard, pEasyTargetPiffle);
		// Use type 1 cards(Graduate Student Cards), Piffle gets attacked
		pGameState->UseGraduateStudentCard(pTablePiffle, pTablePlagiarist, *pPiffle, *pPlagiarist, "name?", "name?", pCardsPlagiaristDrawn, pGraduateStudentPlagiarist, pCounterPlagiarist->mRandomCard, pEasyTargetPiffle);

		// Exits the do while loop when one of the players loses all their prestige
		if (pPlagiarist->mProfPrestige <= 0 || pPiffle->mProfPrestige <= 0)
		{
			// Exit the do while loop when one of the players loses all their prestige
			break;
		}

		// Use type 1 cards (Student Cards), Plagiarist gets attacked
		pGameState->UseStudentCard(pTablePlagiarist, pTablePiffle, *pPlagiarist, *pPiffle, "name?", "name?", pCardsPiffleDrawn, pCardsPiffleStudentsDrawn, pCounterPiffle->mRandomCard, pEasyTargetPlagiarist);

		// Initialize random range between one or two to choose truly random card
		randomRangeOneorTwo = pCounterPiffle->Random(1, 2);

		// Use type x cards (Plagiarism Hearing Cards), Plagiarist gets attacked
		pGameState->UsePlagiarismHearingCard(pCardsPiffleDrawn, pDrawPlagiarismHearingCardPiffle, pTablePlagiarist, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", randomRangeOneorTwo, pEasyTargetPlagiarist);
		// Use type x cards (Course Accreditation Cards), Plagiarist gets attacked
		pGameState->UseCourseAccreditationCard(pCardsPiffleDrawn, pDrawCourseAccreditationCardPiffle, pTablePlagiarist, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", pEasyTargetPlagiarist);
		// Use type x cards (Feedback Forum Cards), Plagiarist gets attacked or Piffle gets healed
		pGameState->UseFeedbackForumCard(pCardsPiffleDrawn, pFeedbackForumPiffle, pTablePlagiarist, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", randomRangeOneorTwo, pTablePiffle, pEasyTargetPlagiarist);
		// Use type x cards (Feedback Forum Cards), Plagiarist gets attacked or Piffle gets healed
		pGameState->UseIndustrialPlacementCard(pCardsPiffleDrawn, pIndustrialPlacementPiffle, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "attackerName", pTablePiffle, pTablePlagiarist, pEasyTargetPlagiarist);
		// Use type x cards (Pass Leader Cards), Piffle type 6 deck gets increased attack power
		pGameState->UsePassLeaderCard(pCardsPiffleDrawn, pPassLeaderPiffle, pCounterPiffle->mRandomCard, *pPiffle, *pPiffle, "Piffle-Paper", pTablePiffle);
		// Use type x cards (Research Funding Cards), Piffle type 6 deck gets increased attack power
		pGameState->UseResearchFundingCard(pCardsPiffleDrawn, pResearchFundingPiffle, pCounterPiffle->mRandomCard, *pPiffle, "Piffle-Paper", pTablePiffle);
		// Use type x cards(Mitigiating Circumstances Cards), Piffle type 6 deck gets increased attack power
		pGameState->UseMitigatingCircumstancesCard(pCardsPiffle, pStudentPiffleTest, pTablePiffle, pMitigatingCircumstancesPiffle, pCounterPiffle->mRandomCard);
		// Use type x cards(Easy Target Cards), Piffle type 6 deck gets increased attack power
		pGameState->UseEasyTargetCard(pCardsPiffle, pEasyTargetPiffle, pCounterPiffle->mRandomCard, *pPiffle, "Piffle-Paper", pTablePiffle);
		// Use type 1 cards (Student Cards), Plagiarist gets attacked
		pGameState->UseSerialOffenderCard(pTablePlagiarist, pTablePiffle, *pPlagiarist, *pPiffle, "name?", "name?", pCardsPiffleDrawn, pSerialOffenderPiffle, pCounterPiffle->mRandomCard, pEasyTargetPlagiarist);
		// Use type 1 cards (Graduate Student Cards), Plagiarist gets attacked
		pGameState->UseGraduateStudentCard(pTablePlagiarist, pTablePiffle, *pPlagiarist, *pPiffle, "name?", "name?", pCardsPiffleDrawn, pGraduateStudentPiffle, pCounterPiffle->mRandomCard, pEasyTargetPlagiarist);

		// Exits the do while loop when one of the players loses all their prestige
		if (pPlagiarist->mProfPrestige <= 0 || pPiffle->mProfPrestige <= 0)
		{
			// Exit the loop when one of the players loses all their prestige
			break;
		}



	} while (pPlagiarist->mProfPrestige > 0 && pPiffle->mProfPrestige > 0);

	// GameOver function checks which player has won
	pGameState->GameOver(*pPiffle, *pPlagiarist);

	// Memory Leak Detection
	_CrtDumpMemoryLeaks();

	// Return statement which returns 0 to finish executing code
	return 0;

}

// Function definition to read seed file
time_t ReadSeedFile(string filename)
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
	// Returns time_t statement of seed value read from file
	return seed_value;
}
