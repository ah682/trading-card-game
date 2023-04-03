// Adam James Anthony Hall

// Initialize necessary header files
#include "CCourseAccreditation.h"



void CCourseAccreditation::printCardUse()
{
	cout << "Using Course Accreditation Card" << endl;
}

void CCourseAccreditation::printCardDeath(int j, vector<shared_ptr<CTable>>& tableAttacked)
{
	cout << tableAttacked[j]->mType << " " << tableAttacked[j]->mFirstname << " " << tableAttacked[j]->mLastname << " " << tableAttacked[j]->mPower << " " << tableAttacked[j]->mResilience << " " << tableAttacked[j]->mBoost << " is defeated" << endl;
}