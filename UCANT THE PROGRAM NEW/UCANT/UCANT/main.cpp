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

	// Create a unique pointer to a CCounter object
	auto pCounter = make_unique<CCounter>();
	// Create a unique pointer to a CCounter object for Piffle
	auto pCounterPiffle = make_unique<CCounter>();
	// Create a unique pointer to a CCounter object for Plagiarist
	auto pCounterPlagiarist = make_unique<CCounter>();
	// Create a unique pointer to a CCounter object for Perdition
	auto pCounterPerdition = make_unique<CCounter>();
	// Create a unique pointer to a CCounter object for Pointless
	auto pCounterPointless = make_unique<CCounter>();

	// Genereate seed from read file
	pCounter->mSeeder = pCounter->getSeed();
	pCounter->mSeeder = ReadSeedFile("seed.txt");
	// Generate random number from seed
	srand(static_cast<unsigned int>(pCounter->mSeeder));
	pCounter->setSeed(pCounter->mSeeder);

	// Initialize data before commencing U-Can't
	auto pGameState = make_unique<CManager>();
	pGameState->GameStart();

	// Open texts files and assign the contents to mFile
	pCounterPlagiarist->setFile("plagiarist.txt");
	pCounterPiffle->setFile("piffle-paper.txt");
	pCounterPointless->setFile("pointless.txt");
	pCounterPerdition->setFile("perdition.txt");

	// Create a shared pointer to new SProfessor objects and CPlayer objects
	auto pPlagiarist = make_shared<CPlayers>();
	pPlagiarist->mProfNamer = pPlagiarist->setProfessorName("Plagiarist");
	auto pPiffle = make_shared<CPlayers>();
	auto pPiffleName = make_shared<CPlayers>();
	pPiffle->mProfNamer = pPiffle->setProfessorName("Piffle-Paper");
	auto pPerdition = make_shared<CPlayers>();
	pPerdition->mProfNamer = pPerdition->setProfessorName("Perdition");
	auto pPointless = make_shared<CPlayers>();
	pPointless->mProfNamer = pPointless->setProfessorName("Pointless");

	// Create a shared pointer to new CPlayer objects
	auto pStudent = make_shared<CPlayers>();

	// Count the number of cards in each players file via countCardsInFile Function with CCounter class
	pCounterPlagiarist->countCardsInFile(pCounterPlagiarist);
	pCounterPiffle->countCardsInFile(pCounterPiffle);
	pCounterPointless->countCardsInFile(pCounterPointless);
	pCounterPerdition->countCardsInFile(pCounterPerdition);

	// Create a vector of shared pointers to CCard objects from pCounterPiffle's mCardCounter
	auto pCardsPiffle = vector<shared_ptr<CCard>>(pCounterPiffle->mCardCounter);

	pCounterPiffle->createCardsInVector(pCounterPiffle, pCardsPiffle);

	// Create a vector of shared pointers to CCard objects from pCounterPlagiarist's mCardCounter
	auto pCardsPlagiarist = vector<shared_ptr<CCard>>(pCounterPlagiarist->mCardCounter);

	pCounterPlagiarist->createCardsInVector(pCounterPlagiarist, pCardsPlagiarist);

	//Create a vector of shared pointers to CCard objects from pCounterPointless's mCardCounter
	auto pCardsPointless = vector<shared_ptr<CCard>>(pCounterPointless->mCardCounter);

	pCounterPointless->createCardsInVector(pCounterPointless, pCardsPointless);

	//Create a vector of shared pointers to CCard objects from pCounterPerdition's mCardCounter
	auto pCardsPerdition = vector<shared_ptr<CCard>>(pCounterPerdition->mCardCounter);

	pCounterPerdition->createCardsInVector(pCounterPerdition, pCardsPerdition);

	// Create a vector of shared pointers to CCard objects from pCounterPlagiarist's mCardCounter
	auto pHandPiffle = vector<shared_ptr<CCard>>(pCounterPiffle->mCardCounter);

	// Iterate over each element in the vector using a for loop
	pCounterPiffle->initializeHand(pHandPiffle, pCounterPiffle->mCardCounter);

	// Create a vector of shared pointers to CCard objects from pCounterPlagiarist's mCardCounter
	auto pHandPlagiarist = vector<shared_ptr<CCard>>(pCounterPlagiarist->mCardCounter);

	// Iterate over each element in the vector using a for loop
	pCounterPlagiarist->initializeHand(pHandPlagiarist, pCounterPlagiarist->mCardCounter);

	// Create a vector of shared pointers to CCard objects from pCounterPointless's mCardCounter
	auto pHandPointless = vector<shared_ptr<CCard>>(pCounterPointless->mCardCounter);

	// Iterate over each element in the vector using a for loop
	pCounterPointless->initializeHand(pHandPointless, pCounterPointless->mCardCounter);

	// Create a vector of shared pointers to CCard objects from pCounterPerdition's mCardCounter
	auto pHandPerdition = vector<shared_ptr<CCard>>(pCounterPerdition->mCardCounter);

	// Iterate over each element in the vector using a for loop
	pCounterPerdition->initializeHand(pHandPerdition, pCounterPerdition->mCardCounter);

	// Create a new vector of shared_ptr Student objects with variousStudents alias
	typedef vector <shared_ptr<CStudent>> variousStudents;
	// Create a new shared_ptr<CStudent> object that points to a null pointer
	auto pStudents = shared_ptr<CStudent>();
	// Create a vector of shared pointers to CStudent objects from pCounterPlagiarist's mCardCounter
	auto pCardsPlagiaristStudents = variousStudents(pCounterPlagiarist->mCardCounter);
	// Create a vector of shared pointers to CStudent objects from pCounterPiffle's mCardCounter
	auto pCardsPiffleStudents = variousStudents(pCounterPiffle->mCardCounter);
	// Create a vector of shared pointers to CStudent objects from pCounterPointless's mCardCounter
	auto pCardsPointlessStudents = variousStudents(pCounterPointless->mCardCounter);
	// Create a vector of shared pointers to CStudent objects from pCounterPerdition's mCardCounter
	auto pCardsPerditionStudents = variousStudents(pCounterPerdition->mCardCounter);

	// Iterate over each element in the vector using a for loop
	pStudents->AddStudents(pCardsPlagiaristStudents);
	// Iterate over each element in the vector using a for loop
	pStudents->AddStudents(pCardsPiffleStudents);
	// Iterate over each element in the vector using a for loop
	pStudents->AddStudents(pCardsPointlessStudents);
	// Iterate over each element in the vector using a for loop
	pStudents->AddStudents(pCardsPerditionStudents);

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


	/* Creates synynoms for existing types for readability
	through the project*/
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

	typedef shared_ptr<CStudent> StudentCard;
	// Create an instance of StudentCard named pUseStudentCard
	auto pUseStudentCard = StudentCard{};




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
	// Create an instance of studentCard named pStudentPlagiarist
	auto pStudentPlagiarist = studentCard{};
	// Create an instance of studentCard named pStudentPiffle
	auto pStudentPiffle = studentCard{};
	// Create an instance of studentCard named pStudentPointless
	auto pStudentPointless = studentCard{};
	// Create an instance of studentCard named pStudentPerdition
	auto pStudentPerdition = studentCard{};

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
	pGameState->FillDeck(pCounterPlagiarist->getFile(), pCardsPlagiarist, pCardsPlagiaristStudents);
	// Call the FillDeck method of the pGameState object with arguments pCounterPiffle->mFile, pCardsPiffle and pCardsPiffleStudents
	pGameState->FillDeck(pCounterPiffle->getFile(), pCardsPiffle, pCardsPiffleStudents);
	// Call the FillDeck method of the pGameState object with arguments pCounterPointless->mFile, pCardsPointless and pCardsPointlessStudents
	pGameState->FillDeck(pCounterPointless->getFile(), pCardsPointless, pCardsPointlessStudents);
	// Call the FillDeck method of the pGameState object with arguments pCounterPerdition->mFile, pCardsPerdition and pCardsPerditionStudents
	pGameState->FillDeck(pCounterPerdition->getFile(), pCardsPerdition, pCardsPerditionStudents);


	// Define a type alias for a vector of shared pointers to bools
	typedef vector<shared_ptr<bool>> checkUsedCard;

	// Create a checkUsedCard object for Plagiarist with size DECK_SIZE
	auto pCheckUsedCardPlagiarist = checkUsedCard(G_DECK_SIZE);

	// Initialize all elements of pCheckUsedCardPlagiarist to unique pointers to false
	pCounterPlagiarist->initializeCheckUsedCard(pCheckUsedCardPlagiarist);

	// Create a checkUsedCard object for Piffle with size DECK_SIZE
	auto pCheckUsedCardPiffle = checkUsedCard(G_DECK_SIZE);

	// Initialize all elements of pCheckUsedCardPiffle to unique pointers to false
	pCounterPiffle->initializeCheckUsedCard(pCheckUsedCardPiffle);

	// Create a checkUsedCard object for Pointless with size DECK_SIZE
	auto pCheckUsedCardPointless = checkUsedCard(G_DECK_SIZE);

	// Initialize all elements of pCheckUsedCardPointless to unique pointers to false
	pCounterPointless->initializeCheckUsedCard(pCheckUsedCardPointless);

	// Create a checkUsedCard object for Perdition with size DECK_SIZE
	auto pCheckUsedCardPerdition = checkUsedCard(G_DECK_SIZE);

	// Initialize all elements of pCheckUsedCardPerdition to unique pointers to false
	pCounterPerdition->initializeCheckUsedCard(pCheckUsedCardPerdition);

	// Do while loop which continues until pPlagiarist->profPrestige > 0 and pPiffle->profPrestige > 0;
	do
	{
		// Gets round numbner and increments every time a new round is started
		pGameState->mGetRoundInteger = pGameState->getRoundCounter();
		pGameState->StartRound(pGameState->mGetRoundInteger);
		pGameState->setRoundCounter(pGameState->mGetRoundInteger);

		// Draw card function draws two cards for Plagiarist
		pGameState->DrawCard(pCardsPlagiarist, pCardsPlagiaristDrawn, pCounterPlagiarist->mDeckCounter, pCounterPlagiarist->mLoopCounter, *pPlagiarist, pCheckUsedCardPlagiarist);
		pGameState->PrintTable(pTablePlagiarist, pCardsPlagiaristDrawn, *pPlagiarist, "Plagiarist", pCounterPlagiarist->mRandomCard);

		// Use type 1 cards (Student Cards), Pointless gets attacked
		pUseStudentCard->UseCard(pTablePointless, pTablePlagiarist, *pPointless, *pPlagiarist, pCardsPlagiaristDrawn, pCardsPlagiaristStudentsDrawn, pCounterPlagiarist->mRandomCard, pEasyTargetPointless);

		// Plagiarist Chooses a random card from the two cards DrawCard function have selected
		pCounterPlagiarist->mRandomCard = pCounterPlagiarist->Random(static_cast<int>(pCardsPlagiaristDrawn.size() - 1), static_cast<int>(pCardsPlagiaristDrawn.size() - 1));


		// Initialize random range between one or two to choose truly random card
		pGameState->mGetChoiceInteger = pGameState->getChoice();
		pGameState->mGetChoiceInteger = pCounterPlagiarist->Random(pGameState->eChoiceAlpha, pGameState->eChoiceBeta);
		pGameState->setChoice(pGameState->mGetChoiceInteger);
		// Use type x cards (Plagiarism Hearing Cards), Pointless gets attacked by plagiarist
		pUsePlagiarismCard->useCard(pCardsPlagiaristDrawn, pDrawPlagiarismHearingCardPlagiarist, pTablePointless, pCounterPlagiarist->mRandomCard, *pPointless, *pPlagiarist, "Pointless", "Plagiarist", pGameState->mGetChoiceInteger, pEasyTargetPointless);
		// Use type x cards (Course Accreditation Cards), Pointless gets attacked
		pUseCourseAccreditationCard->useCard(pCardsPlagiaristDrawn, pDrawCourseAccreditationCardPlagiarist, pTablePointless, pCounterPlagiarist->mRandomCard, *pPointless, *pPlagiarist, "Pointless", "Plagiarist", pEasyTargetPointless);
		// Use type x cards (Feedback Forum Cards), Pointless gets attacked or Plagiarist gets healed
		pUseFeedbackForumCard->useCard(pCardsPlagiaristDrawn, pFeedbackForumPlagiarist, pTablePointless, pCounterPlagiarist->mRandomCard, *pPointless, *pPlagiarist, "Pointless", "Plagiarist", pGameState->mGetChoiceInteger, pTablePlagiarist, pEasyTargetPointless);
		// Use type x cards (Feedback Forum Cards), Pointless gets attacked or Plagiarist gets healed
		pUseIndustrialPlacementCard->useCard(pCardsPlagiaristDrawn, pIndustrialPlacementPlagiarist, pCounterPlagiarist->mRandomCard, *pPointless, *pPlagiarist, "attackerName", pTablePlagiarist, pTablePointless, pEasyTargetPointless);
		// Use type x cards (Pass Leader Cards), Plagiarist table gets increased attack power
		pUsePassLeaderCard->useCard(pCardsPlagiaristDrawn, pPassLeaderPlagiarist, pCounterPlagiarist->mRandomCard, *pPlagiarist, *pPlagiarist, "Plagiarist", pTablePlagiarist);
		// Use type x cards (Research Funding Cards), Plagiarist table gets increased attack power
		pUseResearchFundingCard->useCard(pCardsPlagiaristDrawn, pResearchFundingPlagiarist, pCounterPlagiarist->mRandomCard, *pPlagiarist, "Plagiarist", pTablePlagiarist);
		// Use type x cards(Mitigiating Circumstances Cards), Plagiarist cards gets increased attack power
		pUseMitigatingCircumstancesCard->useCard(pCardsPlagiarist, pStudentPlagiarist, pTablePlagiarist, pMitigatingCircumstancesPlagiarist, pCounterPlagiarist->mRandomCard);
		// Use type x cards(Easy Target Cards), spawns easy target card on table for plagiarist
		pUseEasyTargetCard->UseCard(pCardsPlagiarist, pEasyTargetPlagiarist, pCounterPlagiarist->mRandomCard, *pPlagiarist, "Plagiarist", pTablePlagiarist);
		// Use type 1 cards (Student Cards), Pointless gets attacked
		pUseSerialOffenderCard->useCard(pTablePointless, pTablePlagiarist, *pPointless, *pPlagiarist, pCardsPlagiaristDrawn, pSerialOffenderPlagiarist, pCounterPlagiarist->mRandomCard, pEasyTargetPointless);
		// Use type 1 cards (Graduate Student Cards), Pointless gets attacked
		pUseGraduateStudentCard->useCard(pTablePointless, pTablePlagiarist, *pPointless, *pPlagiarist, pCardsPlagiaristDrawn, pGraduateStudentPlagiarist, pCounterPlagiarist->mRandomCard, pEasyTargetPointless);

		//Check if prestige is 0
		pStudent->ProfessorSacked(pPlagiarist, pPiffle, pPointless, pPerdition);

		// Exits the do while loop when one of the players loses all their prestige
		if (pPlagiarist->mProfPrestige <= 0 || pPiffle->mProfPrestige <= 0 || pPointless->mProfPrestige <= 0 || pPerdition->mProfPrestige <= 0)
		{
			// Exit the loop when one of the players loses all their prestige
			break;
		}

		cout << endl;
		//	Draw card function draws two cards for Piffle
		pGameState->DrawCard(pCardsPiffle, pCardsPiffleDrawn, pCounterPiffle->mDeckCounter, pCounterPiffle->mLoopCounter, *pPiffle, pCheckUsedCardPiffle);

		// Piffle Chooses a random card from hand the two cards DrawCard function have selected
		pCounterPiffle->mRandomCard = pCounterPiffle->Random(static_cast<int>(pCardsPiffleDrawn.size() - 1), static_cast<int>(pCardsPiffleDrawn.size() - 1));

		//PrintTable function prints current cards on table for each player
		pGameState->PrintTable(pTablePiffle, pCardsPiffleDrawn, *pPiffle, "Piffle-Paper", pCounterPiffle->mRandomCard);

		// Initialize random range between one or two to choose truly random card
		pGameState->mGetChoiceInteger = pGameState->getChoice();
		pGameState->mGetChoiceInteger = pCounterPiffle->Random(pGameState->eChoiceAlpha, pGameState->eChoiceBeta);
		pGameState->setChoice(pGameState->mGetChoiceInteger);

		// Use type 1 cards (Student Cards), Plagiarist gets attacked
		pUseStudentCard->UseCard(pTablePlagiarist, pTablePiffle, *pPlagiarist, *pPiffle, pCardsPiffleDrawn, pCardsPiffleStudentsDrawn, pCounterPiffle->mRandomCard, pEasyTargetPlagiarist);
		// Use type x cards (Plagiarism Hearing Cards), Plagiarist gets attacked
		pUsePlagiarismCard->useCard(pCardsPiffleDrawn, pDrawPlagiarismHearingCardPiffle, pTablePlagiarist, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", pGameState->mGetChoiceInteger, pEasyTargetPlagiarist);
		// Use type x cards (Course Accreditation Cards), Plagiarist gets attacked
		pUseCourseAccreditationCard->useCard(pCardsPiffleDrawn, pDrawCourseAccreditationCardPiffle, pTablePlagiarist, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", pEasyTargetPlagiarist);
		// Use type x cards (Feedback Forum Cards), Plagiarist gets attacked or Piffle gets healed
		pUseFeedbackForumCard->useCard(pCardsPiffleDrawn, pFeedbackForumPiffle, pTablePlagiarist, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "Plagiarist", "Piffle-Paper", pGameState->mGetChoiceInteger, pTablePiffle, pEasyTargetPlagiarist);
		// Use type x cards (Industrial Placement Cards), Plagiarist gets attacked but piffle minions gain 1 resilience
		pUseIndustrialPlacementCard->useCard(pCardsPiffleDrawn, pIndustrialPlacementPiffle, pCounterPiffle->mRandomCard, *pPlagiarist, *pPiffle, "Paper-Paper", pTablePiffle, pTablePlagiarist, pEasyTargetPlagiarist);
		// Use type x cards (Pass Leader Cards), Piffle minions get increased attack power depending on amont of minions on the table
		pUsePassLeaderCard->useCard(pCardsPiffleDrawn, pPassLeaderPiffle, pCounterPiffle->mRandomCard, *pPiffle, *pPiffle, "Piffle-Paper", pTablePiffle);
		// Use type x cards (ResearchFunding Cards), Piffle deck gets increased attack power by 2
		pUseResearchFundingCard->useCard(pCardsPiffleDrawn, pResearchFundingPiffle, pCounterPiffle->mRandomCard, *pPiffle, "Piffle-Paper", pTablePiffle);
		// Use type x cards(MitigatingCircumstances Cards), piffle cards get power of attack damage recieved reduced by 1
		pUseMitigatingCircumstancesCard->useCard(pCardsPiffle, pStudentPiffle, pTablePiffle, pMitigatingCircumstancesPiffle, pCounterPiffle->mRandomCard);
		// Use type x cards(EasyTarget Cards), Piffle minions get increased attack power
		pUseEasyTargetCard->UseCard(pCardsPiffle, pEasyTargetPiffle, pCounterPiffle->mRandomCard, *pPiffle, "Piffle-Paper", pTablePiffle);
		// Use type x cards(Serial Offender Cards), Plagiarist gets attacked
		pUseSerialOffenderCard->useCard(pTablePlagiarist, pTablePiffle, *pPlagiarist, *pPiffle, pCardsPiffleDrawn, pSerialOffenderPiffle, pCounterPiffle->mRandomCard, pEasyTargetPlagiarist);
		// Use type 1 cards(Graduate Student Cards), Plagiarist gets attacked
		pUseGraduateStudentCard->useCard(pTablePlagiarist, pTablePiffle, *pPlagiarist, *pPiffle, pCardsPiffleDrawn, pGraduateStudentPiffle, pCounterPiffle->mRandomCard, pEasyTargetPlagiarist);

		//Check if prestige is 0
		pStudent->ProfessorSacked(pPlagiarist, pPiffle, pPointless, pPerdition);

		// Exits the do while loop when one of the players loses all their prestige
		if (pPlagiarist->mProfPrestige <= 0 || pPiffle->mProfPrestige <= 0 || pPointless->mProfPrestige <= 0 || pPerdition->mProfPrestige <= 0)
		{
			// Exit the do while loop when one of the players loses all their prestige
			break;
		}

		cout << endl;
		//	Draw card function draws two cards for Pointless
		pGameState->DrawCard(pCardsPointless, pCardsPointlessDrawn, pCounterPointless->mDeckCounter, pCounterPointless->mLoopCounter, *pPointless, pCheckUsedCardPointless);

		// Pointless Chooses a random card from the two cards DrawCard function have selected
		pCounterPointless->mRandomCard = pCounterPointless->Random(static_cast<int>(pCardsPointlessDrawn.size() - 1), static_cast<int>(pCardsPointlessDrawn.size() - 1));

		// Initialize random range between one or two to choose truly random card
		pGameState->mGetChoiceInteger = pGameState->getChoice();
		pGameState->mGetChoiceInteger = pCounterPointless->Random(pGameState->eChoiceAlpha, pGameState->eChoiceBeta);
		pGameState->setChoice(pGameState->mGetChoiceInteger);

		pGameState->PrintTable(pTablePointless, pCardsPointlessDrawn, *pPointless, "Pointless", pCounterPointless->mRandomCard);

		// Use type 1 cards (Student Cards), Perdition gets attacked
		pUseStudentCard->UseCard(pTablePerdition, pTablePointless, *pPerdition, *pPointless, pCardsPointlessDrawn, pCardsPointlessStudentsDrawn, pCounterPointless->mRandomCard, pEasyTargetPerdition);
		// Use type x cards (Plagiarism Hearing Cards), Perdition gets attacked
		pUsePlagiarismCard->useCard(pCardsPointlessDrawn, pDrawPlagiarismHearingCardPointless, pTablePerdition, pCounterPointless->mRandomCard, *pPerdition, *pPointless, "Perdition", "Pointless", pGameState->mGetChoiceInteger, pEasyTargetPerdition);
		// Use type x cards (Course Accreditation Cards), Perdition gets attacked
		pUseCourseAccreditationCard->useCard(pCardsPointlessDrawn, pDrawCourseAccreditationCardPointless, pTablePerdition, pCounterPointless->mRandomCard, *pPerdition, *pPointless, "Perdition", "Pointless", pEasyTargetPerdition);
		// Use type x cards (Feedback Forum Cards), Perdition gets attacked or Pointless minions gets healed
		pUseFeedbackForumCard->useCard(pCardsPointlessDrawn, pFeedbackForumPointless, pTablePerdition, pCounterPointless->mRandomCard, *pPerdition, *pPointless, "Perdition", "Pointless", pGameState->mGetChoiceInteger, pTablePointless, pEasyTargetPerdition);
		// Use type x cards (Feedback Forum Cards), Perdition gets attacked but pointless minions gain 1 resilience
		pUseIndustrialPlacementCard->useCard(pCardsPointlessDrawn, pIndustrialPlacementPointless, pCounterPointless->mRandomCard, *pPerdition, *pPointless, "Pointless", pTablePointless, pTablePerdition, pEasyTargetPerdition);
		// Use type x cards (Pass Leader Cards), Pointless minions gets increased attack power depending on amount of minions on the table
		pUsePassLeaderCard->useCard(pCardsPointlessDrawn, pPassLeaderPointless, pCounterPointless->mRandomCard, *pPointless, *pPointless, "Pointless", pTablePointless);
		// Use type x cards (Research Funding Cards), Pointless deck gets increased attack power by 2
		pUseResearchFundingCard->useCard(pCardsPointlessDrawn, pResearchFundingPointless, pCounterPointless->mRandomCard, *pPointless, "Pointless", pTablePointless);
		// Use type x cards(Mitigating Circumstances Cards), Pointless cards get power of attack damage recieved reduced by 1
		pUseMitigatingCircumstancesCard->useCard(pCardsPointless, pStudentPointless, pTablePointless, pMitigatingCircumstancesPointless, pCounterPointless->mRandomCard);
		// Use type x cards(Easy Target Cards), spawns easy target card for Pointless
		pUseEasyTargetCard->UseCard(pCardsPointless, pEasyTargetPointless, pCounterPointless->mRandomCard, *pPointless, "Pointless", pTablePointless);
		// Use type 1 cards (Student Cards), Perdition gets attacked
		pUseSerialOffenderCard->useCard(pTablePerdition, pTablePointless, *pPerdition, *pPointless, pCardsPointlessDrawn, pSerialOffenderPointless, pCounterPointless->mRandomCard, pEasyTargetPerdition);
		// Use type 1 cards (Graduate Student Cards), Perdition gets attacked
		pUseGraduateStudentCard->useCard(pTablePerdition, pTablePointless, *pPerdition, *pPointless, pCardsPointlessDrawn, pGraduateStudentPointless, pCounterPointless->mRandomCard, pEasyTargetPerdition);

		//Check if prestige is 0
		pStudent->ProfessorSacked(pPlagiarist, pPiffle, pPointless, pPerdition);
		// Exits the do while loop when one of the players loses all their prestige
		if (pPlagiarist->mProfPrestige <= 0 || pPiffle->mProfPrestige <= 0 || pPointless->mProfPrestige <= 0 || pPerdition->mProfPrestige <= 0)
		{
			// Exit the loop when one of the players loses all their prestige
			break;
		}

		cout << endl;
		//	Draw card function draws two cards for Perdition
		pGameState->DrawCard(pCardsPerdition, pCardsPerditionDrawn, pCounterPerdition->mDeckCounter, pCounterPerdition->mLoopCounter, *pPerdition, pCheckUsedCardPerdition);
		// Perdition Chooses a random card from the two cards DrawCard function have selected
		pCounterPerdition->mRandomCard = pCounterPerdition->Random(static_cast<int>(pCardsPerditionDrawn.size() - 1), static_cast<int>(pCardsPerditionDrawn.size() - 1));

		pGameState->PrintTable(pTablePerdition, pCardsPerditionDrawn, *pPerdition, "Perdition", pCounterPerdition->mRandomCard);

		// Initialize random range between one or two to choose truly random card
		pGameState->mGetChoiceInteger = pGameState->getChoice();
		pGameState->mGetChoiceInteger = pCounterPerdition->Random(pGameState->eChoiceAlpha, pGameState->eChoiceBeta);
		pGameState->setChoice(pGameState->mGetChoiceInteger);

		// Use type 1 cards (Student Cards) of Perdition, Pointless gets attacked
		pUseStudentCard->UseCard(pTablePointless, pTablePerdition, *pPointless, *pPerdition, pCardsPerditionDrawn, pCardsPerditionStudentsDrawn, pCounterPerdition->mRandomCard, pEasyTargetPointless);

		// Use type x cards (Plagiarism Hearing Cards), Piffle gets attacked
		pUsePlagiarismCard->useCard(pCardsPerditionDrawn, pDrawPlagiarismHearingCardPerdition, pTablePiffle, pCounterPerdition->mRandomCard, *pPiffle, *pPerdition, "Piffle-Paper", "Perdition", pGameState->mGetChoiceInteger, pEasyTargetPiffle);
		// Use type x cards (Course Accreditation Cards), Piffle gets attacked
		pUseCourseAccreditationCard->useCard(pCardsPerditionDrawn, pDrawCourseAccreditationCardPerdition, pTablePiffle, pCounterPerdition->mRandomCard, *pPiffle, *pPerdition, "Piffle-Paper", "Perdition", pEasyTargetPiffle);
		// Use type x cards (Feedback Forum Cards), Piffle gets attacked or Perdition and minions gets healed
		pUseFeedbackForumCard->useCard(pCardsPerditionDrawn, pFeedbackForumPerdition, pTablePiffle, pCounterPerdition->mRandomCard, *pPiffle, *pPerdition, "Piffle-Paper", "Perdition", pGameState->mGetChoiceInteger, pTablePerdition, pEasyTargetPiffle);
		// Use type x cards (Industrial Placement Cards), Piffle gets attacked but perdition minion gains 1 resilience
		pUseIndustrialPlacementCard->useCard(pCardsPerditionDrawn, pIndustrialPlacementPerdition, pCounterPerdition->mRandomCard, *pPiffle, *pPerdition, "Perdition", pTablePerdition, pTablePiffle, pEasyTargetPiffle);
		// Use type x cards (Pass Leader Cards), Perdition type 6 deck gets increased attack power depending on amount on table
		pUsePassLeaderCard->useCard(pCardsPerditionDrawn, pPassLeaderPerdition, pCounterPerdition->mRandomCard, *pPerdition, *pPerdition, "Perdition", pTablePerdition);
		// Use type x cards (Research Funding Cards), Perdition type 6 deck gets increased attack power by 2
		pUseResearchFundingCard->useCard(pCardsPerditionDrawn, pResearchFundingPerdition, pCounterPerdition->mRandomCard, *pPerdition, "Perdition", pTablePerdition);
		// Use type x cards(Mitigating Circumstances Cards), Perdition cards get power of attack damage recieved reduced by 1
		pUseMitigatingCircumstancesCard->useCard(pCardsPerdition, pStudentPerdition, pTablePerdition, pMitigatingCircumstancesPerdition, pCounterPerdition->mRandomCard);
		// Use type x cards(Easy Target Cards), spawns easy target card for perdition
		pUseEasyTargetCard->UseCard(pCardsPerdition, pEasyTargetPerdition, pCounterPerdition->mRandomCard, *pPerdition, "Perdition", pTablePerdition);
		// Use type 1 cards (Student Cards), Piffle gets attacked
		pUseSerialOffenderCard->useCard(pTablePiffle, pTablePerdition, *pPiffle, *pPerdition, pCardsPerditionDrawn, pSerialOffenderPerdition, pCounterPerdition->mRandomCard, pEasyTargetPiffle);
		// Use type 1 cards (Graduate Student Cards), Piffle gets attacked
		pUseGraduateStudentCard->useCard(pTablePiffle, pTablePerdition, *pPiffle, *pPerdition, pCardsPerditionDrawn, pGraduateStudentPerdition, pCounterPerdition->mRandomCard, pEasyTargetPiffle);

		//Check if prestige is 0
		pStudent->ProfessorSacked(pPlagiarist, pPiffle, pPointless, pPerdition);
		// Exits the do while loop when one of the players loses all their prestige
		if (pPlagiarist->mProfPrestige <= 0 || pPiffle->mProfPrestige <= 0 || pPointless->mProfPrestige <= 0 || pPerdition->mProfPrestige <= 0)
		{
			// Exit the loop when one of the players loses all their prestige
			break;
		}



	} while (pPlagiarist->mProfPrestige > 0 && pPiffle->mProfPrestige > 0 && pPointless->mProfPrestige > 0 && pPerdition->mProfPrestige > 0);

	// GameOver function checks which player has won
	pGameState->GameOver(pPiffle, pPlagiarist, pPointless, pPerdition);

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
		cout << "Unable to open file " << filename << endl;
	}
	// Returns time_t statement of seed value read from file
	return seed_value;
}
