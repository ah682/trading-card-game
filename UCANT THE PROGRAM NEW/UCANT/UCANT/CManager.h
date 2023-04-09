// Adam James Anthony Hall
#pragma once
#pragma warning(disable : 4267)
#pragma warning(disable : 6031)
// Initialize necessary header files
#include <fstream>
#include <vector>

#include "CCard.h"
#include "CPlayers.h"
#include "CStudent.h"
#include "CTable.h"
#include "CCounter.h"
#include "CCourseAccreditation.h"
#include "CPlagiarismHearing.h"
#include "CFeedbackForum.h"
#include "CPassLeader.h"
#include "CResearchFunding.h"
#include "CMitigatingCircumstances.h"
#include "CEasyTarget.h"
#include "CSerialOffender.h"
#include "CGraduateStudent.h"
#include "CIndustrialPlacement.h"

/*
 * The CManager class has several public member functions and an enum for selecting choices.
 * The public member functions include:
 * - GameStart: which starts the game.
 * - GameOver: which takes several SProfessor objects as arguments and ends the game.
 * - StartRound: which takes a reference to an int for the round number and starts a new round.
 * - UseStudentCard: which takes several arguments including vectors of shared pointers to CTable, CCard, CStudent and CEasyTarget objects,
 *   as well as references to SProfessor objects and an int for a random card.
 * - FillDeck: which takes an ifstream object, a vector of shared pointers to CCard objects and a vector of shared pointers to CStudent objects as arguments and fills the deck with cards.
 * - DrawCard: which takes several arguments including vectors of shared pointers to CCard objects, references to ints for the deck counter and index,
 *   an SProfessor object for the player name and a vector of shared pointers to bools for used cards.
 * - pushToHand: which takes vectors of shared pointers to CCard objects, a reference to an int for the index,
 *   and an SProfessor object for the player name as arguments and pushes cards to the player's hand.
 * - PrintTable: which takes several arguments including vectors of shared pointers to CTable and CCard objects,
 *   an SProfessor object for the player name, a string for the professor name and an int for a random card.
 * - UseEasyTargetCard: which takes several arguments including vectors of shared pointers to CCard and CEasyTarget objects,
 *   an int for a random card, a reference to an SProfessor object for the attacker, a string for the attacker name
 *   and a vector of shared pointers to CTable objects for the table attacker.
 * - getChoice: which returns the value of mChoice.
 * - setChoice: which takes an int for the choice and sets the value of mChoice using the values from the mSelectChoice enum.
 * - getRoundCounter: which returns the value of mRoundCounter.
 * - setRoundCounter: which takes an int for the round number and sets the value of mRoundCounter.
 *
 * The class also has two private data members:
 * - mChoice: which stores the value of the choice selected by the user.
 * - mRoundCounter: which stores the value of the current round number.
 */
class CManager
{
public:
	enum mSelectChoice // Enum for selecting choices
	{
		eChoiceAlpha = 1,
		eChoiceBeta = 2,
	};
	void GameStart(); // Starts the game
	void GameOver(shared_ptr<CPlayers> piffle, shared_ptr<CPlayers> plagiarist, shared_ptr<CPlayers> pointless, shared_ptr<CPlayers> perdition); // Ends the game
	void StartRound(int& round); // Starts a new round
	void FillDeck(ifstream& inFile, vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CStudent>>& cardsStudent); // Fills the deck with cards
	void DrawCard(vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CCard>>& drawnCards, int& deckCounter, int& i, CPlayers playerName, vector<shared_ptr<bool>>& usedCards); // Draws a card
	void pushToHand(vector<shared_ptr<CCard>>& drawnCards, vector<shared_ptr<CCard>>& hand, int& i, CPlayers playerName); // Pushes cards to the player's hand
	void PrintTable(vector<shared_ptr<CTable>>& table, vector<shared_ptr<CCard>>& cardsDrawn, CPlayers playerName, string professor, int randomCard); // Prints the table
	int getChoice() const;  // Returns mChoice
	void setChoice(int choice);  //Sets mChoice either 1 or two from enum mSelectChoice
	int getRoundCounter() const; // Returns round number
	void setRoundCounter(int round); // Sets round number when incremented
	int mGetRoundInteger = 0; // Stores the value of the round number
	int mGetChoiceInteger = 0; // Stores the value of the choice selected by the user

private:
	int mChoice = 0; // Stores the value of the choice selected by the user
	int mRoundCounter = 1; // Stores the value of the current round number
};


