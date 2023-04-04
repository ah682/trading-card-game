// Adam James Anthony Hall

// Initialize necessary header files
#include "CPlagiarismHearing.h"


void CPlagiarismHearing::printCardUse()
{
	cout << "Using Plagiarism Hearing Card" << endl;
}

void CPlagiarismHearing::activateCardDeath(CCard* enemyTable, vector <shared_ptr<CTable>>& tableAttacked) //Function overloading
{
	enemyTable->mResilience = "-0";
	cout << enemyTable->mType << " " << enemyTable->mFirstname << " " << enemyTable->mLastname << " " << enemyTable->mPower << " " << enemyTable->mResilience << " " << enemyTable->mBoost << " is defeated" << endl;

	enemyTable->mResilience = G_DEAD_CARD;
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
			CCard* enemyTable = tableAttacked.back().get();
			if (!enemyTable->mResilience.empty()) {
				cardResilience = stoi(enemyTable->mResilience);
			}

			if (randomChoice == 1)
			{
				if (cardResilience > 0) {
					cardResilience -= CARD_POWER;
					string cardResilienceString = to_string(cardResilience);
					tableAttacked[tableAttacked.size() - 1]->mResilience = cardResilienceString;
					cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks: " << enemyTable->mType << " " << enemyTable->mFirstname << " " << enemyTable->mLastname << " " << enemyTable->mPower << " " << enemyTable->mResilience << " " << enemyTable->mBoost << " " << enemyTable->mFirstname << " " << enemyTable->mLastname << " resilience is now " << enemyTable->mResilience << endl;
				}
				if (cardResilience <= 0) {
					printCardType->activateCardDeath(enemyTable, tableAttacked);
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
