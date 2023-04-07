// Adam James Anthony Hall

// Initialize necessary header files
#include "CCourseAccreditation.h"

void CCourseAccreditation::useCard(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CCourseAccreditation>>& accreditation, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	unique_ptr<CCourseAccreditation> printCardType = make_unique<CCourseAccreditation>();
	shared_ptr<CEasyTarget> activateEasyTarget = make_shared<CEasyTarget>();


	const int CARD_POWER = 1;
	int cardResilience = 0;

	printCardType->printCardUse();

	if (cardsDrawn[randomCard]->mType == G_COURSE_ACCREDITATION)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CCourseAccreditation> pAccreditationElement = static_pointer_cast<CCourseAccreditation>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		accreditation.push_back(pAccreditationElement);
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
	
}

void CCourseAccreditation::activateCardDeath(int j, vector<shared_ptr<CTable>>& tableAttacked) // Overloaded function
{
	cout << tableAttacked[j]->mType << " " << tableAttacked[j]->mFirstname << " " << tableAttacked[j]->mLastname << " " << tableAttacked[j]->mPower << " " << tableAttacked[j]->mResilience << " " << tableAttacked[j]->mBoost << " is defeated" << endl;
	tableAttacked.erase(tableAttacked.begin() + j);
}

void CCourseAccreditation::attackProfessor(int cardPower, int randomCard, CPlayers::SProfessor& professorAttacked, vector<shared_ptr<CCard>>& cardsDrawn)
{
	professorAttacked.mProfPrestige -= cardPower;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << professorAttacked.mProfName << ". " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
}

void CCourseAccreditation::attackEntity(string& cardResilienceString, vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CCard>>& cardsDrawn, int j, int randomCard)
{
	tableAttacked[j]->mResilience = cardResilienceString;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << tableAttacked[j]->mFirstname << " " << tableAttacked[j]->mLastname << ". " << tableAttacked[j]->mFirstname << " " << tableAttacked[j]->mLastname << " resilience is now " << tableAttacked[j]->mResilience << endl;
}