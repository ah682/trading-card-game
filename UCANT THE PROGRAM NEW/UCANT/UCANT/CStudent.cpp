// Adam James Anthony Hall

// Initialize necessary header files
#include "CStudent.h"
#include "CCard.h"

void CStudent::printCardUse()
{
	cout << "Using Student Card" << endl;
}

void CStudent::printCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked)
{

	tableAttacked[randomIndex]->mResilience = "0";
	cout << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " is defeated" << endl;
	tableAttacked[randomIndex]->mResilience = G_DEAD_CARD;
	tableAttacked.erase(tableAttacked.begin() + randomIndex);
}