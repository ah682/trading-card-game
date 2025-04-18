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
void CManager::PrintTable(vector<shared_ptr<CTable>>& table, vector<shared_ptr<CCard>>& cardsDrawn, CPlayers playerName, string professor, int randomCard)
{
	playerName.mProfName = professor;
	if (((((((cardsDrawn[randomCard]->mType == G_STUDENT || cardsDrawn[randomCard]->mType == G_INDUSTRIAL_PLACEMENT) || cardsDrawn[randomCard]->mType == G_PASS_LEADER) || cardsDrawn[randomCard]->mType == G_EASY_TARGET) || cardsDrawn[randomCard]->mType == G_FEEDBACK_FORUM) || cardsDrawn[randomCard]->mType == G_SERIAL_OFFENDER) || cardsDrawn[randomCard]->mType == G_GRADUATE_STUDENT))
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CTable> tableElements = static_pointer_cast<CTable>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		table.push_back(tableElements);
	}

	// Shows cards placed on table
	cout << playerName.mProfName << " cards on table: ";
	for (int i = 0; i < table.size(); i++)
	{
		cout << table[i]->mFirstName << " " << table[i]->mLastName << " (" << table[i]->mType << ")" << " , ";
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
void CManager::GameOver(shared_ptr<CPlayers> piffle, shared_ptr<CPlayers> plagiarist, shared_ptr<CPlayers> pointless, shared_ptr<CPlayers> perdition)
{


	if (piffle->mProfPrestige > plagiarist->mProfPrestige && piffle->mProfPrestige > pointless->mProfPrestige && piffle->mProfPrestige > perdition->mProfPrestige)
	{
		cout << endl << "Game Over" << endl << "=========" << endl;
		cout << "Prof " << plagiarist->mProfName << "'s prestige is " << plagiarist->mProfPrestige << endl;
		cout << "Prof " << pointless->mProfName << "'s prestige is " << pointless->mProfPrestige << endl;
		cout << "Prof " << perdition->mProfName << "'s prestige is " << perdition->mProfPrestige << endl;
		cout << "Prof " << piffle->mProfName << "'s prestige is " << piffle->mProfPrestige << endl << endl;
		cout << "Prof " << piffle->mProfName << " wins!" << endl;
	}
	if (plagiarist->mProfPrestige > piffle->mProfPrestige && plagiarist->mProfPrestige > pointless->mProfPrestige && plagiarist->mProfPrestige > perdition->mProfPrestige)
	{
		cout << endl << "Game Over" << endl << "=========" << endl;
		cout << "Prof " << plagiarist->mProfName << "'s prestige is " << plagiarist->mProfPrestige << endl;
		cout << "Prof " << pointless->mProfName << "'s prestige is " << pointless->mProfPrestige << endl;
		cout << "Prof " << perdition->mProfName << "'s prestige is " << perdition->mProfPrestige << endl;
		cout << "Prof " << piffle->mProfName << "'s prestige is " << piffle->mProfPrestige << endl << endl;
		cout << "Prof " << plagiarist->mProfName << " wins!" << endl;
	}
	if (pointless->mProfPrestige > plagiarist->mProfPrestige && pointless->mProfPrestige > piffle->mProfPrestige && pointless->mProfPrestige > perdition->mProfPrestige)
	{
		cout << endl << "Game Over" << endl << "=========" << endl;
		cout << "Prof " << plagiarist->mProfName << "'s prestige is " << plagiarist->mProfPrestige << endl;
		cout << "Prof " << pointless->mProfName << "'s prestige is " << pointless->mProfPrestige << endl;
		cout << "Prof " << perdition->mProfName << "'s prestige is " << perdition->mProfPrestige << endl;
		cout << "Prof " << piffle->mProfName << "'s prestige is " << piffle->mProfPrestige << endl << endl;
		cout << "Prof " << pointless->mProfName << " wins!" << endl;
	}
	if (perdition->mProfPrestige > plagiarist->mProfPrestige && perdition->mProfPrestige > pointless->mProfPrestige && perdition->mProfPrestige > piffle->mProfPrestige)
	{
		cout << endl << "Game Over" << endl << "=========" << endl;
		cout << "Prof " << plagiarist->mProfName << "'s prestige is " << plagiarist->mProfPrestige << endl;
		cout << "Prof " << pointless->mProfName << "'s prestige is " << pointless->mProfPrestige << endl;
		cout << "Prof " << perdition->mProfName << "'s prestige is " << perdition->mProfPrestige << endl;
		cout << "Prof " << piffle->mProfName << "'s prestige is " << piffle->mProfPrestige << endl << endl;
		cout << "Prof " << perdition->mProfName << " wins!" << endl;
	}
	else
	{
		cout << "";
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
			ss >> cards[i]->mType >> cards[i]->mFirstName >> cards[i]->mLastName >> cards[i]->mPower >> cards[i]->mResilience >> cards[i]->mBoost;
			if (cardsStudent[i]->mType == G_STUDENT)
			{
				ss >> cardsStudent[i]->mType >> cardsStudent[i]->mFirstName >> cardsStudent[i]->mLastName >> cardsStudent[i]->mPower >> cardsStudent[i]->mResilience >> cardsStudent[i]->mBoost;
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
void CManager::DrawCard(vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CCard>>& drawnCards, int& deckCounter, int& i, CPlayers playerName, vector<shared_ptr<bool>>& usedCards)
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
			cout << playerName.mProfName << " draws " << drawnCards[j]->mType << " " << drawnCards[j]->mFirstName << " " << drawnCards[j]->mLastName << " " << drawnCards[j]->mPower << " " << drawnCards[j]->mResilience << " " << drawnCards[j]->mBoost << endl;
			cout << playerName.mProfName << " plays " << drawnCards[j]->mFirstName << " " << drawnCards[j]->mLastName << " " << drawnCards[j]->mPower << " " << drawnCards[j]->mResilience << " " << drawnCards[j]->mBoost << endl;
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
void CManager::pushToHand(vector<shared_ptr<CCard>>& drawnCards, vector<shared_ptr<CCard>>& hand, int& i, CPlayers playerName)
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
			cout << playerName.mProfName << " has pushed " << hand[j]->mType << " " << hand[j]->mFirstName << " " << hand[j]->mLastName << " " << hand[j]->mPower << " " << hand[j]->mResilience << " " << hand[j]->mBoost << " to hand" << endl;
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

