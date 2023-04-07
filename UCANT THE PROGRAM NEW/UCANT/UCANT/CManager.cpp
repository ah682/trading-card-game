// Adam James Anthony Hall

// Initialize necessary header files
#include <memory>

#include "CManager.h"
#include "CPlayers.h"
#include "CTable.h"
#include "CCounter.h"
#include "CStudent.h"
#include "CCourseAccreditation.h"
#include "CPlagiarismHearing.h"
#include "CFeedbackForum.h"
#include "CSerialOffender.h"
#include "CMitigatingCircumstances.h"
#include "CIndustrialPlacement.h"
#include "CEasyTarget.h"
#include "CGraduateStudent.h"

// Tells the compiler to use the standard namespace
using namespace std;

/**
This function, PrintTable, takes in a vector of shared pointers to CTable objects, a vector of shared pointers to CCard objects, 
the name of the player as a struct, the name of the professor as a string, and an integer representing a random card drawn. It checks 
if the drawn card is of a certain type and, if so, converts it to a shared pointer to a CTable object and adds it to the table vector. 
It then prints out the cards on the table, along with their type, for the specified professor.
*/
void CManager::PrintTable(vector<shared_ptr<CTable>>& table, vector<shared_ptr<CCard>>& cardsDrawn, CPlayers::SProfessor playerName, string professor, int randomCard)
{
	playerName.mProfName = professor;
	if (((((((cardsDrawn[randomCard]->mType == G_STUDENT || cardsDrawn[randomCard]->mType == G_INDUSTRIAL_PLACEMENT) || cardsDrawn[randomCard]->mType == G_PASS_LEADER) || cardsDrawn[randomCard]->mType == G_EASY_TARGET) || cardsDrawn[randomCard]->mType == G_FEEDBACK_FORUM) || cardsDrawn[randomCard]->mType == G_SERIAL_OFFENDER) || cardsDrawn[randomCard]->mType == G_GRADUATE_STUDENT))
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CTable> tableElement = static_pointer_cast<CTable>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		table.push_back(tableElement);
	}

	// Shows cards placed on table
	cout << playerName.mProfName << " cards on table: ";
	for (int i = 0; i < table.size(); i++)
	{
		cout << table[i]->mFirstname << " " << table[i]->mLastname << " (" << table[i]->mType << ")" << " , ";
		if (i > table.size() - table.size() + 1)
		{
			break;
		}
	}
	cout << endl;
}

/**

This function represents the starting point of the game.
It prints a welcome message to the console and signals the start of the game.
The message printed is "Welcome to U-Can't. Let the winnowing begin...".
*/
void CManager::GameStart()
{
	cout << "Welcome to U-Can't. Let the winnowing begin..." << endl;
}

/**
 * GameOver - Determines the winner of the game based on the prestige of each professor
 * @param piffle - Professor object representing Piffle
 * @param plagiarist - Professor object representing Plagiarist
 * @param pointless - Professor object representing Pointless
 * @param perdition - Professor object representing Perdition
 */
