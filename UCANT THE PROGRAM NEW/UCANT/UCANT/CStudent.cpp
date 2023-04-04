// Adam James Anthony Hall

// Initialize necessary header files
#include "CStudent.h"
#include "CCard.h"

void CStudent::printCardUse()
{
	cout << "Using Student Card" << endl;
}

void CStudent::activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked)
{

	tableAttacked[randomIndex]->mResilience = "0";
	cout << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " is defeated" << endl;
	tableAttacked[randomIndex]->mResilience = G_DEAD_CARD;
	tableAttacked.erase(tableAttacked.begin() + randomIndex);
}

void CStudent::attackEntity(int &cardResilienceAttackedInt, int &cardPowerAttackerInt, int randomIndex, int randomCard, vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CCard>> cardsDrawn)
{
	cardResilienceAttackedInt -= cardPowerAttackerInt;
	string cardResilienceStringDueled = to_string(cardResilienceAttackedInt);
	tableAttacked[randomIndex]->mResilience = cardResilienceStringDueled;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks : " << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " resilience is now " << tableAttacked[randomIndex]->mResilience << endl;
}

void CStudent::attackProfessor(CPlayers::SProfessor& professorAttacked, vector<shared_ptr<CCard>> cardsDrawn, int randomCard, int& cardPowerAttackerInt)
{
	professorAttacked.mProfPrestige -= cardPowerAttackerInt;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks  " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
}