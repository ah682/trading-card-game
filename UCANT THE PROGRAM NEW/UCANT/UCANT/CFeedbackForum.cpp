// Adam James Anthony Hall

// Initialize necessary header files
#include "CFeedbackForum.h"
#include "CCard.h"

void CFeedbackForum::printCardUse()
{
	cout << "Using FeedBackForum Card" << endl;
}

void CFeedbackForum::printCardDeath(shared_ptr<CCard> elementneeded)
{
	cout << elementneeded->mType << " " << elementneeded->mFirstname << " " << elementneeded->mLastname << " " << elementneeded->mPower << " " << elementneeded->mResilience << " " << elementneeded->mBoost << " is defeated" << endl;
}