void CManager::GameOver(CPlayers::SProfessor piffle, CPlayers::SProfessor plagiarist, CPlayers::SProfessor pointless, CPlayers::SProfessor perdition)
{


	if (piffle.mProfPrestige > plagiarist.mProfPrestige && piffle.mProfPrestige > pointless.mProfPrestige && piffle.mProfPrestige > perdition.mProfPrestige)
	{
		cout << endl << "Game Over" << endl << "=========" << endl;
		cout << "Prof " << plagiarist.mProfName << "'s prestige is " << plagiarist.mProfPrestige << endl;
		cout << "Prof " << pointless.mProfName << "'s prestige is " << pointless.mProfPrestige << endl;
		cout << "Prof " << perdition.mProfName << "'s prestige is " << perdition.mProfPrestige << endl;
		cout << "Prof " << piffle.mProfName << "'s prestige is " << piffle.mProfPrestige << endl << endl;
		cout << "Prof " << piffle.mProfName << " wins!" << endl;
	}
	else if (plagiarist.mProfPrestige > piffle.mProfPrestige && plagiarist.mProfPrestige > pointless.mProfPrestige && plagiarist.mProfPrestige > perdition.mProfPrestige)
	{
		cout << endl << "Game Over" << endl << "=========" << endl;
		cout << "Prof " << plagiarist.mProfName << "'s prestige is " << plagiarist.mProfPrestige << endl;
		cout << "Prof " << pointless.mProfName << "'s prestige is " << pointless.mProfPrestige << endl;
		cout << "Prof " << perdition.mProfName << "'s prestige is " << perdition.mProfPrestige << endl;
		cout << "Prof " << piffle.mProfName << "'s prestige is " << piffle.mProfPrestige << endl << endl;
		cout << "Prof " << plagiarist.mProfName << " wins!" << endl;
	}
	else if (pointless.mProfPrestige > plagiarist.mProfPrestige && pointless.mProfPrestige > piffle.mProfPrestige && pointless.mProfPrestige > perdition.mProfPrestige)
	{
		cout << endl << "Game Over" << endl << "=========" << endl;
		cout << "Prof " << plagiarist.mProfName << "'s prestige is " << plagiarist.mProfPrestige << endl;
		cout << "Prof " << pointless.mProfName << "'s prestige is " << pointless.mProfPrestige << endl;
		cout << "Prof " << perdition.mProfName << "'s prestige is " << perdition.mProfPrestige << endl;
		cout << "Prof " << piffle.mProfName << "'s prestige is " << piffle.mProfPrestige << endl << endl;
		cout << "Prof " << pointless.mProfName << " wins!" << endl;
	}
	else if (perdition.mProfPrestige > plagiarist.mProfPrestige && perdition.mProfPrestige > pointless.mProfPrestige && perdition.mProfPrestige > piffle.mProfPrestige)
	{
		cout << endl << "Game Over" << endl << "=========" << endl;
		cout << "Prof " << plagiarist.mProfName << "'s prestige is " << plagiarist.mProfPrestige << endl;
		cout << "Prof " << pointless.mProfName << "'s prestige is " << pointless.mProfPrestige << endl;
		cout << "Prof " << perdition.mProfName << "'s prestige is " << perdition.mProfPrestige << endl;
		cout << "Prof " << piffle.mProfName << "'s prestige is " << piffle.mProfPrestige << endl << endl;
		cout << "Prof " << perdition.mProfName << " wins!" << endl;
	}
	else
	{
		cout << endl << "Game Over" << endl << "=========" << endl;
	}
}

/**

Start a new round of the game and increment the round number.
@param round a reference to an integer storing the current round number
*/
void CManager::StartRound(int& round)
{
	if (round == 1)
	{
		cout << endl;
	}
	cout << endl << "Round: " << round << endl << "=========" << endl << endl;
	round++;
}

/**

Fills the deck of cards and students with data read from the input file stream.

@param[in] inFile The input file stream.

@param[in] cards A vector of shared pointers to CCard objects to be filled with data.

@param[in] cardsStudent A vector of shared pointers to CStudent objects to be filled with data.
*/
void CManager::FillDeck(ifstream& inFile, vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CStudent>>& cardsStudent)
{
	inFile.clear();
	inFile.seekg(0);

	string line;
	for (int i = 0; i < cards.size(); i++)
	{
		if (getline(inFile, line)) {
			stringstream ss(line);
			ss >> cards[i]->mType >> cards[i]->mFirstname >> cards[i]->mLastname >> cards[i]->mPower >> cards[i]->mResilience >> cards[i]->mBoost;
			if (cardsStudent[i]->mType == G_STUDENT)
			{
				ss >> cardsStudent[i]->mType >> cardsStudent[i]->mFirstname >> cardsStudent[i]->mLastname >> cardsStudent[i]->mPower >> cardsStudent[i]->mResilience >> cardsStudent[i]->mBoost;
			}
		}

	}
}

