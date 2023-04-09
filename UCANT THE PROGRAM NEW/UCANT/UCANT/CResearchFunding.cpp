// Adam James Anthony Hall
#include "CResearchFunding.h"

/**

This function takes in a vector of shared pointers to cards, a vector of shared pointers to research funding cards, an integer
representing a random card index, a player's professor structure, a string representing the attacker's name, and a vector of shared pointers to table objects.
The function converts the shared pointer to a research funding card and adds it to the research funding vector if the drawn card is a research funding card.
Then, it randomly selects a table object and adds 2 to its power if there are research funding cards in the research funding vector and the table vector is
not empty. If the table vector is empty, the professor's prestige is increased by 2.
Finally, if the research funding vector is empty, the function does nothing, and the research funding vector is cleared at the end of the function.
*/
void CResearchFunding::useCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CResearchFunding>> researchFunding, int randomCard, CPlayers& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker)
{
	unique_ptr<CResearchFunding> printCardType = make_unique<CResearchFunding>();
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>();
	printCardType->printCardUse();

	if (cardsDrawn[randomCard]->mType == G_RESEARCH_FUNDING)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CResearchFunding> pResearchFundingElement = static_pointer_cast<CResearchFunding>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		researchFunding.push_back(pResearchFundingElement);

	}

	professorAttacker.mProfName = attackerName;

	int cardPowerAdditionInteger = 2;
	int cardPower;

	for (int i = 0; i < researchFunding.size(); i++)
	{
		int randomIndex = randomNumber->Random(tableAttacker.size() - 1);
		if (randomIndex < tableAttacker.size())
		{
			if (!researchFunding.empty())
			{

				if (!tableAttacker.empty())
				{

					shared_ptr<CCard> elementneeded = tableAttacker[randomIndex];
					cardPower = stoi(elementneeded->mPower);
					cardPower += cardPowerAdditionInteger;
					string cardPowerString = to_string(cardPower);
					tableAttacker[randomIndex]->mPower = cardPowerString;
					cout << tableAttacker[randomIndex]->mType << " " << tableAttacker[randomIndex]->mFirstname << " " << tableAttacker[randomIndex]->mLastname << " " << tableAttacker[randomIndex]->mPower << " " << tableAttacker[randomIndex]->mResilience << " " << tableAttacker[randomIndex]->mBoost << "has recieved a power increase of " << cardPowerAdditionInteger << endl;

				}

			}

			if (tableAttacker.empty())
			{
				professorAttacker.mProfPrestige += cardPowerAdditionInteger;
				cout << cardsDrawn[randomCard]->mFirstname << cardsDrawn[randomCard]->mLastname << " gives " << professorAttacker.mProfName << " " << cardPowerAdditionInteger << " prestige points, prestige is now " << professorAttacker.mProfPrestige << endl;

			}
		}
	}
	if (researchFunding.empty())
	{

	}
	researchFunding.clear();
}

void CResearchFunding::printCardUse()
{

}

void CResearchFunding::activateCardDeath()
{
	cout << "You have been killed by Research Funding." << endl;
}