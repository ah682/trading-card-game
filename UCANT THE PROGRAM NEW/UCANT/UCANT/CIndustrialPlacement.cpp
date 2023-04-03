// Adam James Anthony Hall
#include "CIndustrialPlacement.h"


void CIndustrialPlacement::printCardUse()
{
	cout << "Using Industrial Placement Card" << endl;
}

void CIndustrialPlacement::printCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked)
{
	cout << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " is defeated" << endl;
}
