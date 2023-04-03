#include "CResearchFunding.h"

void CResearchFunding::useCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CResearchFunding>> researchFunding, int randomCard, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker)
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
		cout << "There is no research funding cards to use" << endl;
	}
}

void CResearchFunding::printCardUse()
{
	cout << "Using Research Funding Card" << endl;
}

void CResearchFunding::printCardDeath()
{
	cout << "You have been killed by Research Funding." << endl;
}