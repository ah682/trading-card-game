// Adam James Anthony Hall

// Initialize necessary header files
#include "CCourseAccreditation.h"

/**
 * Uses a card to attack professors and tables, and adds it to the accreditation vector if it's a course accreditation card.
 *
 * @param cardsDrawn The vector of drawn cards.
 * @param accreditation The vector of accreditation cards.
 * @param tableAttacked The vector of tables being attacked.
 * @param randomCard The index of the randomly chosen card to use.
 * @param professorAttacked The professor being attacked.
 * @param professorAttacker The professor attacking.
 * @param attackedName The name of the professor being attacked.
 * @param attackerName The name of the professor attacking.
 * @param easyTarget The vector of easy target cards.
 */
void CCourseAccreditation::useCard(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CCourseAccreditation>>& accreditation, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers& professorAttacked, CPlayers& professorAttacker, string attackedName, string attackerName, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	unique_ptr<CCourseAccreditation> printCardType = make_unique<CCourseAccreditation>();
	shared_ptr<CEasyTarget> activateEasyTarget = make_shared<CEasyTarget>();


	const int CARD_POWER = 1;
	int cardResilience = 0;

	printCardType->printCardUse();

	if (cardsDrawn[randomCard]->mType == G_COURSE_ACCREDITATION)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CCourseAccreditation> pAccreditationElements = static_pointer_cast<CCourseAccreditation>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		accreditation.push_back(pAccreditationElements);
	}

	professorAttacked.mProfName = attackedName;
	professorAttacker.mProfName = attackerName;

	for (int i = 0; i < accreditation.size(); i++)
	{
		if (!tableAttacked.empty()) {
			for (int j = 0; j < tableAttacked.size() - 1; j++)
			{
				activateEasyTarget->useCardSpecialAbility(CARD_POWER, easyTarget);
				cardResilience = stoi(tableAttacked[j]->mResilience);
				cardResilience -= CARD_POWER;
				string cardResilienceString = to_string(cardResilience);
				printCardType->attackEntity(cardResilienceString, tableAttacked, cardsDrawn, j, randomCard);


				if (cardResilience <= 0) {
					printCardType->activateCardDeath(j, tableAttacked);
				}
			}

			printCardType->attackProfessor(CARD_POWER, randomCard, professorAttacked, cardsDrawn);

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}
		}

	}
}


void CCourseAccreditation::printCardUse()
{
	// NULL
}

/**
 * This function activates the death of a table element in the vector tableAttacked.
 * It takes in two parameters:
 * 1. j: the index of the table element to be removed
 * 2. tableAttacked: a vector of shared_ptr to CTable objects representing the table elements
 *
 * When a table element's resilience drops to 0 or less, it is considered defeated and removed from the table.
 * This function prints a message to the console indicating the details of the defeated table element.
 * It then uses the erase() method of the vector class to remove the defeated table element from the tableAttacked vector.
 */
void CCourseAccreditation::activateCardDeath(int j, vector<shared_ptr<CTable>>& tableAttacked) // Overloaded function
{
	cout << tableAttacked[j]->mType << " " << tableAttacked[j]->mFirstName << " " << tableAttacked[j]->mLastName << " is defeated" << endl;
	tableAttacked.erase(tableAttacked.begin() + j);
}

/**
* Decreases the prestige of the attacked professor based on the power of the card played
* Prints out a message indicating the attackand the resulting prestige of the professor
* @param cardPower an integer representing the power of the card played
* @param randomCard an integer representing the index of the card played in the cardsDrawn vector
* @param professorAttacked a reference to a struct representing the professor who is being attacked
* @param cardsDrawn a vector of shared pointers to CCard objects representing the cards in the current game
*/
void CCourseAccreditation::attackProfessor(int cardPower, int randomCard, CPlayers& professorAttacked, vector<shared_ptr<CCard>>& cardsDrawn)
{
	professorAttacked.mProfPrestige -= cardPower;
	cout << cardsDrawn[randomCard]->mFirstName << " " << cardsDrawn[randomCard]->mLastName << " attacks " << professorAttacked.mProfName << ". " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
}

/**
 * This function updates the resilience of a card that has been attacked by a card of type CCourseAccreditation.
 * It takes the current resilience of the card as a string, subtracts the card power of the attacking card and updates the
 * resilience of the card. It also prints out the details of the attack, including the name and type of the attacking card,
 * the name of the attacked entity, and the new resilience of the attacked entity.
 *
 * @param cardResilienceString A reference to a string representing the current resilience of the attacked card.
 * @param tableAttacked A vector of shared pointers to CTable objects representing the table on which the attacked card is located.
 * @param cardsDrawn A vector of shared pointers to CCard objects representing the cards drawn in the game.
 * @param j An integer representing the index of the attacked card in the tableAttacked vector.
 * @param randomCard An integer representing the index of the attacking card in the cardsDrawn vector.
 */
void CCourseAccreditation::attackEntity(string& cardResilienceString, vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CCard>>& cardsDrawn, int j, int randomCard)
{
	tableAttacked[j]->mResilience = cardResilienceString;
	cout << cardsDrawn[randomCard]->mFirstName << " " << cardsDrawn[randomCard]->mLastName << " attacks " << tableAttacked[j]->mFirstName << " " << tableAttacked[j]->mLastName << ". " << tableAttacked[j]->mFirstName << " " << tableAttacked[j]->mLastName << "'s resilience is now " << tableAttacked[j]->mResilience << endl;
}