/**

Draws a card from the given deck of cards and adds it to the drawnCards vector.
Also updates the usedCards vector to mark the drawn card as used.
@param cards - The deck of cards to draw from.
@param drawnCards - The vector of drawn cards to add the drawn card to.
@param deckCounter - The current number of cards in the deck.
@param i - The current index of the card being drawn.
@param playerName - The name of the player drawing the card.
@param usedCards - A vector of bools representing whether a card has already been drawn.
*/
void CManager::DrawCard(vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CCard>>& drawnCards, int& deckCounter, int& i, CPlayers::SProfessor playerName, vector<shared_ptr<bool>>& usedCards)
{
	for (int j = i; j < deckCounter; j++)
	{
		if (i == G_DECK_SIZE)
		{
			break;
		}
		if (*usedCards[j] == false)
		{
			drawnCards.push_back(cards[j]);
			*usedCards[j] = true;
			cout << playerName.mProfName << " draws " << drawnCards[j]->mType << " " << drawnCards[j]->mFirstname << " " << drawnCards[j]->mLastname << " " << drawnCards[j]->mPower << " " << drawnCards[j]->mResilience << " " << drawnCards[j]->mBoost << endl;
			cout << playerName.mProfName << " plays " << drawnCards[j]->mFirstname << " " << drawnCards[j]->mLastname << " " << drawnCards[j]->mPower << " " << drawnCards[j]->mResilience << " " << drawnCards[j]->mBoost << endl;
		}
		else
		{
			i++;
			deckCounter++;
			*usedCards[j] = true;
		}
	}
}

/**

This function adds cards from the 'drawnCards' vector to the 'hand' vector, for a given professor 'playerName'.
It uses a for loop to iterate over the 'drawnCards' vector, starting from index 'i'.
It breaks out of the loop if 'i' equals G_DECK_SIZE.
If the 'hand' vector is not full, it adds the card at index 'j' to the 'hand' vector and prints a message indicating that the card was added.
@param drawnCards A vector of shared pointers to the cards drawn from the deck
@param hand A vector of shared pointers to the cards in the player's hand
@param i An integer representing the starting index for the for loop
@param playerName A struct representing the current player's name
@return void
*/
void CManager::pushToHand(vector<shared_ptr<CCard>>& drawnCards, vector<shared_ptr<CCard>>& hand, int& i, CPlayers::SProfessor playerName)
{
	for (int j = i; j < drawnCards.size(); j++)
	{
		if (i == G_DECK_SIZE)
		{
			break;
		}
		if (hand.size() < 2)
		{
			hand.push_back(drawnCards[j]);
			cout << playerName.mProfName << " has pushed " << hand[j]->mType << " " << hand[j]->mFirstname << " " << hand[j]->mLastname << " " << hand[j]->mPower << " " << hand[j]->mResilience << " " << hand[j]->mBoost << " to hand" << endl;
		}
	}
} 

