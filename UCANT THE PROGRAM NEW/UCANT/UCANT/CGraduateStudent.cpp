#include "CGraduateStudent.h"

/**

This function uses a card played by a graduate student player against another player. It takes in various parameters such as the tables being attacked, the professors being attacked and attacking, the cards drawn, the graduate students involved, and the easy targets available. It then performs various actions such as checking if the drawn card is a graduate student card, selecting a random target table to attack, and activating the easy target's special ability. It also updates the prestige of the attacking professor and checks if the attacked professor's prestige has dropped to zero.
*/
void CGraduateStudent::useCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers& professorAttacked, CPlayers& professorAttacker, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CGraduateStudent>>& graduateStudent, int randomCard, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	unique_ptr<CGraduateStudent> printCardType = make_unique<CGraduateStudent>();
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>();
	shared_ptr<CEasyTarget> activateEasyTarget = make_shared<CEasyTarget>(); 

	printCardType->printCardUse();

	int cardPowerAttackerInt = 0;
	int cardResilienceAttackerInt = 0;
	int cardPowerAttackedInt = 0;
	int cardResilienceAttackedInt = 0;

	if (cardsDrawn[randomCard]->mType == G_GRADUATE_STUDENT)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CGraduateStudent> pStudentElement = static_pointer_cast<CGraduateStudent>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		graduateStudent.push_back(pStudentElement);
	}

	professorAttacked.mProfName;
	professorAttacker.mProfName;

	if (!graduateStudent.empty())
	{

		for (int i = 0; i < graduateStudent.size(); i++)
		{

			string cardPowerAttacker = graduateStudent[i]->mPower;
			string cardResilienceAttacker = graduateStudent[i]->mResilience;

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
					string cardResilienceStringDueled;
					printCardType->attackEntity(cardResilienceAttackedInt, cardPowerAttackerInt, cardResilienceStringDueled, tableAttacked, randomIndex, randomCard, cardsDrawn);
					professorAttacker.mProfPrestige += 2;
				}
				if (cardResilienceAttackedInt <= 0) {
					printCardType->activateCardDeath(randomIndex, tableAttacked);
				
				}
			}

			if (tableAttacked.empty()) {
				printCardType->attackProfessor(professorAttacked, cardPowerAttackerInt, cardsDrawn, randomCard);
				professorAttacker.mProfPrestige += 2;
			}

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}


		}
	}
	if (graduateStudent.empty())
	{
		
	}
	graduateStudent.clear();
}
void CGraduateStudent::printCardUse()
{
	
}

/**

This function activates the death of a card and removes it from the tableAttacked vector.
@param randomIndex The index of the card to be removed from tableAttacked vector.
@param tableAttacked The vector of shared pointers to CTable objects representing the cards on the attacked player's table.
*/
void CGraduateStudent::activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked)
{
	cout << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " is defeated" << endl;
	tableAttacked.erase(tableAttacked.begin() + randomIndex);
}

/**
 * Decreases the resilience of an entity attacked by a graduate student.
 *
 * @param cardResilienceAttackedInt The resilience value of the entity being attacked.
 * @param cardPowerAttackerInt The power value of the graduate student attacking the entity.
 * @param cardResilienceStringDueled A string representation of the new resilience value after the attack.
 * @param tableAttacked A vector of shared pointers to CTable objects representing the entities that can be attacked.
 * @param randomIndex The index of the entity being attacked in the tableAttacked vector.
 * @param randomCard The index of the card drawn from the deck of cards.
 * @param cardsDrawn A vector of shared pointers to CCard objects representing the deck of cards.
 */
void CGraduateStudent::attackEntity(int &cardResilienceAttackedInt, int &cardPowerAttackerInt, string &cardResilienceStringDueled, vector<shared_ptr<CTable>>& tableAttacked, int randomIndex, int randomCard, vector<shared_ptr<CCard>> &cardsDrawn)
{
	cardResilienceAttackedInt -= cardPowerAttackerInt;
	cardResilienceStringDueled = to_string(cardResilienceAttackedInt);
	tableAttacked[randomIndex]->mResilience = cardResilienceStringDueled;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << ". " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << "'s resilience is now " << tableAttacked[randomIndex]->mResilience << endl;
}

/**

This method is used to attack a professor with a card drawn from a player's deck.
@param professorAttacked - a reference to the professor object being attacked.
@param cardPowerAttackerInt - an integer representing the power of the attacking card.
@param cardsDrawn - a vector of shared pointers to the cards drawn by the player.
@param randomCard - an integer representing the index of the randomly drawn card from the player's deck.
*/
void CGraduateStudent::attackProfessor(CPlayers& professorAttacked, int cardPowerAttackerInt, vector<shared_ptr<CCard>> cardsDrawn, int randomCard)
{
	professorAttacked.mProfPrestige -= cardPowerAttackerInt;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << professorAttacked.mProfName << ". " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
}