#include "CGraduateStudent.h"

void CGraduateStudent::printCardUse()
{
	cout << "Using Graduate Student Card" << endl;
}

void CGraduateStudent::printCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked)
{
	cout << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " is defeated" << endl;
}
