// Adam James Anthony Hall

// Initialize necessary header files
#include "CPlagiarismHearing.h"


void CPlagiarismHearing::printCardUse()
{
	cout << "Using Plagiarism Hearing Card" << endl;
}

void CPlagiarismHearing::activateCardDeath(CCard* elementneeded, vector <shared_ptr<CTable>>& tableAttacked) //Function overloading
{
	elementneeded->mResilience = "-0";
	cout << elementneeded->mType << " " << elementneeded->mFirstname << " " << elementneeded->mLastname << " " << elementneeded->mPower << " " << elementneeded->mResilience << " " << elementneeded->mBoost << " is defeated" << endl;

	elementneeded->mResilience = G_DEAD_CARD;
	tableAttacked.pop_back();
}

void CPlagiarismHearing::useCard(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CPlagiarismHearing>>& plagiarism, vector <shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	unique_ptr<CPlagiarismHearing> printCardType = make_unique<CPlagiarismHearing>();
	shared_ptr<CEasyTarget> activateEasyTarget = make_shared<CEasyTarget>();
	printCardType->printCardUse();

	if (cardsDrawn[randomCard]->mType == G_PLAGIARISM_HEARING && cardsDrawn[randomCard]->mResilience != G_DEAD_CARD)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CPlagiarismHearing> pPlagiarismElement = static_pointer_cast<CPlagiarismHearing>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		plagiarism.push_back(pPlagiarismElement);
	}

	professorAttacked.mProfName = attackedName;
	professorAttacker.mProfName = attackerName;

	const int CARD_POWER = 3;
	int cardResilience = 0;

	for (int i = 0; i < plagiarism.size(); i++)
	{
		activateEasyTarget->useCardSpecialAbility(CARD_POWER, easyTarget);
		if (!tableAttacked.empty()) {
			CCard* elementneeded = tableAttacked.back().get();
			if (!elementneeded->mResilience.empty()) {
				cardResilience = stoi(elementneeded->mResilience);
			}

			if (randomChoice == 1)
			{
				if (cardResilience > 0) {
					cardResilience -= CARD_POWER;
					string cardResilienceString = to_string(cardResilience);
					tableAttacked[tableAttacked.size() - 1]->mResilience = cardResilienceString;
					cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks: " << elementneeded->mType << " " << elementneeded->mFirstname << " " << elementneeded->mLastname << " " << elementneeded->mPower << " " << elementneeded->mResilience << " " << elementneeded->mBoost << " " << elementneeded->mFirstname << " " << elementneeded->mLastname << " resilience is now " << elementneeded->mResilience << endl;
				}
				if (cardResilience <= 0) {
					printCardType->activateCardDeath(elementneeded, tableAttacked);
				}
			}

			if (randomChoice == 2) {
				professorAttacked.mProfPrestige -= CARD_POWER;
				cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
			}
			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}
		}
	}
}
