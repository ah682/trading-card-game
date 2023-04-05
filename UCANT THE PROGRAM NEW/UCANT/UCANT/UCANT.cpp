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

	// Create a unique pointer to a CCounter object
	auto pCounter = make_unique<CCounter>();

	// Create a unique pointer to a CCounter object for Perdition
	auto pCounterPerdition = make_unique<CCounter>();

	// Create a unique pointer to a CCounter object for Pointless
	auto pCounterPointless = make_unique<CCounter>();

	// Genereate seed from read file
	pCounter->mSeed = ReadSeedFile("seed.txt");
	// Generate random number from seed
	srand(pCounter->mSeed);
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
	while (getline(pCounterPlagiarist->mFile, pCounterPlagiarist->mLine))
	{
		pCounterPlagiarist->mCardCounter++ + G_DECK_SIZE;
	}

	// Count the number of cards in the piffle file
	while (getline(pCounterPiffle->mFile, pCounterPiffle->mLine))
	{
		pCounterPiffle->mCardCounter++ + G_DECK_SIZE;
	}

	// Count the number of cards in the pointless file
	while (getline(pCounterPointless->mFile, pCounterPointless->mLine))
	{
		pCounterPointless->mCardCounter++ + G_DECK_SIZE;
	}

	// Count the number of cards in the perdition file
	while (getline(pCounterPerdition->mFile, pCounterPerdition->mLine))
	{
		pCounterPerdition->mCardCounter++ + G_DECK_SIZE;
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

	//Create a vector of shared pointers to CCard objects from pCounterPointless's mCardCounter
	auto pCardsPointless = vector<shared_ptr<CCard>>(pCounterPointless->mCardCounter);

	// Iterate over each element in the vector using a for loop
	for (int i = 0; i < pCounterPointless->mCardCounter; i++)
	{	// Use make_shared to create a new shared_ptr to a CCard object and assign it to the current element in the vector
		pCardsPointless[i] = make_shared<CCard>(); // Assign the shared_ptr to the vector element
	}

	//Create a vector of shared pointers to CCard objects from pCounterPerdition's mCardCounter
	auto pCardsPerdition = vector<shared_ptr<CCard>>(pCounterPerdition->mCardCounter);

	// Iterate over each element in the vector using a for loop
	for (int i = 0; i < pCounterPerdition->mCardCounter; i++)
	{	// Use make_shared to create a new shared_ptr to a CCard object and assign it to the current element in the vector
		pCardsPerdition[i] = make_shared<CCard>(); // Assign the shared_ptr to the vector element
	}
	
	// Create a vector of shared pointers to CCard objects from pCounterPlagiarist's mCardCounter
	auto pHandPiffle = vector<shared_ptr<CCard>>(pCounterPiffle->mCardCounter);

	// Iterate over each element in the vector using a for loop
	for (int i = 0; i < pCounterPiffle->mCardCounter; i++)
	{	// Use make_shared to create a new shared_ptr to a CCard object and assign it to the current element in the vector
		pHandPiffle[i] = make_shared<CCard>();
	}

	// Create a vector of shared pointers to CCard objects from pCounterPlagiarist's mCardCounter
	auto pHandPlagiarist = vector<shared_ptr<CCard>>(pCounterPlagiarist->mCardCounter);

	// Iterate over each element in the vector using a for loop
	for (int i = 0; i < pCounterPlagiarist->mCardCounter; i++)
	{	// Use make_shared to create a new shared_ptr to a CCard object and assign it to the current element in the vector
		pHandPlagiarist[i] = make_shared<CCard>(); // Assign the shared_ptr to the vector element
	}

	// Create a vector of shared pointers to CCard objects from pCounterPointless's mCardCounter
	auto pHandPointless = vector<shared_ptr<CCard>>(pCounterPointless->mCardCounter);

	// Iterate over each element in the vector using a for loop
	for (int i = 0; i < pCounterPointless->mCardCounter; i++)
	{	// Use make_shared to create a new shared_ptr to a CCard object and assign it to the current element in the vector
		pHandPointless[i] = make_shared<CCard>(); // Assign the shared_ptr to the vector element
	}

	// Create a vector of shared pointers to CCard objects from pCounterPerdition's mCardCounter
	auto pHandPerdition = vector<shared_ptr<CCard>>(pCounterPerdition->mCardCounter);

	// Iterate over each element in the vector using a for loop
	for (int i = 0; i < pCounterPerdition->mCardCounter; i++)
	{	// Use make_shared to create a new shared_ptr to a CCard object and assign it to the current element in the vector
		pHandPerdition[i] = make_shared<CCard>(); // Assign the shared_ptr to the vector element
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

	// Create a vector of shared pointers to CStudent objects from pCounterPointless's mCardCounter
	auto pCardsPointlessStudents = vector<shared_ptr<CStudent>>(pCounterPointless->mCardCounter);

	// Iterate over each element in the vector using a for loop
	for (int i = 0; i < pCounterPointless->mCardCounter; i++)
	{
		// Use make_shared to create a new shared_ptr to a CStudent object and assign it to the current element in the vector
		pCardsPointlessStudents[i] = make_shared<CStudent>(); // Assign the shared_ptr to the vector element
	}

	// Create a vector of shared pointers to CStudent objects from pCounterPerdition's mCardCounter
	auto pCardsPerditionStudents = vector<shared_ptr<CStudent>>(pCounterPerdition->mCardCounter);

	// Iterate over each element in the vector using a for loop
	for (int i = 0; i < pCounterPerdition->mCardCounter; i++)
	{
		// Use make_shared to create a new shared_ptr to a CStudent object and assign it to the current element in the vector
		pCardsPerditionStudents[i] = make_shared<CStudent>(); // Assign the shared_ptr to the vector element
	}

	// Define a new type alias named cardsDrawn for a vector of shared pointers to CCard objects
	typedef vector <shared_ptr<CCard>> cardsDrawn;
	// Create two new variables of type cardsDrawn and initialize them with empty vectors
	auto pCardsPlagiaristDrawn = cardsDrawn{};
	auto pCardsPiffleDrawn = cardsDrawn{};
	auto pCardsPointlessDrawn = cardsDrawn{};
	auto pCardsPerditionDrawn = cardsDrawn{};

	// Define a new type alias named cardsStudentDrawn for a vector of shared pointers to CStudent objects
	typedef vector <shared_ptr<CStudent>> cardsStudentDrawn;
	// Create two new variables of type cardsStudentDrawn and initialize them with empty vectors
	auto pCardsPlagiaristStudentsDrawn = cardsStudentDrawn{};
	auto pCardsPiffleStudentsDrawn = cardsStudentDrawn{};
	auto pCardsPointlessStudentsDrawn = cardsStudentDrawn{};
	auto pCardsPerditionStudentsDrawn = cardsStudentDrawn{};

	// Define a new type alias named Table for a vector of shared pointers to CTable objects
	typedef vector <shared_ptr<CTable>> Table;
	// Create two new variables of type Table and initialize them with empty vectors
	auto pTablePlagiarist = Table{};
	auto pTablePiffle = Table{};
	auto pTablePointless = Table{};
	auto pTablePerdition = Table{};

	// Define a type alias for a vector of shared pointers to CPlagiarismHearing objects
	typedef vector <shared_ptr<CPlagiarismHearing>> DrawPlagiarismHearingCards;
	// Create an instance of DrawPlagiarismHearingCards named pDrawPlagiarismHearingCardsPlagiarist
	auto pDrawPlagiarismHearingCardPlagiarist = DrawPlagiarismHearingCards{};
	// Create an instance of DrawPlagiarismHearingCardS named pDrawPlagiarismHearingCardsPiffle
	auto pDrawPlagiarismHearingCardPiffle = DrawPlagiarismHearingCards{};
	// Create an instance of DrawPlagiarismHearingCardS named pDrawPlagiarismHearingCardsPointless
	auto pDrawPlagiarismHearingCardPointless = DrawPlagiarismHearingCards{};
	// Create an instance of DrawPlagiarismHearingCardS named pDrawPlagiarismHearingCardsPerdition
	auto pDrawPlagiarismHearingCardPerdition = DrawPlagiarismHearingCards{};


	/// <summary>
	/// ELELELELELELELELELE
	/// </summary>
	/// <returns></returns>
	typedef shared_ptr<CPlagiarismHearing> PlagiarismCard;
	// Create an instance of PlagiarismCard named pUsePlagiarismCard
	auto pUsePlagiarismCard = PlagiarismCard{};

	typedef shared_ptr<CCourseAccreditation> CourseAccreditationCard;
	// Create an instance of CourseAccreditationCard named pUseCourseAccreditationCard
	auto pUseCourseAccreditationCard = CourseAccreditationCard{};

	typedef shared_ptr<CEasyTarget> EasyTargetCard;
	// Create an instance of EasyTargetCard named pUseEasyTargetCard
	auto pUseEasyTargetCard = EasyTargetCard{};

	typedef shared_ptr<CFeedbackForum> FeedbackForumCard;
	// Create an instance of FeedbackForumCard named pUseFeedbackForumCard
	auto pUseFeedbackForumCard = FeedbackForumCard{};

	typedef shared_ptr<CGraduateStudent> GraduateStudentCard;
	// Create an instance of GraduateStudentCard named pUseGraduateStudentCard
	auto pUseGraduateStudentCard = GraduateStudentCard{};

	typedef shared_ptr<CIndustrialPlacement> IndustrialPlacementCard;
	// Create an instance of IndustrialPlacementCard named pUseIndustrialPlacementCard
	auto pUseIndustrialPlacementCard = IndustrialPlacementCard{};

	typedef shared_ptr<CMitigatingCircumstances> MitigatingCircumstancesCard;
	// Create an instance of MitigatingCircumstancesCard named pUseMitigatingCircumstancesCard
	auto pUseMitigatingCircumstancesCard = MitigatingCircumstancesCard{};

	typedef shared_ptr<CPassLeader> PassLeaderCard;
	// Create an instance of PassLeaderCard named pUsePassLeaderCard
	auto pUsePassLeaderCard = PassLeaderCard{};

	typedef shared_ptr<CResearchFunding> ResearchFundingCard;
	// Create an instance of PassLeaderCard named pUsePassLeaderCard
	auto pUseResearchFundingCard = ResearchFundingCard{};

	typedef shared_ptr<CSerialOffender> SerialOffenderCard;
	// Create an instance of SerialOffenderCard named pUseSerialOffenderCard
	auto pUseSerialOffenderCard = SerialOffenderCard{};




	// Define a type alias for a vector of shared pointers to CCourseAccreditation objects
	typedef vector <shared_ptr<CCourseAccreditation>> DrawCourseAccreditationCards;
	// Create an instance of DrawCourseAccreditationCards named pDrawCourseAccreditationCardPlagiarist
	auto pDrawCourseAccreditationCardPlagiarist = DrawCourseAccreditationCards{};
	// Create an instance of DrawCourseAccreditationCards named pDrawCourseAccreditationCardPiffle
	auto pDrawCourseAccreditationCardPiffle = DrawCourseAccreditationCards{};
	// Create an instance of DrawCourseAccreditationCards named pDrawCourseAccreditationCardPointless
	auto pDrawCourseAccreditationCardPointless = DrawCourseAccreditationCards{};
	// Create an instance of DrawCourseAccreditationCards named pDrawCourseAccreditationCardPerdition
	auto pDrawCourseAccreditationCardPerdition = DrawCourseAccreditationCards{};

	// Define a type alias for a vector of shared pointers to CFeedbackForum objects
	typedef vector <shared_ptr<CFeedbackForum>> feedbackForumCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pFeedbackForumPlagiarist = feedbackForumCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pFeedbackForumPiffle = feedbackForumCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPointless
	auto pFeedbackForumPointless = feedbackForumCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPerdition
	auto pFeedbackForumPerdition = feedbackForumCards{};

	// Define a type alias for a vector of shared pointers to CFeedbackForum objects
	typedef vector <shared_ptr<CPassLeader>> passLeaderCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pPassLeaderPlagiarist = passLeaderCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pPassLeaderPiffle = passLeaderCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPointless
	auto pPassLeaderPointless = passLeaderCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPerdition
	auto pPassLeaderPerdition = passLeaderCards{};

	// Define a type alias for a vector of shared pointers to CResearchFunding objects
	typedef vector <shared_ptr<CResearchFunding>> researchFundingCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pResearchFundingPlagiarist = researchFundingCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pResearchFundingPiffle = researchFundingCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPointless
	auto pResearchFundingPointless = researchFundingCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPerdition
	auto pResearchFundingPerdition = researchFundingCards{};

	//	Define  a type alias for a vector of shared pointers to CMitigatingCircumstances objects
	typedef vector <shared_ptr<CMitigatingCircumstances>> mitigatingCircumstancesCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pMitigatingCircumstancesPlagiarist = mitigatingCircumstancesCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pMitigatingCircumstancesPiffle = mitigatingCircumstancesCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPointless
	auto pMitigatingCircumstancesPointless = mitigatingCircumstancesCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPerdition
	auto pMitigatingCircumstancesPerdition = mitigatingCircumstancesCards{};

	// Define a type for a shared pointer to a CStudent object
	typedef  shared_ptr<CMitigatingCircumstances> studentCard;
	// Create an instance of studentCard named pStudentPlagiaristTest
	auto pStudentPlagiaristTest = studentCard{};
	// Create an instance of studentCard named pStudentPiffleTest
	auto pStudentPiffleTest = studentCard{};
	// Create an instance of studentCard named pStudentPointlessTest
	auto pStudentPointlessTest = studentCard{};
	// Create an instance of studentCard named pStudentPerditionTest
	auto pStudentPerditionTest = studentCard{};

	//	Define  a type alias for a vector of shared pointers to CEasyTarget objects
	typedef vector <shared_ptr<CEasyTarget>> easyTargetCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pEasyTargetPlagiarist = easyTargetCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pEasyTargetPiffle = easyTargetCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPointless
	auto pEasyTargetPointless = easyTargetCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPerdition
	auto pEasyTargetPerdition = easyTargetCards{};

	//	Define  a type alias for a vector of shared pointers to CSerialOffender objects
	typedef vector <shared_ptr<CSerialOffender>> serialOffenderCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pSerialOffenderPlagiarist = serialOffenderCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pSerialOffenderPiffle = serialOffenderCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPointless
	auto pSerialOffenderPointless = serialOffenderCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPerdition
	auto pSerialOffenderPerdition = serialOffenderCards{};

	//	Define  a type alias for a vector of shared pointers to CGraduateStudent objects
	typedef vector <shared_ptr<CGraduateStudent>> graduateStudentCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pGraduateStudentPlagiarist = graduateStudentCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pGraduateStudentPiffle = graduateStudentCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPointless
	auto pGraduateStudentPointless = graduateStudentCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPerdition
	auto pGraduateStudentPerdition = graduateStudentCards{};

	//	Define  a type alias for a vector of shared pointers to CIndustrialPlacement objects
	typedef vector <shared_ptr<CIndustrialPlacement>> industrialPlacementCards;
	// Create an instance of feedbackForumCards named pFeedbackForumPlagiarist
	auto pIndustrialPlacementPlagiarist = industrialPlacementCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPiffle
	auto pIndustrialPlacementPiffle = industrialPlacementCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPointless
	auto pIndustrialPlacementPointless = industrialPlacementCards{};
	// Create an instance of feedbackForumCards named pFeedbackForumPerdition
	auto pIndustrialPlacementPerdition = industrialPlacementCards{};

	// Call the FillDeck method of the pGameState object with arguments pCounterPlagiarist->mFile, pCardsPlagiarist and pCardsPlagiaristStudents
	pGameState->FillDeck(pCounterPlagiarist->mFile, pCardsPlagiarist, pCardsPlagiaristStudents);
	// Call the FillDeck method of the pGameState object with arguments pCounterPiffle->mFile, pCardsPlagiarist and pCardsPiffleStudents
	pGameState->FillDeck(pCounterPiffle->mFile, pCardsPiffle, pCardsPiffleStudents);
	// Call the FillDeck method of the pGameState object with arguments pCounterPointless->mFile, pCardsPlagiarist and pCardsPointlessStudents
	pGameState->FillDeck(pCounterPointless->mFile, pCardsPointless, pCardsPointlessStudents);
	// Call the FillDeck method of the pGameState object with arguments pCounterPerdition->mFile, pCardsPlagiarist and pCardsPerditionStudents
	pGameState->FillDeck(pCounterPerdition->mFile, pCardsPerdition, pCardsPerditionStudents);


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

	// Create a checkUsedCard object for Pointless with size DECK_SIZE
	auto pCheckUsedCardPointless = checkUsedCard(G_DECK_SIZE);

	// Initialize all elements of pCheckUsedCardPointless to unique pointers to false
	for (int i = 0; i < G_DECK_SIZE; i++)
	{
		pCheckUsedCardPointless[i] = make_unique<bool>(false);
	}

	// Create a checkUsedCard object for Perdition with size DECK_SIZE
	auto pCheckUsedCardPerdition = checkUsedCard(G_DECK_SIZE);

	// Initialize all elements of pCheckUsedCardPerdition to unique pointers to false
	for (int i = 0; i < G_DECK_SIZE; i++)
	{
		pCheckUsedCardPerdition[i] = make_unique<bool>(false);
	}

	// Do while loop which continues until pPlagiarist->profPrestige > 0 and pPiffle->profPrestige > 0;
	do
	{
			pGameState->StartRound(pGameState->mRoundCounter);

		
			// Draw card function draws two cards for Plagiarist
			pGameState->DrawCard(pCardsPlagiarist, pCardsPlagiaristDrawn, pCounterPlagiarist->mDeckCounter, pCounterPlagiarist->mI, *pPlagiarist, pCheckUsedCardPlagiarist);

			//	Draw card function draws two cards for Piffle
			pGameState->DrawCard(pCardsPiffle, pCardsPiffleDrawn, pCounterPiffle->mDeckCounter, pCounterPiffle->mI, *pPiffle, pCheckUsedCardPiffle);

			//	Draw card function draws two cards for Pointless
			pGameState->DrawCard(pCardsPointless, pCardsPointlessDrawn, pCounterPointless->mDeckCounter, pCounterPointless->mI, *pPointless, pCheckUsedCardPointless);

			//	Draw card function draws two cards for Perdition
			pGameState->DrawCard(pCardsPerdition, pCardsPerditionDrawn, pCounterPerdition->mDeckCounter, pCounterPerdition->mI, *pPerdition, pCheckUsedCardPerdition);

			// Piffle Chooses a random card from hand the two cards DrawCard function have selected
			pCounterPiffle->mRandomCard = pCounterPiffle->Random(pCardsPiffleDrawn.size() - 1, pCardsPiffleDrawn.size() - 1);
			// Prints out chosen card for Piffle-Paper
			cout << "Piffle-Paper chooses card: " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mType << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mFirstname << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mLastname << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mPower << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mResilience << " " << pCardsPiffleDrawn[pCounterPiffle->mRandomCard]->mBoost << endl;

			// Plagiarist Chooses a random card from the two cards DrawCard function have selected
			pCounterPlagiarist->mRandomCard = pCounterPlagiarist->Random(pCardsPlagiaristDrawn.size() - 1, pCardsPlagiaristDrawn.size() - 1);
			// Prints out chosen card for Plagiarist
			cout << "Plagiarist chooses: " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mType << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mFirstname << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mLastname << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mPower << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mResilience << " " << pCardsPlagiaristDrawn[pCounterPlagiarist->mRandomCard]->mBoost << endl;

			// Pointless Chooses a random card from the two cards DrawCard function have selected
			pCounterPointless->mRandomCard = pCounterPointless->Random(pCardsPointlessDrawn.size() - 1, pCardsPointlessDrawn.size() - 1);
			// Prints out chosen card for Pointless
			cout << "Pointless chooses: " << pCardsPointlessDrawn[pCounterPointless->mRandomCard]->mType << " " << pCardsPointlessDrawn[pCounterPointless->mRandomCard]->mFirstname << " " << pCardsPointlessDrawn[pCounterPointless->mRandomCard]->mLastname << " " << pCardsPointlessDrawn[pCounterPointless->mRandomCard]->mPower << " " << pCardsPointlessDrawn[pCounterPointless->mRandomCard]->mResilience << " " << pCardsPointlessDrawn[pCounterPointless->mRandomCard]->mBoost << endl;

			// Perdition Chooses a random card from the two cards DrawCard function have selected
			pCounterPerdition->mRandomCard = pCounterPerdition->Random(pCardsPerditionDrawn.size() - 1, pCardsPerditionDrawn.size() - 1);
			// Prints out chosen card for Perdition
			cout << "Perdition chooses: " << pCardsPerditionDrawn[pCounterPerdition->mRandomCard]->mType << " " << pCardsPerditionDrawn[pCounterPerdition->mRandomCard]->mFirstname << " " << pCardsPerditionDrawn[pCounterPerdition->mRandomCard]->mLastname << " " << pCardsPerditionDrawn[pCounterPerdition->mRandomCard]->mPower << " " << pCardsPerditionDrawn[pCounterPerdition->mRandomCard]->mResilience << " " << pCardsPerditionDrawn[pCounterPerdition->mRandomCard]->mBoost << endl;

		

		//PrintTable function prints current cards on table for each player
		pGameState->PrintTable(pTablePiffle, pCardsPiffleDrawn, *pPiffle, "Piffle-Paper", pCounterPiffle->mRandomCard);
		pGameState->PrintTable(pTablePlagiarist, pCardsPlagiaristDrawn, *pPlagiarist, "Plagiarist", pCounterPlagiarist->mRandomCard);
		pGameState->PrintTable(pTablePointless, pCardsPointlessDrawn, *pPointless, "Pointless", pCounterPointless->mRandomCard);
		pGameState->PrintTable(pTablePerdition, pCardsPerditionDrawn, *pPerdition, "Perdition", pCounterPerdition->mRandomCard);

		// Use type 1 cards (Student Cards), Piffle gets attacked
		pGameState->UseStudentCard(pTablePlagiarist, pTablePiffle, *pPlagiarist, *pPiffle, pCardsPiffleDrawn, pCardsPiffleStudentsDrawn, pCounterPiffle->mRandomCard, pEasyTargetPlagiarist);

		// Initialize random range between one or two to choose truly random card
		int randomRangeOneorTwo = pCounterPiffle->Random(1, 2);

		// Use type x cards (Plagiarism Hearing Cards), Piffle gets attacked
		pUsePlagiarismCard->useCard(pCardsPiffleDrawn, pDrawPlagiarismHearingCardPiffle, pTablePlagiarist, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle", randomRangeOneorTwo, pEasyTargetPlagiarist);
		// Use type x cards (Course Accreditation Cards), Piffle gets attacked
		pUseCourseAccreditationCard->useCard(pCardsPiffleDrawn, pDrawCourseAccreditationCardPiffle, pTablePlagiarist, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle", pEasyTargetPlagiarist);
		// Use type x cards (Feedback Forum Cards), Piffle gets attacked or Plagiarist gets healed
		pUseFeedbackForumCard->useCard(pCardsPiffleDrawn, pFeedbackForumPiffle, pTablePlagiarist, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle", randomRangeOneorTwo, pTablePiffle, pEasyTargetPlagiarist);
		// Use type x cards (Industrial Placement Cards), Piffle gets attacked
		pUseIndustrialPlacementCard->useCard(pCardsPiffleDrawn, pIndustrialPlacementPiffle, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "attackerName", pTablePiffle, pTablePlagiarist, pEasyTargetPlagiarist);
		// Use type x cards (Pass Leader Cards), Plagiarist type 6 deck gets increased attack power
		pUsePassLeaderCard->useCard(pCardsPiffleDrawn, pPassLeaderPiffle, pCounterPiffle->mRandomCard, *pPiffle, *pPiffle, "Piffle", pTablePiffle);
		// Use type x cards (ResearchFunding Cards), Piffle type 6 deck gets increased attack power
		pUseResearchFundingCard->useCard(pCardsPiffleDrawn, pResearchFundingPiffle, pCounterPiffle->mRandomCard, *pPiffle, "Piffle", pTablePiffle);
		// Use type x cards(MitigatingCircumstances Cards), Piffle type 6 deck gets increased attack power
		pUseMitigatingCircumstancesCard->useCard(pCardsPiffle, pStudentPiffleTest, pTablePiffle, pMitigatingCircumstancesPiffle, pCounterPiffle->mRandomCard);
		// Use type x cards(EasyTarget Cards), Piffle type 6 deck gets increased attack power
		pGameState->UseEasyTargetCard(pCardsPiffle, pEasyTargetPiffle, pCounterPiffle->mRandomCard, *pPiffle, "Piffle", pTablePiffle);
		// Use type x cards(Serial Offender Cards), Piffle type 6 deck gets increased attack power
		pUseSerialOffenderCard->useCard(pTablePlagiarist, pTablePiffle, *pPlagiarist, *pPiffle, pCardsPiffleDrawn, pSerialOffenderPiffle, pCounterPiffle->mRandomCard, pEasyTargetPlagiarist);
		// Use type 1 cards(Graduate Student Cards), Piffle gets attacked
		pUseGraduateStudentCard->useCard(pTablePlagiarist, pTablePiffle, *pPlagiarist, *pPiffle, pCardsPiffleDrawn, pGraduateStudentPiffle, pCounterPiffle->mRandomCard, pEasyTargetPlagiarist);

		// Exits the do while loop when one of the players loses all their prestige
		if (pPlagiarist->mProfPrestige <= 0 || pPiffle->mProfPrestige <= 0 || pPointless->mProfPrestige <= 0 || pPerdition->mProfPrestige <= 0)
		{
			// Exit the do while loop when one of the players loses all their prestige
			break;
		}

		// Use type 1 cards (Student Cards), Plagiarist gets attacked
		pGameState->UseStudentCard(pTablePointless, pTablePlagiarist, *pPointless, *pPlagiarist, pCardsPlagiaristDrawn, pCardsPlagiaristStudentsDrawn, pCounterPlagiarist->mRandomCard, pEasyTargetPointless);

		// Initialize random range between one or two to choose truly random card
		randomRangeOneorTwo = pCounterPlagiarist->Random(1, 2);

		// Use type x cards (Plagiarism Hearing Cards), Pointless gets attacked by plagiarist
		pUsePlagiarismCard->useCard(pCardsPlagiaristDrawn, pDrawPlagiarismHearingCardPlagiarist, pTablePointless, pCounterPlagiarist->mRandomCard, *pPointless, *pPlagiarist, "Pointless", "Plagiarist", randomRangeOneorTwo, pEasyTargetPointless);
		// Use type x cards (Course Accreditation Cards), Plagiarist gets attacked
		pUseCourseAccreditationCard->useCard(pCardsPlagiaristDrawn, pDrawCourseAccreditationCardPlagiarist, pTablePointless, pCounterPlagiarist->mRandomCard, *pPointless, *pPlagiarist, "Pointless", "Plagiarist", pEasyTargetPointless);
		// Use type x cards (Feedback Forum Cards), Plagiarist gets attacked or Piffle gets healed
		pUseFeedbackForumCard->useCard(pCardsPlagiaristDrawn, pFeedbackForumPlagiarist, pTablePointless, pCounterPlagiarist->mRandomCard, *pPointless, *pPlagiarist, "Pointless", "Plagiarist", randomRangeOneorTwo, pTablePlagiarist, pEasyTargetPointless);
		// Use type x cards (Feedback Forum Cards), Plagiarist gets attacked or Piffle gets healed
		pUseIndustrialPlacementCard->useCard(pCardsPlagiaristDrawn, pIndustrialPlacementPlagiarist, pCounterPlagiarist->mRandomCard, *pPointless, *pPlagiarist, "attackerName", pTablePlagiarist, pTablePointless, pEasyTargetPointless);
		// Use type x cards (Pass Leader Cards), Piffle type 6 deck gets increased attack power
		pUsePassLeaderCard->useCard(pCardsPlagiaristDrawn, pPassLeaderPlagiarist, pCounterPlagiarist->mRandomCard, *pPlagiarist, *pPlagiarist, "Plagiarist", pTablePlagiarist);
		// Use type x cards (Research Funding Cards), Piffle type 6 deck gets increased attack power
		pUseResearchFundingCard->useCard(pCardsPlagiaristDrawn, pResearchFundingPlagiarist, pCounterPlagiarist->mRandomCard, *pPlagiarist, "Plagiarist", pTablePlagiarist);
		// Use type x cards(Mitigiating Circumstances Cards), Piffle type 6 deck gets increased attack power
		pUseMitigatingCircumstancesCard->useCard(pCardsPlagiarist, pStudentPlagiaristTest, pTablePlagiarist, pMitigatingCircumstancesPlagiarist, pCounterPlagiarist->mRandomCard);
		// Use type x cards(Easy Target Cards), Piffle type 6 deck gets increased attack power THIS NEEDS TO BE FIXED
		pGameState->UseEasyTargetCard(pCardsPlagiarist, pEasyTargetPlagiarist, pCounterPlagiarist->mRandomCard, *pPlagiarist, "Plagiarist", pTablePlagiarist);
		// Use type 1 cards (Student Cards), Plagiarist gets attacked
		pUseSerialOffenderCard->useCard(pTablePointless, pTablePlagiarist, *pPointless, *pPlagiarist, pCardsPlagiaristDrawn, pSerialOffenderPlagiarist, pCounterPlagiarist->mRandomCard, pEasyTargetPointless);
		// Use type 1 cards (Graduate Student Cards), Plagiarist gets attacked
		pUseGraduateStudentCard->useCard(pTablePointless, pTablePlagiarist, *pPointless, *pPlagiarist, pCardsPlagiaristDrawn, pGraduateStudentPlagiarist, pCounterPlagiarist->mRandomCard, pEasyTargetPointless);

		// Use type 1 cards (Student Cards) of Pointless, Perdition gets attacked
		pGameState->UseStudentCard(pTablePerdition, pTablePointless, *pPerdition, *pPointless, pCardsPointlessDrawn, pCardsPointlessStudentsDrawn, pCounterPointless->mRandomCard, pEasyTargetPerdition);

		// Initialize random range between one or two to choose truly random card
		randomRangeOneorTwo = pCounterPointless->Random(1, 2);

		// Use type x cards (Plagiarism Hearing Cards), Perdition gets attacked
		pUsePlagiarismCard->useCard(pCardsPointlessDrawn, pDrawPlagiarismHearingCardPointless, pTablePerdition, pCounterPointless->mRandomCard, *pPerdition, *pPointless, "Perdition", "Pointless-Paper", randomRangeOneorTwo, pEasyTargetPerdition);
		// Use type x cards (Course Accreditation Cards), Perdition gets attacked
		pUseCourseAccreditationCard->useCard(pCardsPointlessDrawn, pDrawCourseAccreditationCardPointless, pTablePerdition, pCounterPointless->mRandomCard, *pPerdition, *pPointless, "Perdition", "Pointless-Paper", pEasyTargetPerdition);
		// Use type x cards (Feedback Forum Cards), Perdition gets attacked or Pointless gets healed
		pUseFeedbackForumCard->useCard(pCardsPointlessDrawn, pFeedbackForumPointless, pTablePerdition, pCounterPointless->mRandomCard, *pPerdition, *pPointless, "Perdition", "Pointless-Paper", randomRangeOneorTwo, pTablePointless, pEasyTargetPerdition);
		// Use type x cards (Feedback Forum Cards), Perdition gets attacked or Pointless gets healed
		pUseIndustrialPlacementCard->useCard(pCardsPointlessDrawn, pIndustrialPlacementPointless, pCounterPointless->mRandomCard, *pPerdition, *pPointless, "attackerName", pTablePointless, pTablePerdition, pEasyTargetPerdition);
		// Use type x cards (Pass Leader Cards), Pointless type 6 deck gets increased attack power
		pUsePassLeaderCard->useCard(pCardsPointlessDrawn, pPassLeaderPointless, pCounterPointless->mRandomCard, *pPointless, *pPointless, "Pointless-Paper", pTablePointless);
		// Use type x cards (Research Funding Cards), Pointless type 6 deck gets increased attack power
		pUseResearchFundingCard->useCard(pCardsPointlessDrawn, pResearchFundingPointless, pCounterPointless->mRandomCard, *pPointless, "Pointless-Paper", pTablePointless);
		// Use type x cards(Mitigating Circumstances Cards), Pointless type 6 deck gets increased attack power
		pUseMitigatingCircumstancesCard->useCard(pCardsPointless, pStudentPointlessTest, pTablePointless, pMitigatingCircumstancesPointless, pCounterPointless->mRandomCard);
		// Use type x cards(Easy Target Cards), Pointless type 6 deck gets increased attack power THIS NEEDS TO BE FIXED
		pGameState->UseEasyTargetCard(pCardsPointless, pEasyTargetPointless, pCounterPointless->mRandomCard, *pPointless, "Pointless-Paper", pTablePointless);
		// Use type 1 cards (Student Cards), Perdition gets attacked
		pUseSerialOffenderCard->useCard(pTablePerdition, pTablePointless, *pPerdition, *pPointless, pCardsPointlessDrawn, pSerialOffenderPointless, pCounterPointless->mRandomCard, pEasyTargetPerdition);
		// Use type 1 cards (Graduate Student Cards), Perdition gets attacked
		pUseGraduateStudentCard->useCard(pTablePerdition, pTablePointless, *pPerdition, *pPointless, pCardsPointlessDrawn, pGraduateStudentPointless, pCounterPointless->mRandomCard, pEasyTargetPerdition);

		// Use type 1 cards (Student Cards) of Perdition, Pointless gets attacked
		pGameState->UseStudentCard(pTablePointless, pTablePerdition, *pPointless, *pPerdition, pCardsPerditionDrawn, pCardsPerditionStudentsDrawn, pCounterPerdition->mRandomCard, pEasyTargetPointless);

		// Initialize random range between one or two to choose truly random card
		randomRangeOneorTwo = pCounterPerdition->Random(1, 2);

		// Use type x cards (Plagiarism Hearing Cards), Piffle gets attacked
		pUsePlagiarismCard->useCard(pCardsPerditionDrawn, pDrawPlagiarismHearingCardPerdition, pTablePiffle, pCounterPerdition->mRandomCard, *pPiffle, *pPerdition, "Piffle", "Perdition", randomRangeOneorTwo, pEasyTargetPiffle);
		// Use type x cards (Course Accreditation Cards), Piffle gets attacked
		pUseCourseAccreditationCard->useCard(pCardsPerditionDrawn, pDrawCourseAccreditationCardPerdition, pTablePiffle, pCounterPerdition->mRandomCard, *pPiffle, *pPerdition, "Piffle", "Perdition", pEasyTargetPiffle);
		// Use type x cards (Feedback Forum Cards), Piffle gets attacked or Perdition gets healed
		pUseFeedbackForumCard->useCard(pCardsPerditionDrawn, pFeedbackForumPerdition, pTablePiffle, pCounterPerdition->mRandomCard, *pPiffle, *pPerdition, "Piffle", "Perdition", randomRangeOneorTwo, pTablePerdition, pEasyTargetPiffle);
		// Use type x cards (Industrial Placement Cards), Piffle gets attacked or Perdition gets healed
		pUseIndustrialPlacementCard->useCard(pCardsPerditionDrawn, pIndustrialPlacementPerdition, pCounterPerdition->mRandomCard, *pPiffle, *pPerdition, "Perdition", pTablePerdition, pTablePiffle, pEasyTargetPiffle);
		// Use type x cards (Pass Leader Cards), Perdition type 6 deck gets increased attack power
		pUsePassLeaderCard->useCard(pCardsPerditionDrawn, pPassLeaderPerdition, pCounterPerdition->mRandomCard, *pPerdition, *pPerdition, "Perdition", pTablePerdition);
		// Use type x cards (Research Funding Cards), Perdition type 6 deck gets increased attack power
		pUseResearchFundingCard->useCard(pCardsPerditionDrawn, pResearchFundingPerdition, pCounterPerdition->mRandomCard, *pPerdition, "Perdition", pTablePerdition);
		// Use type x cards(Mitigating Circumstances Cards), Perdition type 6 deck gets increased attack power
		pUseMitigatingCircumstancesCard->useCard(pCardsPerdition, pStudentPerditionTest, pTablePerdition, pMitigatingCircumstancesPerdition, pCounterPerdition->mRandomCard);
		// Use type x cards(Easy Target Cards), Perdition type 6 deck gets increased attack power
		pGameState->UseEasyTargetCard(pCardsPerdition, pEasyTargetPerdition, pCounterPerdition->mRandomCard, *pPerdition, "Perdition", pTablePerdition);
		// Use type 1 cards (Student Cards), Piffle gets attacked
		pUseSerialOffenderCard->useCard(pTablePiffle, pTablePerdition, *pPiffle, *pPerdition, pCardsPerditionDrawn, pSerialOffenderPerdition, pCounterPerdition->mRandomCard, pEasyTargetPiffle);
		// Use type 1 cards (Graduate Student Cards), Piffle gets attacked
		pUseGraduateStudentCard->useCard(pTablePiffle, pTablePerdition, *pPiffle, *pPerdition, pCardsPerditionDrawn, pGraduateStudentPerdition, pCounterPerdition->mRandomCard, pEasyTargetPiffle);

		// Exits the do while loop when one of the players loses all their prestige
		if (pPlagiarist->mProfPrestige <= 0 || pPiffle->mProfPrestige <= 0 || pPointless->mProfPrestige <= 0 || pPerdition->mProfPrestige <= 0)
		{
			// Exit the loop when one of the players loses all their prestige
			break;
		}



	} while (pPlagiarist->mProfPrestige > 0 && pPiffle->mProfPrestige > 0 && pPointless->mProfPrestige > 0 && pPerdition->mProfPrestige > 0);

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
