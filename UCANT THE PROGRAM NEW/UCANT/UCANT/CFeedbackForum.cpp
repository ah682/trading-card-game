// Adam James Anthony Hall

// Initialize necessary header files
#include "CFeedbackForum.h"
#include "CCard.h"
#include "CCounter.h"


/**

The useCard() function is a member function of the CFeedbackForum class which represents a card in a card game.
This function takes in several parameters including a vector of shared pointers to cards drawn, a vector of
shared pointers to feedback forums, a vector of shared pointers to tables being attacked, an integer randomCard,
a struct representing a professor being attacked, a struct representing a professor being attacked, the name of the
attacked and attacking professors, an integer randomChoice, a vector of shared pointers to tables being attacked,
and a vector of shared pointers to easy targets.
The function first creates a unique pointer to a CCounter object and a shared pointer to a CEasyTarget object,
and then creates a unique pointer to a CFeedbackForum object which is used to print the type of card being used.
If the type of card being used is a feedback forum card, the function converts the shared pointer to a
feedback forum and adds it to the feedback forum vector.
The function then sets the name of the attacked and attacking professors, and initializes a constant integer
CARD_POWER to 2, and initializes an integer variable cardResilience to 0.
The function then iterates through the feedback forum vector, using the easy target object to activate the
special ability of the easy target card. If randomChoice is 1, the function selects a random index in the
tableAttacked vector, and if the selected card has a resilience value greater than 0, the function reduces
the resilience value by CARD_POWER and updates the tableAttacked vector with the new resilience value. If
the resilience value becomes less than or equal to 0, the function calls the activateCardDeath() function to
remove the card from the tableAttacked vector. The function also reduces the prestige of the attacked professor
by CARD_POWER.
If randomChoice is 2, the function selects a random index in the tableAttacker vector, and if the selected
card has a resilience value, the function increases the resilience value by CARD_POWER and updates the
tableAttacker vector with the new resilience value. The function also increases the prestige of the attacking
professor by CARD_POWER.
The function then checks if the attacked professor's prestige has become negative and sets it to 0 if so.
The function finally prints the updated prestige of the attacked professor.
At the end, the feedbackforum vector is cleared.
*/
void CFeedbackForum::useCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CFeedbackForum>>& feedbackforum, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers& professorAttacked, CPlayers& professorAttacker, string attackedName, string attackerName, int randomChoice, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>();
	shared_ptr<CEasyTarget> activateEasyTarget = make_shared<CEasyTarget>();
	unique_ptr<CFeedbackForum> printCardType = make_unique<CFeedbackForum>();

	printCardType->printCardUse();

	if (cardsDrawn[randomCard]->mType == G_FEEDBACK_FORUM)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CFeedbackForum> pFeedbackElement = static_pointer_cast<CFeedbackForum>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		feedbackforum.push_back(pFeedbackElement);

	}

	professorAttacked.mProfName = attackedName;
	professorAttacker.mProfName = attackerName;

	const int CARD_POWER = 2;
	int cardResilience = 0;

	for (int i = 0; i < feedbackforum.size(); i++)
	{
		activateEasyTarget->useCardSpecialAbility(CARD_POWER, easyTarget);
		if (randomChoice == 1)
		{
			int randomIndex = randomNumber->Random(tableAttacked.size() - 1);

			if (!tableAttacked.empty())
			{
				shared_ptr<CCard> tableAttackedElements = tableAttacked[randomIndex];
				if (!tableAttackedElements->mResilience.empty())
				{
					cardResilience = stoi(tableAttackedElements->mResilience);
				}


				if (cardResilience > 0)
				{
					cardResilience -= CARD_POWER;
					string cardResilienceString = to_string(cardResilience);
					tableAttacked[randomIndex]->mResilience = cardResilienceString;
					cout << cardsDrawn[randomCard]->mFirstName << " " << cardsDrawn[randomCard]->mLastName << " attacks " << tableAttacked[randomIndex]->mFirstName << " " << tableAttacked[randomIndex]->mLastName << ". " << tableAttacked[randomIndex]->mFirstName << " " << tableAttacked[randomIndex]->mLastName << "'s resilience is now " << tableAttacked[randomIndex]->mResilience << endl;
				}
				if (cardResilience <= 0)
				{
					printCardType->activateCardDeath(tableAttackedElements, tableAttacked, randomIndex);
				}
				professorAttacked.mProfPrestige -= CARD_POWER;
			}

			if (randomChoice == 2)
			{

				int randomIndex = randomNumber->Random(tableAttacker.size() - 1);
				if (!tableAttacker.empty())
				{
					shared_ptr<CCard> tableAttackerElements = tableAttacker[randomIndex];
					if (!tableAttackerElements->mResilience.empty())
					{
						cardResilience = stoi(tableAttackerElements->mResilience);
					}
				}
				cardResilience += CARD_POWER;
				string cardResilienceString = to_string(cardResilience);
				tableAttacker[randomIndex]->mResilience = cardResilienceString;
				professorAttacker.mProfPrestige += CARD_POWER;
				cout << cardsDrawn[randomCard]->mFirstName << " " << cardsDrawn[randomCard]->mLastName << " boosts " << professorAttacker.mProfName << ". " << professorAttacker.mProfName << " resilience is now " << professorAttacker.mProfName << endl;
				cout << cardsDrawn[randomCard]->mFirstName << " " << cardsDrawn[randomCard]->mLastName << " boosts " << tableAttacker[tableAttacker.size() - 1]->mFirstName << " " << tableAttacker[tableAttacker.size() - 1]->mLastName << ". " << tableAttacker[tableAttacker.size() - 1]->mFirstName << tableAttacker[tableAttacker.size() - 1] << " resilience is now " << tableAttacker[tableAttacker.size() - 1]->mResilience << endl;
			}


			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}

		}
		cout << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
	}
	feedbackforum.clear();
}

void CFeedbackForum::printCardUse()
{

}

/**

This function is called when a card's resilience reaches zero or below. It removes the defeated card from the table
and prints a message indicating the card's type, name, power, resilience, and boost.
@param defeatedCard - A shared pointer to the card that has been defeated.
@param tableAttacked - A vector of shared pointers to the cards that have been attacked.
@param randomIndex - An integer representing the index of the defeated card in the vector.
*/
void CFeedbackForum::activateCardDeath(shared_ptr<CCard> defeatedCard, vector<shared_ptr<CTable>>& tableAttacked, int randomIndex)
{
	cout << defeatedCard->mType << " " << defeatedCard->mFirstName << " " << defeatedCard->mLastName << " is defeated" << endl;
	tableAttacked.erase(tableAttacked.begin() + randomIndex);
}