/**

This function uses a student card to attack either a table or a professor. If a table is attacked, the function selects a random table from the tableAttacked vector and subtracts the card's power from the table's resilience. If a professor is attacked, the function subtracts the card's power from the professor's prestige. If the table's resilience or the professor's prestige reaches zero or below, they are removed from the game. The function also activates any special abilities of the card, and adds any drawn student cards to the ordinaryStudent vector.
@param tableAttacked - a vector of shared_ptr<CTable> representing the tables being attacked
@param tableAttacker - a vector of shared_ptr<CTable> representing the tables belonging to the attacker
@param professorAttacked - a struct representing the professor being attacked
@param professorAttacker - a struct representing the professor who owns the attacking card
@param cardsDrawn - a vector of shared_ptr<CCard> representing the cards drawn during the turn
@param ordinaryStudent - a vector of shared_ptr<CStudent> representing the drawn student cards
@param randomCard - an integer representing the index of the card being used
@param easyTarget - a vector of shared_ptr<CEasyTarget> representing the cards that can be used on tables directly
@return void
*/
void CManager::UseStudentCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CStudent>>& ordinaryStudent, int randomCard, vector<shared_ptr<CEasyTarget>> &easyTarget)
{
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>(); 
	shared_ptr<CEasyTarget> activateEasyTarget = make_shared<CEasyTarget>(); 
	shared_ptr<CStudent> printCardType = make_shared<CStudent>();

	activateEasyTarget->printCardUse();

	int cardPowerAttackerInt = 0;
	int cardResilienceAttackerInt = 0;
	int cardPowerAttackedInt = 0;
	int cardResilienceAttackedInt = 0;

	if (cardsDrawn[randomCard]->mType == G_STUDENT)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CStudent> pStudentElement = static_pointer_cast<CStudent>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		ordinaryStudent.push_back(pStudentElement);
	}

	professorAttacked.mProfName;
	professorAttacker.mProfName;

	if (!ordinaryStudent.empty())
	{

		for (int i = 0; i < ordinaryStudent.size(); i++)
		{
			
			string cardPowerAttacker = ordinaryStudent[i]->mPower;
			string cardResilienceAttacker = ordinaryStudent[i]->mResilience;

			if (!tableAttacked.empty()) {
				int randomIndex = randomNumber->Random(tableAttacked.size() - 1);

				string cardPowerAttacked = tableAttacked[randomIndex]->mPower;
				string cardResilienceAttacked = tableAttacked[randomIndex]->mResilience;

				cardPowerAttackerInt = stoi(cardPowerAttacker);
				cardResilienceAttackerInt = stoi(cardResilienceAttacker);
				cardPowerAttackedInt = stoi(cardPowerAttacked);
				cardResilienceAttackedInt = stoi(cardResilienceAttacked);

				activateEasyTarget->useCardSpecialAbility(cardPowerAttackerInt, easyTarget);

				if (cardResilienceAttackedInt > 0) {
					printCardType->attackEntity(cardResilienceAttackedInt, cardPowerAttackerInt, randomIndex, randomCard, tableAttacked, cardsDrawn);
				}
				if (cardResilienceAttackedInt <= 0) {
					printCardType->activateCardDeath(randomIndex, tableAttacked);
				}
			}

			if (tableAttacked.empty()) {
				printCardType->attackProfessor(professorAttacked, cardsDrawn, randomCard, cardPowerAttackedInt);
			}

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}


		}
	}
	if (ordinaryStudent.empty())
	{
		
	}
	ordinaryStudent.clear();

}

/**

This method is responsible for using Card Type 9 - Student. When students are activating, if there is an Easy Target in the enemy cohort, they MUST target them rather than choosing a random target.

@param cardsDrawn A vector containing shared pointers to all cards drawn

@param easyTarget A vector containing shared pointers to all Easy Target cards in play

@param randomCard An integer representing the index of the card chosen at random

@param professorAttacker A struct representing the attacking professor

@param attackerName A string representing the name of the attacking professor

@param tableAttacker A vector containing shared pointers to all tables in the attacking professor's cohort
*/
void CManager::UseEasyTargetCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CEasyTarget>> easyTarget, int randomCard, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker)
{
	unique_ptr<CEasyTarget> printCardType = make_unique<CEasyTarget>();
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>();
	printCardType->printCardUse();
	if (randomCard < cardsDrawn.size())
	{
		if (cardsDrawn[randomCard]->mType == G_EASY_TARGET)
		{
			// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
			shared_ptr<CEasyTarget> pEasyTargetElement = static_pointer_cast<CEasyTarget>(cardsDrawn[randomCard]);
			// Add the converted element to the accreditation vector
			easyTarget.push_back(pEasyTargetElement);
		}
	}
	else
	{


		professorAttacker.mProfName = attackerName;
		for (int i = 0; i < easyTarget.size(); i++)
		{
			int randomIndex = randomNumber->Random(tableAttacker.size() - 1);
			if (randomIndex < tableAttacker.size())
			{
				if (!easyTarget.empty())
				{
					if (!tableAttacker.empty())
					{
						if (randomIndex < tableAttacker.size())
						{
						}
						else
						{

						}
					}
				}
				if (tableAttacker.empty())
				{

				}
			}
		}
		if (easyTarget.empty())
		{
			cout << "Easy Target card is empty" << endl;
		}
	}
}

int CManager::getChoice() const // Returns mChoice
{
	return mChoice;
}

void CManager::setChoice(int choice) //Sets mChoice either 1 or two from enum mSelectChoice
{
	mChoice = choice;
}

int CManager::getRoundCounter() const // Returns round number
{
	return mRoundCounter;
}

void CManager::setRoundCounter(int round) // Sets round number when incremented
{
	mRoundCounter = round;
}

